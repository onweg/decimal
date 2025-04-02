#include "../s21_decimal.h"

void s21_print_decimal(const s21_decimal value) {
  for (int i = 127; i >= 0; i--) {
    if (i == 95 || i == 63 || i == 31) printf(" ");
    printf("%d", s21_get_bit(value, i));
  }
}
