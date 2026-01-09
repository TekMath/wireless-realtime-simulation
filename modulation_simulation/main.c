#include <stdlib.h>
#include <stdio.h>

#include "encode.h"
#include "noise.h"
#include "decode.h"

int main()
{
    char *test_string = "MOBILE COMMUNICATION PROTOCOLS";
    iq_t **encoded_samples = encode_str(test_string);

    // Debug
    for (size_t i = 0; encoded_samples[i] != NULL; i++)
    {
        printf("Symbol %zu: I = %f, Q = %f\n", i, encoded_samples[i]->i, encoded_samples[i]->q);
    }

    char *decoded_string = decode_iqs(encoded_samples);
    printf("Decoded string: %s\n", decoded_string);
    free(decoded_string);

    float noise_sigma = 0.02f;
    add_noise_to_samples(encoded_samples, noise_sigma);

    // Debug
    for (size_t i = 0; encoded_samples[i] != NULL; i++)
    {
        printf("Symbol %zu: I = %f, Q = %f\n", i, encoded_samples[i]->i, encoded_samples[i]->q);
    }

    decoded_string = decode_iqs(encoded_samples);
    printf("Decoded string: %s\n", decoded_string);
    free(decoded_string);

    free_encoded_samples(encoded_samples);

    return 0;
}
