#include <stdio.h>
#include <stdbool.h>
#include "../maybe.h"

#define TEST 1
/* #define TEST 2 */
/* #define TEST 3 */
/* #define TEST 4 */

/* #define PRINTALL */

/* int -> maybe int */
static maybe mprint(void *x_) {
	int *x = (int *) x_;
	printf("%d\n", *x);
	return mreturn(x);
}

/* void -> maybe int */
static maybe try_thing1(void *x_) {
	int x = 1;

	int success = true;
#	if TEST == 4
	success = false;
#	endif
	
	if (success) {
		return mreturn(&x);
	} else {
		return nothing();
	}
}

/* int -> maybe int */
static maybe try_thing2(void *x_) {
	int *x = (int *) x_;
	int r = (*x * 10) + 2;

	int success = true;
#	if TEST == 3
	success = false;
#	endif

	if (success) {
		return mreturn(&r);
	} else {
		return nothing();
	}
}

/* int -> maybe int */
static maybe try_thing3(void *x_) {
	int *x = (int *) x_;
	int r = (*x * 10) + 3;

	int success = true;
#	if TEST == 2
	success = false;
#	endif

	if (success) {
		return mreturn(&r);
	} else {
		return nothing();
	}
}

void main(void) {
#	ifdef PRINTALL
	
	maybe_do
		(mstart,
		 try_thing1,
		 mprint,
		 try_thing2,
		 mprint,
		 try_thing3,
		 mprint);
	
#	else
	
	maybe_do
		(mstart,
		 try_thing1,
		 try_thing2,
		 try_thing3,
		 mprint);
	
#	endif
}
