#ifndef MAYBE_H
#define MAYBE_H

#include <stdbool.h>
#include "maybe_do.h"

typedef struct {
	bool nothing;
	void *just;
} maybe;

typedef maybe (*maybe_f)(void *);

maybe mreturn(void *);
maybe nothing(void);
maybe bind(maybe_f, maybe);
bool is_nothing(maybe);
bool is_just(maybe);

#endif
