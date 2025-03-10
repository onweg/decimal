#include "../s21_decimal.h"

int get_sign(const s21_decimal value){
    return get_bit(value, 127);
}

