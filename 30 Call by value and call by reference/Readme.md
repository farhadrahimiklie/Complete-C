
---

# 🔹 **Call by Value and Call by Reference in C – Full Details**

---

## 🧠 1. What is “Passing Arguments to Functions”?

When a function is called, **values are passed to it as arguments**.

* How these values are passed determines whether changes inside the function **affect the original variables** or not.
* There are **two main ways** to pass arguments:

1. **Call by Value**
2. **Call by Reference**

---

## 🔹 2. Call by Value

### 2.1 Definition

* **Call by Value (CBV)** passes a **copy of the actual value** to the function.
* Changes inside the function **do NOT affect the original variable**.
* Default behavior in C for all basic data types.

### 2.2 Syntax

```c
#include <stdio.h>

void increment(int x) { // x is parameter (copy)
    x = x + 1;
    printf("Inside function: %d\n", x);
}

int main() {
    int num = 5;       // original variable
    increment(num);    // pass by value
    printf("In main: %d\n", num);
    return 0;
}
```

**Output:**

```
Inside function: 6
In main: 5
```

**Observation:**

* `x` inside function is a **copy** of `num`.
* Changing `x` **does not change `num`**.

### 2.3 Memory Behavior

```
Main Function (Stack)
+--------+
| num=5  |
+--------+

Function Call (Stack)
+--------+
| x=5    |
+--------+
```

* Two separate memory locations → **modification in function does not affect original**.

---

### 2.4 Advantages of Call by Value

1. Safe → original data cannot be accidentally modified.
2. Simple → default method in C.

### 2.5 Disadvantages

* **Cannot modify original data**.
* Passing **large structures/arrays** → inefficient (copies entire data).

---

## 🔹 3. Call by Reference

### 3.1 Definition

* **Call by Reference (CBR)** passes the **address of the original variable** to the function.
* Changes inside the function **directly affect the original variable**.
* Achieved using **pointers** in C.

### 3.2 Syntax

```c
#include <stdio.h>

void increment(int *x) { // pointer parameter
    *x = *x + 1;         // modify value at address
    printf("Inside function: %d\n", *x);
}

int main() {
    int num = 5;
    increment(&num);      // pass address
    printf("In main: %d\n", num);
    return 0;
}
```

**Output:**

```
Inside function: 6
In main: 6
```

**Observation:**

* `*x` directly accesses the memory of `num`.
* Modification inside function **changes original variable**.

---

### 3.3 Memory Behavior

```
Main Function (Stack)
+--------+
| num=5  |
+--------+

Function Call (Stack)
+--------+
| x -> num (same address)
+--------+
```

* Both `x` and `num` **point to same memory location**.
* Changes in function **affect the original variable**.

---

### 3.4 Advantages of Call by Reference

1. Can modify original variable.
2. Efficient for **large data structures or arrays** → no need to copy entire data.

### 3.5 Disadvantages

1. Risky → can accidentally modify data.
2. Requires knowledge of **pointers**.

---

## 🔹 4. Call by Value vs Call by Reference (Comparison Table)

| Feature           | Call by Value         | Call by Reference             |
| ----------------- | --------------------- | ----------------------------- |
| What is passed    | Copy of variable      | Address of variable (pointer) |
| Original variable | Not changed           | Can be changed                |
| Memory usage      | Extra memory for copy | Efficient (no copy)           |
| Safety            | Safe                  | Risky, can modify original    |
| Syntax            | `func(num)`           | `func(&num)`                  |
| Pointer needed    | No                    | Yes                           |

---

## 🔹 5. Special Cases

### 5.1 Arrays

* In C, **arrays are always passed by reference** (actually, pointer to first element) by default.

```c
#include <stdio.h>
void modify(int arr[], int size) {
    arr[0] = 100;
}
int main() {
    int a[3] = {1,2,3};
    modify(a, 3);
    printf("%d\n", a[0]); // 100
    return 0;
}
```

### 5.2 Structures

* Can be passed by **value** (copy entire structure) → inefficient.
* Can be passed by **reference** (pointer to structure) → efficient and modifiable.

---

## 🔹 6. Summary / Key Points

1. **Call by Value** → function works with a **copy**, original data safe.
2. **Call by Reference** → function works with **original memory**, data can change.
3. Use **call by value** for **basic variables** if you don’t want them changed.
4. Use **call by reference** for **large structures, arrays, or when modification needed**.
5. In C, **pointers are essential** for call by reference.
6. Arrays are **naturally passed by reference**.

---

Farhad, in **simple analogy**:

* **Call by Value** → giving someone a **photocopy** of your homework. They can change it, but your original is safe.
* **Call by Reference** → giving someone your **actual homework**. Changes they make will **affect your original**.

---
