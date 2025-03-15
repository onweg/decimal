#include "../s21_decimal.h"

void s21_normalize_decimal(s21_decimal *value) {
	while (get_exp(*value) != 0) {
		s21_decimal tmp = *value;
		s21_scale_decrease(&tmp, 1);
		s21_scale_increase(&tmp, 1);
		if (tmp.bits[0] == value->bits[0] && tmp.bits[1] == value->bits[1] && tmp.bits[2] == value->bits[2] && tmp.bits[3] == value->bits[3]) {
			s21_scale_decrease(value, 1);
		} else {
			return;
		}
	}
	return;

}