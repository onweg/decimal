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

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result){
    // if (s21_is_zero(value_2)) return 4;
    // s21_normalize_decimal(&value_1);
    // s21_normalize_decimal(&value_2);
    // int sign_result = s21_get_sign(value_1) == s21_get_sign(value_2) ? 0 : 1;
    // s21_set_sign(&value_1, 0);
    // s21_set_sign(&value_2, 0);
    // int exp_result = s21_get_exp(value_1) - s21_get_exp(value_2);

    // s21_decimal tmp_value_1 = {0};
    // s21_copy(&tmp_value_2, value_2);
    // while (s21_is_greater(tmp_value_1, tmp_value_2)) {
    //     int i = 0;
    //     while (s21_is_greater(tmp_value_1, tmp_value_2)) {
    //         if (s21_get _bit(value_2, 95) == 0) {
    //             s21_shift_bits_to_left(&tmp_value_2, 1);
    //             i++;
    //         } else {
    //             break;
    //         }
    //     }
    //     s21_shift_bits_to_right(&tmp_value_2, 1);
    //     i--;
    //     s21_sub(tmp_value_1, tmp_value_2, &tmp_value_1);
    //     s21_decimal r = {1, 0, 0, 0};
    //     s21_shift_bits_to_left(&r, i);
    //     s21_add(tmp_result, r, &tmp_result);
    // }

    // // теперь работа с остатком 
    // // начинается рекурсия

    // s21_decimal remain = {0};
    // s21_copy(&remain, tmp_value_1);

    // if (s21_is_zero(remain)) {
    //     return 0;
    // }
    // // выход из рекурсии if (остаток 0 то возвращаю ту остаток )
    // // вход в s21_div()

    // if (exp_result < 0) {
    //     то еще домножить на 10, сначала степень exp уменьшить, а только потом умножать 
    // } 

    // return 0;
}

// s21_decimal getting_fractional(s21_decimal value_1, s21_decimal value_2) {
//     if (s21_is_zero(value_2)) return {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF};


//     s21_decimal tmp_value_1 = {0};
//     s21_copy(&tmp_value_2, value_2);
//     while (s21_is_greater(tmp_value_1, tmp_value_2)) {
//         int i = 0;
//         while (s21_is_greater(tmp_value_1, tmp_value_2)) {
//             if (s21_get _bit(value_2, 95) == 0) {
//                 s21_shift_bits_to_left(&tmp_value_2, 1);
//                 i++;
//             } else {
//                 break;
//             }
//         }
//         s21_shift_bits_to_right(&tmp_value_2, 1);
//         i--;
//         s21_sub(tmp_value_1, tmp_value_2, &tmp_value_1);
//         s21_decimal r = {1, 0, 0, 0};
//         s21_shift_bits_to_left(&r, i);
//         s21_add(tmp_result, r, &tmp_result);
//     }

//     // теперь работа с остатком 
//     // начинается рекурсия

//     s21_decimal remain = {0};
//     s21_copy(&remain, tmp_value_1);

//     if (s21_is_zero(remain)) {
//         return 0;
//     }
//     // выход из рекурсии if (остаток 0 то возвращаю ту остаток )
//     // вход в s21_div()

//     if (exp_result < 0) {
//         то еще домножить на 10, сначала степень exp уменьшить, а только потом умножать 
//     } 

//     return 0;
// }