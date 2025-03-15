#include "../s21_decimal.h"

// вычисляет только разницу мантисс
// это не функия вычитания, а помогающая функция, следовательно гарантировано должно подаваться
// что value_1 больше или равно value_2

// 0 - успешное вычитание
// 1 - некорректные данные

int s21_calculating_sub_mantissa(const s21_decimal value_1, const s21_decimal value_2, s21_decimal *result) {
	if (
		(unsigned int)value_1.bits[2] < (unsigned int)value_2.bits[2] || 
		(unsigned int)value_1.bits[2] == (unsigned int)value_2.bits[2] && (unsigned int)value_1.bits[1] < (unsigned int)value_2.bits[1] ||
		(unsigned int)value_1.bits[2] == (unsigned int)value_2.bits[2] && (unsigned int)value_1.bits[1] == (unsigned int)value_2.bits[1] && (unsigned int)value_1.bits[0] < (unsigned int)value_2.bits[0]
	) return 1;
   

	return 0;
}