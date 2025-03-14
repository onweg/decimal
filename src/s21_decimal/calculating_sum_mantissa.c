#include "../s21_decimal.h"

// 0 - успешное завершение
// 1 - переполнение

int calculating_sum_mantissa(const s21_decimal value_1, const s21_decimal value_2, s21_decimal *result) {
	int index = 0, remains = 0;
	while (index < 96) {
		int sum = get_bit(value_1, index) + get_bit(value_2, index) + remains;
		set_bit(result, index, sum%2);
		remains = sum / 2;
		index++;
	}
	if (remains) { return 1; }
	return 0;
}