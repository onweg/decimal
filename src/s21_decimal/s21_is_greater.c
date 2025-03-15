#include "../s21_decimal.h"

// 0 - false
// 1 - true

int s21_is_greater(s21_decimal value_1, s21_decimal value_2) {
	if (s21_decimal_is_zero(value_1) && s21_decimal_is_zero(value_2)) {
		return 0;
	}
	int sign1 = s21_get_sign(value_1);
    int sign2 = s21_get_sign(value_2);
	if (sign1 != sign2)
        return (sign1 == 0) ? 1 : 0;
	s21_normalize_decimal(&value_1);
	s21_normalize_decimal(&value_2);
	s21_scale_equalize(&value_1, &value_2);
	if (value_1.bits[2] != value_2.bits[2]) return (sign1 == 0) ? ((unsigned int)value_1.bits[2] > (unsigned int)value_2.bits[2]) : ((unsigned int)value_1.bits[2] < (unsigned int)value_2.bits[2]);
    if (value_1.bits[1] != value_2.bits[1]) return (sign1 == 0) ? ((unsigned int)value_1.bits[1] > (unsigned int)value_2.bits[1]) : ((unsigned int)value_1.bits[1] < (unsigned int)value_2.bits[1]);
    if (value_1.bits[0] != value_2.bits[0]) return (sign1 == 0) ? ((unsigned int)value_1.bits[0] > (unsigned int)value_2.bits[0]) : ((unsigned int)value_1.bits[0] < (unsigned int)value_2.bits[0]);
    
	return 0;
}