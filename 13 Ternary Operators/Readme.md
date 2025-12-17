# 🔹 **Ternary Operator in C (Full Details)**

---

## 🧠 1. What is the Ternary Operator?

* The **ternary operator** is the **only operator in C that takes three operands**.
* It is also called the **conditional operator**.
* It is used to **replace simple if-else statements** with a **single line expression**.

---

## 🔹 2. Syntax

```c
condition ? expression_if_true : expression_if_false;
```

* `condition` → a **boolean expression** (relational or logical operators can be used)
* `expression_if_true` → executed **if condition is true**
* `expression_if_false` → executed **if condition is false**

---

## 🔹 3. How It Works (Concept)

```
if (condition) {
    result = expression_if_true;
} else {
    result = expression_if_false;
}
```

is equivalent to:

```c
result = condition ? expression_if_true : expression_if_false;
```

> ✅ It **returns a value** based on the condition.

---

## 🔹 4. Example 1: Basic Ternary Operator

```c
#include <stdio.h>

int main() {
    int a = 10, b = 20;
    int max;

    max = (a > b) ? a : b;  // if a > b then max = a else max = b

    printf("Maximum = %d\n", max);
    return 0;
}
```

**Output:**

```
Maximum = 20
```

> ✅ Here, `(a > b)` is true → `max = b` otherwise `max = a`.

---

## 🔹 5. Example 2: Inline Ternary in printf

```c
#include <stdio.h>

int main() {
    int age = 18;

    printf("%s\n", (age >= 18) ? "Adult" : "Minor");

    return 0;
}
```

**Output:**

```
Adult
```

> ⚡ You can **use it directly** inside `printf`, `return`, or any expression.

---

## 🔹 6. Example 3: Nested Ternary Operator

* You can **nest ternary operators** to handle multiple conditions.

```c
#include <stdio.h>

int main() {
    int marks = 85;
    char grade;

    grade = (marks >= 90) ? 'A' :
            (marks >= 75) ? 'B' :
            (marks >= 60) ? 'C' : 'F';

    printf("Grade = %c\n", grade);
    return 0;
}
```

**Output:**

```
Grade = B
```

> ⚠️ Nested ternary can **reduce readability** if overused.
>
> * Use for **short multiple conditions**
> * Otherwise, stick to **if-else** for clarity

---

## 🔹 7. Key Points About Ternary Operator

1. **Takes three operands:**

   * condition ? value_if_true : value_if_false

2. **Returns a value**, so it can be **assigned to a variable**

3. **Can replace simple if-else statements**

4. **Nested ternary is allowed** but **readability decreases**

5. **Operators can be any type:** int, float, char, string (via printf)

---

### ⚡ 8. Example: Using Ternary for Even/Odd

```c
#include <stdio.h>

int main() {
    int num = 7;

    (num % 2 == 0) ? printf("Even\n") : printf("Odd\n");

    return 0;
}
```

**Output:**

```
Odd
```

---

### 🏁 Summary

| Feature          | Explanation                                |
| ---------------- | ------------------------------------------ |
| **Type**         | Conditional / Ternary operator             |
| **Syntax**       | `condition ? expr_if_true : expr_if_false` |
| **Operands**     | Three (condition, true value, false value) |
| **Return Value** | Yes, result of true or false expression    |
| **Use Case**     | Shorter alternative to if-else             |
| **Nested**       | Possible but reduce readability            |

> ⚡ Tip:
> Use ternary operator for **simple decisions**.
> For complex conditions, always use **if-else** for clarity.

---
