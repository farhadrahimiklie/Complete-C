
---

## 🧠 1. What Is `void`?

* `void` is a **special or empty data type** in C.
* It **represents nothing** — no value, no memory allocation (usually 0 bytes).
* It is **used in functions, pointers, and parameters** to indicate “no data.”

---

## 🧩 2. Uses of `void` in C

### **A. Void Function (No Return Value)**

* When a function does **not return any value**, we declare it as `void`.
* Example:

```c
#include <stdio.h>

void sayHello() {
    printf("Hello, Farhad!\n");
}

int main() {
    sayHello();
    return 0;
}
```

* Output:

```
Hello, Farhad!
```

> ✅ `void` indicates **no value will be returned** by the function.

---

### **B. Function with Void Parameters**

* If a function **takes no arguments**, we can declare it with `void` in parameters.

```c
#include <stdio.h>

void greet(void) {  // void inside () means no parameters
    printf("Welcome to C language!\n");
}

int main() {
    greet();
    return 0;
}
```

> ✅ `void` in parameter list explicitly tells the compiler: **function accepts no arguments**.

---

### **C. Void Pointers (Generic Pointer)**

* A **void pointer** is a pointer that can point to **any data type**.
* Syntax: `void *ptr;`

#### Example:

```c
#include <stdio.h>

int main() {
    int x = 10;
    float y = 3.14;

    void *ptr;      // generic pointer
    ptr = &x;       // points to int
    printf("Value of x: %d\n", *(int *)ptr); // typecast needed

    ptr = &y;       // points to float
    printf("Value of y: %.2f\n", *(float *)ptr);

    return 0;
}
```

**Output:**

```
Value of x: 10
Value of y: 3.14
```

> ✅ Key points:
>
> * Void pointer is **generic**.
> * You **must typecast** it before dereferencing.

---

### **D. Void as a Return Type in Pointers (Advanced)**

* `void` is used in **dynamic memory allocation** functions like `malloc()`:

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    void *ptr = malloc(5 * sizeof(int)); // allocate memory for 5 ints

    int *intPtr = (int *)ptr;            // typecast to int pointer
    for (int i = 0; i < 5; i++)
        intPtr[i] = i * 10;

    for (int i = 0; i < 5; i++)
        printf("%d ", intPtr[i]);

    free(ptr);  // free allocated memory
    return 0;
}
```

**Output:**

```
0 10 20 30 40
```

> 🔹 `malloc()` returns `void *` because it can allocate memory for **any data type**.

---

## 🧩 3. Key Points About `void` Type

| Feature                | Explanation                                |
| ---------------------- | ------------------------------------------ |
| **Memory**             | Usually 0 bytes                            |
| **Represents**         | Nothing (no value)                         |
| **Usage**              | Functions, pointers, and parameters        |
| **Function return**    | `void` means no value returned             |
| **Function parameter** | `void` inside () means no arguments        |
| **Pointer**            | `void *` can point to any type             |
| **Typecasting**        | Required for `void *` before dereferencing |

---

### ⚡ 4. Example: Using Void in All Ways

```c
#include <stdio.h>
#include <stdlib.h>

void displayMessage(void) {
    printf("Welcome to void data type in C!\n");
}

int main() {
    displayMessage();

    // Void pointer example
    int num = 42;
    void *ptr = &num;
    printf("Value using void pointer: %d\n", *(int *)ptr);

    return 0;
}
```

**Output:**

```
Welcome to void data type in C!
Value using void pointer: 42
```

---

### 🏁 Summary

1. `void` = **empty type** → no value, no memory
2. Use **void in functions**:

   * `void function()` → function returns nothing
   * `void function(void)` → function takes no arguments
3. Use **void pointers** to store **any type of address**
4. `malloc()` and `free()` often use **void pointers**
5. Always **typecast void pointers** before dereferencing

---