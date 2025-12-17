## 1. What is Memory Management in C?

* In C, memory is the space your program uses to store variables, data structures, and program instructions.
* Managing memory properly is essential to avoid errors like memory leaks, crashes, or unexpected behavior.

---

## 2. Types of Memory Allocation in C

There are **two main ways** memory is allocated in a C program:

### A. Static Memory Allocation (Compile-Time)

* Memory size and location are determined **before** the program runs.
* Happens for:

  * Global variables
  * Static variables
  * Local variables with fixed size (like `int a[10];`)
* Memory is allocated on the **stack** (for local variables) or in **data/bss segment** (for globals/statics).
* Memory size is fixed and cannot change at runtime.
* Managed automatically (allocation and deallocation happen when the scope is entered/exited).

### B. Dynamic Memory Allocation (Run-Time)

* Memory is allocated **while the program is running** (on demand).
* Allows you to request memory of any size from the heap.
* You control when to allocate and free memory.
* Requires special functions: `malloc()`, `calloc()`, `realloc()`, and `free()` from `stdlib.h`.

---

## 3. Static Memory in Detail

### 3.1 What is Static Memory?

* Used for variables declared as `static` or global variables.
* Allocated **once** and exists for the entire program run.
* Stored in the **data segment** (initialized data) or **bss segment** (uninitialized data).
* Access speed is fast because it's fixed and predictable.

### 3.2 Local Variables (Stack Allocation)

* Local variables are allocated on the **stack**.
* Stack grows and shrinks as functions are called and return.
* Memory size must be fixed at compile time.
* Example:

```c
void func() {
    int a = 10;      // allocated on stack
    int arr[5];      // fixed size array on stack
}
```

* When `func()` finishes, the stack space is freed automatically.

### 3.3 Static Variables

* Declared with `static` keyword inside functions or globally.
* They retain their value between function calls.
* Allocated in data/bss segment, **not on stack**.

Example:

```c
void counter() {
    static int count = 0;
    count++;
    printf("%d\n", count);
}
```

Calling `counter()` multiple times increases `count` and retains value.

---

## 4. Dynamic Memory in Detail

### 4.1 What is Dynamic Memory?

* Allocated at runtime from a memory area called the **heap**.
* The heap is managed manually by the programmer.
* Useful for data where size is not known before running (e.g., user input).

### 4.2 Dynamic Memory Functions

* `malloc(size_t size)`: allocates `size` bytes, returns pointer to allocated memory (uninitialized).
* `calloc(size_t n, size_t size)`: allocates memory for `n` elements of `size` bytes each, initializes to zero.
* `realloc(void *ptr, size_t size)`: resizes previously allocated memory.
* `free(void *ptr)`: frees memory allocated dynamically.

### 4.3 Example of Dynamic Memory Usage

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr;
    int n = 5;

    ptr = (int *)malloc(n * sizeof(int));  // allocate memory for 5 integers

    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        ptr[i] = i + 1;
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", ptr[i]);
    }

    free(ptr);  // release the memory

    return 0;
}
```

---

## 5. Differences Between Static and Dynamic Memory

| Aspect           | Static Memory                                             | Dynamic Memory                       |
| ---------------- | --------------------------------------------------------- | ------------------------------------ |
| Allocation time  | Compile time                                              | Runtime                              |
| Memory location  | Stack or Data segment                                     | Heap                                 |
| Size flexibility | Fixed size, known at compile time                         | Flexible size, can change at runtime |
| Lifetime         | Static: entire program execution<br>Local: function scope | Until `free()` is called             |
| Management       | Automatic by compiler                                     | Manual by programmer                 |
| Speed            | Faster allocation/deallocation                            | Slower allocation/deallocation       |
| Examples         | Local variables, global variables, static variables       | Variables allocated with malloc/free |

---

## 6. How Memory is Managed at Runtime

* Stack memory grows/shrinks automatically with function calls.
* Heap memory must be allocated and freed explicitly.
* Incorrect handling of dynamic memory can lead to:

  * **Memory leaks:** forgetting to free memory.
  * **Dangling pointers:** using memory after it’s freed.
  * **Double free:** freeing same memory twice.
  * **Fragmentation:** inefficient use of heap memory.

---

## 7. Working with Static and Dynamic Memory Together

* Often, programs use static variables for fixed-size or permanent data.
* Use dynamic memory when data size is unknown or changes during runtime.
* Example of mixing:

```c
void process() {
    static int staticArr[10];      // fixed-size static array
    int *dynArr = malloc(20 * sizeof(int)); // dynamic array

    if (dynArr == NULL) {
        // handle allocation failure
        return;
    }

    // Use arrays...

    free(dynArr);  // remember to free dynamic memory
}
```

---

## 8. Memory and Structs: Static vs Dynamic

* Structs can be allocated statically:

```c
struct Point {
    int x, y;
};

struct Point p1;  // static allocation
```

* Or dynamically:

```c
struct Point *p2 = malloc(sizeof(struct Point));
```

* For nested structs or arrays inside structs, dynamic allocation is often used to save memory or handle variable sizes.

---

## 9. Common Mistakes and Best Practices

* Always check if `malloc` or `calloc` returns `NULL`.
* Always free dynamically allocated memory.
* Avoid using memory after freeing it.
* Initialize pointers after freeing to `NULL`.
* Use tools like `valgrind` to detect memory leaks.
* Avoid mixing stack and heap pointers carelessly.

---

## 10. Memory Layout of a C Program

A simple memory model includes:

* **Text segment:** program code.
* **Data segment:** initialized global/static variables.
* **BSS segment:** uninitialized global/static variables.
* **Heap:** dynamically allocated memory.
* **Stack:** function call frames and local variables.

---

## Summary

| Term             | Description                                            | Example                            |
| ---------------- | ------------------------------------------------------ | ---------------------------------- |
| Static memory    | Memory allocated at compile time, fixed size           | `int a[10];` or `static int x;`    |
| Stack            | Local variables with automatic allocation/deallocation | `int x = 5;` inside function       |
| Heap             | Dynamically allocated memory at runtime                | `int *p = malloc(10*sizeof(int));` |
| malloc()         | Allocates uninitialized memory                         | `malloc(size)`                     |
| calloc()         | Allocates zero-initialized memory                      | `calloc(n, size)`                  |
| realloc()        | Resizes previously allocated memory                    | `realloc(ptr, new_size)`           |
| free()           | Frees dynamically allocated memory                     | `free(ptr)`                        |
| Memory leak      | Forgetting to free allocated memory                    | —                                  |
| Dangling pointer | Pointer pointing to freed memory                       | —                                  |
