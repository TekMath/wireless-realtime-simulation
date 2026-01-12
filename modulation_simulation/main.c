#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "debug.h"
#include "export.h"

int main(int argc, char *argv[])
{
    if (argc < 3)
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

        export_iq_csv_from_string(test_string, noise_sigma);

        return EXIT_SUCCESS;
    }

    fprintf(stderr, "Invalid mode: %s\n", mode);
    return EXIT_FAILURE;
}
