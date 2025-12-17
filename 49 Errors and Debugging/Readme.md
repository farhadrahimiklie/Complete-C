# 🔹 **Errors and Debugging in C – Full Details**

---

## 🧠 1. Types of Errors in C

Errors in C can be classified into **three main types**:

### a) **Syntax Errors (Compile-Time Errors)**

* Occur when the **rules of C language are violated**.
* Detected **during compilation**.

**Examples:**

```c
int main() {
    printf("Hello World!" // Missing closing parenthesis → syntax error
    return 0;
}
```

* Compiler Output Example:

```
error: expected ‘)’ before ‘return’
```

**Common causes:**

* Missing semicolons `;`
* Mismatched braces `{}`
* Wrong function calls
* Misspelled keywords or variable names

---

### b) **Runtime Errors**

* Occur **while the program is running**.
* Usually caused by **illegal operations** or invalid inputs.

**Examples:**

1. Division by zero:

```c
int a = 5, b = 0;
printf("%d", a/b); // runtime error
```

2. Invalid memory access:

```c
int *ptr = NULL;
*ptr = 10; // segmentation fault
```

---

### c) **Logical Errors**

* Program **runs successfully** but produces **incorrect output**.
* Hardest to detect because **compiler cannot catch them**.

**Example:**

```c
int sum(int a, int b) {
    return a - b; // logical error, should be a + b
}
```

---

## 🔹 2. How to Debug Programs in C

**Debugging** = finding and fixing errors in your program.

### Step 1: **Read Compiler Error Messages**

* Always read compiler messages carefully.
* They usually indicate **line number** and **type of error**.

### Step 2: **Use Print Statements**

* Insert `printf()` to check **variable values** and program flow.

```c
printf("Value of x: %d\n", x);
```

### Step 3: **Check Logic**

* Trace the algorithm manually with sample inputs.
* Logical errors often require careful analysis.

---

## 🔹 3. Using Debuggers (GDB)

* **GDB** = GNU Debugger for C/C++ programs.
* Allows **step-by-step execution**, **breakpoints**, **watch variables**, and **call stack inspection**.

### Basic GDB Commands

1. **Compile with -g flag**

```bash
gcc -g program.c -o program
```

2. **Start GDB**

```bash
gdb ./program
```

3. **Set a breakpoint**

```bash
break main
```

4. **Run program**

```bash
run
```

5. **Step through code**

```bash
step  // go inside functions
next  // go to next line
```

6. **Print variable values**

```bash
print x
```

7. **Continue execution**

```bash
continue
```

8. **Exit GDB**

```bash
quit
```

---

## 🔹 4. Common Debugging Techniques

1. **Divide and Conquer**

   * Comment out parts of code to isolate the problem.

2. **Check Input/Output**

   * Ensure inputs are valid and match expected data type.

3. **Use Assertions**

```c
#include <assert.h>
int x = -5;
assert(x > 0); // program stops if condition is false
```

4. **Check Memory Usage**

   * Tools like **Valgrind** detect memory leaks, invalid reads/writes.

5. **Code Review**

   * Sometimes a fresh pair of eyes can find mistakes.

---

## 🔹 5. Common Runtime Issues and How to Fix

| Issue              | Cause                              | Solution                            |
| ------------------ | ---------------------------------- | ----------------------------------- |
| Segmentation Fault | Invalid memory access              | Check pointers, array bounds        |
| Stack Overflow     | Infinite recursion or large arrays | Optimize recursion, use heap memory |
| Memory Leak        | Memory allocated but not freed     | Use `free()` and check pointers     |
| Division by zero   | Denominator = 0                    | Add checks before division          |

---

## 🔹 6. Best Practices to Avoid Errors

1. **Initialize Variables**
2. **Always free dynamically allocated memory**
3. **Check pointer validity before dereferencing**
4. **Validate user inputs**
5. **Use const and type safety where possible**
6. **Break large functions into smaller functions**
7. **Use meaningful variable names**
8. **Comment your code and maintain readability**

---

## 🔹 7. Example Debugging Scenario

```c
#include <stdio.h>

int main() {
    int a = 5, b = 0;
    printf("%d\n", a/b); // runtime error: division by zero
    return 0;
}
```

**Debugging steps:**

1. Read error → division by zero
2. Check variables → b = 0
3. Add check:

```c
if(b != 0) printf("%d\n", a/b);
else printf("Error: Division by zero\n");
```

* Program now runs correctly.

---

## 🔹 8. Summary

* **Errors in C**:

  * Syntax → compile-time
  * Runtime → during execution
  * Logical → program runs but wrong output

* **Debugging Methods**:

  * Print statements
  * Use GDB or other debuggers
  * Assertions
  * Memory checking tools

* **Preventive Measures**:

  * Initialize variables
  * Validate inputs
  * Free memory
  * Modular and readable code

---

Farhad, in simple words:

> * **Syntax errors** = code is wrong
> * **Runtime errors** = program crashes
> * **Logical errors** = program gives wrong results
> * **Debugging** = process of finding and fixing these errors efficiently

---
