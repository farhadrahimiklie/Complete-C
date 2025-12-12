
---

# 🔹 **Operators in C (Full Detailed Explanation)**

Operators are **special symbols** that tell the compiler to **perform operations on variables and values**.

C operators are divided into several categories:

1. **Arithmetic Operators**
2. **Assignment Operators**
3. **Relational Operators**
4. **Logical Operators**
5. **Bitwise Operators**
6. **Unary Operators (Increment & Decrement)**

---

## 1️⃣ **Arithmetic Operators**

Used to perform **mathematical calculations**.

| Operator | Description    | Example | Output                                  |
| -------- | -------------- | ------- | --------------------------------------- |
| `+`      | Addition       | `a + b` | Sum of a and b                          |
| `-`      | Subtraction    | `a - b` | Difference of a and b                   |
| `*`      | Multiplication | `a * b` | Product                                 |
| `/`      | Division       | `a / b` | Quotient (integer division if both int) |
| `%`      | Modulus        | `a % b` | Remainder after division                |

### Example:

```c
#include <stdio.h>
int main() {
    int a = 10, b = 3;
    printf("a + b = %d\n", a + b);
    printf("a - b = %d\n", a - b);
    printf("a * b = %d\n", a * b);
    printf("a / b = %d\n", a / b);
    printf("a %% b = %d\n", a % b); // %% because % is special in printf
    return 0;
}
```

**Output:**

```
a + b = 13
a - b = 7
a * b = 30
a / b = 3
a % b = 1
```

> ⚠️ Note:
>
> * **Integer division** truncates decimal part.
> * To get decimal, at least one operand should be `float` or `double`.

---

## 2️⃣ **Assignment Operators**

Used to **assign values to variables**.

| Operator | Meaning             | Example                |
| -------- | ------------------- | ---------------------- |
| `=`      | Simple assignment   | `a = 5;`               |
| `+=`     | Add and assign      | `a += 5; // a = a + 5` |
| `-=`     | Subtract and assign | `a -= 3; // a = a - 3` |
| `*=`     | Multiply and assign | `a *= 2; // a = a * 2` |
| `/=`     | Divide and assign   | `a /= 2; // a = a / 2` |
| `%=`     | Modulus and assign  | `a %= 3; // a = a % 3` |

### Example:

```c
#include <stdio.h>
int main() {
    int a = 10;
    a += 5;   // a = 15
    a *= 2;   // a = 30
    a -= 10;  // a = 20
    printf("Final a = %d\n", a);
    return 0;
}
```

**Output:**

```
Final a = 20
```

---

## 3️⃣ **Relational Operators**

Used to **compare values**. They **return 1 (true) or 0 (false)**.

| Operator | Meaning               | Example  |
| -------- | --------------------- | -------- |
| `==`     | Equal to              | `a == b` |
| `!=`     | Not equal to          | `a != b` |
| `>`      | Greater than          | `a > b`  |
| `<`      | Less than             | `a < b`  |
| `>=`     | Greater than or equal | `a >= b` |
| `<=`     | Less than or equal    | `a <= b` |

### Example:

```c
#include <stdio.h>
int main() {
    int a = 10, b = 20;
    printf("a == b: %d\n", a == b); // 0 (false)
    printf("a != b: %d\n", a != b); // 1 (true)
    printf("a > b: %d\n", a > b);   // 0
    printf("a < b: %d\n", a < b);   // 1
    return 0;
}
```

---

## 4️⃣ **Logical Operators**

Used to combine **conditional statements**.

| Operator | Meaning     | Example  |            |    |   |    |
| -------- | ----------- | -------- | ---------- | -- | - | -- |
| `&&`     | Logical AND | `a && b` |            |    |   |    |
| `        |             | `        | Logical OR | `a |   | b` |
| `!`      | Logical NOT | `!a`     |            |    |   |    |

### Truth Table:

#### AND `&&`:

```
0 && 0 = 0
0 && 1 = 0
1 && 0 = 0
1 && 1 = 1
```

#### OR `||`:

```
0 || 0 = 0
0 || 1 = 1
1 || 0 = 1
1 || 1 = 1
```

#### NOT `!`:

```
!0 = 1
!1 = 0
```

### Example:

```c
#include <stdio.h>
int main() {
    int a = 1, b = 0;
    printf("a && b = %d\n", a && b); // 0
    printf("a || b = %d\n", a || b); // 1
    printf("!a = %d\n", !a);         // 0
    return 0;
}
```

---

## 5️⃣ **Bitwise Operators**

Used to perform operations **at the bit level**.

| Operator | Meaning     | Example  |    |    |
| -------- | ----------- | -------- | -- | -- |
| `&`      | AND         | `a & b`  |    |    |
| `        | `           | OR       | `a | b` |
| `^`      | XOR         | `a ^ b`  |    |    |
| `~`      | NOT         | `~a`     |    |    |
| `<<`     | Left shift  | `a << 2` |    |    |
| `>>`     | Right shift | `a >> 2` |    |    |

### Example:

```c
#include <stdio.h>
int main() {
    int a = 5;  // 0101 in binary
    int b = 3;  // 0011 in binary

    printf("a & b = %d\n", a & b);  // 1
    printf("a | b = %d\n", a | b);  // 7
    printf("a ^ b = %d\n", a ^ b);  // 6
    printf("~a = %d\n", ~a);        // -6
    printf("a << 1 = %d\n", a << 1); // 10
    printf("a >> 1 = %d\n", a >> 1); // 2
    return 0;
}
```

---

## 6️⃣ **Unary Operators: Increment `++` & Decrement `--`**

### **A. Increment `++`**

* Increases variable by 1
* Two types:

  1. **Pre-increment:** `++a` → increment first, then use
  2. **Post-increment:** `a++` → use first, then increment

### **B. Decrement `--`**

* Decreases variable by 1
* Two types:

  1. **Pre-decrement:** `--a` → decrement first, then use
  2. **Post-decrement:** `a--` → use first, then decrement

### Example:

```c
#include <stdio.h>
int main() {
    int a = 5;
    printf("Pre-increment: %d\n", ++a); // 6
    a = 5;
    printf("Post-increment: %d\n", a++); // 5
    printf("Now a = %d\n", a);           // 6

    a = 5;
    printf("Pre-decrement: %d\n", --a); // 4
    a = 5;
    printf("Post-decrement: %d\n", a--); // 5
    printf("Now a = %d\n", a);          // 4
    return 0;
}
```

---

## ✅ **Summary of Operators**

| Type       | Operators          | Purpose             |                 |                    |
| ---------- | ------------------ | ------------------- | --------------- | ------------------ |
| Arithmetic | `+ - * / %`        | Math operations     |                 |                    |
| Assignment | `= += -= *= /= %=` | Assign values       |                 |                    |
| Relational | `== != > < >= <=`  | Compare values      |                 |                    |
| Logical    | `&&                |                     | !`              | Combine conditions |
| Bitwise    | `&                 | ^ ~ << >>`          | Operate on bits |                    |
| Unary      | `++ --`            | Increment/decrement |                 |                    |

> ⚡ Tip:
>
> * Use **bitwise operators** for **low-level optimization**.
> * **Logical operators** are mostly for **conditional statements**.
> * **Unary operators** are very useful in **loops and counters**.

---
