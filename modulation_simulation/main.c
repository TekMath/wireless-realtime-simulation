#include <stdlib.h>
#include <stdio.h>

#include "encode.h"
#include "noise.h"

int main()
{
    char *test_string = "MOBILE COMMUNICATION PROTOCOLS";
    iq_t **encoded_samples = encode_str(test_string);

    // Debug
    for (size_t i = 0; encoded_samples[i] != NULL; i++)
    {
        printf("Symbol %zu: I = %f, Q = %f\n", i, encoded_samples[i]->i, encoded_samples[i]->q);
    }

    float noise_sigma = 0.5f;
    add_noise_to_samples(encoded_samples, noise_sigma);

    // Debug
    for (size_t i = 0; encoded_samples[i] != NULL; i++)
    {
        printf("Symbol %zu: I = %f, Q = %f\n", i, encoded_samples[i]->i, encoded_samples[i]->q);
    }

    free_encoded_samples(encoded_samples);

    return 0;
}
