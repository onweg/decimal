#include "../s21_decimal.h"

// чтобы сделать функцию деления надо:
// 1. проверить на ноль
//
// 2. сделать нормализацию двух decimal
//
// 3. убрать лишнюю стпенеь сократить одну на вторую
//
// 4. поделить мантиссу на мантиссу
//
// 5. 
//
// 6. Нормализация результата


// переполнение я буду учитывать во время сложения 


// 0 — OK;
// 1 — число слишком велико или равно бесконечности;
// 2 — число слишком мало или равно отрицательной бесконечности;
// 3 - деление на ноль

s21_decimal s21_div_with_remainder(s21_decimal value_1, s21_decimal value_2, s21_decimal *remainder);

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result){
    if (s21_decimal_is_zero(value_2)) return 3;
    s21_normalize_decimal(&value_1);
    s21_normalize_decimal(&value_2);
    int sign_result = s21_get_sign(value_1) == s21_get_sign(value_2) ? 0 : 1;
    s21_set_sign(&value_1, 0);
    s21_set_sign(&value_2, 0);
    int exp_result = s21_get_exp(value_1) - s21_get_exp(value_2);
    s21_decimal tmp_result = {0};
    s21_decimal remainder = {0};
    s21_copy(&tmp_result, s21_div_with_remainder(value_1, value_2, &remainder));
    s21_decimal quotient = {0};
    while (exp_result < 28 && !s21_decimal_is_zero(remainder)) {
        s21_decimal ten = {10, 0, 0, 0};
        if (s21_mul(remainder, ten, &remainder) == 1) {

        }
        s21_copy(&quotient, s21_div_with_remainder(remainder, value_2, &remainder));
        s21_mul(tmp_result, ten, &tmp_result);
        s21_add(tmp_result, quotient, &tmp_result);
        exp_result++;
    }

    while (exp_result < 0) {
        if (s21_multiplication_by_10(tmp_result, &tmp_result) == 1) {
            return sign_result == 0 ? 1 : 2;
        }
        exp_result++;
    } 
    s21_set_exp(&tmp_result, exp_result);
    s21_set_sign(&tmp_result, sign_result);
    s21_normalize_decimal(&tmp_result);
    s21_copy(result, tmp_result);

    return 0;
}

s21_decimal s21_div_with_remainder(s21_decimal value_1, s21_decimal value_2, s21_decimal *remainder) {
    s21_set_exp(&value_1, 0);
    s21_set_exp(&value_2, 0);
    s21_set_sign(&value_1, 0);
    s21_set_sign(&value_1, 0);
    s21_decimal tmp_result = {0};
    while (s21_is_greater_or_equal(value_1, value_2)) {
        int i = 0;
        int flag = 0;
        s21_decimal tmp_value_2 = {0};
        s21_copy(&tmp_value_2, value_2);
        while (s21_is_greater_or_equal(value_1, tmp_value_2)) {
            if (s21_get_bit(tmp_value_2, 95) == 0) {
                s21_shift_bits_to_left(&tmp_value_2, 1);
                i++;
            } else {
                flag = 1;
                break;
            }
        }
        if (!flag) {
            s21_shift_bits_to_right(&tmp_value_2, 1);
            i--;
        }
        s21_sub(value_1, tmp_value_2, &value_1);
        s21_decimal r = {1, 0, 0, 0};
        s21_shift_bits_to_left(&r, i);
        s21_add(tmp_result, r, &tmp_result);
    }
    s21_copy(remainder, value_1);
    return tmp_result;
}