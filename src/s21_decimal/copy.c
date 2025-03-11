#include "../s21_decimal.h"

void copy(s21_decimal *value, const s21_decimal src) {
	for (int i = 0; i < 4; i++) {
		value->bits[i] = src.bits[i];
	}
	return;
}