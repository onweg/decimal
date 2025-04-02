#include "../s21_decimal.h"

int s21_get_exp(const s21_decimal value) {
  return (value.bits[3] & S21_DEC_EXP_MASK) >> S21_DEC_EXP_SHIFT;
}
