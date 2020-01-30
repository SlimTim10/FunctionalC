#include <stdbool.h>
#include <stdarg.h>
#include "maybe.h"

maybe mreturn(void *x) {
	maybe r;
	r.nothing = false;
	r.just = x;
	return r;
}

maybe nothing(void) {
	maybe r;
	r.nothing = true;
	return r;
}

maybe bind(maybe_f f, maybe x) {
	return x.nothing
		? nothing()
		: f(x.just);
}

bool is_nothing(maybe x) {
	return (x.nothing == true);
}

bool is_just(maybe x) {
	return (x.nothing == false);
}
