# Complete Guide to `extern` Storage Class in C

---

### What is `extern` storage class?

* The `extern` keyword is a **storage class specifier** in C.
* It is used to **declare a variable or function that is defined in another file or later in the same file**.
* It tells the compiler: **“This variable/function exists somewhere else, not here.”**
* It is used for **external linkage** — allowing variables/functions to be shared across multiple files.

---

### Why do we need `extern`?

* In C, each source file (translation unit) is compiled separately.
* If you want to use a variable or function defined in one source file from another source file, you declare it with `extern` to tell the compiler about its existence.
* It avoids duplicate definitions but allows multiple declarations.

---

### Basic example: Sharing a global variable across files

Suppose you have two files: `file1.c` and `file2.c`.

```c
// file1.c
int count = 10; // Definition and initialization of global variable

void display() {
    printf("Count = %d\n", count);
}
```

```c
// file2.c
extern int count;  // Declaration (not definition) of count variable

void change() {
    count = 20;
}
```

* `extern int count;` in `file2.c` means: "The variable `count` exists somewhere else."
* At linking time, both files are linked, and `count` refers to the same memory location.

---

### Key points about `extern`:

1. **Declaration vs Definition:**

   * Declaration: tells the compiler a variable or function exists.
   * Definition: actually allocates memory or provides the function code.

2. **`extern` is only a declaration.**

   * Using `extern int x;` does NOT allocate memory.
   * You must define `int x;` somewhere (usually in one source file only).

3. **You can declare a variable multiple times with `extern`, but define it only once.**

4. **`extern` is default for functions**

   * Functions have external linkage by default, so writing `extern` before function declaration is optional.

---

### `extern` with variables vs functions

* For **variables**, you need `extern` to declare a variable defined elsewhere.
* For **functions**, declarations are extern by default.

Example:

```c
// file1.c
void func() {
    printf("Hello\n");
}

// file2.c
extern void func();  // extern optional, it's the same as void func();
```

---

### Common mistakes with `extern`

1. **Defining a variable multiple times**

```c
// file1.c
int x = 10;  // Definition

// file2.c
int x = 20;  // ERROR: multiple definitions
```

Correct way:

```c
// file2.c
extern int x;  // Just declaration, no definition
```

2. **Using `extern` without definition**

```c
// file2.c
extern int y;  // But y is not defined anywhere => linker error
```

---

### `extern` and initialization

* You **cannot initialize** a variable in an `extern` declaration.

```c
extern int x = 5;  // ERROR: extern variable cannot be initialized here
```

Initialization must be done where the variable is **defined**, not declared.

---

### `extern` and header files

* To use global variables across multiple files, it’s common to:

1. **Define** the variable in exactly one `.c` file.
2. **Declare** it with `extern` in a `.h` header file.
3. **Include** the header file in any `.c` files that need the variable.

Example:

```c
// globals.h
extern int global_var;

// globals.c
int global_var = 100;  // definition

// main.c
#include "globals.h"

void foo() {
    printf("%d\n", global_var);
}
```

---

### `extern` and scope

* Variables declared with `extern` have **global scope**.
* They refer to variables that exist outside the current translation unit (file).
* You cannot use `extern` for variables declared inside functions (local variables).

---

### How `extern` works with Binary Files (in context of your Git project)

* When working with binary files, you might want to store program state or data in global variables.
* `extern` allows you to **share these variables across multiple source files** in your Git project.
* For example, if you have a global config or buffer, define it once, declare it with `extern` elsewhere.

---

### Summary table

| Concept               | `extern` Behavior                           |
| --------------------- | ------------------------------------------- |
| Purpose               | Declare variable/function defined elsewhere |
| Memory allocation     | No memory allocated on `extern` declaration |
| Initialization        | Not allowed in `extern` declarations        |
| Multiple declarations | Allowed                                     |
| Multiple definitions  | Not allowed (linker error)                  |
| Use with functions    | Functions are extern by default             |
| Common use case       | Sharing globals across multiple files       |

---

### Complete simple example with multiple files

**globals.h**

```c
#ifndef GLOBALS_H
#define GLOBALS_H

extern int global_counter;  // Declaration only

void increment_counter();

#endif
```

**globals.c**

```c
#include <stdio.h>
#include "globals.h"

int global_counter = 0;  // Definition and initialization

void increment_counter() {
    global_counter++;
    printf("Counter: %d\n", global_counter);
}
```

**main.c**

```c
#include "globals.h"

int main() {
    increment_counter();
    increment_counter();
    return 0;
}
```

* Compile: `gcc main.c globals.c -o program`
* Output:

  ```
  Counter: 1
  Counter: 2
  ```

---

### Advanced notes on `extern`

* **`extern` can be used with arrays**

```c
extern int arr[10];  // Declare array defined elsewhere
```

* **`extern` and `const` variables**

```c
// const variables have internal linkage by default in C, so you must add extern carefully:
extern const int MAX_VALUE;
```

* **`extern "C"` in C++**

In C++, when including C headers or using C functions, you often use:

```cpp
extern "C" {
    void c_function();
}
```

This tells the compiler to use C linkage (name mangling) for interoperability. But this is a C++ specific topic.

---

### Tips for your Git project with `extern`

* Always define global variables in **one** `.c` file only.
* Declare them with `extern` in a header file for use in other `.c` files.
* Keep variable naming consistent.
* Use `extern` for sharing global state but avoid excessive use of globals for better code design.