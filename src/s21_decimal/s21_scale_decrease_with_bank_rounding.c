#include "../s21_decimal.h"

int s21_scale_decrease_with_bank_rounding(s21_decimal *value, int shift) {
    if (shift <= 0) { 
        return 0;
    }
    for (int s = 0; s < shift - 1; s++) {
        unsigned long long remainder = 0;
        for (int i = 2; i >= 0; i--) {
            unsigned long long current = (remainder << 32) | ((unsigned int)value->bits[i]);
            value->bits[i] = (int)(current / 10);
            remainder = current % 10;
        }
        s21_set_exp(value, s21_get_exp(*value) - 1);
    }
	int num1 = 0;
	s21_decimal tmp = {0};
	s21_divide_by_10(*value, &tmp, &num1);
	s21_scale_decrease(value, 1);
	int num2 = 0;
	s21_divide_by_10(*value, &tmp, &num2);
	if (num1 > 5 || num1 == 5 && num2 % 2 == 0){
		s21_decimal one = {1, 0, 0, 0};
		s21_set_sign(&one, s21_get_sign(*value));
		s21_add(*value, one, value);
	}

    return 0;
}
