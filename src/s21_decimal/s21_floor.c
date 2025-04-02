#include "../s21_decimal.h"

int s21_floor(s21_decimal value, s21_decimal *result){
    if (result == NULL) {
        return 1;
    }
    int exp = s21_get_exp(value);
    int sign = s21_get_sign(value);
    s21_set_sign(&value, 0);
    if (exp > 0) {
        int rem = 0;
        while (exp > 0) {
            rem = 0;
            s21_divide_by_10(value, &value, &rem);
            exp--;
        }
        if (sign == 1 && rem > 0) {
            s21_decimal one = {1, 0, 0, 0};
            s21_add(value, one, &value);
        }
    }
    s21_set_sign(&value, sign);
    s21_copy(result, value);
    return 0;
}

