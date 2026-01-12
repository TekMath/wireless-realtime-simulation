#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "debug.h"
/* int main()
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
 */

// Argument format: <mode> <test_string> <noise_sigma>
int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s <mode> <test_string>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *mode = argv[1];
    char *test_string = argv[2];

    if (strcmp(mode, "debug") == 0)
    {
        debug_mode(test_string);
        return EXIT_SUCCESS;
    }

    if (strcmp(mode, "export") == 0)
    {
        if (argc != 4)
        {
            fprintf(stderr, "Usage: %s export <test_string> <noise_level>\n", argv[0]);
            return EXIT_FAILURE;
        }

        float noise_sigma = strtof(argv[3], NULL);

        return EXIT_SUCCESS;
    }

    fprintf(stderr, "Invalid mode: %s\n", mode);
    return EXIT_FAILURE;
}
