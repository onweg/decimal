#include "../s21_decimal.h"
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MIN_FLOAT_VALUE 1e-28
#define MAX_FLOAT_VALUE 7.9228162514264337593543950335e28

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
    if (dst == NULL || isnan(src) || isinf(src)) return 1; 
    if (src == 0.0f) {
        dst->bits[0] = 0;
        dst->bits[1] = 0;
        dst->bits[2] = 0;
        dst->bits[3] = 0;
        return 0;
    }
    int sign_result = 0;
    if (src < 0) {  
        sign_result = 1;
        src = -src;
    }
    if (src < MIN_FLOAT_VALUE || src > MAX_FLOAT_VALUE) {
        return 1; 
    }
    char buffer[64];
    snprintf(buffer, sizeof(buffer), "%.7g", src);
    char *dot_position = strchr(buffer, '.');
    if (dot_position != NULL) {
        *dot_position = '\0';
    }
    char intPart[32] = {0};
    strncpy(intPart, buffer, sizeof(intPart) - 1);
    char fracPart[32] = {0};
    if (dot_position != NULL) {
        strncpy(fracPart, dot_position + 1, sizeof(fracPart) - 1);
    }
    int scale = strlen(fracPart);
    char digits[64] = {0};
    strcpy(digits, intPart);
    strcat(digits, fracPart);
    __int128 intValue = 0;
    for (int i = 0; digits[i] != '\0'; i++) {
        intValue = intValue * 10 + (digits[i] - '0');
    }
    if (intValue >= ((__int128)1 << 96)) return 1;
    dst->bits[0] = (uint32_t)(intValue & 0xFFFFFFFF);
    dst->bits[1] = (uint32_t)((intValue >> 32) & 0xFFFFFFFF);
    dst->bits[2] = (uint32_t)((intValue >> 64) & 0xFFFFFFFF);
    s21_set_exp(dst, scale);
    s21_set_sign(dst, sign_result);
    return 0;
}
