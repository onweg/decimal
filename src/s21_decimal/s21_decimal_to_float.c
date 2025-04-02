#include <stdint.h>
#include <stdio.h>

#include "../s21_decimal.h"

#define MIN_FLOAT_VALUE 1e-28

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  if (dst == NULL) return 1;
  if (s21_decimal_is_zero(src)) {
    *dst = 0.0f;
    return 0;
  }
  int sign = s21_get_sign(src);
  int exp = s21_get_exp(src);
  __int128 mantissa = ((__int128)src.bits[2] << 64) |
                      ((__int128)src.bits[1] << 32) | src.bits[0];
  double floatValue = (double)mantissa;
  while (exp > 0) {
    floatValue /= 10.0;
    exp--;
  }
  if (floatValue < MIN_FLOAT_VALUE) {
    *dst = 0.0f;
    return 1;
  }
  if (sign) {
    floatValue = -floatValue;
  }
  char buffer[32];
  snprintf(buffer, sizeof(buffer), "%.7g", floatValue);
  sscanf(buffer, "%f", dst);
  return 0;
}
