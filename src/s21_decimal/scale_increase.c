#include "../s21_decimal.h"

void scale_increase(s21_decimal *value, int shift) {
	if (shift <= 0) { return; }
	set_exp(value, get_exp(*value) + shift);
	for (int i = 0; i < shift; i++) {
		s21_decimal tmp1 = {0};
		copy(&tmp1, *value);
		s21_decimal tmp2 = {0};
		copy(&tmp2, *value);
		
		shift_bits_to_left(&tmp1, 1);
		shift_bits_to_left(&tmp2, 3);
		s21_add(tmp1, tmp2, value);
	}
	return;
}

