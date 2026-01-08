#include <math.h>
#include <stdlib.h>

#include "noise.h"

static float uniform_random() {
    return ((float)rand() + 1.0f) / ((float)RAND_MAX + 2.0f);
}

static float gaussian_noise(float sigma) {
    float u1 = uniform_random();
    float u2 = uniform_random();

    float z0 = sqrtf(-2.0f * logf(u1)) * cosf(2.0f * (float)M_PI * u2);
    return z0 * sigma;
}

static void iq_add_noise(iq_t *iq, float sigma) {
    iq->i += gaussian_noise(sigma);
    iq->q += gaussian_noise(sigma);
}

/**
 * @brief Add Gaussian noise to an array of IQ samples
 * @param samples The array of IQ samples (terminated by NULL)
 * @param sigma The standard deviation of the Gaussian noise
 */
void add_noise_to_samples(iq_t **samples, float sigma) {
    if (samples == NULL)
        return;

    for (size_t i = 0; samples[i] != NULL; i++) {
        iq_add_noise(samples[i], sigma);
    }
}
