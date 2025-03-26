#include "../s21_decimal.h"

int s21_is_greater_or_equal(s21_decimal val_1, s21_decimal val_2){
    return s21_is_greater(val_1, val_2) || s21_is_equal(val_1, val_2);
}