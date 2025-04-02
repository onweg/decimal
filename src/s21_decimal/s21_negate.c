#include "../s21_decimal.h"

int s21_negate(s21_decimal value, s21_decimal *result){
    if (result == NULL) {
        return 1;
    }
    s21_copy(result, value);
    s21_set_sign(result, !s21_get_sign(value));
    return 0;
}

