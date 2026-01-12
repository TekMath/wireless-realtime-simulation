#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "encode.h"
#include "decode.h"
#include "noise.h"
#include "debug.h"

static size_t get_number_incorrect_characters(const char *str1, const char *str2)
{
    size_t incorrect_count = 0;
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);
    size_t min_len = (len1 < len2) ? len1 : len2;

    for (size_t i = 0; i < min_len; i++)
    {
        if (str1[i] != str2[i])
        {
            incorrect_count++;
        }
    }

    incorrect_count += abs((int)(len1 - len2));

    return incorrect_count;
}

static void avoid_invalid_characters(char *str)
{
    for (size_t i = 0; str[i] != '\0'; i++)
    {
        if (str[i] < 32 || str[i] > 126)
        {
            str[i] = '?';
        }
    }
}

void debug_mode(const char *test_string)
{
    iq_t **encoded_samples = encode_str(test_string);

    printf("= DEBUG MODE =\n\n");
    printf("- Original String: \"%s\"\n", test_string);
    printf("- Encoded -> Decoded Strings:\n");

    char* no_noise_decoded_string = decode_iqs(encoded_samples);
    printf("\t- [No Noise]: \"%s\"\n", no_noise_decoded_string);
    free(no_noise_decoded_string);

    for (size_t i = 0; i < NOISE_LEVELS; i++)
    {
        float sigma = noise_levels[i];
        iq_t **noisy_samples = add_noise_to_samples(encoded_samples, sigma);

        char* decoded_string = decode_iqs(noisy_samples);
        size_t incorrect_chars = get_number_incorrect_characters(test_string, decoded_string);

        avoid_invalid_characters(decoded_string);
        printf("\t- [Noise σ=%.3f]: \"%s\"\t| Incorrect Characters: %zu\n", sigma, decoded_string, incorrect_chars);

        free(decoded_string);
        free_encoded_samples(noisy_samples);
    }

    free_encoded_samples(encoded_samples);
    return;
}
