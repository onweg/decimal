#include "../s21_decimal.h"

// 0 - успешное увеличение масштаба
// 1 - переполнение мантиссы или степень стала больше 28

int s21_scale_increase(s21_decimal *value, int shift) {
	if (shift <= 0) { return 0; }
	if (s21_get_exp(*value) + shift > 28) { return 1; }
	for (int i = 0; i < shift; i++) {
		s21_decimal tmp1 = *value;
		s21_decimal tmp2 = *value;
		s21_decimal tmp_result = *value;
		
		s21_shift_bits_to_left(&tmp1, 1);
		s21_shift_bits_to_left(&tmp2, 3);

		if (s21_calculating_sum_mantissa(tmp1, tmp2, &tmp_result) == 1) {
			// переполнение
			return 1;
		}
		
		value->bits[0] = tmp_result.bits[0];
		value->bits[1] = tmp_result.bits[1];
		value->bits[2] = tmp_result.bits[2];
		s21_set_exp(value, s21_get_exp(*value) + 1);
	}
	return 0;
}

