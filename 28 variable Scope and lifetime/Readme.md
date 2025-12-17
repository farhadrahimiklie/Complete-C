# 🔹 **Variable Scope and Lifetime in C – Full Details**

---

## 🧠 1. What Are Scope and Lifetime?

1. **Scope** → **where a variable can be accessed** in the code.
2. **Lifetime** → **how long the variable exists in memory** during program execution.

> ⚠️ Scope is **about accessibility**, Lifetime is **about memory duration**.

---

## 🔹 2. Types of Variable Scope

### 2.1 Local Variables

* Declared **inside a function or block**.
* Accessible **only within that function/block**.
* Lifetime: **exist only during function execution**, destroyed afterward.

```c
#include <stdio.h>
void func() {
    int localVar = 10; // local variable
    printf("Inside func: %d\n", localVar);
}
int main() {
    func();
    // printf("%d", localVar); // Error! localVar not accessible here
    return 0;
}
```

* **Memory:** Typically stored in **stack**.

---

### 2.2 Global Variables

* Declared **outside all functions**, usually at the top.
* Accessible by **all functions** in the file.
* Lifetime: **entire program execution**.

```c
#include <stdio.h>
int globalVar = 100; // global variable

void func() {
    printf("Inside func: %d\n", globalVar);
}

int main() {
    printf("Inside main: %d\n", globalVar);
    func();
    return 0;
}
```

* **Memory:** Stored in **data segment**.

---

### 2.3 Block Scope (Nested Blocks)

* Variables declared inside **curly braces `{}`** are accessible **only inside that block**.

```c
#include <stdio.h>
int main() {
    int x = 10; // main block
    {
        int y = 20; // nested block
        printf("x = %d, y = %d\n", x, y);
    }
    // printf("%d", y); // Error! y is out of scope
    return 0;
}
```

---

### 2.4 Function Scope (Labels)

* Labels used in **goto** have **function scope**, i.e., accessible **only within the function**.

```c
#include <stdio.h>
int main() {
    goto label;
    printf("This will not print\n");
label:
    printf("Jumped to label\n");
    return 0;
}
```

---

### 2.5 Function Prototype Scope

* Parameters of a function exist **only inside the function** → also called **parameter scope**.

```c
#include <stdio.h>
void add(int a, int b) {
    printf("%d\n", a + b); // a, b only accessible here
}
```

---

## 🔹 3. Types of Variable Lifetime

### 3.1 Automatic (Local) Variables

* Declared inside a function/block **without static** keyword.
* **Created when block is entered**, **destroyed when block exits**.
* Default storage class → `auto` (optional keyword).

```c
#include <stdio.h>
void func() {
    auto int x = 5; // auto is default
    printf("%d\n", x);
}
```

---

### 3.2 Static Variables

* Declared with `static` keyword **inside function** or **outside function**.
* Lifetime: **entire program execution**, but scope **inside the function/block** if declared inside.

```c
#include <stdio.h>
void func() {
    static int x = 0; // retains value between calls
    x++;
    printf("%d\n", x);
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
1
2
3
```

> ⚠️ Static variable inside function **remembers its value** between calls.

---

### 3.3 Dynamic Variables

* Created using **`malloc`/`calloc`** in heap memory.
* Lifetime: **until freed using `free()`**.
* Scope: depends on **pointer variable holding address**.

```c
#include <stdio.h>
#include <stdlib.h>
int main() {
    int *ptr = (int*) malloc(sizeof(int));
    *ptr = 100;
    printf("%d\n", *ptr);
    free(ptr); // release memory
    return 0;
}
```

---

## 🔹 4. Storage Classes in C

| Storage Class | Scope        | Lifetime           | Default Value | Example           |
| ------------- | ------------ | ------------------ | ------------- | ----------------- |
| auto          | Local        | Function execution | Garbage       | `auto int x;`     |
| register      | Local        | Function execution | Garbage       | `register int r;` |
| static        | Local/Global | Program execution  | 0             | `static int s;`   |
| extern        | Global       | Program execution  | Depends       | `extern int g;`   |

---

## 🔹 5. Scope and Lifetime Memory Diagram

```
Memory Segments:

[Stack]      → local variables, function parameters
[Heap]       → dynamically allocated variables (malloc/calloc)
[Data]       → global/static variables
[Code]       → instructions
```

* Local → stack → destroyed after function/block
* Static/global → data segment → exists entire program
* Dynamic → heap → exists until `free()`

---

## 🔹 6. Key Points / Rules

1. **Scope** = accessibility, **Lifetime** = memory duration.
2. Local variables → stack → auto-created → destroyed after function ends.
3. Global variables → data segment → exist entire program → accessible by all functions.
4. Static variables → keep value between function calls → lifetime = entire program.
5. Dynamic variables → allocated in heap → exist until freed → scope depends on pointer.
6. Always initialize variables, especially **static/global** (default 0) and **local** (default garbage).

---

## 🔹 7. Example Showing All Types

```c
#include <stdio.h>
int globalVar = 10; // global

void func() {
    int localVar = 5;        // automatic/local
    static int staticVar = 0; // static
    localVar++;
    staticVar++;
    globalVar++;
    printf("local=%d static=%d global=%d\n", localVar, staticVar, globalVar);
}

int main() {
    func(); // local=6 static=1 global=11
    func(); // local=6 static=2 global=12
    func(); // local=6 static=3 global=13
    return 0;
}
```

**Output:**

```
local=6 static=1 global=11
local=6 static=2 global=12
local=6 static=3 global=13
```

* Notice how **local resets**, **static retains value**, **global keeps incrementing**.

---
