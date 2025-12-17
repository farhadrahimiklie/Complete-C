# 🔹 **Loops in C (Full Details)**

---

## 🧠 1. What Is a Loop?

* A **loop** is a **control flow statement** that executes a block of code **repeatedly** while a condition is **true**.
* Loops are used for **repetitive tasks** like iteration over arrays, counting, and input/output operations.

---

## 🔹 2. Types of Loops in C

1. **`for` loop** → Count-controlled loop
2. **`while` loop** → Condition-controlled loop (entry controlled)
3. **`do-while` loop** → Condition-controlled loop (exit controlled)
4. **Nested loops** → Loops inside loops

---

## 🔹 3. The `for` Loop

### Syntax

```c
for(initialization; condition; increment/decrement) {
    // code block to be executed
}
```

* **Initialization** → executed **once** at the start
* **Condition** → evaluated **before each iteration**; loop continues if true
* **Increment/Decrement** → executed **after each iteration**

---

### Example 1: Basic For Loop

```c
#include <stdio.h>

int main() {
    int i;
    for(i = 1; i <= 5; i++) {
        printf("%d\n", i);
    }
    return 0;
}
```

**Output:**

```
1
2
3
4
5
```

> ✅ Explanation:

* Start `i = 1`
* Check `i <= 5` → true
* Execute `printf` → increment `i++` → repeat

---

### Example 2: For Loop Counting Backwards

```c
for(int i = 5; i >= 1; i--) {
    printf("%d\n", i);
}
```

**Output:**

```
5
4
3
2
1
```

---

## 🔹 4. The `while` Loop

### Syntax

```c
while(condition) {
    // code block to be executed
}
```

* **Condition** is checked **before** the loop executes
* If **condition is false initially**, the loop **never executes**

---

### Example 1: Basic While Loop

```c
#include <stdio.h>

int main() {
    int i = 1;
    while(i <= 5) {
        printf("%d\n", i);
        i++; // increment
    }
    return 0;
}
```

**Output:**

```
1
2
3
4
5
```

---

### Example 2: Infinite While Loop

```c
while(1) {
    printf("Infinite loop\n");
}
```

* ⚠️ Use **`break`** to exit:

```c
int i = 1;
while(1) {
    printf("%d\n", i);
    if(i == 5) break;
    i++;
}
```

---

## 🔹 5. The `do-while` Loop

### Syntax

```c
do {
    // code block to be executed
} while(condition);
```

* Executes **the code block first**, then checks the condition
* Ensures **loop executes at least once**

---

### Example 1: Basic Do-While Loop

```c
#include <stdio.h>

int main() {
    int i = 1;
    do {
        printf("%d\n", i);
        i++;
    } while(i <= 5);

    return 0;
}
```

**Output:**

```
1
2
3
4
5
```

> ✅ Key difference from `while`: **executed at least once**.

---

### Example 2: Do-While Executes Once Even If Condition Is False

```c
int i = 10;
do {
    printf("%d\n", i);
} while(i < 5);
```

**Output:**

```
10
```

* Condition `i < 5` is false, but **loop executes once**.

---

## 🔹 6. Nested Loops

* **Loops inside loops** are called nested loops.
* Often used for **matrices, patterns, and tables**.

### Example: Nested For Loop

```c
#include <stdio.h>

int main() {
    int i, j;
    for(i = 1; i <= 3; i++) {
        for(j = 1; j <= 3; j++) {
            printf("%d ", j);
        }
        printf("\n");
    }
    return 0;
}
```

**Output:**

```
1 2 3
1 2 3
1 2 3
```

---

## 🔹 7. Using `break` and `continue`

### `break`

* Exits **entire loop** immediately

```c
for(int i = 1; i <= 5; i++) {
    if(i == 3) break;
    printf("%d\n", i);
}
```

**Output:**

```
1
2
```

### `continue`

* Skips **current iteration**, continues with next

```c
for(int i = 1; i <= 5; i++) {
    if(i == 3) continue;
    printf("%d\n", i);
}
```

**Output:**

```
1
2
4
5
```

---

## 🔹 8. Infinite Loops

* Can be created using `for`, `while`, or `do-while`:

```c
for(;;) { printf("Infinite loop\n"); }    // for
while(1) { printf("Infinite loop\n"); }   // while
do { printf("Infinite loop\n"); } while(1); // do-while
```

* Use **`break`** to exit

---

## 🔹 9. Summary Table

| Loop Type    | Syntax                 | Condition Checked           | Executes At Least Once? | Use Case                   |
| ------------ | ---------------------- | --------------------------- | ----------------------- | -------------------------- |
| `for`        | `for(init; cond; inc)` | Before each iteration       | No                      | Count-controlled loops     |
| `while`      | `while(cond)`          | Before each iteration       | No                      | Condition-controlled loops |
| `do-while`   | `do {} while(cond)`    | After each iteration        | Yes                     | Run at least once          |
| Nested loops | Loop inside loop       | Before each inner iteration | Depends on loop type    | Matrices, patterns         |

---

### ⚡ Key Tips for Loops

1. **Always initialize loop variables**
2. **Ensure condition eventually becomes false** → avoids infinite loops
3. **Use break/continue wisely** for control
4. **Nested loops** can increase complexity → optimize if needed
5. **`for` is ideal for count-controlled loops**, `while` for unknown iterations, `do-while` when execution **at least once is needed**

---
