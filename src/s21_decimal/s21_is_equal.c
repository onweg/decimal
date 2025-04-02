#include "../s21_decimal.h"

// 0 - false
// 1 - true

int s21_is_equal(s21_decimal value_1, s21_decimal value_2) {
  if (s21_decimal_is_zero(value_1) && s21_decimal_is_zero(value_2)) {
    return 1;
  }
  s21_normalize_decimal(&value_1);
  s21_normalize_decimal(&value_2);
  return value_1.bits[3] == value_2.bits[3] &&
         value_1.bits[2] == value_2.bits[2] &&
         value_1.bits[1] == value_2.bits[1] &&
         value_1.bits[0] == value_2.bits[0];
}
