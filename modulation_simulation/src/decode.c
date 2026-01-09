#include <stdlib.h>
#include <math.h>
#include <stdio.h>

#include "decode.h"
#include "consts.h"

static char decode_iq(iq_t *sample)
{
    int8_t i_level = roundf(sample->i / IQ_AMPLITUDE);
    int8_t q_level = roundf(sample->q / IQ_AMPLITUDE);

    uint8_t i_idx = (i_level + (SQRT_QAM_M - 1)) / 2;
    uint8_t q_idx = (q_level + (SQRT_QAM_M - 1)) / 2;

    uint8_t byte = (i_idx << (uint8_t)log2(SQRT_QAM_M)) | q_idx;

    return (char)byte;
}

char *decode_iqs(iq_t **samples)
{
    if (samples == NULL)
    {
        return NULL;
    }

    size_t length = 0;
    while (samples[length] != NULL)
    {
        length++;
    }

    char *decoded_str = malloc(sizeof(char) * (length + 1));

    for (size_t i = 0; i < length; i++)
    {
        decoded_str[i] = decode_iq(samples[i]);
    }

    decoded_str[length] = '\0';
    return decoded_str;
}
