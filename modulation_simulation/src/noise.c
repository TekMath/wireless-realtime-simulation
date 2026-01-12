#include <math.h>
#include <stdlib.h>

#include "noise.h"

static float uniform_random()
{
    return ((float)rand() + 1.0f) / ((float)RAND_MAX + 2.0f);
}

static float gaussian_noise(float sigma)
{
    float u1 = uniform_random();
    float u2 = uniform_random();

    float z0 = sqrtf(-2.0f * logf(u1)) * cosf(2.0f * (float)M_PI * u2);
    return z0 * sigma;
}

static iq_t *iq_add_noise(iq_t *iq, float sigma)
{
    iq_t *new_iq = malloc(sizeof(iq_t));

    if (new_iq == NULL)
    {
        return NULL;
    }

    new_iq->i = iq->i + gaussian_noise(sigma);
    new_iq->q = iq->q + gaussian_noise(sigma);
    return new_iq;
}

/**
 * @brief Add Gaussian noise to an array of IQ samples
 * @param samples The array of IQ samples (terminated by NULL)
 * @param sigma The standard deviation of the Gaussian noise
 */
iq_t **add_noise_to_samples(iq_t **samples, float sigma)
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

    iq_t **noisy_samples = malloc(sizeof(iq_t *) * (length + 1));
    if (noisy_samples == NULL)
    {
        return NULL;
    }

    for (size_t i = 0; samples[i] != NULL; i++)
    {
        noisy_samples[i] = iq_add_noise(samples[i], sigma);
    }

    noisy_samples[length] = NULL;
    return noisy_samples;
}
