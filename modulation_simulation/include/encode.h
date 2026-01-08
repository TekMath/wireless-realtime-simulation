#pragma once

typedef struct {
    float i;
    float q;
} iq_t;

iq_t **encode_str(char *);
