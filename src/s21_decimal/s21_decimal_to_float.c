#include <stdint.h>
#include <stdio.h>

#include "../s21_decimal.h"

#define MIN_FLOAT_VALUE 1e-28

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  if (dst == NULL) return 1;

  if (s21_decimal_is_zero(src)) {
    *dst = 0.0f;
    return 0;
  }

  int sign = s21_get_sign(src);
  int exp = s21_get_exp(src);

  // Собираем мантиссу как 64-битное число
  uint64_t high = ((uint64_t)src.bits[2] << 32) | src.bits[1];
  uint32_t low = src.bits[0];

  // Преобразуем в double
  double floatValue = (double)high * 4294967296.0 + (double)low;

  // Применяем десятичный порядок
  while (exp > 0) {
    floatValue /= 10.0;
    exp--;
  }

  // Проверка на слишком малые числа
  if (floatValue < MIN_FLOAT_VALUE) {
    *dst = 0.0f;
    return 1;
  }

  // Применяем знак
  if (sign) {
    floatValue = -floatValue;
  }

  // Округляем до 7 значимых цифр
  char buffer[32];
  snprintf(buffer, sizeof(buffer), "%.7g", floatValue);
  sscanf(buffer, "%f", dst);

  return 0;
}
