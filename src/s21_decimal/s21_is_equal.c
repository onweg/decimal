#include "../s21_decimal.h"

int s21_is_equal(s21_decimal value_1, s21_decimal value_2) {
	s21_normalize_decimal(&value_1);
	s21_normalize_decimal(&value_2);
	// если оба нули
	// если разные знаки то false
	// если одинаковые знаки, то идем проверять все bits
	if (value_1.bits[0] == 0 && value_1.bits)
}