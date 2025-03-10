#include "../s21_decimal.h"

int get_bit(const s21_decimal value, int i){
    int bit = -1;
    if (i >= 0 && i < 32) {
        bit = (value.bits[0] & (1 << i)) != 0;
    } else if (i >= 32 && i < 64) {
        bit = (value.bits[1] & (1 << (i -= 32))) != 0;
    } else if (i >= 64 && i < 96) {
        bit = (value.bits[2] & (1 << (i -= 64))) != 0;
    } else if (i >= 96 && i < 128) {
        bit = (value.bits[3] & (1 << (i -= 96))) != 0;
    }
    return bit;
}

