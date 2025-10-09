
---

# 🔹 **Pointers and Dynamic Memory Allocation in C – Full Details**

---

## 🧠 1. What is Dynamic Memory?

* **Dynamic Memory** is memory **allocated at runtime** (while the program is running), unlike static memory, which is **fixed at compile time**.
* Allows programs to **adjust memory usage according to need**.
* Managed using **pointers**.

**Why dynamic memory is important:**

1. When **array size is unknown at compile-time**.
2. To **save memory** by allocating only what is needed.
3. To **create data structures** like linked lists, trees, and graphs.

---

## 🔹 2. Memory Layout in C

C program memory is divided into:

1. **Stack** → automatic variables (fixed size, fast, temporary)
2. **Heap** → dynamic memory (variable size, slower, manually managed)

**Pointers** are used to **access memory in the heap**.

---

## 🔹 3. Dynamic Memory Functions (stdlib.h)

C provides four main functions for dynamic memory management:

| Function  | Purpose                            | Syntax                                      |
| --------- | ---------------------------------- | ------------------------------------------- |
| `malloc`  | Allocate memory (uninitialized)    | `ptr = (type*) malloc(size_in_bytes);`      |
| `calloc`  | Allocate memory + initialize to 0  | `ptr = (type*) calloc(n, size_of_element);` |
| `realloc` | Resize previously allocated memory | `ptr = (type*) realloc(ptr, new_size);`     |
| `free`    | Deallocate memory                  | `free(ptr);`                                |

---

## 🔹 4. malloc (Memory Allocation)

* Allocates **specified bytes** in heap.
* Returns **pointer to first byte**.
* Memory is **uninitialized** → contains garbage values.

### Example:

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr;
    ptr = (int*) malloc(5 * sizeof(int)); // allocate array of 5 integers

    if(ptr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Assign values
    for(int i=0; i<5; i++) ptr[i] = i+1;

    // Print values
    for(int i=0; i<5; i++) printf("%d ", ptr[i]);

    free(ptr); // free memory
    return 0;
}
```

**Output:**

```
1 2 3 4 5
```

---

## 🔹 5. calloc (Contiguous Allocation)

* Allocates memory for **n elements of size bytes**.
* **Initializes all bytes to 0**.
* Syntax:

```c
ptr = (int*) calloc(n, sizeof(int));
```

### Example:

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr = (int*) calloc(5, sizeof(int)); // allocate and initialize to 0

    for(int i=0; i<5; i++) printf("%d ", ptr[i]); // prints 0 0 0 0 0

    free(ptr); // free memory
    return 0;
}
```

---

## 🔹 6. realloc (Re-allocation)

* Resize previously allocated memory.
* Can **increase or decrease size**.
* Preserves existing data (up to new size).

### Example:

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr = (int*) malloc(3 * sizeof(int));
    ptr[0]=1; ptr[1]=2; ptr[2]=3;

    ptr = (int*) realloc(ptr, 5 * sizeof(int)); // resize to 5 integers
    ptr[3] = 4; ptr[4] = 5;

    for(int i=0;i<5;i++) printf("%d ", ptr[i]);

    free(ptr); // free memory
    return 0;
}
```

**Output:**

```
1 2 3 4 5
```

---

## 🔹 7. free (Deallocate Memory)

* Frees previously allocated memory to avoid **memory leaks**.
* After `free`, pointer becomes **dangling** → should be set to `NULL`.

```c
free(ptr);
ptr = NULL; // avoid dangling pointer
```

---

## 🔹 8. Dynamic Memory and Pointers

* **Pointer stores the address of dynamically allocated memory**.
* Example:

```c
int *ptr = (int*) malloc(sizeof(int));
*ptr = 100; // store value
printf("%d\n", *ptr);
free(ptr); // free heap memory
```

**Memory Diagram:**

```
Heap:
0x500: 100  (malloc allocated memory)

Stack:
ptr -> 0x500 (pointer to heap)
```

---

## 🔹 9. Dynamic 2D Arrays Using Pointers

* Use **pointer to pointer** for dynamic 2D arrays.

### Example:

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows = 2, cols = 3;
    int **arr = (int**) malloc(rows * sizeof(int*));

    for(int i=0;i<rows;i++)
        arr[i] = (int*) malloc(cols * sizeof(int));

    // Assign values
    int count = 1;
    for(int i=0;i<rows;i++)
        for(int j=0;j<cols;j++)
            arr[i][j] = count++;

    // Print values
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }

    // Free memory
    for(int i=0;i<rows;i++)
        free(arr[i]);
    free(arr);

    return 0;
}
```

**Output:**

```
1 2 3
4 5 6
```

---

## 🔹 10. Advantages of Dynamic Memory Allocation

1. **Flexible memory usage** → allocate only what is needed.
2. Allows creation of **variable-sized arrays** at runtime.
3. Essential for **dynamic data structures** (linked lists, trees).
4. Can return memory from function via pointer.

---

## 🔹 11. Common Mistakes / Tips

1. **Not freeing memory** → memory leak.
2. **Dangling pointer** → access after `free`.
3. **Invalid pointer arithmetic** → undefined behavior.
4. **Check `NULL`** after malloc/calloc/realloc.
5. **Always match malloc/calloc with free**.

---

Farhad, in **simple words**:

> * **Static memory** → fixed at compile-time, fast, stack
> * **Dynamic memory** → allocated at runtime, flexible, heap, managed via pointers
> * **malloc/calloc** → allocate memory
> * **realloc** → resize memory
> * **free** → deallocate memory

---
