#include "../maybe.h"

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/* char[] -> maybe char[] */
static maybe safe_tail(void *xs_) {
	static char *xs; xs = (char *) xs_;
	if (strlen(xs) > 1) {
		return mreturn(&xs[1]);
	} else {
		return nothing();
	}
}

/* char[] -> maybe void */
static maybe mprint(void *xs_) {
	char *xs = (char *) xs_;
	printf("%s\n", xs);
	return nothing();
}

void main(void) {
	static char buf[32];
	sprintf(buf, "test");
	maybe x = {
		.nothing = false,
		.just = buf
	};

	bind(mprint, x);

	int i;
	int too_many = 10;
	for (i = 0; i < too_many; i++) {
		x = bind(safe_tail, x);
		bind(mprint, x);
	}
}
