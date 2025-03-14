#include "../s21_decimal.h"

int scale_decrease(s21_decimal *value, int shift) {
    if (shift <= 0) { 
        return 0;
    }
    for (int s = 0; s < shift; s++) {
        unsigned long long remainder = 0;
        for (int i = 2; i >= 0; i--) {
            unsigned long long current = (remainder << 32) | ((unsigned int)value->bits[i]);
            value->bits[i] = (int)(current / 10);
            remainder = current % 10;
        }
        set_exp(value, get_exp(*value) - 1);
    }
    return 0;
}
