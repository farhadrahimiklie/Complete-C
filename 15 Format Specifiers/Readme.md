# 🔹 **Format Specifiers in C (Full Details)**

---

## 🧠 1. What Are Format Specifiers?

* **Format specifiers** are **placeholders** used in **`printf()`** and **`scanf()`** to **tell the compiler the type of variable** to print or read.
* They **match the variable type** so that the compiler can **correctly interpret the data**.

> Example:

```c
int a = 10;
printf("Value of a = %d\n", a);
```

* `%d` tells `printf()` that the variable `a` is **an integer**.

---

## 🔹 2. Format Specifiers for `printf()` and `scanf()`

| Specifier | Type                                  | Example                                     |
| --------- | ------------------------------------- | ------------------------------------------- |
| `%d`      | Signed decimal integer                | `int a = 10; printf("%d", a);`              |
| `%i`      | Signed decimal integer (same as `%d`) | `int a = 10; printf("%i", a);`              |
| `%u`      | Unsigned integer                      | `unsigned int a = 10; printf("%u", a);`     |
| `%f`      | Float                                 | `float x = 3.14; printf("%f", x);`          |
| `%lf`     | Double                                | `double y = 3.14159; printf("%lf", y);`     |
| `%c`      | Character                             | `char ch = 'A'; printf("%c", ch);`          |
| `%s`      | String                                | `char str[] = "Farhad"; printf("%s", str);` |
| `%p`      | Pointer (memory address)              | `int *ptr = &a; printf("%p", ptr);`         |
| `%o`      | Octal (base 8)                        | `int a = 8; printf("%o", a);`               |
| `%x`      | Hexadecimal (lowercase)               | `int a = 15; printf("%x", a);`              |
| `%X`      | Hexadecimal (uppercase)               | `int a = 15; printf("%X", a);`              |
| `%%`      | Percent sign                          | `printf("%%");` prints `%`                  |

---

## 🔹 3. Examples of Format Specifiers

### Example 1: Integer

```c
#include <stdio.h>
int main() {
    int a = 10;
    printf("Integer a = %d\n", a);
    return 0;
}
```

**Output:**

```
Integer a = 10
```

### Example 2: Float and Double

```c
#include <stdio.h>
int main() {
    float f = 3.14;
    double d = 9.876543;
    printf("Float f = %f\n", f);
    printf("Double d = %lf\n", d);
    return 0;
}
```

**Output:**

```
Float f = 3.140000
Double d = 9.876543
```

> ⚠️ Note: `%f` prints **6 decimal places by default**.

---

### Example 3: Character and String

```c
#include <stdio.h>
int main() {
    char ch = 'A';
    char str[] = "Farhad";
    printf("Character = %c\n", ch);
    printf("String = %s\n", str);
    return 0;
}
```

**Output:**

```
Character = A
String = Farhad
```

---

### Example 4: Hexadecimal, Octal, and Unsigned

```c
#include <stdio.h>
int main() {
    int a = 255;
    printf("Octal = %o\n", a);
    printf("Hexadecimal = %x\n", a);
    printf("Unsigned = %u\n", a);
    return 0;
}
```

**Output:**

```
Octal = 377
Hexadecimal = ff
Unsigned = 255
```

---

### Example 5: Pointer

```c
#include <stdio.h>
int main() {
    int a = 10;
    int *ptr = &a;
    printf("Address of a = %p\n", ptr);
    return 0;
}
```

**Output:** (example, varies each run)

```
Address of a = 0x7ffee4c9a98c
```

---

## 🔹 4. Format Specifiers in `scanf()`

* In **`scanf()`**, the **same format specifiers are used**, but you must provide the **address of the variable** using `&` (except for strings).

### Example:

```c
#include <stdio.h>
int main() {
    int a;
    float f;
    char ch;
    char str[20];

    printf("Enter integer: ");
    scanf("%d", &a);

    printf("Enter float: ");
    scanf("%f", &f);

    printf("Enter character: ");
    scanf(" %c", &ch);  // notice space before %c

    printf("Enter string: ");
    scanf("%s", str);

    printf("You entered: %d, %.2f, %c, %s\n", a, f, ch, str);
    return 0;
}
```

> ⚠️ Note:
>
> * For `%c`, **use a space before %c** to consume leftover newline.
> * For `%s`, no `&` is needed because string names are **pointers**.

---

## 🔹 5. Special Notes

1. `%f` → float, `%lf` → double (important in `scanf`)
2. `%%` → prints `%` symbol
3. Always **match the format specifier with variable type** to avoid **undefined behavior**
4. You can **control decimal places** using precision:

```c
float f = 3.14159;
printf("%.2f\n", f);  // prints 3.14
```

---

### 🏁 Summary of Format Specifiers

| Specifier   | Type         | Usage                     |
| ----------- | ------------ | ------------------------- |
| `%d` / `%i` | int          | Signed integer            |
| `%u`        | unsigned int | Unsigned integer          |
| `%f`        | float        | Floating-point number     |
| `%lf`       | double       | Double precision number   |
| `%c`        | char         | Single character          |
| `%s`        | char array   | String                    |
| `%p`        | pointer      | Memory address            |
| `%o`        | int          | Octal number              |
| `%x` / `%X` | int          | Hexadecimal (lower/upper) |
| `%%`        | —            | Percent symbol            |

---
