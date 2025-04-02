#include "../s21_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  if (dst == NULL) {
    return 1;
  }
  int sign_result = 0;
  if (src < 0) {
    sign_result = 1;
    src = -src;
  }
  dst->bits[0] = src;
  dst->bits[1] = 0;
  dst->bits[2] = 0;
  dst->bits[3] = 0;
  s21_set_sign(dst, sign_result);
  return 0;
}
