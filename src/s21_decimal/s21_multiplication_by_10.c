#include "../s21_decimal.h"

int s21_multiplication_by_10(s21_decimal value, s21_decimal *result) {
  s21_decimal tmp1 = {0};
  s21_copy(&tmp1, value);
  s21_decimal tmp2 = {0};
  s21_copy(&tmp2, value);
  s21_shift_bits_to_left(&tmp1, 1);
  s21_shift_bits_to_left(&tmp2, 3);
  return s21_add(tmp1, tmp2, result);
}
