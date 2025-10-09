
---

# 🔹 **Types of Errors in C**

Errors in C can be broadly classified into **three main categories**:

---

## 1️⃣ **Syntax Errors (Compile-Time Errors)**

### Definition:

* Occur when the **rules of the C language** are violated.
* Detected by the **compiler** before the program runs.

### Examples of Syntax Errors:

1. **Missing semicolon**

```c
#include <stdio.h>
int main() {
    printf("Hello World") // ❌ missing ;
    return 0;
}
```

**Compiler Output:**

```
error: expected ';' before 'return'
```

2. **Mismatched braces**

```c
int main() {
    printf("Hi");
```

* Compiler will say **expected '}' before end of file**.

3. **Misspelled keywords**

```c
int mian() { // ❌ should be main
    return 0;
}
```

**Key Points:**

* **Detected at compile time**
* Must fix before program can run
* Usually the easiest errors to solve

---

## 2️⃣ **Runtime Errors**

### Definition:

* Errors that occur **while the program is running**.
* Usually caused by **invalid operations or illegal memory access**.

### Common Runtime Errors:

1. **Division by Zero**

```c
int a = 5, b = 0;
printf("%d", a / b); // ❌ runtime error
```

2. **Invalid Memory Access (Segmentation Fault)**

```c
int *ptr = NULL;
*ptr = 10; // ❌ runtime error
```

3. **Stack Overflow**

```c
void recurse() {
    recurse(); // ❌ infinite recursion
}
int main() {
    recurse();
    return 0;
}
```

**Key Points:**

* Detected **only when the program runs**
* Can **crash the program**
* Often harder to find than syntax errors

---

## 3️⃣ **Logical Errors**

### Definition:

* Program runs successfully, **but produces wrong output**.
* The **logic or algorithm** is incorrect.

### Example:

```c
int sum(int a, int b) {
    return a - b; // ❌ should be a + b
}
int main() {
    printf("%d", sum(5, 3)); // Output: 2 ❌ wrong
    return 0;
}
```

**Key Points:**

* Compiler **cannot detect** these errors
* Requires careful **testing and debugging**
* Often subtle and hardest to find

---

# 🔹 **Using `assert` in C**

### 1️⃣ **Definition**

* `assert()` is used to **test assumptions in your code**.
* If the condition inside `assert()` is false, the program **stops immediately** and shows an error message.

### 2️⃣ **Include Header**

```c
#include <assert.h>
```

### 3️⃣ **Syntax**

```c
assert(expression);
```

* **expression** → must evaluate to **true (non-zero)** or **false (zero)**
* If **false**, program aborts with **file and line number**

### 4️⃣ **Example**

```c
#include <stdio.h>
#include <assert.h>

int main() {
    int x = -5;
    assert(x > 0); // ❌ will fail
    printf("x is positive\n");
    return 0;
}
```

**Output:**

```
a.out: test.c:6: main: Assertion `x > 0' failed.
Aborted (core dumped)
```

* Useful for **debugging and validating assumptions**.

---

### 5️⃣ **Advantages of `assert`**

1. **Detect errors early** → during development
2. **Helps with debugging** → shows file and line number
3. **Documents assumptions** in your code

---

### 6️⃣ **Disabling `assert` in Production**

* By defining `NDEBUG` before including `assert.h`, all assertions are **ignored**.

```c
#define NDEBUG
#include <assert.h>
```

* Useful to **avoid performance overhead** in production code.

---

## 🔹 **Summary Table of Error Types**

| Error Type    | When Detected | Cause                 | Example                        |
| ------------- | ------------- | --------------------- | ------------------------------ |
| Syntax Error  | Compile-time  | Violation of C rules  | Missing semicolon              |
| Runtime Error | Run-time      | Illegal operations    | Division by zero, NULL pointer |
| Logical Error | Run-time      | Wrong logic/algorithm | Using `-` instead of `+`       |

---

Farhad, in simple words:

> * **Syntax errors** → compiler catches it
> * **Runtime errors** → program crashes during execution
> * **Logical errors** → program runs but gives wrong results
> * **assert()** → helps detect wrong assumptions early, useful for debugging

---
