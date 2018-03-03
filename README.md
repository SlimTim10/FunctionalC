# MaybeC

## Description

The [Maybe monad](https://en.wikipedia.org/wiki/Monad_(functional_programming)#The_Maybe_monad) in C99. For facilitating error handling and function sequencing.

The `maybe_do` macro supports sequencing up to 10 functions, but it can be expanded to support more if needed.

## Usage

A particularly useful case is turning something like this:

```
int x = try_thing1();
if (x != NULL) {
    int y = try_thing2(x);
    if (y != NULL) {
        int z = try_thing3(y);
        if (z != NULL) {
            final_thing(z);
        }
    }
}
```

into this:

```
#include "maybe.h"
maybe_do
    (mstart,
    try_thing1,
    try_thing2,
    try_thing3,
    final_thing);
```

See `examples/` for more examples usage.