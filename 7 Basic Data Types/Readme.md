# 🧠 What Are Data Types in C?

A **data type** defines:

> The *type of data* a variable can store, and
> The *amount of memory* required to store that data.

Every variable in C must have a **data type**, which tells the compiler:

* How much memory to allocate.
* What kind of data (integer, character, floating-point, etc.) it will hold.
* How to interpret that data in expressions.

---

## 🧩 Types of Data in C

C is a **strongly typed** language — it has a rich set of data types.

The C data types are broadly divided into three main categories:

| Category                       | Examples                                             |
| ------------------------------ | ---------------------------------------------------- |
| **Primary (Basic) Data Types** | `int`, `float`, `char`, `double`, `void`             |
| **Derived Data Types**         | `array`, `pointer`, `structure`, `union`, `function` |
| **User-Defined Data Types**    | `typedef`, `enum`, `struct`, `union`                 |

In this lesson, we’ll focus on the **Basic (Primary) Data Types** — the foundation of all others.

---

# 🧱 Basic (Primary) Data Types in C

| Data Type            | Keyword  | Memory Size (Typical) | Range (Approximate)                         | Description                                   |
| -------------------- | -------- | --------------------- | ------------------------------------------- | --------------------------------------------- |
| **Integer**          | `int`    | 4 bytes               | –2,147,483,648 to 2,147,483,647             | Stores whole numbers (no decimal)             |
| **Character**        | `char`   | 1 byte                | –128 to 127 (signed) or 0 to 255 (unsigned) | Stores a single character                     |
| **Floating Point**   | `float`  | 4 bytes               | ±3.4 × 10⁻³⁸ to ±3.4 × 10³⁸                 | Stores decimal (fractional) numbers           |
| **Double Precision** | `double` | 8 bytes               | ±1.7 × 10⁻³⁰⁸ to ±1.7 × 10³⁰⁸               | Stores large decimal numbers (more precision) |
| **Void**             | `void`   | 0 bytes               | —                                           | Represents no value / no type                 |

> ⚠️ Note: The size of data types may vary slightly depending on the compiler and system architecture (e.g., 16-bit, 32-bit, 64-bit).

---

## 🧩 1. `int` — Integer Type

Used to store **whole numbers** (positive, negative, or zero).
It does **not store fractional or decimal** values.

### Example:

```c
#include <stdio.h>
int main() {
    int age = 25;
    int year = 2025;
    printf("Age: %d\nYear: %d\n", age, year);
    return 0;
}
```

### 📏 Typical Memory Size:

* Usually **4 bytes** (on most modern compilers).

### ⚙️ Range:

* **Signed int:** –2,147,483,648 to 2,147,483,647
* **Unsigned int:** 0 to 4,294,967,295

### 🧩 Variants of int:

| Type                 | Size         | Range (approx.)                           |
| -------------------- | ------------ | ----------------------------------------- |
| `short int`          | 2 bytes      | –32,768 to 32,767                         |
| `unsigned short int` | 2 bytes      | 0 to 65,535                               |
| `long int`           | 4 or 8 bytes | –2,147,483,648 to 2,147,483,647 (or more) |
| `unsigned long int`  | 4 or 8 bytes | 0 to 4,294,967,295 (or more)              |

---

## 🧩 2. `char` — Character Type

Used to store a **single character** like `'A'`, `'b'`, `'1'`, or special characters like `'@'`.

### Example:

```c
#include <stdio.h>
int main() {
    char grade = 'A';
    printf("Your grade is: %c\n", grade);
    return 0;
}
```

### 📏 Memory Size:

* **1 byte**

### ⚙️ Range:

* **Signed char:** –128 to 127
* **Unsigned char:** 0 to 255

> Characters in C are stored using **ASCII values** (numerical codes).
> For example:
>
> * `'A'` = 65
> * `'B'` = 66
> * `'a'` = 97

### Example:

```c
#include <stdio.h>
int main() {
    char letter = 'A';
    printf("Character: %c\n", letter);
    printf("ASCII Value: %d\n", letter);
    return 0;
}
```

---

## 🧩 3. `float` — Floating Point Type

Used to store **real numbers** (numbers with decimal points).

### Example:

```c
#include <stdio.h>
int main() {
    float price = 9.99;
    float pi = 3.14159;
    printf("Price: %.2f\nPI: %.5f\n", price, pi);
    return 0;
}
```

### 📏 Memory Size:

* **4 bytes**

### ⚙️ Range:

* ±3.4 × 10⁻³⁸ to ±3.4 × 10³⁸

### ⚙️ Precision:

* Up to **6 decimal places**

---

## 🧩 4. `double` — Double Precision Floating Point

Used for **large or more precise** floating-point numbers.

### Example:

```c
#include <stdio.h>
int main() {
    double distance = 123456.789123;
    printf("Distance: %lf\n", distance);
    return 0;
}
```

### 📏 Memory Size:

* **8 bytes**

### ⚙️ Range:

* ±1.7 × 10⁻³⁰⁸ to ±1.7 × 10³⁰⁸

### ⚙️ Precision:

* Up to **15–16 decimal places**

### 🔹 `long double`

For even higher precision.

| Type          | Size        | Precision  |
| ------------- | ----------- | ---------- |
| `float`       | 4 bytes     | ~6 digits  |
| `double`      | 8 bytes     | ~15 digits |
| `long double` | 10–16 bytes | ~19 digits |

---

## 🧩 5. `void` — Empty Data Type

`void` means **nothing** — no value, no type.
It’s used in three main ways:

### 🔹 1. Function with no return value

```c
void sayHello() {
    printf("Hello, Farhad!\n");
}
```

### 🔹 2. Function with no parameters

```c
void greet(void) {
    printf("Hi!\n");
}
```

### 🔹 3. Void pointers (advanced)

A pointer that can point to any data type:

```c
void *ptr;
int a = 10;
ptr = &a;
printf("%d", *(int *)ptr); // Typecasting required
```

---

# ⚙️ Format Specifiers in `printf()` and `scanf()`

Each data type has a **format specifier** used with `printf()` and `scanf()`.

| Data Type      | Format Specifier (printf/scanf) | Example                 |
| -------------- | ------------------------------- | ----------------------- |
| `int`          | `%d` / `%i`                     | `printf("%d", x);`      |
| `char`         | `%c`                            | `printf("%c", ch);`     |
| `float`        | `%f`                            | `printf("%f", price);`  |
| `double`       | `%lf`                           | `printf("%lf", dist);`  |
| `long int`     | `%ld`                           | `printf("%ld", value);` |
| `unsigned int` | `%u`                            | `printf("%u", num);`    |

---

# 📦 Example: Using All Data Types

```c
#include <stdio.h>

int main() {
    int age = 21;
    char grade = 'A';
    float height = 5.9;
    double salary = 12345.67;

    printf("Age: %d\n", age);
    printf("Grade: %c\n", grade);
    printf("Height: %.1f\n", height);
    printf("Salary: %.2lf\n", salary);

    return 0;
}
```

---

# 🧠 Summary Table

| Data Type | Size    | Range                           | Format Specifier | Example               |
| --------- | ------- | ------------------------------- | ---------------- | --------------------- |
| `char`    | 1 byte  | –128 to 127                     | `%c`             | `char c = 'A';`       |
| `int`     | 4 bytes | –2,147,483,648 to 2,147,483,647 | `%d`             | `int a = 100;`        |
| `float`   | 4 bytes | ±3.4×10⁻³⁸ to ±3.4×10³⁸         | `%f`             | `float pi = 3.14;`    |
| `double`  | 8 bytes | ±1.7×10⁻³⁰⁸ to ±1.7×10³⁰⁸       | `%lf`            | `double x = 123.456;` |
| `void`    | 0 bytes | —                               | —                | `void func() {}`      |

---

# 🧩 Bonus: Type Modifiers

C allows you to modify basic data types to change their **range and storage size** using **modifiers**:

| Modifier   | Meaning                                           |
| ---------- | ------------------------------------------------- |
| `short`    | Decreases storage size                            |
| `long`     | Increases storage size                            |
| `signed`   | Allows both positive and negative values          |
| `unsigned` | Only positive values (doubles max positive range) |

### Example:

```c
short int a;
long int b;
unsigned int c;
```

---

# 🏁 Final Summary

✅ **Basic Data Types in C:**

* `int`, `char`, `float`, `double`, `void`
  ✅ **Modifiers:**
* `short`, `long`, `signed`, `unsigned`
  ✅ **Purpose:**
* Defines how much memory to allocate and what kind of values can be stored.

---
