#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "iq.h"
#include "encode.h"
#include "noise.h"

static int export_iq_csv(iq_t **data)
{
    char filename[64];
    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    snprintf(filename, sizeof(filename), "%04d%02d%02d_%02d%02d%02d.csv",
             t->tm_year + 1900, t->tm_mon + 1, t->tm_mday,
             t->tm_hour, t->tm_min, t->tm_sec);

    FILE *fp = fopen(filename, "w");
    if (fp == NULL)
    {
        return -1;
    }

    fprintf(fp, "I,Q\n");

    int i = 0;
    while (data[i] != NULL)
    {
        fprintf(fp, "%f,%f\n", data[i]->i, data[i]->q);
        i++;
    }

    fclose(fp);
    return 0;
}

void export_iq_csv_from_string(const char *string, float noise_level)
{
    iq_t **encoded_samples = encode_str(string);
    iq_t **noisy_samples = add_noise_to_samples(encoded_samples, noise_level);

    if (export_iq_csv(noisy_samples) != 0)
    {
        fprintf(stderr, "Error exporting IQ data to CSV file.\n");
    }

    free_encoded_samples(encoded_samples);
    free_encoded_samples(noisy_samples);
}
