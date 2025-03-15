#include "../s21_decimal.h"

void s21_set_bit(s21_decimal *value, int i, int bit){
    int shift, bit_cell;
    if (i >= 0 && i < 96) {
        shift = i % 32;
        bit_cell = i / 32;
        if (bit == 0) {
            value->bits[bit_cell] &= ~(1 << shift);
        } else if (bit == 1) {
            value->bits[bit_cell] |= (1 << shift);
        }
    }
    return;
}

