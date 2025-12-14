## 1. General Rule of `printf` Format Specifiers

The basic syntax is:

```c
printf("%[flags][width][.precision][length]specifier", value);
```

What matters most here is:

* **length modifier** → size of the data type
* **specifier** → how the value is printed

---

## 2. Integer Types (Signed & Unsigned)

### 2.1 `short int` and `unsigned short int`

| Data Type            | Format Specifier |
| -------------------- | ---------------- |
| `short int`          | `%hd`            |
| `unsigned short int` | `%hu`            |

Example:

```c
short int a = -123;
unsigned short int b = 123;

printf("%hd\n", a);
printf("%hu\n", b);
```

Important:

* `%d` is **wrong** for `short` in strict correctness
* `%hd` tells `printf` the value is a `short`

---

### 2.2 `int` and `unsigned int`

| Data Type      | Format Specifier |
| -------------- | ---------------- |
| `int`          | `%d` or `%i`     |
| `unsigned int` | `%u`             |

Example:

```c
int x = -10;
unsigned int y = 10;

printf("%d\n", x);
printf("%u\n", y);
```

Difference:

* `%d` and `%i` behave the same in `printf`
* `%i` is different only in `scanf`

---

### 2.3 `long int` and `unsigned long int`

| Data Type           | Format Specifier |
| ------------------- | ---------------- |
| `long int`          | `%ld`            |
| `unsigned long int` | `%lu`            |

Example:

```c
long int a = 100000L;
unsigned long int b = 100000UL;

printf("%ld\n", a);
printf("%lu\n", b);
```

---

### 2.4 `long long int` and `unsigned long long int`

| Data Type                | Format Specifier |
| ------------------------ | ---------------- |
| `long long int`          | `%lld`           |
| `unsigned long long int` | `%llu`           |

Example:

```c
long long int a = 1234567890123LL;
unsigned long long int b = 1234567890123ULL;

printf("%lld\n", a);
printf("%llu\n", b);
```

---

## 3. Character Types

### 3.1 `char` (as a character)

| Data Type | Format Specifier |
| --------- | ---------------- |
| `char`    | `%c`             |

Example:

```c
char ch = 'A';
printf("%c\n", ch);
```

---

### 3.2 `char` (as an integer / ASCII value)

| Data Type        | Format Specifier |
| ---------------- | ---------------- |
| `char` as number | `%d`             |

Example:

```c
char ch = 'A';
printf("%d\n", ch);   // prints ASCII value (65)
```

---

### 3.3 `signed char` and `unsigned char`

| Data Type       | Format Specifier |
| --------------- | ---------------- |
| `signed char`   | `%hhd`           |
| `unsigned char` | `%hhu`           |

Example:

```c
signed char a = -10;
unsigned char b = 250;

printf("%hhd\n", a);
printf("%hhu\n", b);
```

---

## 4. Strings

### 4.1 Character Array / String Literal

| Data Type            | Format Specifier |
| -------------------- | ---------------- |
| `char *` or `char[]` | `%s`             |

Example:

```c
char name[] = "Linux";
printf("%s\n", name);
```

Rule:

* `%s` expects a **null-terminated string**
* Passing a non-string pointer causes **undefined behavior**

---

## 5. Floating-Point Types

### 5.1 `float`

Important rule:

> **`float` is automatically promoted to `double` in `printf`**

| Data Type | Format Specifier |
| --------- | ---------------- |
| `float`   | `%f`             |

Example:

```c
float f = 3.14f;
printf("%f\n", f);
```

---

### 5.2 `double`

| Data Type           | Format Specifier |
| ------------------- | ---------------- |
| `double`            | `%f`             |
| scientific notation | `%e`             |
| shortest form       | `%g`             |

Example:

```c
double d = 123.456;

printf("%f\n", d);
printf("%e\n", d);
printf("%g\n", d);
```

---

### 5.3 `long double`

| Data Type     | Format Specifier |
| ------------- | ---------------- |
| `long double` | `%Lf`            |
| scientific    | `%Le`            |
| shortest      | `%Lg`            |

Example:

```c
long double ld = 123.456L;
printf("%Lf\n", ld);
```

---

## 6. Boolean Type (`_Bool` / `bool`)

C does **not** have a native `%b` format specifier.

### 6.1 Using `<stdbool.h>`

```c
#include <stdbool.h>

bool flag = true;
printf("%d\n", flag);  // prints 1 or 0
```

Correct specifier:

* `%d` (because `bool` is an integer type)

### 6.2 Printing as text

```c
printf("%s\n", flag ? "true" : "false");
```

---

## 7. Pointer Types

### 7.1 Any Pointer (`int*`, `char*`, etc.)

| Data Type | Format Specifier |
| --------- | ---------------- |
| pointer   | `%p`             |

Example:

```c
int x = 10;
printf("%p\n", (void*)&x);
```

Rule:

* Always cast to `(void *)` when printing pointers

---

## 8. Size Types

### 8.1 `size_t`

| Data Type | Format Specifier |
| --------- | ---------------- |
| `size_t`  | `%zu`            |

Example:

```c
size_t n = sizeof(int);
printf("%zu\n", n);
```

---

### 8.2 `ptrdiff_t`

| Data Type   | Format Specifier |
| ----------- | ---------------- |
| `ptrdiff_t` | `%td`            |

---

## 9. Summary Table (Quick Reference)

| C Type               | Format |
| -------------------- | ------ |
| `char`               | `%c`   |
| `signed char`        | `%hhd` |
| `unsigned char`      | `%hhu` |
| `short`              | `%hd`  |
| `unsigned short`     | `%hu`  |
| `int`                | `%d`   |
| `unsigned int`       | `%u`   |
| `long`               | `%ld`  |
| `unsigned long`      | `%lu`  |
| `long long`          | `%lld` |
| `unsigned long long` | `%llu` |
| `float`              | `%f`   |
| `double`             | `%f`   |
| `long double`        | `%Lf`  |
| `char *`             | `%s`   |
| `pointer`            | `%p`   |
| `bool`               | `%d`   |
| `size_t`             | `%zu`  |

---

## 10. Critical Rules You Must Remember

1. **Wrong specifier = undefined behavior**
2. `float` → promoted to `double` in `printf`
3. `%s` needs a null-terminated string
4. No `%b` for binary or boolean
5. Use correct length modifiers (`h`, `l`, `ll`, `L`)







```c
printf("%[flags][width][.precision][length]specifier", value);
```

explained **one component at a time**, **from left to right**, with **practical examples** and **rules**.
This is written to give you **deep understanding**, not memorization.

---

# 1. Full Structure of a `printf` Format Specifier

A single format specifier always starts with `%` and ends with a **conversion specifier**.

```c
% [flags] [width] [.precision] [length] specifier
```

Only `%` and `specifier` are mandatory.
Everything else is optional.

---

# 2. `%` — Start of a Format Specifier

```c
%
```

This tells `printf`:

> “The next characters describe how to print a value.”

Example:

```c
printf("%d", x);
```

Without `%`, `printf` prints characters literally.

---

# 3. `[flags]` — Output Behavior Modifiers

Flags **change how the output looks**, not the value itself.

You can use **multiple flags together**.

---

## 3.1 `-` (Left Alignment)

Default behavior is **right-aligned**.

```c
printf("%-5d", 10);
```

Output:

```
10   
```

Without `-`:

```c
printf("%5d", 10);
```

Output:

```
   10
```

---

## 3.2 `0` (Zero Padding)

Pads numeric output with zeros **instead of spaces**.

```c
printf("%05d", 42);
```

Output:

```
00042
```

Rules:

* Only works with numbers
* Ignored if `-` flag is present

---

## 3.3 `+` (Always Show Sign)

Shows `+` for positive numbers.

```c
printf("%+d", 10);
```

Output:

```
+10
```

Without `+`:

```
10
```

---

## 3.4 Space (` `) Flag

Adds a **leading space** for positive numbers.

```c
printf("% d", 10);
```

Output:

```
 10
```

Rule:

* Ignored if `+` flag is used

---

## 3.5 `#` (Alternate Form)

Meaning depends on the specifier.

### For integers:

```c
printf("%#x", 255);
```

Output:

```
0xff
```

### For floating-point:

```c
printf("%#.0f", 10.0);
```

Output:

```
10.
```

---

# 4. `[width]` — Minimum Field Width

Defines **minimum number of characters** printed.

```c
printf("%5d", 42);
```

Output:

```
   42
```

Rules:

* If value is longer than width → width ignored
* Applies to numbers and strings

### Width with string

```c
printf("%10s", "C");
```

Output:

```
         C
```

---

## 4.1 Dynamic Width (`*`)

Width provided at runtime.

```c
printf("%*d", 5, 42);
```

Equivalent to:

```c
printf("%5d", 42);
```

---

# 5. `[.precision]` — Precision (VERY IMPORTANT)

Precision **changes meaning depending on data type**.

---

## 5.1 Precision with Integers

Minimum number of digits.

```c
printf("%.5d", 42);
```

Output:

```
00042
```

Rule:

* Adds leading zeros
* Overrides `0` flag

---

## 5.2 Precision with Floating-Point Numbers

Number of digits **after decimal point**.

```c
printf("%.2f", 3.14159);
```

Output:

```
3.14
```

Default:

```c
printf("%f", 3.14159);
```

Output:

```
3.141590
```

---

## 5.3 Precision with Strings

Maximum number of characters printed.

```c
printf("%.3s", "Linux");
```

Output:

```
Lin
```

---

## 5.4 Dynamic Precision (`*`)

```c
printf("%.*f", 2, 3.14159);
```

Equivalent to:

```c
printf("%.2f", 3.14159);
```

---

# 6. `[length]` — Size of the Data Type

This tells `printf` **how many bytes** to read from memory.

Wrong length = **undefined behavior**.

---

## 6.1 Length Modifiers Table

| Modifier | Meaning       |
| -------- | ------------- |
| `hh`     | `char`        |
| `h`      | `short`       |
| `l`      | `long`        |
| `ll`     | `long long`   |
| `L`      | `long double` |
| `z`      | `size_t`      |
| `t`      | `ptrdiff_t`   |

---

### Examples

```c
printf("%hd", (short)10);
printf("%ld", 100000L);
printf("%lld", 10000000000LL);
printf("%Lf", 3.14L);
printf("%zu", sizeof(int));
```

---

# 7. `specifier` — What Type to Print

This is **mandatory**.

---

## 7.1 Common Specifiers

| Specifier | Meaning          |
| --------- | ---------------- |
| `d`, `i`  | signed integer   |
| `u`       | unsigned integer |
| `f`       | float / double   |
| `c`       | character        |
| `s`       | string           |
| `p`       | pointer          |
| `x`, `X`  | hexadecimal      |
| `o`       | octal            |
| `%`       | literal `%`      |

---

# 8. Complete Examples (Everything Together)

---

### Example 1: Integer Formatting

```c
printf("%-+08.5d", 42);
```

Breakdown:

* `-` → left align
* `+` → show sign
* `0` → ignored because of `-`
* `8` → width
* `.5` → precision
* `d` → integer

Output:

```
+00042  
```

---

### Example 2: Floating-Point Formatting

```c
printf("%10.3f", 3.14159);
```

Output:

```
     3.142
```

---

### Example 3: String Formatting

```c
printf("%-10.4s", "Programming");
```

Output:

```
Prog      
```

---

# 9. Why This Matters (Critical Insight)

`printf`:

* **does not know variable types**
* relies entirely on **your format string**
* reads raw memory based on `[length][specifier]`

That is why:

> A single wrong character can crash your program.