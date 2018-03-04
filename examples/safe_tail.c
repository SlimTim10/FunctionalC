#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "../maybe.h"

static char buf[32];

/* char[] -> maybe char[] */
static maybe safe_tail(void *xs_) {
	char *xs = (char *) xs_;
	if (strlen(xs) > 1) {
		sprintf(buf, &xs[1]);
		return mreturn(buf);
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
