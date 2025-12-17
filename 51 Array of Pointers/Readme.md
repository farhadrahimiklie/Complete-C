# 🔹 **Array of Pointers in C – Full Details**

---

## 🧠 1. What is an Array of Pointers?

* An **array of pointers** is **an array where each element is a pointer** instead of a regular variable.
* Each element can **store the address of a variable, array, or dynamically allocated memory**.

### Syntax:

```c
data_type *array_name[size];
```

* `data_type *` → pointer to data_type
* `size` → number of pointers in the array

---

## 🔹 2. Basic Example: Array of Integer Pointers

```c
#include <stdio.h>

int main() {
    int a = 10, b = 20, c = 30;

    // Array of pointers
    int *arr[3];

    arr[0] = &a;
    arr[1] = &b;
    arr[2] = &c;

    // Access values via pointers
    for(int i = 0; i < 3; i++) {
        printf("Value of element %d = %d\n", i, *arr[i]);
    }

    return 0;
}
```

**Output:**

```
Value of element 0 = 10
Value of element 1 = 20
Value of element 2 = 30
```

**Explanation:**

* `arr` is an **array of 3 pointers**
* Each pointer stores the **address of an integer**
* `*arr[i]` → dereferences the pointer to get the value

---

## 🔹 3. Array of Pointers to Strings

* **Strings in C** are **character arrays**, but you can store **addresses of strings** in an array of pointers.

### Example:

```c
#include <stdio.h>

int main() {
    char *names[] = {"Farhad", "Ali", "Sara"};

    for(int i = 0; i < 3; i++) {
        printf("Name %d: %s\n", i, names[i]);
    }

    return 0;
}
```

**Output:**

```
Name 0: Farhad
Name 1: Ali
Name 2: Sara
```

**Explanation:**

* `names` → array of pointers to **char (strings)**
* Each element points to the **first character of a string literal**
* Very memory-efficient because **strings can have different lengths**

---

## 🔹 4. Array of Pointers with Dynamic Memory

* Useful for **dynamic arrays of different sizes**.

### Example:

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 3;
    int *arr[n];

    // Dynamically allocate memory for each pointer
    for(int i = 0; i < n; i++) {
        arr[i] = (int*)malloc(sizeof(int));
        *arr[i] = (i+1) * 10;
    }

    for(int i = 0; i < n; i++) {
        printf("%d ", *arr[i]);
        free(arr[i]); // free memory
    }

    return 0;
}
```

**Output:**

```
10 20 30
```

* Each element points to **dynamically allocated memory**
* Useful for arrays where **size of each sub-array may vary**

---

## 🔹 5. Array of Function Pointers

* You can also have an **array of pointers to functions**, very useful for **callbacks and menu-driven programs**.

### Example:

```c
#include <stdio.h>

void hello() { printf("Hello\n"); }
void bye() { printf("Goodbye\n"); }

int main() {
    void (*funcArr[2])() = {hello, bye};

    for(int i = 0; i < 2; i++) {
        funcArr[i](); // call function via pointer
    }

    return 0;
}
```

**Output:**

```
Hello
Goodbye
```

* Each element of `funcArr` stores the **address of a function**
* Can **call functions dynamically**

---

## 🔹 6. Key Points / Advantages

1. **Memory Efficiency**: Especially for strings of varying lengths
2. **Flexibility**: Can store addresses of different variables, arrays, or functions
3. **Dynamic Data Handling**: Works well with **malloc/free**
4. **Powerful in Advanced C**: Used in **callback functions, tables, and dynamic structures**

---

## 🔹 7. Summary

* **Array of Pointers** = array where each element is a **pointer**
* Can point to:

  * Regular variables
  * Strings / character arrays
  * Dynamically allocated memory
  * Functions
* Useful for **dynamic and flexible programming**

---

Farhad, in simple words:

> * Think of it like a **row of addresses** instead of values.
> * Each address points to something important: a number, string, or function.
> * Super useful when you need **flexible, dynamic, or variable-sized data**.

---
