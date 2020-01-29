#include "../maybe.h"

#include <stdio.h>
#include <stdbool.h>

enum {
	LEN = 6
};

/* (int, int) -> maybe int */
static maybe safe_div(void *x_, void *y_) {
	int *x = (int *) x_;
	int *y = (int *) y_;
	if (*y == 0) {
		return nothing();
	} else {
		static int z; z = *x / *y;
		return mreturn(&z);
	}
}

/* int -> maybe int */
static maybe safe_inc(void *x_) {
	int *x = (int *) x_;
	static int y; y = *x + 1;
	return mreturn(&y);
}

/* int -> maybe void */
static maybe mprint(void *x_) {
	int *x = (int *) x_;
	printf("%d\n", *x);
	return nothing();
}

void main(void) {
	static int n = 100;
	static int divisors[LEN] = {4, 2, 0, 10, 5, 0};

	int i;
	for (i = 0; i < LEN; i++) {
		maybe x = safe_div(&n, &divisors[i]);
		x = bind(safe_inc, x);
		x = bind(safe_inc, x);
		bind(mprint, x);
	}

	printf("\n");

	/* Or with maybe_do_with */
	for (i = 0; i < LEN; i++) {
		maybe x = safe_div(&n, &divisors[i]);
		maybe_do_with(x, safe_inc, safe_inc, mprint);
	}
}
