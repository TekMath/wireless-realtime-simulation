#include <math.h>

#define QAM_M 256
#define SQRT_QAM_M (int)sqrt(QAM_M)
#define IQ_AMPLITUDE 1.0f / SQRT_QAM_M

// I want to have amplitude < 1.0 so I don't add -1 to be evrytime lower than 1.0
// For 256-QAM, max level is 15, so max amplitude is 15/16 = 0.9375
