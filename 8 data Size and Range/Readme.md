
---

## 🧠 What Is “Size” and “Range” in C?

Every **data type** in C occupies a **specific amount of memory** (measured in *bytes*).
This amount determines:

1. **How much memory** the variable takes.
2. **What range of values** it can represent.

So:

* **Size →** How many bytes are used in memory.
* **Range →** Minimum and maximum values that can be stored using those bytes.

---

## 🧩 1. Understanding Memory and Binary Representation

Before understanding data ranges, let’s recall:

* **1 byte = 8 bits**
* Each bit can be either **0** or **1**
* So with *n bits*, you can represent **2ⁿ different values**

Example:
If you have **8 bits (1 byte)**, you can represent **2⁸ = 256 different combinations**.

---

## 🧩 2. Signed vs Unsigned Data Types

C supports both **signed** and **unsigned** types.

| Type         | Explanation                                            |
| ------------ | ------------------------------------------------------ |
| **Signed**   | Can store **positive and negative** numbers (default). |
| **Unsigned** | Can store **only positive** numbers (no negatives).    |

So:

* **Signed types** divide the available bits:

  * 1 bit for the sign (+/–)
  * Remaining bits for the value.
* **Unsigned types** use *all bits* for value (so double the positive range).

---

## 🧮 3. Formula for Range

To calculate the **range** of a data type:

* For **signed types**:
  → Range = –(2ⁿ⁻¹) to (2ⁿ⁻¹ – 1)

* For **unsigned types**:
  → Range = 0 to (2ⁿ – 1)

Where `n` = number of bits used by the data type.

---

## 📘 4. Sizes and Ranges of Basic Data Types (on a 32-bit or 64-bit system)

> 🧩 Note: Sizes can vary slightly depending on **compiler** and **architecture**, but these are the most common standards (especially in GCC and modern compilers).

| Data Type       | Size (bytes) | Bits   | Signed Range                                             | Unsigned Range                  | Format Specifier |
| --------------- | ------------ | ------ | -------------------------------------------------------- | ------------------------------- | ---------------- |
| `char`          | 1            | 8      | –128 to +127                                             | 0 to 255                        | `%c` / `%d`      |
| `short int`     | 2            | 16     | –32,768 to +32,767                                       | 0 to 65,535                     | `%hd` / `%hu`    |
| `int`           | 4            | 32     | –2,147,483,648 to +2,147,483,647                         | 0 to 4,294,967,295              | `%d` / `%u`      |
| `long int`      | 4 or 8       | 32/64  | –2,147,483,648 to +2,147,483,647 (32-bit)                | 0 to 4,294,967,295              | `%ld` / `%lu`    |
| `long long int` | 8            | 64     | –9,223,372,036,854,775,808 to +9,223,372,036,854,775,807 | 0 to 18,446,744,073,709,551,615 | `%lld` / `%llu`  |
| `float`         | 4            | 32     | ±3.4 × 10⁻³⁸ to ±3.4 × 10³⁸                              | —                               | `%f`             |
| `double`        | 8            | 64     | ±1.7 × 10⁻³⁰⁸ to ±1.7 × 10³⁰⁸                            | —                               | `%lf`            |
| `long double`   | 10 or 16     | 80–128 | ±3.4 × 10⁻⁴⁹³² to ±1.1 × 10⁴⁹³²                          | —                               | `%Lf`            |

---

## 🧩 5. Example: Visualizing Bit Usage (Signed vs Unsigned)

Let’s take an **8-bit `char`** as an example.

### ➤ Signed char

```
Bit pattern: 1 bit for sign, 7 bits for value
```

| Binary (8 bits) | Decimal Value |
| --------------- | ------------- |
| 0000 0000       | 0             |
| 0111 1111       | +127          |
| 1111 1111       | –1            |
| 1000 0000       | –128          |

→ Range = **–128 to +127**

---

### ➤ Unsigned char

```
All 8 bits used for value
```

| Binary    | Decimal |
| --------- | ------- |
| 0000 0000 | 0       |
| 1111 1111 | 255     |

→ Range = **0 to 255**

---

## 🧩 6. How to Check Size in C

You can find the exact **size (in bytes)** of any data type on your system using the `sizeof()` operator.

### Example:

```c
#include <stdio.h>
int main() {
    printf("Size of char: %lu bytes\n", sizeof(char));
    printf("Size of int: %lu bytes\n", sizeof(int));
    printf("Size of short: %lu bytes\n", sizeof(short));
    printf("Size of long: %lu bytes\n", sizeof(long));
    printf("Size of float: %lu bytes\n", sizeof(float));
    printf("Size of double: %lu bytes\n", sizeof(double));
    printf("Size of long double: %lu bytes\n", sizeof(long double));
    return 0;
}
```

Output (on 64-bit system):

```
Size of char: 1 bytes
Size of int: 4 bytes
Size of short: 2 bytes
Size of long: 8 bytes
Size of float: 4 bytes
Size of double: 8 bytes
Size of long double: 16 bytes
```

---

## 🧠 7. Floating-Point Data Type Range

Floating-point data types represent **real numbers (decimals)** using scientific notation.

| Type          | Size        | Precision     | Range                          | Example                               |
| ------------- | ----------- | ------------- | ------------------------------ | ------------------------------------- |
| `float`       | 4 bytes     | ~6 digits     | ±3.4 × 10⁻³⁸ → ±3.4 × 10³⁸     | `float pi = 3.14159;`                 |
| `double`      | 8 bytes     | ~15 digits    | ±1.7 × 10⁻³⁰⁸ → ±1.7 × 10³⁰⁸   | `double d = 12345.6789;`              |
| `long double` | 10–16 bytes | ~18–19 digits | ±3.4 × 10⁻⁴⁹³² → ±1.1 × 10⁴⁹³² | `long double ld = 3.141592653589793;` |

---

## ⚙️ 8. Practical Example: Signed vs Unsigned Difference

```c
#include <stdio.h>

int main() {
    signed char a = -1;
    unsigned char b = -1;

    printf("Signed char: %d\n", a);
    printf("Unsigned char: %u\n", b);
    return 0;
}
```

🧩 **Explanation:**

* `a = -1` stored as `1111 1111` (binary) → interpreted as **–1**
* `b = -1` also stored as `1111 1111` but **interpreted as 255** (since unsigned)

🧾 Output:

```
Signed char: -1
Unsigned char: 255
```

---

## 🧩 9. Summary Table (Modern 64-bit System)

| Type          | Size     | Signed Range                | Unsigned Range |
| ------------- | -------- | --------------------------- | -------------- |
| `char`        | 1 byte   | –128 to +127                | 0 to 255       |
| `short`       | 2 bytes  | –32,768 to +32,767          | 0 to 65,535    |
| `int`         | 4 bytes  | –2.1×10⁹ to +2.1×10⁹        | 0 to 4.2×10⁹   |
| `long`        | 8 bytes  | –9.2×10¹⁸ to +9.2×10¹⁸      | 0 to 1.8×10¹⁹  |
| `float`       | 4 bytes  | ±3.4×10⁻³⁸ to ±3.4×10³⁸     | —              |
| `double`      | 8 bytes  | ±1.7×10⁻³⁰⁸ to ±1.7×10³⁰⁸   | —              |
| `long double` | 16 bytes | ±3.4×10⁻⁴⁹³² to ±1.1×10⁴⁹³² | —              |

---

## ⚡ 10. Why Size and Range Matter

Understanding size and range is essential because:

1. You prevent **overflow** and **underflow**.
2. You use **memory efficiently**.
3. You ensure correct **type conversions**.
4. You understand how **data loss** can occur.

Example of overflow:

```c
#include <stdio.h>
int main() {
    unsigned char x = 255;
    x = x + 1; // overflow
    printf("%u\n", x); // prints 0
    return 0;
}
```

🧩 Explanation:

* Max value of `unsigned char` = 255
* Adding 1 → wraps back to 0 (modulo behavior)

---

## 🧩 11. Quick Visualization (Bits and Ranges)

| Bits         | Possible Values     | Signed Range                    | Unsigned Range    |
| ------------ | ------------------- | ------------------------------- | ----------------- |
| 8 (1 byte)   | 2⁸ = 256            | –128 → +127                     | 0 → 255           |
| 16 (2 bytes) | 2¹⁶ = 65,536        | –32,768 → +32,767               | 0 → 65,535        |
| 32 (4 bytes) | 2³² = 4,294,967,296 | –2,147,483,648 → +2,147,483,647 | 0 → 4,294,967,295 |
| 64 (8 bytes) | 2⁶⁴ = huge          | –9.22×10¹⁸ → +9.22×10¹⁸         | 0 → 1.84×10¹⁹     |

---

## 🏁 Final Summary

| Concept      | Meaning                                                   |
| ------------ | --------------------------------------------------------- |
| **Size**     | Amount of memory a data type occupies (in bytes).         |
| **Range**    | Minimum and maximum value representable within that size. |
| **Signed**   | Includes both negative and positive numbers.              |
| **Unsigned** | Only positive numbers (doubles the positive range).       |
| **Formula**  | Signed → –(2ⁿ⁻¹) to (2ⁿ⁻¹–1), Unsigned → 0 to (2ⁿ–1)      |
| **Tool**     | Use `sizeof()` to check size on your machine.             |

---