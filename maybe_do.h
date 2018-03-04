#ifndef MAYBE_DO_H
#define MAYBE_DO_H

#define maybe_do1(x, f) ( bind(f, x) )
#define maybe_do2(x, f, ...) ( maybe_do1(bind(f, x), __VA_ARGS__) )
#define maybe_do3(x, f, ...) ( maybe_do2(bind(f, x), __VA_ARGS__) )
#define maybe_do4(x, f, ...) ( maybe_do3(bind(f, x), __VA_ARGS__) )
#define maybe_do5(x, f, ...) ( maybe_do4(bind(f, x), __VA_ARGS__) )
#define maybe_do6(x, f, ...) ( maybe_do5(bind(f, x), __VA_ARGS__) )
#define maybe_do7(x, f, ...) ( maybe_do6(bind(f, x), __VA_ARGS__) )
#define maybe_do8(x, f, ...) ( maybe_do7(bind(f, x), __VA_ARGS__) )
#define maybe_do9(x, f, ...) ( maybe_do8(bind(f, x), __VA_ARGS__) )
#define maybe_do10(x, f, ...) ( maybe_do9(bind(f, x), __VA_ARGS__) )

#define GET_MACRO(_1,\
	_2,\
	_3,\
	_4,\
	_5,\
	_6,\
	_7,\
	_8,\
	_9,\
	_10,\
	_11,\
	NAME,\
	...) NAME

#define maybe_do(...)\
	GET_MACRO(__VA_ARGS__,\
		maybe_do10,\
		maybe_do9,\
		maybe_do8,\
		maybe_do7,\
		maybe_do6,\
		maybe_do5,\
		maybe_do4,\
		maybe_do3,\
		maybe_do2,\
		maybe_do1)\
	(__VA_ARGS__)

#define mstart ( mreturn(NULL) )

#endif
