# MaybeC

## Description

The [Maybe monad](https://en.wikipedia.org/wiki/Monad_(functional_programming)#The_Maybe_monad) in C99. For facilitating error handling and function sequencing.

The `maybe_do` macro supports sequencing up to 10 functions, but it can be expanded to support more if needed.

I created this with Arduino projects in mind. There are often cases where it is necessary to do a sequence of functions based on external factors. The sequence should only continue as each function succeeds, and perhaps pass along data from one function to the next. To use this as an Arduino library, download it as a ZIP and extract the folder to your [Arduino libraries](https://www.arduino.cc/en/hacking/libraries) directory, then rename the folder from `MaybeC-master` to `maybe` and rename `maybe.c` to `maybe.cpp`.

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