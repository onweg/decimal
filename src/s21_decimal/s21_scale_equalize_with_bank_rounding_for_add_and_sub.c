#include "../s21_decimal.h"

int s21_divide_by_10(const s21_decimal *value, s21_decimal *quotient, int *remainder);

void s21_scale_equalize_with_bank_rounding_for_add_and_sub(s21_decimal *value1, s21_decimal *value2) {
	int exp1 = s21_get_exp(*value1);
	int exp2 = s21_get_exp(*value2);
	if (exp1 == exp2) { return; }
	if (exp1 > exp2) {
		int flag = 0;
		while (flag == 0 && s21_get_exp(*value2) < 28 && s21_get_exp(*value2) < s21_get_exp(*value1)) {
			flag = s21_scale_increase(value2, 1);
		}
		if (s21_get_exp(*value1) > s21_get_exp(*value2)) {
			s21_scale_decrease(value1, s21_get_exp(*value1) - s21_get_exp(*value2) - 1);
			int num1 = 0;
			s21_decimal tmp = {0};
			s21_divide_by_10(value1, &tmp, &num1);
			s21_scale_decrease(value1, 1);
			int num2 = 0;
			s21_divide_by_10(value1, &tmp, &num2);
			if (num1 > 5 || num1 == 5 && num2 % 2 == 0){
				s21_decimal one = {1, 0, 0, 0};
				s21_set_sign(&one, s21_get_sign(*value1));
				s21_add(*value1, one, value1);
			}
		}
		
	} else {
		int flag = 0;
		while (flag == 0 && s21_get_exp(*value1) < 28 && s21_get_exp(*value1) < s21_get_exp(*value2)) {
			flag = s21_scale_increase(value1, 1);
		}
		if (s21_get_exp(*value1) < s21_get_exp(*value2)) {
			s21_scale_decrease(value2, s21_get_exp(*value2) - s21_get_exp(*value1) - 1);
			int num1 = 0;
			s21_decimal tmp = {0};
			s21_divide_by_10(value2, &tmp, &num1);
			s21_scale_decrease(value2, 1);
			int num2 = 0;
			s21_divide_by_10(value2, &tmp, &num2);

			if (num1 > 5 || num1 == 5 && num2 % 2 == 0){
				s21_decimal one = {1, 0, 0, 0};
				s21_set_sign(&one, s21_get_sign(*value2));
				s21_add(*value2, one, value2);
			}
			
		}
		
	}
	return;
}


int s21_divide_by_10(const s21_decimal *value, s21_decimal *quotient, int *remainder) {
    *quotient = (s21_decimal){0};
    unsigned long long rem = 0;
    for (int i = 2; i >= 0; i--) {
        unsigned long long current = (rem << 32) | ((unsigned int)value->bits[i]);
        quotient->bits[i] = (int)(current / 10);
        rem = current % 10;
    }
    *remainder = (int)rem;
    return 0;
}
