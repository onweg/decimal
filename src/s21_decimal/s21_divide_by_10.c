#include "../s21_decimal.h"

int s21_divide_by_10(const s21_decimal value, s21_decimal *quotient, int *remainder) {
    *quotient = (s21_decimal){0};
    unsigned long long rem = 0;
    for (int i = 2; i >= 0; i--) {
        unsigned long long current = (rem << 32) | ((unsigned int)value.bits[i]);
        quotient->bits[i] = (int)(current / 10);
        rem = current % 10;
    }
    *remainder = (int)rem;
    return 0;
}