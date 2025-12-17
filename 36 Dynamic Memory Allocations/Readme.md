# 🔹 **Dynamic Memory Allocation in C – Full Details**

---

## 🧠 1. What is Dynamic Memory Allocation?

* Dynamic Memory Allocation means **allocating memory at runtime** (while the program is running) instead of **compile time**.
* Allows programs to **allocate memory as needed** and **free it when not needed**, improving efficiency.

**Static Memory:** Fixed size, allocated at compile time (e.g., arrays: `int arr[10];`)
**Dynamic Memory:** Size decided at runtime using **pointers and heap** (e.g., `malloc`, `calloc`).

---

## 🔹 2. Why Use Dynamic Memory Allocation?

1. When **size of data is unknown at compile time**.
2. To **save memory** by allocating only the required memory.
3. Needed for **dynamic data structures** (linked list, tree, graph).
4. To **return memory from a function**.
5. To **adjust memory at runtime** using `realloc`.

---

## 🔹 3. Memory Layout in C

C program memory is divided into:

| Segment           | Purpose                                                                    |
| ----------------- | -------------------------------------------------------------------------- |
| Stack             | Stores local variables, function calls (automatic memory, temporary, fast) |
| Heap              | Stores dynamic memory (managed manually using malloc/calloc/free)          |
| Data Segment      | Global & static variables                                                  |
| Code/Text Segment | Program instructions                                                       |

**Dynamic memory is allocated in the heap** using pointers.

---

## 🔹 4. Functions for Dynamic Memory Allocation (`stdlib.h`)

C provides **four main functions**:

| Function  | Purpose                                         |
| --------- | ----------------------------------------------- |
| `malloc`  | Allocate memory (uninitialized)                 |
| `calloc`  | Allocate memory for n elements, initialize to 0 |
| `realloc` | Resize previously allocated memory              |
| `free`    | Deallocate memory to avoid memory leaks         |

---

## 🔹 5. malloc (Memory Allocation)

* **Syntax:**

```c
ptr = (type*) malloc(size_in_bytes);
```

* Allocates **contiguous memory** in heap.
* Memory is **uninitialized** → contains garbage values.
* Returns **NULL** if allocation fails.

### Example:

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr = (int*) malloc(5 * sizeof(int)); // array of 5 integers

    if(ptr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for(int i=0;i<5;i++)
        ptr[i] = i+1;

    for(int i=0;i<5;i++)
        printf("%d ", ptr[i]);

    free(ptr); // free memory
    ptr = NULL; // avoid dangling pointer
    return 0;
}
```

**Output:**

```
1 2 3 4 5
```

**Memory Diagram:**

```
Heap:
0x500: 1 2 3 4 5
Stack:
ptr -> 0x500
```

---

## 🔹 6. calloc (Contiguous Allocation)

* Allocates memory for **n elements of size bytes**.
* **Initializes all memory to 0**.
* Syntax:

```c
ptr = (type*) calloc(n, sizeof(type));
```

### Example:

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr = (int*) calloc(5, sizeof(int));

    for(int i=0;i<5;i++)
        printf("%d ", ptr[i]); // prints 0 0 0 0 0

    free(ptr);
    return 0;
}
```

---

## 🔹 7. realloc (Reallocation)

* **Resize previously allocated memory**.
* Can **increase or decrease size**.
* Preserves **existing data** up to new size.

### Example:

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr = (int*) malloc(3 * sizeof(int));
    ptr[0]=1; ptr[1]=2; ptr[2]=3;

    ptr = (int*) realloc(ptr, 5 * sizeof(int)); // resize
    ptr[3]=4; ptr[4]=5;

    for(int i=0;i<5;i++)
        printf("%d ", ptr[i]);

    free(ptr);
    return 0;
}
```

**Output:**

```
1 2 3 4 5
```

---

## 🔹 8. free (Deallocation)

* Frees **allocated memory** to prevent **memory leaks**.
* After `free`, pointer becomes **dangling** → should set to `NULL`.

```c
free(ptr);
ptr = NULL;
```

---

## 🔹 9. Dynamic Arrays Using Pointers

* Arrays can be **created dynamically** when size is unknown at compile-time.

### 1D Array Example:

```c
int *arr = (int*) malloc(n * sizeof(int));
for(int i=0;i<n;i++) arr[i] = i+1;
```

### 2D Array Example:

```c
int **arr = (int**) malloc(rows * sizeof(int*));
for(int i=0;i<rows;i++)
    arr[i] = (int*) malloc(cols * sizeof(int));
```

* Use `free` for each row, then free main pointer:

```c
for(int i=0;i<rows;i++) free(arr[i]);
free(arr);
```

---

## 🔹 10. Advantages of Dynamic Memory Allocation

1. **Flexible memory usage** → allocate only what is needed.
2. **Adjustable at runtime** → use realloc to resize memory.
3. **Supports dynamic data structures** → linked lists, trees, graphs.
4. Efficient for **large arrays or structures** → avoid stack overflow.
5. Can **return memory from functions** via pointers.

---

## 🔹 11. Common Mistakes and Best Practices

1. **Not checking NULL** after malloc/calloc/realloc → crash.
2. **Not freeing memory** → memory leak.
3. **Dangling pointer** → pointer used after `free`.
4. **Invalid pointer arithmetic** → undefined behavior.
5. **Always match malloc/calloc with free**.
6. Initialize pointers to **NULL** after freeing.

---

## 🔹 12. Quick Comparison Table

| Function | Initialization | Syntax                 | Notes                          |
| -------- | -------------- | ---------------------- | ------------------------------ |
| malloc   | Garbage        | malloc(size)           | Returns void*, typecast needed |
| calloc   | 0              | calloc(n, size)        | Allocates for n elements       |
| realloc  | Preserves old  | realloc(ptr, new_size) | Resizes memory                 |
| free     | -              | free(ptr)              | Deallocates memory             |

---

Farhad, in **simple words**:

> * **Static memory** → fixed size, stack, compile-time
> * **Dynamic memory** → flexible, heap, runtime, controlled via pointers
> * **malloc/calloc** → allocate memory
> * **realloc** → resize memory
> * **free** → release memory

---
