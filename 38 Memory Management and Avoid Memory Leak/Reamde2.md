## Introduction

Memory management is a fundamental concept in C programming that deals with how a program allocates, uses, and releases memory during execution. Understanding memory management is essential for building efficient and bug-free programs, especially complex data structures like linked lists, trees, or even systems like Git.

This guide will cover:

- Types of memory used in C programs
- Static, automatic, and dynamic memory allocation
- How to use pointers with memory
- Dynamic memory functions: `malloc`, `calloc`, `realloc`, and `free`
- Common issues: memory leaks, dangling pointers, double free
- Best practices for memory management
- Example: Implementing a linked list with dynamic memory
- Tips for building bigger projects

---

## 1. Memory in C Programs

C programs use memory in several ways:

### a) Stack Memory

- Used for local variables and function call management.
- Fast allocation and deallocation (automatic).
- Limited size (usually a few MB).
- Variables are automatically freed when the function returns.

Example:
```c
void foo() {
    int x = 10; // stored on stack
}
````

### b) Heap Memory

* Used for dynamic memory allocation.
* Managed manually by the programmer.
* Larger than stack but slower to allocate.
* Memory persists until explicitly freed.

### c) Data Segment

* Contains global and static variables.
* Memory allocated for the lifetime of the program.

---

## 2. Types of Memory Allocation

### a) Static Allocation

* Memory allocated at compile time.
* For global variables and static variables.

Example:

```c
static int x = 5;
int globalVar = 10;
```

### b) Automatic Allocation

* Memory allocated on the stack at runtime.
* For local variables inside functions.

### c) Dynamic Allocation

* Memory allocated on the heap at runtime.
* You request memory with functions (`malloc`, `calloc`, etc.).
* You must free it manually.

---

## 3. Pointers and Memory

Pointers hold memory addresses. They are essential for dynamic memory management.

```c
int *p;       // p is a pointer to int
int x = 10;
p = &x;       // p stores the address of x
```

When you allocate memory dynamically, pointers point to that memory block.

---

## 4. Dynamic Memory Functions

### a) `malloc`

* Allocates a block of memory of specified size.
* Returns a `void*` pointer to the allocated memory.
* Memory is **uninitialized** (contains garbage values).

```c
int *arr = (int *)malloc(5 * sizeof(int));
if (arr == NULL) {
    // Allocation failed
}
```

### b) `calloc`

* Allocates memory for an array of elements, initializing all bytes to zero.

```c
int *arr = (int *)calloc(5, sizeof(int));
```

### c) `realloc`

* Resizes a previously allocated memory block.
* Can expand or shrink memory.

```c
arr = (int *)realloc(arr, 10 * sizeof(int));
```

### d) `free`

* Releases previously allocated memory back to the system.
* You must call `free` for every `malloc`/`calloc`/`realloc` to avoid leaks.

```c
free(arr);
arr = NULL; // good practice to avoid dangling pointers
```

---

## 5. Common Memory Management Issues

### a) Memory Leak

* When allocated memory is not freed, causing wasted memory.
* Happens if `free` is never called or pointer is lost.

### b) Dangling Pointer

* Pointer points to freed memory.
* Accessing it causes undefined behavior.

### c) Double Free

* Calling `free` twice on the same pointer.
* Causes program crashes or undefined behavior.

---

## 6. Best Practices

* Always check the return value of `malloc`, `calloc`, and `realloc`.
* Initialize pointers to `NULL` and set to `NULL` after freeing.
* Free every dynamically allocated memory once done.
* Avoid memory leaks by tracking allocations.
* Use tools like `valgrind` to detect leaks.
* Use comments to document ownership of allocated memory.

---

## 7. Practical Example: Linked List

```c
#include <stdio.h>
#include <stdlib.h>

// Define a node of linked list
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Create a new node dynamically
Node* create_node(int data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Insert node at the front
void push(Node **head_ref, int new_data) {
    Node *new_node = create_node(new_data);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Print linked list
void print_list(Node *node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Free the entire list
void free_list(Node *head) {
    Node *tmp;
    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

int main() {
    Node *head = NULL;

    push(&head, 10);
    push(&head, 20);
    push(&head, 30);

    print_list(head);

    free_list(head);
    head = NULL;

    return 0;
}
```

---

## 8. Tips for Building Big Projects Using Memory Management

* Design clear ownership rules for dynamically allocated memory.
* Modularize your code to isolate allocation and deallocation.
* Use data structures like linked lists, trees, hash tables that use dynamic memory.
* Avoid global variables holding dynamic memory to prevent leaks.
* Test memory usage with tools (`valgrind`) regularly.
* For very complex projects (like Git), study their source code to see how they manage memory safely.

---

## Summary

* Memory management controls how your program uses RAM.
* Stack is for automatic, short-lived variables.
* Heap is for dynamic, long-lived data — managed by `malloc`/`free`.
* Pointers are keys to using memory efficiently.
* Avoid leaks and dangling pointers.
* Practice with examples like linked lists.
* Build gradually, always freeing what you allocate.
