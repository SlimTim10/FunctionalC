#include <stdio.h>
#include <stdbool.h>
#include "../maybe.h"

#define TEST 1
/* #define TEST 2 */
/* #define TEST 3 */
/* #define TEST 4 */

/* #define PRINTALL */

static int global_i;

/* int -> maybe int */
static maybe mprint(void *x_) {
	global_i = *(int *) x_;
	printf("%d\n", global_i);
	return mreturn(&global_i);
}

/* void -> maybe int */
static maybe try_thing1(void *x_) {
	global_i = 1;
	
	int success = true;
#	if TEST == 4
	success = false;
#	endif
	
	if (success) {
		return mreturn(&global_i);
	} else {
		return nothing();
	}
}

/* int -> maybe int */
static maybe try_thing2(void *x_) {
	int *x = (int *) x_;
	global_i = (*x * 10) + 2;

	int success = true;
#	if TEST == 3
	success = false;
#	endif

	if (success) {
		return mreturn(&global_i);
	} else {
		return nothing();
	}
}

/* int -> maybe int */
static maybe try_thing3(void *x_) {
	int *x = (int *) x_;
	global_i = (*x * 10) + 3;

	int success = true;
#	if TEST == 2
	success = false;
#	endif

	if (success) {
		return mreturn(&global_i);
	} else {
		return nothing();
	}
}

void main(void) {
#	ifdef PRINTALL
	
	maybe_do
		(try_thing1,
		 mprint,
		 try_thing2,
		 mprint,
		 try_thing3,
		 mprint);
	
#	else
	
	maybe_do
		(try_thing1,
		 try_thing2,
		 try_thing3,
		 mprint);
	
#	endif
}
