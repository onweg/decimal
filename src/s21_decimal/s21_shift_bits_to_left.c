#include "../s21_decimal.h"

void s21_shift_bits_to_left(s21_decimal *value, int shift) {
	if (shift <= 0) return; 
	if (shift > 95) {
		value->bits[0] = 0;
		value->bits[1] = 0;
		value->bits[2] = 0;
		return;
	}
    for (int i = 95; i >= shift; i--) {
		s21_set_bit(value, i, s21_get_bit(*value, i - shift));
	}
	for (int i = shift - 1; i >= 0; i--) {
		s21_set_bit(value, i, 0);
	}
	return;
}


