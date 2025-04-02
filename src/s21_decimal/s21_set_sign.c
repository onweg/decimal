#include "../s21_decimal.h"

void s21_set_sign(s21_decimal *value, int sign) {
  if (sign == 0) {
    value->bits[3] &= ~(1 << S21_DEC_SIGN_SHIFT);
  } else if (sign == 1) {
    value->bits[3] |= (1 << S21_DEC_SIGN_SHIFT);
  }
  return;
}
