#include "../s21_decimal.h"

void s21_set_exp(s21_decimal *value, int exp) {
  if (exp >= 0 && exp < 29) {
    for (int i = 16; i < 24; i++, exp /= 2) {
      int bit = exp % 2;
      if (bit == 0) {
        value->bits[3] &= ~(1 << i);
      } else if (bit == 1) {
        value->bits[3] |= (1 << i);
      }
    }
  }
  return;
}
