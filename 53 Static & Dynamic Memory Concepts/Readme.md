# 🔹 **Memory Concepts in C: Static vs Dynamic Memory**

---

## 🧠 1. Introduction

In C, memory for variables can be allocated in two main ways:

1. **Static Memory Allocation** – memory is fixed at **compile-time**.
2. **Dynamic Memory Allocation** – memory is allocated at **runtime** as needed.

Understanding the difference is crucial for **efficient programming, avoiding memory leaks, and optimizing performance**.

---

## 🔹 2. Static Memory Allocation

### a) Definition

* Memory is **allocated before program execution**.
* Size of memory must be **known at compile-time**.
* Typically stored in:

  * **Stack** → for local variables
  * **Data Segment** → for global/static variables

### b) Characteristics

| Feature      | Description                                              |
| ------------ | -------------------------------------------------------- |
| Allocation   | Compile-time                                             |
| Lifespan     | Entire function/block (stack) or program (global/static) |
| Size         | Must be known before execution                           |
| Access Speed | Fast (stack memory)                                      |
| Example      | `int x = 10;` , `static int y;`                          |

### c) Example: Static Allocation

```c
#include <stdio.h>

int global_var = 100; // global → static memory

void func() {
    int local_var = 10; // stack → static memory at compile time
    static int counter = 0; // persists between calls
    counter++;
    printf("Local: %d, Counter: %d\n", local_var, counter);
}

int main() {
    func(); // Counter: 1
    func(); // Counter: 2
    func(); // Counter: 3
    return 0;
}
```

**Output:**

```
Local: 10, Counter: 1
Local: 10, Counter: 2
Local: 10, Counter: 3
```

**Explanation:**

* `local_var` → allocated on stack, destroyed after function ends
* `counter` → static, persists across function calls
* `global_var` → stored in data segment, exists for entire program

---

## 🔹 3. Dynamic Memory Allocation

### a) Definition

* Memory is **allocated at runtime**, using library functions.
* Useful when **size of data is not known at compile-time**.
* Allocated in the **heap** memory region.

### b) Characteristics

| Feature      | Description                       |
| ------------ | --------------------------------- |
| Allocation   | Runtime                           |
| Lifespan     | Until explicitly freed (`free()`) |
| Size         | Can be determined dynamically     |
| Access Speed | Slightly slower than stack        |
| Example      | `malloc`, `calloc`, `realloc`     |

---

### c) Dynamic Memory Functions

1. **`malloc(size)`** – allocate memory (uninitialized)

```c
int *ptr = (int*)malloc(5 * sizeof(int)); // allocate 5 integers
```

2. **`calloc(num, size)`** – allocate and initialize to 0

```c
int *ptr = (int*)calloc(5, sizeof(int)); // 5 integers initialized to 0
```

3. **`realloc(ptr, new_size)`** – resize memory block

```c
ptr = (int*)realloc(ptr, 10 * sizeof(int)); // resize to 10 integers
```

4. **`free(ptr)`** – release memory

```c
free(ptr);
```

---

### d) Example: Dynamic Allocation

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);

    // Allocate memory dynamically
    int *arr = (int*)malloc(n * sizeof(int));

    // Check if allocation succeeded
    if(arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Initialize and display array
    for(int i = 0; i < n; i++) {
        arr[i] = i * 10;
        printf("%d ", arr[i]);
    }

    free(arr); // release memory
    return 0;
}
```

**Output (example for n=5):**

```
0 10 20 30 40
```

**Explanation:**

* `malloc` allocates memory on heap
* Memory persists until `free()` is called
* Allows **variable-sized arrays** and **flexible memory usage**

---

## 🔹 4. Differences Between Static and Dynamic Memory

| Feature         | Static Memory                                           | Dynamic Memory                            |
| --------------- | ------------------------------------------------------- | ----------------------------------------- |
| Allocation Time | Compile-time                                            | Runtime                                   |
| Memory Region   | Stack / Data Segment                                    | Heap                                      |
| Size            | Fixed                                                   | Flexible                                  |
| Lifespan        | Stack: till function ends, Global/Static: whole program | Until `free()` is called                  |
| Initialization  | Optional                                                | `malloc` → uninitialized, `calloc` → zero |
| Speed           | Faster                                                  | Slightly slower                           |
| Example         | `int x; static int y;`                                  | `malloc`, `calloc`, `realloc`             |

---

## 🔹 5. Advantages of Dynamic Memory

1. **Flexible memory usage** → allocate only what you need
2. **Efficient for large data structures** → linked lists, trees, graphs
3. **Resizable structures** → arrays can grow/shrink at runtime
4. **Memory optimization** → allocate and free as needed

---

## 🔹 6. Common Pitfalls in Dynamic Memory

1. **Memory Leak** → forgetting to `free()` allocated memory
2. **Dangling Pointer** → using memory after it is freed
3. **Double Free** → calling `free()` twice on same pointer
4. **Accessing NULL** → check pointer before use

---

### Example: Avoiding Memory Leak

```c
int *ptr = malloc(5 * sizeof(int));
if(ptr != NULL) {
    // use ptr
    free(ptr); // always free memory
    ptr = NULL; // avoid dangling pointer
}
```

---

## 🔹 7. Summary

* **Static Memory** → fixed size, allocated at compile-time, fast, less flexible
* **Dynamic Memory** → flexible, allocated at runtime, heap memory, must manage manually
* Use **heap memory** for **variable-sized or large data**
* Always **free memory** to avoid leaks

---

Farhad, in simple words:

> * **Static memory** = fixed boxes, ready before program starts
> * **Dynamic memory** = make boxes while program is running, can decide size and number
> * **Heap** is like a flexible storage room, **stack** is like temporary workspace

---
