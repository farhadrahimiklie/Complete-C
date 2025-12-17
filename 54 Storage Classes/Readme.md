# 🔹 **Storage Classes in C – Full Details**

---

## 🧠 1. Introduction

In C, a **storage class** defines:

1. **Scope** → where the variable is accessible
2. **Lifetime** → how long the variable exists in memory
3. **Storage location** → stack, data segment, or heap
4. **Default initial value** → if uninitialized

There are **four main storage classes** in C:

1. `auto`
2. `register`
3. `static`
4. `extern`

---

## 🔹 2. **auto** Storage Class

### a) Definition

* Default storage class for **local variables** inside a function
* Allocated on **stack**
* Lifetime: **till function exits**
* Scope: **within the block/function**
* Cannot be initialized **globally**

### b) Syntax

```c
auto int x; // optional, because local variables are auto by default
```

### c) Example

```c
#include <stdio.h>

int main() {
    auto int x = 10; // same as int x = 10;
    printf("%d\n", x);
    return 0;
}
```

**Explanation:**

* `x` exists **only inside main**
* Memory is **allocated on stack**

---

## 🔹 3. **register** Storage Class

### a) Definition

* Requests compiler to store variable in **CPU register** (fastest access)
* Only for **small local variables** (like int, char)
* Cannot use `&` operator → no address in memory

### b) Syntax

```c
register int count = 5;
```

### c) Example

```c
#include <stdio.h>

int main() {
    register int i;
    for(i=0; i<5; i++) {
        printf("%d ", i);
    }
    return 0;
}
```

**Key Points:**

* Lifetime: **till function ends**
* Scope: **local to function/block**
* Modern compilers often **ignore `register`**, as optimization is automatic

---

## 🔹 4. **static** Storage Class

### a) Definition

* Preserves **value of variable** between function calls
* Allocated in **data segment**, not stack
* Can be **local or global**

### b) Syntax

```c
static int count = 0;
```

### c) Examples

#### i) Static Local Variable

```c
#include <stdio.h>

void counter() {
    static int count = 0; // retains value between calls
    count++;
    printf("Count = %d\n", count);
}

int main() {
    counter(); // Count = 1
    counter(); // Count = 2
    counter(); // Count = 3
    return 0;
}
```

#### ii) Static Global Variable

```c
#include <stdio.h>

static int globalVar = 100; // accessible only in this file

int main() {
    printf("%d\n", globalVar);
    return 0;
}
```

**Key Points:**

* Local `static` → persists across function calls
* Global `static` → **file scope**, not accessible outside file

---

## 🔹 5. **extern** Storage Class

### a) Definition

* Used to **access global variables across multiple files**
* Tells compiler: “**variable exists somewhere else**”

### b) Syntax

```c
extern int x; // defined in another file
```

### c) Example

**File1.c**

```c
#include <stdio.h>

int x = 100; // global variable

int main() {
    extern int y; // declared in File2.c
    printf("%d %d\n", x, y);
    return 0;
}
```

**File2.c**

```c
int y = 200;
```

**Explanation:**

* `extern` allows **cross-file access** to global variables
* Lifetime: **entire program**

---

## 🔹 6. Summary Table of Storage Classes

| Storage Class | Scope                           | Lifetime       | Default Value                 | Memory Location            |
| ------------- | ------------------------------- | -------------- | ----------------------------- | -------------------------- |
| auto          | Local                           | Function ends  | Garbage (uninitialized)       | Stack                      |
| register      | Local                           | Function ends  | Garbage (uninitialized)       | CPU register (if possible) |
| static        | Local → function, Global → file | Entire program | 0                             | Data segment               |
| extern        | Global                          | Entire program | Must be initialized elsewhere | Data segment               |

---

## 🔹 7. Key Points / Best Practices

1. Use **auto** for normal local variables (default)
2. Use **register** for variables needing **frequent access** (modern compilers optimize automatically)
3. Use **static** for **persistent local variables** or **file scope globals**
4. Use **extern** for **cross-file global variables**

---

Farhad, in simple words:

> * **auto** = normal local variables
> * **register** = fast local variables in CPU
> * **static** = keeps value even after function ends
> * **extern** = global variables shared across files

---
