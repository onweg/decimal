#include "../s21_decimal.h"

// чтобы сделать функцию вычитания надо:

// 1. сделать нормализацию двух decimal
// 2. привести к общему знаменателю
//      1. сделать функию по выравниванию мантиссы в которой мы будем уметь:
//          1. увеличивать масштаб числа с меньшей степенью до тех пор, пока эта
//          степень позволяет или до тех пор, пока мантисса не переполненистя
//              1. сделать функцию по увеличению масштаба с обработкой ошибок и
//              переполнений
//          2. уменьшать масштаб числа с большей степенью, до числа с меньшей
//          степенью
//              1. сделать функцию по уменьшению масштаба
//
// 3. сложить две мантиссы (или вычесть из одной мантиссы другую)
//      1. сделать условие, которая бы в зависимости от знаком могла делать
//      следующее:
//          1. если знаки одинаковые, то складываем две мантисы
//          2. если знаки разные, сохраняем знак большего из чисел и вычитаем их
//          большей мантиссы меньшуую мантиссу
// 4. Нормализация результата
//      1. реализовать функцию, которая будет уменьшать масштаб и убирать
//      незначащие нули в цонцу, например 123000 / 10^2 превратить в 1234 / 10^0

// 0 — OK;
// 1 — число слишком велико или равно бесконечности;
// 2 — число слишком мало или равно отрицательной бесконечности;

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  s21_normalize_decimal(&value_1);
  s21_normalize_decimal(&value_2);
  s21_scale_equalize_with_bank_rounding_for_add_and_sub(&value_1, &value_2);
  s21_decimal tmp_result = {0};
  s21_set_exp(&tmp_result, s21_get_exp(value_1));
  enum S21_STATUS status = 0;
  int sign1 = s21_get_sign(value_1);
  int sign2 = s21_get_sign(value_2);
  if (sign1 != sign2) {
    s21_set_sign(&tmp_result, s21_get_sign(value_1));
    status = s21_calculating_sum_mantissa(value_1, value_2, &tmp_result);
    if (status != 0) {
      if (sign1 == 1) {
        status = S21_STATUS_NINF;
      }
    }
  } else {
    if (((unsigned int)value_1.bits[2] > (unsigned int)value_2.bits[2]) ||
        (((unsigned int)value_1.bits[2] == (unsigned int)value_2.bits[2]) &&
         ((unsigned int)value_1.bits[1] > (unsigned int)value_2.bits[1])) ||
        (((unsigned int)value_1.bits[2] == (unsigned int)value_2.bits[2]) &&
         ((unsigned int)value_1.bits[1] == (unsigned int)value_2.bits[1]) &&
         ((unsigned int)value_1.bits[0] > (unsigned int)value_2.bits[0]))) {
      s21_set_sign(&tmp_result, sign1);
      s21_calculating_sub_mantissa(value_1, value_2, &tmp_result);
    } else {
      s21_set_sign(&tmp_result, !sign1);
      s21_calculating_sub_mantissa(value_2, value_1, &tmp_result);
    }
  }
  if (status == 0) {
    s21_copy(result, tmp_result);
    s21_normalize_decimal(result);
  }
  return status;
}
