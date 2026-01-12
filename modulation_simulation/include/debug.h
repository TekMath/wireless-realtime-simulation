#pragma once

#define NOISE_LEVELS 5

static const float noise_levels[NOISE_LEVELS] = {
    0.01f,
    0.02f,
    0.03f,
    0.05f,
    0.1f
};

void debug_mode(const char *);
