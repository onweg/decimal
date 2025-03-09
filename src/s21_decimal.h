#pragma once

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>

typedef struct s21_decimal{
    uint32_t bits[4];
} s21_decimal;

#define S21_DEC_SIGN_MASK       0b10000000000000000000000000000000
#define S21_DEC_EXP_MASK        0b00000000111111110000000000000000
#define S21_DEC_EXP_SHIFT       16                  

#define S21_DEC_INF             ((s21_decimal){{0, 0, 0, 0}})                               // TODO
#define S21_DEC_NINF            0x80000000                                                  // TODO
#define S21_DEC_NAN             0x80000000                                                  // TODO
#define S21_DEC_MAX             ((s21_decimal){{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}})    // 2^96 - 1
#define S21_DEC_MIN             ((s21_decimal){{1, 0, 0, 28 << S21_DEC_EXP_SHIFT}})         // 1 / 10^28


typedef enum S21_STATUS {
    S21_STATUS_SUCCESS =     0,
    S21_STATUS_INF =         1,
    S21_STATUS_NINF =        2,
    S21_STATUS_ZERO_DEV =    3,

    S21_STATUS_CONV_ERR =    1,
    S21_STATUS_CALC_ERR =    1

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

void s21_dec_print(s21_decimal value);
void set_bit(s21_decimal value, int bit);
void get_bit(s21_decimal value, int bit);




