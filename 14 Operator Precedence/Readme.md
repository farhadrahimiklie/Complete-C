
---

# 🔹 **Operator Precedence and Associativity in C (Full Details)**

---

## 🧠 1. What Is Operator Precedence?

* **Operator precedence** determines the **order in which operators are evaluated** in an expression.
* Operators with **higher precedence** are evaluated **before operators with lower precedence**.

> Example:

```c
int a = 5 + 3 * 2; // Which operation happens first?
```

* `*` (multiplication) has **higher precedence** than `+`.
* So `3 * 2 = 6` happens first → `5 + 6 = 11`.

**Output:** `11`

---

## 🧠 2. What Is Associativity?

* **Associativity** defines the **direction in which operators of the same precedence are evaluated**.
* It can be:

  * **Left-to-right** (most operators)
  * **Right-to-left** (assignment, ternary, unary operators)

> Example:

```c
int a = 10, b = 5, c = 2;
int result = a - b - c;
```

* `-` is **left-to-right associative**, so:

  * First: `a - b = 5`
  * Then: `5 - c = 3`
* **Result:** `3`

---

## 🔹 3. Operator Precedence Table (Important Operators)

| Precedence | Operators                                      | Description                       | Associativity |               |               |
| ---------- | ---------------------------------------------- | --------------------------------- | ------------- | ------------- | ------------- |
| 1          | `()`                                           | Parentheses (grouping)            | Left to Right |               |               |
| 2          | `++`, `--`, `+` (unary), `-` (unary), `!`, `~` | Unary operators                   | Right to Left |               |               |
| 3          | `*`, `/`, `%`                                  | Multiplication, Division, Modulus | Left to Right |               |               |
| 4          | `+`, `-`                                       | Addition, Subtraction             | Left to Right |               |               |
| 5          | `<<`, `>>`                                     | Bitwise Shift                     | Left to Right |               |               |
| 6          | `<`, `<=`, `>`, `>=`                           | Relational                        | Left to Right |               |               |
| 7          | `==`, `!=`                                     | Equality / Inequality             | Left to Right |               |               |
| 8          | `&`                                            | Bitwise AND                       | Left to Right |               |               |
| 9          | `^`                                            | Bitwise XOR                       | Left to Right |               |               |
| 10         | `                                              | `                                 | Bitwise OR    | Left to Right |               |
| 11         | `&&`                                           | Logical AND                       | Left to Right |               |               |
| 12         | `                                              |                                   | `             | Logical OR    | Left to Right |
| 13         | `?:`                                           | Ternary Conditional               | Right to Left |               |               |
| 14         | `=`, `+=`, `-=`, `*=`, `/=`, `%=`              | Assignment operators              | Right to Left |               |               |
| 15         | `,`                                            | Comma operator                    | Left to Right |               |               |

---

## 🔹 4. Examples of Precedence

### Example 1: Arithmetic Operators

```c
#include <stdio.h>
int main() {
    int a = 5 + 3 * 2;
    printf("%d\n", a);  // 11
    return 0;
}
```

* `*` has **higher precedence than `+`**, so `3*2` evaluated first.

---

### Example 2: Parentheses Change Precedence

```c
#include <stdio.h>
int main() {
    int a = (5 + 3) * 2;
    printf("%d\n", a);  // 16
    return 0;
}
```

* Parentheses **override normal precedence**: `5+3=8`, then `8*2=16`.

---

### Example 3: Assignment and Arithmetic

```c
#include <stdio.h>
int main() {
    int a, b;
    a = b = 5 + 2;  // Right-to-left assignment
    printf("a = %d, b = %d\n", a, b); // 7, 7
    return 0;
}
```

* `5 + 2 = 7` calculated first
* Then `b = 7` → `a = b = 7`
* **Associativity matters** for assignment operators

---

### Example 4: Ternary and Arithmetic

```c
#include <stdio.h>
int main() {
    int a = 5, b = 10;
    int max = (a > b) ? a : b + 5;
    printf("max = %d\n", max);  // 15
    return 0;
}
```

* `b + 5` evaluated first due to **parentheses around ternary condition**
* Result: `15`

---

### Example 5: Unary and Arithmetic

```c
#include <stdio.h>
int main() {
    int a = 5;
    int b = ++a * 2;  // Pre-increment evaluated first
    printf("b = %d\n", b); // 12
    return 0;
}
```

* `++a = 6`, then `6*2 = 12`

---

## 🔹 5. Tips to Avoid Confusion

1. **Use parentheses** when in doubt → improves readability
2. Know **common precedence rules**:

   * `* / %` > `+ -`
   * Unary operators (`++`, `--`, `!`) > arithmetic
   * Logical AND `&&` > logical OR `||`
3. Remember **associativity rules** for assignments, ternary, unary

---

### 🏁 Summary

| Concept                   | Explanation                                                   |
| ------------------------- | ------------------------------------------------------------- |
| **Precedence**            | Which operator is evaluated first                             |
| **Associativity**         | Direction of evaluation if multiple same-precedence operators |
| **Parentheses**           | Override normal precedence                                    |
| **Unary operators**       | Have high precedence                                          |
| **Assignments & ternary** | Right-to-left associativity                                   |
| **Comma operator**        | Lowest precedence, evaluated last                             |

> ⚡ Tip: Always **use parentheses in complex expressions** to avoid mistakes and improve readability.

---