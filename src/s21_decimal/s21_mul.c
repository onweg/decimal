#include "../s21_decimal.h"

// чтобы сделать функцию умножения надо:

// 1. сделать нормализацию двух decimal
//
// 2. умножить две мантиссы
//
// 3. поставить соответствующую степень и знак 
//
// 3. Нормализация результата


// переполнение я буду учитывать во время сложения 


// 0 — OK;
// 1 — число слишком велико или равно бесконечности;
// 2 — число слишком мало или равно отрицательной бесконечности;

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result){
    int sign_result = s21_get_sign(value_1) == s21_get_sign(value_2) ? 0 : 1;
    s21_normalize_decimal(&value_1);
    s21_normalize_decimal(&value_2);
    int exp_result = s21_get_exp(value_1) + s21_get_exp(value_2);
    s21_set_exp(&value_1, exp_result);
    s21_set_exp(&value_2, 0);
    s21_decimal tmp_result = {0};
    for (int i = 0; i < 96; i++) {
        if (s21_get_bit(value_2, i) == 1) {
            s21_decimal shift_value_1 = {0};
            s21_copy(&shift_value_1, value_1);
            int shift = i;
            while (s21_get_bit(shift_value_1, 95) != 1 && shift) {
                shift--;
                s21_shift_bits_to_left(&shift_value_1, 1);
            }
            while (shift) {
                if (s21_get_exp(shift_value_1) == 0) {
                    return sign_result == 0 ? 1 : 2;
                }
                s21_scale_decrease(&shift_value_1, 1);
                shift--;
            }
            while (s21_get_exp(shift_value_1) > 28) {
                s21_scale_decrease(&shift_value_1, 1);
            }
            int status = s21_add(tmp_result, shift_value_1, &tmp_result);
            if (status != 0) {
                return sign_result == 0 ? 1 : 2;   
            }
        }
    }
    s21_set_sign(&tmp_result, sign_result);
    while (exp_result > 28) {
        s21_scale_decrease(&tmp_result, 1);
        exp_result--;
    }
    s21_copy(result, tmp_result);
    return 0;
}