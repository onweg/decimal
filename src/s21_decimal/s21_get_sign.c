#include "../s21_decimal.h"

int s21_get_sign(const s21_decimal value) {
  return (value.bits[3] & S21_DEC_SIGN_MASK) != 0;
}
