#pragma once

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>

typedef struct s21_decimal{
    int bits[4];
} s21_decimal;

#define S21_DEC_SIGN_MASK       0b10000000000000000000000000000000
#define S21_DEC_SIGN_SHIFT      31
#define S21_DEC_EXP_MASK        0b00000000111111110000000000000000
#define S21_DEC_EXP_SHIFT       16
#define S21_DEC_SCALE_MAX       28      

#define S21_DEC_MAX             ((s21_decimal){{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}})                   // 2^96 - 1
#define S21_DEC_MIN             ((s21_decimal){{1, 0, 0, S21_DEC_SCALE_MAX << S21_DEC_EXP_SHIFT}})         // 1 / 10^28


typedef enum S21_STATUS {
    S21_STATUS_SUCCESS =     0,
    S21_STATUS_INF =         1,
    S21_STATUS_NINF =        2,
    S21_STATUS_ZERO_DEV =    3,

    // S21_STATUS_CONV_ERR =    1,
    // S21_STATUS_CALC_ERR =    1

} S21_STATUS;


int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

int s21_is_less(s21_decimal val_1, s21_decimal val_2);
int s21_is_less_or_equal(s21_decimal val_1, s21_decimal val_2);
int s21_is_greater(s21_decimal val_1, s21_decimal val_2);
int s21_is_greater_or_equal(s21_decimal val_1, s21_decimal val_2);
int s21_is_equal(s21_decimal val_1, s21_decimal val_2);
int s21_is_not_equal(s21_decimal val_1, s21_decimal val_2);

int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);

int s21_floor(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);

void s21_print_decimal(const s21_decimal value);
void s21_set_bit(s21_decimal *value, int i, int bit);
void s21_set_sign(s21_decimal *value, int sign);
void s21_set_exp(s21_decimal *value, int exp);
int s21_get_bit(const s21_decimal value, int i);
int s21_get_sign(const s21_decimal value);
int s21_get_exp(const s21_decimal value);
void s21_shift_bits_to_left(s21_decimal *value, int shift);
void s21_shift_bits_to_right(s21_decimal *value, int shift);

// выравнивание масштаба с отбросом битов
void s21_scale_equalize_with_bit_drop(s21_decimal *value1, s21_decimal *value2);
// выравнивание масштаба с математическим округлением
void s21_scale_equalize_with_mathematical_rounding(s21_decimal *value1, s21_decimal *value2);
// выравнивание масштаба с банковским округлением
void s21_scale_equalize_with_bank_rounding(s21_decimal *value1, s21_decimal *value2);
// выравнивание масштаба с банковским округлением для вычитания и суммы
void s21_scale_equalize_with_bank_rounding_for_add_and_sub(s21_decimal *value1, s21_decimal *value2);
// выравнивание масштаба с округлением вверх
void s21_scale_equalize_with_rounding_up(s21_decimal *value1, s21_decimal *value2);

int s21_scale_increase(s21_decimal *value, int shift);
int s21_scale_decrease(s21_decimal *value, int shift);
void s21_copy(s21_decimal *value, const s21_decimal src);
int s21_calculating_sum_mantissa(const s21_decimal value_1, const s21_decimal value_2, s21_decimal *result);
int s21_calculating_sub_mantissa(s21_decimal value_1, const s21_decimal value_2, s21_decimal *result);
void s21_normalize_decimal(s21_decimal *value);
int s21_decimal_is_zero(const s21_decimal value);
int s21_divide_by_10(const s21_decimal value, s21_decimal *quotient, int *remainder);







// сделать нормалайз для 0, чтоб когда подавался -0 или 0/10^exp exp становился 0
// проверить тесты где 123 и 109 на банковское округление (проверить все тесты на чужом проекте и посмотреть у кого что врено)
// поять что делать с банковским округлением с уменьшением масштаба (сделать новую функцию которая уменьшает масштаб с банковским округлением)
// проверить тест все 1 MAX (7,92..335 + 1)
// сделать уменьшение масштаба с банковским округлением
// добавить проверку на NULL чтоб возвращалась ошибка




