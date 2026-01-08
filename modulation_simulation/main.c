#include <stdlib.h>
#include <stdio.h>

#include "encode.h"

int main() {
    char *test_string = "MOBILE COMMUNICATION PROTOCOLS";
    iq_t **encoded_samples = encode_str(test_string);

    // Debug
    for (size_t i = 0; encoded_samples[i] != NULL; i++) {
        printf("Symbol %zu: I = %f, Q = %f\n", i, encoded_samples[i]->i, encoded_samples[i]->q);
    }

    // Free allocated memory
    for (size_t i = 0; encoded_samples[i] != NULL; i++) {
        free(encoded_samples[i]);
    }
    free(encoded_samples);

    return 0;
}
