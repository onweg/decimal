#include "../s21_decimal.h"
#define MIN(a, b) ((a) < (b) ? (a) : (b))
void s21_shift_bits_to_left(s21_decimal *value, int shift) {
	if (shift <= 0) return; 
    for (int i = 95; i >= shift; i--) {
		s21_set_bit(value, i, s21_get_bit(*value, i - shift));
	}
	for (int i = MIN(95, shift - 1); i >= 0; i--) {
		s21_set_bit(value, i, 0);
	}
	return;
}


