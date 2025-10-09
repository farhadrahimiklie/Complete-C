
---

# 🔹 **Static Variables in C – Full Details**

---

## 🧠 1. What Is a Static Variable?

* A **static variable** is a variable that **retains its value between function calls**.
* It **exists for the entire lifetime of the program**, but **its scope may be local** if declared inside a function.
* Declared using the **`static`** keyword.

```c
static int x = 0; // declaration
```

---

## 🔹 2. Key Characteristics of Static Variables

1. **Lifetime:**

   * Exists **throughout the program execution**.
   * Unlike local variables, it **does not get destroyed** when the function ends.

2. **Scope:**

   * If declared **inside a function** → scope is **local to that function**.
   * If declared **outside all functions** → scope is **limited to the file** (cannot be accessed in other files).

3. **Initialization:**

   * **Automatically initialized to 0** if not explicitly initialized.
   * Initialization happens **only once**, not every function call.

4. **Memory Location:**

   * Stored in the **Data Segment** (not the stack).

---

## 🔹 3. Syntax

```c
static data_type variable_name = value;
```

* Examples:

```c
static int counter = 0;   // inside function
static int total = 0;     // outside function
```

---

## 🔹 4. Static Variable Inside a Function

* Used to **retain value between function calls**.
* Scope: only visible **inside the function**.

```c
#include <stdio.h>
void func() {
    static int count = 0; // static local variable
    count++;
    printf("Count = %d\n", count);
}
int main() {
    func(); // 1
    func(); // 2
    func(); // 3
    return 0;
}
```

**Output:**

```
Count = 1
Count = 2
Count = 3
```

* **Observation:**

  * `count` is **not reinitialized** every time the function is called.
  * Retains its **previous value**.

---

## 🔹 5. Static Variable Outside Function (Global Static)

* Declared outside all functions → **scope limited to the file**.
* Useful for **file encapsulation** in multi-file programs.

```c
#include <stdio.h>
static int num = 10; // accessible only in this file

void display() {
    printf("Num = %d\n", num);
}
int main() {
    display(); // 10
    return 0;
}
```

* **Cannot be accessed in another file** using `extern`.
* Helps **hide variables** from other modules.

---

## 🔹 6. Static vs Local Variable

| Feature          | Local Variable             | Static Variable                                        |
| ---------------- | -------------------------- | ------------------------------------------------------ |
| Lifetime         | Until function ends        | Entire program                                         |
| Initialization   | Garbage if not initialized | 0 if not initialized                                   |
| Scope            | Function/block only        | Function/block only (inside function) or file (global) |
| Memory           | Stack                      | Data Segment                                           |
| Reinitialization | Every call                 | Only once                                              |

---

## 🔹 7. Static vs Global Variable

| Feature       | Global Variable             | Static Global Variable  |
| ------------- | --------------------------- | ----------------------- |
| Lifetime      | Entire program              | Entire program          |
| Scope         | Accessible across all files | Accessible only in file |
| Storage       | Data Segment                | Data Segment            |
| Default Value | 0                           | 0                       |

---

## 🔹 8. Common Use Cases of Static Variables

1. **Counting Function Calls**

```c
void counter() {
    static int count = 0;
    count++;
    printf("Function called %d times\n", count);
}
```

2. **Retaining State Between Function Calls**

```c
int addTen() {
    static int total = 0;
    total += 10;
    return total;
}
```

3. **File Encapsulation**

```c
// file1.c
static int secret = 100; // cannot be accessed in file2.c
```

4. **Caching Values or Memoization** (in recursion)

```c
int factorial(int n) {
    static int memo[100] = {0};
    if(n == 0) return 1;
    if(memo[n] != 0) return memo[n];
    memo[n] = n * factorial(n-1);
    return memo[n];
}
```

---

## 🔹 9. Important Notes

1. Static variables **retain value between calls**.
2. Inside function → **scope limited**, outside function → **file scope**.
3. **Initialized only once** → saves memory and avoids unnecessary re-initialization.
4. Default initialization → **0 for numbers, NULL for pointers**.
5. Can be used with **arrays, structures, and pointers**.

---

## 🔹 10. Memory Layout

```
+--------------------+
| Code Segment       |
+--------------------+
| Data Segment       | <- static and global variables stored here
|  static int x;     |
|  global int y;     |
+--------------------+
| Heap               |
+--------------------+
| Stack              | <- local variables
+--------------------+
```

---

Farhad, in **simple words**:

* **Static variables are “permanent locals”**: exist throughout program but can still have **local visibility**.
* **Use inside function** → remembers previous values.
* **Use outside function** → hides global data from other files.

---
