#include "../s21_decimal.h"

void scale_equalize(s21_decimal *value1, s21_decimal *value2) {
	int exp1 = get_exp(*value1);
	int exp2 = get_exp(*value2);
	if (exp1 == exp2) { return; }
	if (exp1 > exp2) {
		int flag = 0;
		while (flag == 0 && get_exp(*value2) < 28 && get_exp(*value2) < get_exp(*value1)) {
			flag = scale_increase(value2, 1);
		}
		scale_decrease(value1, get_exp(*value1) - get_exp(*value2));
	} else {
		int flag = 0;
		while (flag == 0 && get_exp(*value1) < 28 && get_exp(*value1) < get_exp(*value2)) {
			flag = scale_increase(value1, 1);
		}
		scale_decrease(value2, get_exp(*value2) - get_exp(*value1));
	}
	return;
}