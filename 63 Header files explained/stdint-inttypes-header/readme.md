# Part 1: Why do we need `<stdint.h>`?

Before C99, integer sizes were not guaranteed.

For example:

```c
int
```

could be

* 16 bits
* 32 bits
* even 64 bits

depending on the compiler.

That caused portability problems.

Example:

```c
int age = 20;
```

Is it

* 2 bytes?
* 4 bytes?
* 8 bytes?

Nobody knows.

C99 solved this using

```c
#include <stdint.h>
```

Now you can explicitly say

```c
int8_t
int16_t
int32_t
int64_t
```

No guessing.

---

# Part 2: Why do we need `<inttypes.h>`?

Suppose you have

```c
int64_t money = 1000000000;
```

How do you print it?

Wrong:

```c
printf("%lld", money);
```

Some systems use

```
long
```

Some use

```
long long
```

Portable solution:

```c
#include <inttypes.h>

printf("%" PRId64 "\n", money);
```

That is exactly why `<inttypes.h>` exists.

It provides portable format macros for `printf()` and `scanf()`.

---

# Part 3: Include

```c
#include <stdint.h>
#include <inttypes.h>
```

---

# Part 4: Integer Types

## Signed

```c
int8_t
int16_t
int32_t
int64_t
```

Example

```c
int32_t salary = 50000;
```

---

## Unsigned

```c
uint8_t
uint16_t
uint32_t
uint64_t
```

Example

```c
uint32_t population = 8000000;
```

---

## Least Integer Types

Minimum size.

```c
int_least8_t
int_least16_t
int_least32_t
int_least64_t
```

Compiler chooses the fastest type that is **at least** that many bits.

---

## Fast Integer Types

```c
int_fast8_t
int_fast16_t
int_fast32_t
int_fast64_t
```

Used for performance.

---

## Maximum Integer Type

```c
intmax_t
uintmax_t
```

Largest integer type available.

---

## Pointer Integer Types

```c
intptr_t
uintptr_t
```

Store addresses safely.

---

# Part 5: Integer Limits

```c
INT8_MIN
INT8_MAX

INT16_MIN
INT16_MAX

INT32_MIN
INT32_MAX

INT64_MIN
INT64_MAX
```

Unsigned

```c
UINT8_MAX
UINT16_MAX
UINT32_MAX
UINT64_MAX
```

Example

```c
#include <stdio.h>
#include <stdint.h>

int main()
{
    printf("%d\n", INT8_MAX);
    printf("%u\n", UINT16_MAX);
}
```

Output

```
127
65535
```

---

# Part 6: Format Macros

Printing

```c
PRId8
PRId16
PRId32
PRId64
```

Unsigned

```c
PRIu8
PRIu16
PRIu32
PRIu64
```

Hex

```c
PRIx32
PRIX64
```

Scanning

```c
SCNd32
SCNu64
SCNx32
```

---

# Part 7: 10 Best and Most Used Examples

## Example 1 — Fixed-Size Integers

```c
#include <stdio.h>
#include <stdint.h>

int main()
{
    int8_t a = 100;
    int16_t b = 2000;
    int32_t c = 500000;
    int64_t d = 10000000000LL;

    printf("%d\n", a);
    printf("%d\n", b);
    printf("%d\n", c);
    printf("%lld\n", (long long)d);
}
```

Use case:

* Embedded systems
* Protocols
* Binary files

---

## Example 2 — Printing Portably

```c
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main()
{
    int64_t number = 1234567890123;

    printf("%" PRId64 "\n", number);
}
```

Recommended over `%lld` for portable code.

---

## Example 3 — Reading User Input

```c
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main()
{
    int32_t age;

    printf("Age: ");

    scanf("%" SCNd32, &age);

    printf("%" PRId32 "\n", age);
}
```

---

## Example 4 — Binary File Header

```c
#include <stdint.h>

struct Header
{
    uint32_t magic;
    uint16_t version;
    uint64_t size;
};
```

Perfect for

* image formats
* databases
* archives

---

## Example 5 — Network Packet

```c
#include <stdint.h>

struct Packet
{
    uint16_t type;
    uint32_t length;
    uint8_t flags;
};
```

Networking software depends heavily on fixed-width integers.

---

## Example 6 — Sensor Data

```c
#include <stdio.h>
#include <stdint.h>

int main()
{
    int16_t temperature = -15;

    printf("%d\n", temperature);
}
```

Used in

* Arduino
* STM32
* ESP32

---

## Example 7 — Pointer Arithmetic

```c
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main()
{
    int x = 10;

    uintptr_t address = (uintptr_t)&x;

    printf("%" PRIxPTR "\n", address);
}
```

Useful in low-level programming and memory inspection.

---

## Example 8 — Maximum Integer

```c
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main()
{
    intmax_t big = INTMAX_MAX;

    printf("%" PRIdMAX "\n", big);
}
```

---

## Example 9 — Integer Limits

```c
#include <stdio.h>
#include <stdint.h>

int main()
{
    printf("%d\n", INT16_MIN);
    printf("%d\n", INT16_MAX);
}
```

---

## Example 10 — Hexadecimal Printing

```c
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main()
{
    uint32_t color = 0xFFAA00;

    printf("%" PRIX32 "\n", color);
}
```

Output

```
FFAA00
```

---

# Part 8: Real-World Project 1 — Binary File Viewer

### Goal

Create a tool that reads any binary file and displays structured information using fixed-width integer types.

### Features

* Read binary files (`.bin`)
* Display offsets
* Show hexadecimal bytes
* Decode 16-bit, 32-bit, and 64-bit integers
* Print file metadata
* Support little-endian and big-endian formats

### Concepts Used

* `uint8_t`
* `uint16_t`
* `uint32_t`
* `uint64_t`
* `intmax_t`
* `PRIx8`
* `PRIx32`
* `PRIx64`
* `fread()`
* `fseek()`
* `ftell()`

### Skills Learned

* Binary parsing
* File formats
* Endianness
* Portable integer handling
* Systems programming

---

# Part 9: Real-World Project 2 — Network Packet Analyzer

### Goal

Build a simple packet parser that reads captured network packets from a binary file and interprets protocol headers.

### Features

* Read packet records
* Parse Ethernet, IPv4, and TCP/UDP header fields
* Display source/destination addresses and ports
* Decode packet lengths and flags
* Print values with `<inttypes.h>` format macros

### Concepts Used

* `uint8_t`
* `uint16_t`
* `uint32_t`
* `uintptr_t` (if working with memory buffers)
* `PRIx8`
* `PRIu16`
* `PRIu32`
* Byte-order conversion (`ntohs()`, `ntohl()`)
* Bit masking and shifting

### Skills Learned

* Network protocol parsing
* Binary data interpretation
* Portable systems programming
* Low-level debugging

---

# Part 10: Best Practices

* Always include `<stdint.h>` when integer size matters.
* Use `<inttypes.h>` format macros (`PRId32`, `PRIu64`, `SCNd32`, etc.) instead of compiler-specific format specifiers for portable code.
* Prefer `uint32_t`/`int32_t` for binary file formats, network protocols, and embedded systems.
* Use `uintptr_t`/`intptr_t` when converting pointers to integer types.
* Check limit macros such as `INT32_MAX` and `UINT64_MAX` to avoid overflow-related bugs.
* Use `intmax_t` and `uintmax_t` when writing generic code that should handle the largest available integer type.

## Summary Table

| Header         | Purpose                                             | Common Items                                       |
| -------------- | --------------------------------------------------- | -------------------------------------------------- |
| `<stdint.h>`   | Defines integer types with guaranteed widths        | `int32_t`, `uint64_t`, `intptr_t`, `intmax_t`      |
| `<inttypes.h>` | Defines portable `printf()`/`scanf()` format macros | `PRId64`, `PRIu32`, `PRIxPTR`, `SCNd32`, `PRIdMAX` |

Mastering these headers is essential for writing portable C programs, especially in systems programming, embedded development, networking, binary file processing, and cross-platform libraries.
