#include <stdio.h>
#include <stdbool.h>
#include "../maybe.h"

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
		int r = *x / *y;
		return mreturn(&r);
	}
}

/* int -> maybe int */
static maybe safe_inc(void *x_) {
	int *x = (int *) x_;
	int r = *x + 1;
	return mreturn(&r);
}

/* int -> maybe void */
static maybe mprint(void *x_) {
	int *x = (int *) x_;
	printf("%d\n", *x);
	return nothing();
}

void main(void) {
	int n = 100;
	int divisors[LEN] = {4, 2, 0, 10, 5, 0};

	int i;
	for (i = 0; i < LEN; i++) {
		maybe x = safe_div(&n, &divisors[i]);
		x = bind(safe_inc, x);
		bind(mprint, x);
	}

	/* Or with maybe_do */
	for (i = 0; i < LEN; i++) {
		maybe x = safe_div(&n, &divisors[i]);
		maybe_do(x, safe_inc, safe_inc, mprint);
	}
}
