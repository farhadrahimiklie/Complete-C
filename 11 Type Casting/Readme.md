# 🔹 **Type Casting in C (Full Details)**

---

## 🧠 1. What Is Type Casting?

**Type casting** is the process of **converting a variable from one data type to another**.

> In simple words:
> “Change the type of data temporarily or permanently to another type.”

### Example Concept:

```c
int x = 10;
float y = (float)x;  // convert int to float
```

* `x` is **int**, `y` becomes **float**
* Conversion can be **explicit** (by programmer) or **implicit** (by compiler)

---

## 🧩 2. Types of Type Casting in C

There are **two main types**:

1. **Implicit Type Casting (Type Conversion)**
2. **Explicit Type Casting (Type Casting)**

---

### 🔹 2.1 Implicit Type Casting (Type Conversion)

* Done **automatically by C compiler**.
* Converts **smaller types to larger types** to avoid data loss.
* Also called **“type promotion”**.

#### Rules:

* `char` → `int` → `long` → `float` → `double`
* `int` → `float` (can store decimal)
* `float` → `double` (more precision)

#### Example:

```c
#include <stdio.h>

int main() {
    int a = 5;
    float b;
    b = a;  // implicit conversion from int to float

    printf("a = %d\n", a);
    printf("b = %.2f\n", b);  // prints 5.00
    return 0;
}
```

* Compiler **automatically converts** `int` → `float`.
* No programmer action needed.

#### Key Points:

* **Safe conversion:** smaller → larger
* **Automatic type promotion** occurs in **expressions**

Example with expression:

```c
int a = 5;
float b = 2.5;
float c = a + b;  // a is promoted to float automatically
```

---

### 🔹 2.2 Explicit Type Casting

* Done **manually by the programmer**.
* Also called **“type casting”**.
* Syntax:

```c
(type) expression
```

* `(type)` = target data type
* `expression` = value or variable to convert

#### Example: Int → Float

```c
#include <stdio.h>

int main() {
    int a = 5;
    float b = (float)a;  // explicit casting

    printf("a = %d\n", a);
    printf("b = %.2f\n", b);
    return 0;
}
```

* `(float)a` converts `int` to `float` **explicitly**.

#### Example: Float → Int

```c
#include <stdio.h>

int main() {
    float x = 9.99;
    int y = (int)x;  // decimal truncated

    printf("x = %.2f\n", x);
    printf("y = %d\n", y);  // prints 9
    return 0;
}
```

> ✅ Important:
>
> * Decimal part **is truncated**, not rounded
> * `float` → `int` can cause **data loss**

---

## 🔹 3. Type Casting Between Different Data Types

| From               | To                  | Effect / Notes                  |
| ------------------ | ------------------- | ------------------------------- |
| `int` → `float`    | safe                | fractional part added (5 → 5.0) |
| `float` → `int`    | data loss           | decimal truncated (5.99 → 5)    |
| `char` → `int`     | safe                | ASCII value used (`'A' → 65`)   |
| `int` → `char`     | may cause data loss | only 1 byte stored              |
| `long` → `int`     | may overflow        | depends on value size           |
| `int` → `double`   | safe                | more precision                  |
| `double` → `float` | may lose precision  | rounding may occur              |

---

### 🔹 4. Type Casting in Expressions

* When **different types** are used in one expression, C **automatically promotes** smaller type to larger type.

#### Example:

```c
#include <stdio.h>

int main() {
    int a = 5;
    float b = 2.5;
    float result;

    result = a + b;        // a promoted to float automatically
    printf("Result = %.2f\n", result);
    return 0;
}
```

* Output: `Result = 7.50`
* `int a` promoted to `float` → **implicit type casting**

---

### 🔹 5. Type Casting with Pointers (Advanced)

* You can cast **pointers** from one type to another.
* Example: `void *` → `int *`

```c
#include <stdio.h>

int main() {
    int a = 100;
    void *ptr = &a;         // void pointer
    int *intPtr = (int *)ptr; // explicit cast

    printf("%d\n", *intPtr); // prints 100
    return 0;
}
```

> ✅ Key point: **Always typecast void pointers before dereferencing.**

---

### 🔹 6. Type Casting Rules in C

1. **Avoid converting large type to small type** if it causes overflow.
2. **Decimal to integer** → truncation occurs.
3. **Char to int** → ASCII code used.
4. **Pointers must be cast properly** before use.

---

### 🔹 7. Practical Examples

#### Example 1: Int → Float → Double

```c
int a = 10;
float b = (float)a;
double c = (double)b;

printf("%d, %.2f, %.2lf\n", a, b, c);
```

#### Example 2: Float → Int

```c
float x = 9.99;
int y = (int)x;  // truncates decimal
printf("x = %.2f, y = %d\n", x, y);
```

#### Example 3: Char → Int

```c
char ch = 'A';
int code = (int)ch;
printf("%c ASCII = %d\n", ch, code);
```

Output:

```
A ASCII = 65
```

---

### 🏁 8. Summary

| Concept                | Explanation                                           |
| ---------------------- | ----------------------------------------------------- |
| **Implicit Casting**   | Done automatically by compiler; smaller → larger type |
| **Explicit Casting**   | Done manually by programmer; `(type)expression`       |
| **Float → Int**        | Decimal truncated, data loss possible                 |
| **Pointer Casting**    | `void *` → specific pointer type                      |
| **Expression Casting** | Smaller type promoted to larger type automatically    |

> ⚡ Key Tip: Always **cast explicitly** when data loss is possible or pointer types differ.

---
