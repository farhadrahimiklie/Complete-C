# 🔹 **Recursive Functions in C – Full Details**

---

## 🧠 1. What is a Recursive Function?

* A **recursive function** is a function that **calls itself directly or indirectly** to solve a problem.
* Recursion is often used when a problem can be **broken into smaller, similar subproblems**.

**Example Conceptual Analogy:**

* Russian dolls → open one doll, inside is another smaller doll → keep opening until last doll.
* Recursion works similarly: a function keeps calling itself until **base condition** is met.

---

## 🔹 2. Structure of a Recursive Function

Every recursive function must have **two main components**:

1. **Base Case (Termination Condition)**

   * Stops the recursion; otherwise, infinite recursion occurs.
2. **Recursive Case**

   * Calls the same function with **smaller/simpler input**.

```c
return_type function_name(parameters) {
    if(base_condition)      // base case
        return value;
    else
        return function_name(modified_parameters); // recursive call
}
```

---

## 🔹 3. Types of Recursion

| Type               | Description                                  | Example                                    |
| ------------------ | -------------------------------------------- | ------------------------------------------ |
| Direct Recursion   | Function calls itself directly               | `factorial()` calls `factorial()`          |
| Indirect Recursion | Function A calls B, B calls A                | `A() -> B() -> A()`                        |
| Tail Recursion     | Recursive call is the **last statement**     | `sum(n-1) + n` can be optimized            |
| Non-Tail Recursion | Recursive call is **not the last statement** | `factorial` multiplication after recursion |

---

## 🔹 4. Example 1: Factorial Using Recursion

* **Problem:** n! = n × (n-1)! , with 0! = 1

```c
#include <stdio.h>

int factorial(int n) {
    if(n == 0)         // base case
        return 1;
    else
        return n * factorial(n - 1); // recursive case
}

int main() {
    int num = 5;
    printf("Factorial of %d = %d\n", num, factorial(num));
    return 0;
}
```

**Output:**

```
Factorial of 5 = 120
```

**Explanation:**

* Calls: factorial(5) → 5*factorial(4) → 5*4*factorial(3)…
* Stops at factorial(0) = 1

---

## 🔹 5. Example 2: Fibonacci Series Using Recursion

* Fibonacci: F(n) = F(n-1) + F(n-2), F(0)=0, F(1)=1

```c
#include <stdio.h>

int fibonacci(int n) {
    if(n == 0) return 0;      // base case
    if(n == 1) return 1;      // base case
    return fibonacci(n-1) + fibonacci(n-2); // recursive case
}

int main() {
    int n = 10;
    for(int i = 0; i < n; i++)
        printf("%d ", fibonacci(i));
    return 0;
}
```

**Output:**

```
0 1 1 2 3 5 8 13 21 34
```

---

## 🔹 6. How Recursion Works in Memory

* Each recursive call **creates a new stack frame** containing:

  * Function parameters
  * Local variables
  * Return address

* **Stack builds up** until base case, then **unwinds**, executing remaining operations.

**Factorial(3) example memory:**

```
Call Stack (Top → Bottom):

factorial(3)
factorial(2)
factorial(1)
factorial(0)   <-- base case reached
```

* Then stack **unwinds**: 1 → 1*1 → 2*2 → 3*6 = 6

> ⚠️ Too many recursive calls → **stack overflow**.

---

## 🔹 7. Tail Recursion vs Non-Tail Recursion

### Tail Recursion

* Recursive call is **last operation** → can be optimized by compiler.

```c
void printNumbers(int n) {
    if(n == 0) return;
    printf("%d ", n);
    printNumbers(n - 1); // last statement
}
```

### Non-Tail Recursion

* Operations occur **after the recursive call** → more stack usage.

```c
int factorial(int n) {
    if(n == 0) return 1;
    return n * factorial(n - 1); // multiplication after call
}
```

* **Tail recursion** is more memory-efficient.

---

## 🔹 8. Advantages of Recursion

1. Simplifies code for **repetitive or nested problems** (factorial, Fibonacci, trees, graphs).
2. Elegant way to solve **divide-and-conquer problems** (merge sort, quick sort).
3. Reduces **code length** and **complexity**.

---

## 🔹 9. Disadvantages of Recursion

1. **Memory-intensive** → uses stack for each call.
2. **Slower** than iteration for simple problems.
3. Risk of **stack overflow** if base case is missing or too deep recursion.
4. Debugging can be tricky.

---

## 🔹 10. Guidelines / Rules for Recursion

1. Always have a **base case** → prevents infinite recursion.
2. Recursive calls should **move toward base case**.
3. Avoid recursion for **simple iterative tasks** (for efficiency).
4. For large input, consider **tail recursion** or **iteration**.
5. Useful for problems naturally **divisible into subproblems**.

---

Farhad, in **simple analogy**:

* Recursion = **asking for help from yourself**, but you must **know when to stop (base case)**.
* Stack = **memory of your calls** → once base case reached, answers **come back step by step**.

---
