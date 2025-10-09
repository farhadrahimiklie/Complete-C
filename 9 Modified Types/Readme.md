
---

# 🔹 **Type Modifiers in C**

**Type modifiers** are keywords that **change the meaning of basic data types**.
They **modify the size, storage, and range** of data types to fit different needs.

---

## 🧩 1. The Four Type Modifiers

1. **`signed`**
2. **`unsigned`**
3. **`short`**
4. **`long`**

> These are used with **`int`**, **`char`**, and sometimes with **`double`** (`long double`).

---

## 🔹 2. `signed` Modifier

* **Default for most numeric types** in C.
* Allows **positive and negative numbers**.
* Can be applied explicitly, e.g., `signed int` or `signed char`.

### Example:

```c
#include <stdio.h>

int main() {
    signed int a = -10;
    signed char b = -128;

    printf("Signed int: %d\n", a);
    printf("Signed char: %d\n", b);
    return 0;
}
```

**Output:**

```
Signed int: -10
Signed char: -128
```

> 🔹 If you don’t write `signed`, integer types are **signed by default**.

---

## 🔹 3. `unsigned` Modifier

* Stores **only positive numbers and zero**.
* Doubles the **maximum positive range**.
* Cannot store negative numbers.

### Example:

```c
#include <stdio.h>

int main() {
    unsigned int x = 4000000000;
    unsigned char y = 255;

    printf("Unsigned int: %u\n", x);
    printf("Unsigned char: %u\n", y);
    return 0;
}
```

**Output:**

```
Unsigned int: 4000000000
Unsigned char: 255
```

> ⚠️ Storing a negative number in `unsigned` causes **wrap-around**.

---

### ⚡ Example of Wrap-Around

```c
#include <stdio.h>

int main() {
    unsigned char a = -1;
    printf("%u\n", a); // Output: 255
    return 0;
}
```

* `-1` cannot be stored → wraps around to maximum value `255`.

---

## 🔹 4. `short` Modifier

* Reduces **memory size** of integers.
* Usually **2 bytes** (16 bits) instead of 4 bytes for `int`.
* Good for **saving memory** in large arrays.

### Example:

```c
#include <stdio.h>

int main() {
    short int a = 32767;
    short int b = -32768;

    printf("Short int a = %d\n", a);
    printf("Short int b = %d\n", b);
    return 0;
}
```

**Range:**

* Signed short: –32,768 → 32,767
* Unsigned short: 0 → 65,535

---

## 🔹 5. `long` Modifier

* Increases **memory size** and **range** of integers.
* Usually **4 bytes** for `long int` (on 32-bit) and **8 bytes** (on 64-bit).
* Can be combined with `long long` for **very large integers**.

### Example:

```c
#include <stdio.h>

int main() {
    long int a = 2147483647;
    long long int b = 9223372036854775807;

    printf("Long int: %ld\n", a);
    printf("Long long int: %lld\n", b);
    return 0;
}
```

**Range:**

* `long int` (64-bit system): –9,223,372,036,854,775,808 → 9,223,372,036,854,775,807
* `unsigned long int`: 0 → 18,446,744,073,709,551,615

---

## 🔹 6. Combining Modifiers

Modifiers can be **combined** with basic types. Examples:

| Combination            | Meaning                | Typical Size | Range                          |
| ---------------------- | ---------------------- | ------------ | ------------------------------ |
| `unsigned int`         | Positive int only      | 4 bytes      | 0 → 4,294,967,295              |
| `signed short int`     | Signed 16-bit integer  | 2 bytes      | –32,768 → 32,767               |
| `long unsigned int`    | Large positive integer | 8 bytes      | 0 → 18,446,744,073,709,551,615 |
| `long long signed int` | Large signed integer   | 8 bytes      | –9.2×10¹⁸ → 9.2×10¹⁸           |

---

## 🔹 7. `long` and `double`

* `long` can also **modify `double`**:
* `long double` → **higher precision floating-point**
* Size: 10–16 bytes
* Precision: 18–19 digits

### Example:

```c
#include <stdio.h>

int main() {
    long double pi = 3.141592653589793238;
    printf("Long double pi = %.18Lf\n", pi);
    return 0;
}
```

Output:

```
Long double pi = 3.141592653589793238
```

---

## 🔹 8. Quick Reference Table of Modified Types

| Base Type | Modifier    | Size              | Signed Range             | Unsigned Range |
| --------- | ----------- | ----------------- | ------------------------ | -------------- |
| `int`     | `short`     | 2 bytes           | –32,768 → 32,767         | 0 → 65,535     |
| `int`     | `int`       | 4 bytes           | –2.1×10⁹ → 2.1×10⁹       | 0 → 4.2×10⁹    |
| `int`     | `long`      | 8 bytes           | –9.2×10¹⁸ → 9.2×10¹⁸     | 0 → 1.8×10¹⁹   |
| `int`     | `long long` | 8 bytes           | –9.2×10¹⁸ → 9.2×10¹⁸     | 0 → 1.8×10¹⁹   |
| `char`    | `signed`    | 1 byte            | –128 → 127               | —              |
| `char`    | `unsigned`  | 1 byte            | —                        | 0 → 255        |
| `float`   | `long`      | 8 bytes (depends) | ±3.4×10³⁸                | —              |
| `double`  | `long`      | 10–16 bytes       | ±1.7×10³⁰⁸ → ±1.1×10⁴⁹³² | —              |

---

## ⚡ 9. Practical Example: All Modifiers

```c
#include <stdio.h>

int main() {
    signed char a = -100;
    unsigned char b = 200;
    short int c = 32000;
    unsigned short int d = 65000;
    long int e = 1000000000;
    long long int f = 9000000000000000000;

    printf("Signed char: %d\n", a);
    printf("Unsigned char: %u\n", b);
    printf("Short int: %d\n", c);
    printf("Unsigned short int: %u\n", d);
    printf("Long int: %ld\n", e);
    printf("Long long int: %lld\n", f);

    return 0;
}
```

---

## 🏁 Key Points to Remember

1. **Default signed/unsigned:**

   * `int` is signed by default
   * `char` can be signed or unsigned depending on compiler

2. **Memory efficiency:**

   * Use `short` if memory is limited
   * Use `long` or `long long` for large numbers

3. **Floating-point modifiers:**

   * Use `long double` for very high precision

4. **Combining modifiers:**

   * `unsigned long int`, `signed short int`, etc. are valid

5. **Range depends on size:**

   * More bytes → bigger range

---