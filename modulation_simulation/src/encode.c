#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

#include "encode.h"
#include "consts.h"

/**
 * @brief Encode a byte to IQ samples
 * @param byte The byte to encode
 * @return iq_t* The encoded IQ samples
 */
static iq_t *encode_byte(uint8_t byte)
{
    iq_t *iq = malloc(sizeof(iq_t));

    uint8_t i_idx = byte >> (uint8_t)log2(SQRT_QAM_M);
    uint8_t q_idx = byte & (SQRT_QAM_M - 1);

    int8_t i_level = (2 * i_idx - (SQRT_QAM_M - 1));
    int8_t q_level = (2 * q_idx - (SQRT_QAM_M - 1));

    iq->i = i_level * IQ_AMPLITUDE;
    iq->q = q_level * IQ_AMPLITUDE;

    return iq;
}

/**
 * @brief Free encoded IQ samples
 * @param samples The encoded IQ samples to free
 */
void free_encoded_samples(iq_t **samples)
{
    if (samples == NULL)
        return;

    for (size_t i = 0; samples[i] != NULL; i++)
    {
        free(samples[i]);
    }

    free(samples);
}

/**
 * @brief Encode a string to IQ samples
 * (byte array to iq_t array)
 * @param string The original string to encode
 * @return iq_t** The encoded IQ samples
 */
iq_t **encode_str(char *string)
{
    size_t string_length = strlen(string);
    iq_t **iq_samples = malloc(string_length * sizeof(iq_t *) + 1);

    for (size_t i = 0; i < string_length; i++)
    {
        iq_samples[i] = encode_byte(string[i]);
    }

    iq_samples[string_length] = NULL;

    return iq_samples;
}
