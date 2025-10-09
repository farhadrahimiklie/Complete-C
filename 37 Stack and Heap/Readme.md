
---

# 🔹 **Stack and Heap in C – Full Details**

---

## 🧠 1. What are Stack and Heap?

### **Stack**

* **Memory region** used for **static memory allocation**.

* Stores:

  * Local variables (inside functions)
  * Function parameters
  * Return addresses

* Operates in **LIFO (Last In, First Out)** order — the **last function called is the first to be removed** from stack.

* Managed **automatically** by the compiler.

### **Heap**

* **Memory region** used for **dynamic memory allocation**.
* Stores memory allocated using **malloc, calloc, realloc**.
* Managed **manually** by the programmer (using `free`).
* Can grow and shrink during program execution.

---

## 🔹 2. Key Differences Between Stack and Heap

| Feature              | Stack                                          | Heap                                        |
| -------------------- | ---------------------------------------------- | ------------------------------------------- |
| Allocation type      | Static / Automatic                             | Dynamic / Manual                            |
| Management           | Managed by compiler                            | Managed by programmer                       |
| Lifetime             | Exists while function is running               | Exists until manually freed or program ends |
| Access speed         | Very fast                                      | Slower (because of dynamic management)      |
| Size                 | Usually smaller (depends on OS, e.g., 1MB–8MB) | Much larger (depends on OS memory)          |
| Allocation method    | Function call                                  | malloc/calloc/realloc                       |
| Memory fragmentation | No                                             | Possible                                    |
| Example usage        | Local variables, function calls                | Dynamic arrays, linked lists, trees         |

---

## 🔹 3. Stack Memory – Details

1. **How it works**:

   * When a function is called, a **stack frame** is created:

     * Parameters
     * Local variables
     * Return address

   * When the function returns, the stack frame is **automatically destroyed**.

2. **Example**:

```c
#include <stdio.h>

void function() {
    int x = 10; // stored in stack
    printf("x = %d\n", x);
}

int main() {
    function();
    return 0;
}
```

* `x` exists **only while function is running**.
* Memory is **automatically released** after function ends.

3. **Advantages of stack**:

   * Fast allocation/deallocation
   * Automatic memory management
   * No fragmentation

4. **Disadvantages of stack**:

   * Limited size
   * Cannot resize at runtime
   * Cannot return stack memory to main safely (address is destroyed)

---

## 🔹 4. Heap Memory – Details

1. **How it works**:

   * Programmer requests memory using **malloc/calloc/realloc**.
   * Memory persists **until free() is called**.

2. **Example**:

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr = (int*) malloc(5 * sizeof(int)); // heap memory
    for(int i=0;i<5;i++) ptr[i] = i+1;

    for(int i=0;i<5;i++) printf("%d ", ptr[i]);

    free(ptr); // must free heap memory
    return 0;
}
```

* Memory is **persistent** until `free` is called.
* Programmer **must manage it manually** to prevent memory leaks.

3. **Advantages of heap**:

   * Flexible memory allocation at runtime
   * Can allocate large amounts of memory
   * Useful for dynamic data structures (linked lists, trees, graphs)

4. **Disadvantages of heap**:

   * Slower than stack
   * Risk of **memory leaks**
   * Risk of **fragmentation**
   * Programmer responsible for deallocation

---

## 🔹 5. Memory Layout Diagram (Simplified)

```
Memory Address (High → Low)
---------------------------
|       Stack            |  <- grows downward
|------------------------|
|       Heap             |  <- grows upward
|------------------------|
|       BSS/Data Segment |  <- global/static variables
|------------------------|
|       Code/Text Segment|  <- instructions
---------------------------
```

* **Stack grows downward** (towards lower addresses)
* **Heap grows upward** (towards higher addresses)
* Both reside in RAM and do **not overlap** (in normal conditions)

---

## 🔹 6. Common Mistakes Related to Stack and Heap

1. **Stack Overflow**:

   * Happens when too much memory is allocated on stack (e.g., huge arrays, infinite recursion).
   * Example:

```c
void recursive() {
    int arr[100000]; // too large
    recursive();     // infinite recursion → stack overflow
}
```

2. **Memory Leak in Heap**:

   * Happens when dynamically allocated memory is **not freed**.
   * Example:

```c
int *ptr = (int*) malloc(100 * sizeof(int));
// forgot to free(ptr)
```

3. **Dangling Pointer**:

   * Accessing **heap memory after free**.

```c
free(ptr);
printf("%d", *ptr); // undefined behavior
```

---

## 🔹 7. Summary / Rules

| Rule         | Stack              | Heap                         |
| ------------ | ------------------ | ---------------------------- |
| Allocation   | Automatic          | Manual                       |
| Deallocation | Automatic          | Must use free()              |
| Lifetime     | Function execution | Until free() or program ends |
| Resizing     | Not possible       | Possible with realloc        |
| Speed        | Fast               | Slower                       |

---

### 🔹 Simple Analogy:

* **Stack** → your desk: you put things on top, remove from top, very fast, limited space.
* **Heap** → warehouse: you store things anywhere, can take as much space as needed, but slower to manage.

---