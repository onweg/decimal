#include "../s21_decimal.h"

// 0 - успешное увеличение масштаба
// 1 - переполнение мантиссы или степень стала больше 28

int scale_increase(s21_decimal *value, int shift) {
	if (shift <= 0) { return 0; }
	if (get_exp(*value) + shift > 28) { return 1; }
	for (int i = 0; i < shift; i++) {
		s21_decimal tmp1 = {0};
		copy(&tmp1, *value);
		s21_decimal tmp2 = {0};
		copy(&tmp2, *value);
		s21_decimal tmp_result = {0};
		copy(&tmp_result, *value);
		
		shift_bits_to_left(&tmp1, 1);
		shift_bits_to_left(&tmp2, 3);
		if (calculating_sum_mantissa(tmp1, tmp2, &tmp_result) == 1) {
			// переполнение
			return 1;
		}
		copy(value, tmp_result);
		set_exp(value, get_exp(*value) + 1);
	}
	return 0;
}

