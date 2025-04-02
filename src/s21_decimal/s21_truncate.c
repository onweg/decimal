#include "../s21_decimal.h"

int s21_truncate(s21_decimal value, s21_decimal *result) {
  if (result == NULL) {
    return 1;
  }
  int exp = s21_get_exp(value);
  while (exp > 0) {
    s21_scale_decrease(&value, 1);
    exp--;
  }
  s21_copy(result, value);
  return 0;
}
