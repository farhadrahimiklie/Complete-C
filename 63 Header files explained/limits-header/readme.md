# 1. Introduction

`limits.h` is a standard C header file that defines the **minimum and maximum values** that can be stored by fundamental data types.

Instead of guessing that an `int` is always 32 bits or assuming a `char` is 8 bits, you should use the constants provided by `limits.h`.

```c
#include <limits.h>
```

It is part of the ISO C Standard Library.

---

# 2. Why Use `limits.h`?

Without `limits.h`, programmers often write:

```c
if (x > 2147483647)
```

This is bad because:

* Different systems may have different integer sizes.
* Your code becomes non-portable.
* It is difficult to maintain.

Better:

```c
if (x == INT_MAX)
```

This works correctly on every compliant C compiler.

---

# 3. Basic Example

```c
#include <stdio.h>
#include <limits.h>

int main()
{
    printf("Maximum int = %d\n", INT_MAX);
    printf("Minimum int = %d\n", INT_MIN);

    return 0;
}
```

Output (Typical)

```
Maximum int = 2147483647
Minimum int = -2147483648
```

---

# 4. Common Macros in `limits.h`

| Macro      | Meaning                    |
| ---------- | -------------------------- |
| CHAR_BIT   | Number of bits in one byte |
| CHAR_MIN   | Minimum char               |
| CHAR_MAX   | Maximum char               |
| SCHAR_MIN  | Minimum signed char        |
| SCHAR_MAX  | Maximum signed char        |
| UCHAR_MAX  | Maximum unsigned char      |
| SHRT_MIN   | Minimum short              |
| SHRT_MAX   | Maximum short              |
| USHRT_MAX  | Maximum unsigned short     |
| INT_MIN    | Minimum int                |
| INT_MAX    | Maximum int                |
| UINT_MAX   | Maximum unsigned int       |
| LONG_MIN   | Minimum long               |
| LONG_MAX   | Maximum long               |
| ULONG_MAX  | Maximum unsigned long      |
| LLONG_MIN  | Minimum long long          |
| LLONG_MAX  | Maximum long long          |
| ULLONG_MAX | Maximum unsigned long long |

---

# 5. Integer Limits

Example:

```c
#include <stdio.h>
#include <limits.h>

int main()
{
    printf("%d\n", INT_MIN);
    printf("%d\n", INT_MAX);

    return 0;
}
```

Typical Output

```
-2147483648
2147483647
```

---

# 6. Character Limits

```c
#include <stdio.h>
#include <limits.h>

int main()
{
    printf("%d\n", CHAR_MIN);
    printf("%d\n", CHAR_MAX);

    return 0;
}
```

---

# 7. `CHAR_BIT`

```c
#include <stdio.h>
#include <limits.h>

int main()
{
    printf("%d\n", CHAR_BIT);

    return 0;
}
```

Typical Output

```
8
```

Meaning:

```
1 Byte = 8 Bits
```

---

# 8. Ten Best and Most Used Examples

## Example 1: Print Every Integer Limit

```c
#include <stdio.h>
#include <limits.h>

int main()
{
    printf("INT_MIN = %d\n", INT_MIN);
    printf("INT_MAX = %d\n", INT_MAX);
    printf("LONG_MAX = %ld\n", LONG_MAX);
    printf("LLONG_MAX = %lld\n", LLONG_MAX);

    return 0;
}
```

---

## Example 2: Prevent Integer Overflow

```c
#include <stdio.h>
#include <limits.h>

int main()
{
    int value = INT_MAX;

    if (value == INT_MAX)
        printf("Cannot increment safely.\n");
    else
        value++;

    return 0;
}
```

---

## Example 3: Validate User Input

```c
#include <stdio.h>
#include <limits.h>

int main()
{
    long num;

    scanf("%ld", &num);

    if (num > INT_MAX || num < INT_MIN)
        printf("Outside int range\n");
    else
        printf("Fits in int\n");

    return 0;
}
```

---

## Example 4: Display Memory Limits

```c
#include <stdio.h>
#include <limits.h>

int main()
{
    printf("Unsigned int max = %u\n", UINT_MAX);

    return 0;
}
```

---

## Example 5: Check Character Capacity

```c
#include <stdio.h>
#include <limits.h>

int main()
{
    printf("Signed char max = %d\n", SCHAR_MAX);
    printf("Unsigned char max = %u\n", UCHAR_MAX);

    return 0;
}
```

---

## Example 6: Portable Program

```c
#include <stdio.h>
#include <limits.h>

int main()
{
    printf("Maximum long = %ld\n", LONG_MAX);

    return 0;
}
```

---

## Example 7: Compare Two Data Types

```c
#include <stdio.h>
#include <limits.h>

int main()
{
    printf("INT_MAX  = %d\n", INT_MAX);
    printf("LONG_MAX = %ld\n", LONG_MAX);

    return 0;
}
```

---

## Example 8: Detect Maximum Unsigned Value

```c
#include <stdio.h>
#include <limits.h>

int main()
{
    printf("%u\n", UINT_MAX);

    return 0;
}
```

---

## Example 9: Safe Addition

```c
#include <stdio.h>
#include <limits.h>

int safeAdd(int a, int b)
{
    if (b > 0 && a > INT_MAX - b)
        return 0;

    return a + b;
}

int main()
{
    printf("%d\n", safeAdd(100, 200));

    return 0;
}
```

---

## Example 10: Print All Limits

```c
#include <stdio.h>
#include <limits.h>

int main()
{
    printf("CHAR_BIT = %d\n", CHAR_BIT);
    printf("CHAR_MAX = %d\n", CHAR_MAX);
    printf("INT_MAX = %d\n", INT_MAX);
    printf("LONG_MAX = %ld\n", LONG_MAX);
    printf("LLONG_MAX = %lld\n", LLONG_MAX);

    return 0;
}
```

---

# 9. Best Practices

* Always use `INT_MAX`, `INT_MIN`, and related macros instead of hard-coded values.
* Write portable code that works across platforms.
* Check for overflow before arithmetic operations.
* Use the correct `printf` format specifier for each data type.
* Combine `limits.h` with `stdint.h` for fixed-width integer programming.

---

# 10. Common Mistakes

### Hard-Coding Limits

❌

```c
if (x > 2147483647)
```

✔

```c
if (x > INT_MAX)
```

---

### Assuming All Systems Are 32-bit

Different systems may have different sizes for `int`, `long`, and `long long`. Always rely on `limits.h`.

---

### Ignoring Overflow

Always validate arithmetic near the maximum or minimum limits to avoid undefined behavior.

---

# 14. Summary

The `limits.h` header is essential for writing portable, reliable C programs. It provides standardized macros describing the minimum and maximum values of fundamental integer types, helping you avoid hard-coded constants and detect overflow safely. Mastering `limits.h` is especially valuable in systems programming, embedded development, networking, security, and any application where correctness across different platforms matters.

After learning `limits.h`, a recommended progression through related headers is:

1. `stdint.h` (fixed-width integer types)
2. `inttypes.h` (format macros and conversions)
3. `float.h` (floating-point limits)
4. `stdbool.h` (Boolean type)
5. `stddef.h` (common type definitions)
6. `errno.h` (error reporting)













```c
#include <stdio.h>
#include <limits.h>
```

## 1. `CHAR_BIT`

`CHAR_BIT` is an integer constant.

```c
printf("CHAR_BIT = %d\n", CHAR_BIT);
```

**Format Specifier**

```c
%d
```

---

## 2. `CHAR_MIN`

```c
printf("CHAR_MIN = %d\n", CHAR_MIN);
```

**Format Specifier**

```c
%d
```

---

## 3. `CHAR_MAX`

```c
printf("CHAR_MAX = %d\n", CHAR_MAX);
```

**Format Specifier**

```c
%d
```

---

## 4. `SCHAR_MIN`

```c
printf("SCHAR_MIN = %d\n", SCHAR_MIN);
```

**Format Specifier**

```c
%d
```

---

## 5. `SCHAR_MAX`

```c
printf("SCHAR_MAX = %d\n", SCHAR_MAX);
```

**Format Specifier**

```c
%d
```

---

## 6. `UCHAR_MAX`

```c
printf("UCHAR_MAX = %u\n", UCHAR_MAX);
```

**Format Specifier**

```c
%u
```

---

## 7. `SHRT_MIN`

```c
printf("SHRT_MIN = %d\n", SHRT_MIN);
```

**Format Specifier**

```c
%d
```

Although `SHRT_MIN` is for a `short`, it is **promoted to `int`** when passed to `printf()`.

---

## 8. `SHRT_MAX`

```c
printf("SHRT_MAX = %d\n", SHRT_MAX);
```

**Format Specifier**

```c
%d
```

---

## 9. `USHRT_MAX`

```c
printf("USHRT_MAX = %u\n", USHRT_MAX);
```

**Format Specifier**

```c
%u
```

---

## 10. `INT_MIN`

```c
printf("INT_MIN = %d\n", INT_MIN);
```

**Format Specifier**

```c
%d
```

---

## 11. `INT_MAX`

```c
printf("INT_MAX = %d\n", INT_MAX);
```

**Format Specifier**

```c
%d
```

---

## 12. `UINT_MAX`

```c
printf("UINT_MAX = %u\n", UINT_MAX);
```

**Format Specifier**

```c
%u
```

---

## 13. `LONG_MIN`

```c
printf("LONG_MIN = %ld\n", LONG_MIN);
```

**Format Specifier**

```c
%ld
```

---

## 14. `LONG_MAX`

```c
printf("LONG_MAX = %ld\n", LONG_MAX);
```

**Format Specifier**

```c
%ld
```

---

## 15. `ULONG_MAX`

```c
printf("ULONG_MAX = %lu\n", ULONG_MAX);
```

**Format Specifier**

```c
%lu
```

---

## 16. `LLONG_MIN`

```c
printf("LLONG_MIN = %lld\n", LLONG_MIN);
```

**Format Specifier**

```c
%lld
```

---

## 17. `LLONG_MAX`

```c
printf("LLONG_MAX = %lld\n", LLONG_MAX);
```

**Format Specifier**

```c
%lld
```

---

## 18. `ULLONG_MAX`

```c
printf("ULLONG_MAX = %llu\n", ULLONG_MAX);
```

**Format Specifier**

```c
%llu
```

---

# Complete Program

```c
#include <stdio.h>
#include <limits.h>

int main(void)
{
    printf("CHAR_BIT   = %d\n", CHAR_BIT);

    printf("CHAR_MIN   = %d\n", CHAR_MIN);
    printf("CHAR_MAX   = %d\n", CHAR_MAX);

    printf("SCHAR_MIN  = %d\n", SCHAR_MIN);
    printf("SCHAR_MAX  = %d\n", SCHAR_MAX);
    printf("UCHAR_MAX  = %u\n", UCHAR_MAX);

    printf("SHRT_MIN   = %d\n", SHRT_MIN);
    printf("SHRT_MAX   = %d\n", SHRT_MAX);
    printf("USHRT_MAX  = %u\n", USHRT_MAX);

    printf("INT_MIN    = %d\n", INT_MIN);
    printf("INT_MAX    = %d\n", INT_MAX);
    printf("UINT_MAX   = %u\n", UINT_MAX);

    printf("LONG_MIN   = %ld\n", LONG_MIN);
    printf("LONG_MAX   = %ld\n", LONG_MAX);
    printf("ULONG_MAX  = %lu\n", ULONG_MAX);

    printf("LLONG_MIN  = %lld\n", LLONG_MIN);
    printf("LLONG_MAX  = %lld\n", LLONG_MAX);
    printf("ULLONG_MAX = %llu\n", ULLONG_MAX);

    return 0;
}
```

## Quick Reference Table

| Macro        | Type                                                  | `printf()` Format |
| ------------ | ----------------------------------------------------- | ----------------- |
| `CHAR_BIT`   | `int`                                                 | `%d`              |
| `CHAR_MIN`   | `char` (promoted to `int`)                            | `%d`              |
| `CHAR_MAX`   | `char` (promoted to `int`)                            | `%d`              |
| `SCHAR_MIN`  | `signed char` (promoted to `int`)                     | `%d`              |
| `SCHAR_MAX`  | `signed char` (promoted to `int`)                     | `%d`              |
| `UCHAR_MAX`  | `unsigned char` (promoted to `int` or `unsigned int`) | `%u`              |
| `SHRT_MIN`   | `short` (promoted to `int`)                           | `%d`              |
| `SHRT_MAX`   | `short` (promoted to `int`)                           | `%d`              |
| `USHRT_MAX`  | `unsigned short` (promoted)                           | `%u`              |
| `INT_MIN`    | `int`                                                 | `%d`              |
| `INT_MAX`    | `int`                                                 | `%d`              |
| `UINT_MAX`   | `unsigned int`                                        | `%u`              |
| `LONG_MIN`   | `long`                                                | `%ld`             |
| `LONG_MAX`   | `long`                                                | `%ld`             |
| `ULONG_MAX`  | `unsigned long`                                       | `%lu`             |
| `LLONG_MIN`  | `long long`                                           | `%lld`            |
| `LLONG_MAX`  | `long long`                                           | `%lld`            |
| `ULLONG_MAX` | `unsigned long long`                                  | `%llu`            |

### A note about `CHAR_MIN` and `CHAR_MAX`

Whether `char` is signed or unsigned is **implementation-defined** in C. On some systems:

* `CHAR_MIN = -128` and `CHAR_MAX = 127` (signed `char`)
* `CHAR_MIN = 0` and `CHAR_MAX = 255` (unsigned `char`)

Using `%d` is still appropriate because `char` values are promoted to `int` when passed to `printf()`.
