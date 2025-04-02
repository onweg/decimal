#include "../s21_decimal.h"

// вычисляет только разницу мантисс
// это не функия вычитания, а помогающая функция, следовательно гарантировано
// должно подаваться что value_1 больше или равно value_2

// 0 - успешное вычитание
// 1 - некорректные данные

int s21_calculating_sub_mantissa(s21_decimal value_1, const s21_decimal value_2,
                                 s21_decimal *result) {
  int i = 0;
  while (i < 96) {
    int bit1 = s21_get_bit(value_1, i);
    int bit2 = s21_get_bit(value_2, i);
    if (bit1 < bit2) {
      int j = i + 1;
      while (j < 96 && s21_get_bit(value_1, j) == 0) {
        j++;
      }
      if (j == 96) {
        return 1;
      }
      s21_set_bit(&value_1, j, 0);
      j--;
      while (j > i) {
        s21_set_bit(&value_1, j, 1);
        j--;
      }
      bit1 = 2;
    }
    s21_set_bit(result, i, bit1 - bit2);
    i++;
  }
  return 0;
}
