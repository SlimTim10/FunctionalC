#ifndef FUNCTIONAL_H
#define FUNCTIONAL_H

#define forEach(xs, len, f) \
	for (size_t i = 0; i < len; i++) f(xs[i]);

#define map(from, to, len, f) \
	for (size_t i = 0; i < len; i++) \
		to[i] = f(from[i]);

#endif
