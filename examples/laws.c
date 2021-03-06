#include "../maybe.h"

#include <stdio.h>
#include <stdbool.h>

/* int -> maybe int */
static maybe f(void *x_) {
	int *x = (int *) x_;
	static int y; y = *x + 10;
	mreturn(&y);
}

/* int -> maybe int */
static maybe f_(void *x_) {
	int *x = (int *) x_;
	static int y; y = *x + 10;
	mreturn(&y);
}

/* int -> maybe int */
static maybe g(void *x_) {
	int *x = (int *) x_;
	static int y; y = *x + 20;
	mreturn(&y);
}

/* int -> maybe int */
static maybe g_f(void *x_) {
	int *x = (int *) x_;
	return bind(g, f(x));
}

static bool eq(maybe x, maybe y) {
	if (is_nothing(x) && is_nothing(y)) {
		return true;
	} else {
		int xjust = *(int *) x.just;
		int yjust = *(int *) y.just;
		return (xjust == yjust);
	}
}

void main(void) {
	maybe ls;
	maybe rs;
	static int x = 3;
	maybe m1 = { .nothing = false, .just = &x };
	maybe m2 = { .nothing = true };
	
	/* Left identity */
	/* return x >>= f   =   f x */
	ls = bind(f, mreturn(&x));
	rs = f_(&x);
	if (eq(ls, rs)) {
		printf("Left identity check passed\n");
	} else {
		printf("x Left identity check failed\n");
	}

	/* Right identity */
	/* m >>= return   =   m */
	ls = bind(mreturn, m1);
	rs = m1;
	if (eq(ls, rs)) {
		printf("Right identity check passed with Just\n");
	} else {
		printf("x Right identity check failed with Just\n");
	}
	
	ls = bind(mreturn, m2);
	rs = m2;
	if (eq(ls, rs)) {
		printf("Right identity check passed with Nothing\n");
	} else {
		printf("x Right identity check failed with Nothing\n");
	}

	/* Associativity */
	/* (m >>= f) >>= g   =   m >>= (\x -> f x >>= g) */
	ls = bind(g, bind(f_, m1));
	rs = bind(g_f, m1);
	if (eq(ls, rs)) {
		printf("Associativity check passed with Just\n");
	} else {
		printf("x Associativity check failed with Just\n");
	}

	ls = bind(g, bind(f_, m2));
	rs = bind(g_f, m2);
	if (eq(ls, rs)) {
		printf("Associativity check passed with Nothing\n");
	} else {
		printf("x Associativity check failed with Nothing\n");
	}
}
