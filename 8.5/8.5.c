#include <stdio.h>

typedef struct {
	double real;
	double imaginary;
} complex_t;

void test(double v1_real, double v1_imag, double v2_real, double v2_img);
complex_t complex_add(complex_t v1, complex_t v2);
complex_t complex_mpy(complex_t v1, complex_t v2);

int main() {
	test(1.0, 1.0, 3.0, 3.0);
}

void test(double v1_real, double v1_imag, double v2_real, double v2_img) {
	complex_t vector1, vector2, sum, product;
	vector1.real = v1_real;
	vector1.imaginary = v1_imag;
	vector2.real = v2_real;
	vector2.imaginary = v2_img;
	
	sum = complex_add(vector1, vector2);
	product = complex_mpy(vector1, vector2);
	
	printf("sum of two complex number = %lf + %lfi\n", sum.real, sum.imaginary);
	printf("product of two complex number = %lf + %lfi\n", product.real, product.imaginary);
}

complex_t complex_add(complex_t v1, complex_t v2) {
	complex_t sum;
	sum.real = v1.real + v2.real;
	sum.imaginary = v1.imaginary + v2.imaginary;
	return sum;
}

complex_t complex_mpy(complex_t v1, complex_t v2) {
	complex_t mult;
	mult.real = v1.real * v2.real - v1.imaginary * v2.imaginary;
	mult.imaginary = v1.real * v2.imaginary + v2.real * v1.imaginary;
	return mult;
}

