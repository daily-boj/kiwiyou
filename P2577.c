#include <stdio.h>

int main() {
	int a, b, c;
	int multiple;
	int count_of_digit[10] = {};
	scanf("%d%d%d", &a, &b, &c);
	multiple = a * b * c;
	do {
		++count_of_digit[multiple % 10];
		multiple /= 10;
	} while (multiple);
	for (int digit = 0; digit <= 9; ++digit) {
		printf("%d\n", count_of_digit[digit]);
	}
}
