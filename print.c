#include <stdio_checked.h>
#pragma CHECKED_SCOPE ON

void __print_int_rec(int a, int flag_printed) {
	if (flag_printed && (a == 0)) {
		return;
	}
	if (a == 0) {
		putchar('0');
		return;
	}
	__print_int_rec(a / 10, 1);
	putchar((a % 10) + '0');
	return;
}

void print_int(int a) {
	if (a < 0) {
		putchar('-');
		__print_int_rec(-a, 0);
	} else {
		__print_int_rec(a, 0);
	} 
}