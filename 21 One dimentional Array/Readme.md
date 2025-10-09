
---

# 🔹 **Arrays in C (One-Dimensional Arrays Full Details)**

---

## 🧠 1. What Is an Array?

* An **array** is a **collection of elements of the same data type** stored in **contiguous memory locations**.
* Each element in the array can be **accessed using an index**.
* Arrays allow **efficient storage and manipulation** of multiple values.

> Example:
> Storing marks of 5 students in a single variable:

```c
int marks[5]; // array of 5 integers
```

---

## 🔹 2. Syntax of One-Dimensional Array

```c
data_type array_name[size];
```

* `data_type` → type of elements (int, float, char, etc.)
* `array_name` → name of the array (identifier)
* `size` → **number of elements** (must be positive integer)

---

### Example 1: Declaring an Array

```c
int numbers[5]; // stores 5 integers
```

* Memory is allocated for **5 integers** in contiguous locations.

---

### Example 2: Initializing an Array

```c
int numbers[5] = {10, 20, 30, 40, 50};
```

* `numbers[0] = 10`
* `numbers[1] = 20`
* `numbers[2] = 30`
* `numbers[3] = 40`
* `numbers[4] = 50`

> ⚠️ Indexing starts at **0** in C. Last index is `size-1`.

---

### Example 3: Partial Initialization

```c
int numbers[5] = {10, 20}; // rest elements = 0
```

* `numbers[0] = 10`
* `numbers[1] = 20`
* `numbers[2] = 0`
* `numbers[3] = 0`
* `numbers[4] = 0`

---

### Example 4: Compiler Can Auto-Calculate Size

```c
int numbers[] = {1, 2, 3, 4, 5}; // size = 5 automatically
```

---

## 🔹 3. Accessing Array Elements

* Use **index** inside square brackets `[ ]`.
* Index starts from **0** to `size-1`.

```c
#include <stdio.h>

int main() {
    int numbers[5] = {10, 20, 30, 40, 50};
    printf("First element: %d\n", numbers[0]);
    printf("Third element: %d\n", numbers[2]);
    return 0;
}
```

**Output:**

```
First element: 10
Third element: 30
```

---

## 🔹 4. Modifying Array Elements

```c
numbers[1] = 25;  // change second element
numbers[4] = 60;  // change fifth element
```

---

## 🔹 5. Input & Output Using Loops

### Example: Input Array Elements from User

```c
#include <stdio.h>
int main() {
    int numbers[5], i;

    // Input
    for(i = 0; i < 5; i++) {
        printf("Enter number %d: ", i+1);
        scanf("%d", &numbers[i]);
    }

    // Output
    printf("You entered: ");
    for(i = 0; i < 5; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    return 0;
}
```

---

## 🔹 6. Memory Layout of Array

* Array elements are stored in **contiguous memory**.
* Example: `int numbers[5] = {10, 20, 30, 40, 50};`

| Index   | 0    | 1    | 2    | 3    | 4    |
| ------- | ---- | ---- | ---- | ---- | ---- |
| Value   | 10   | 20   | 30   | 40   | 50   |
| Address | 1000 | 1004 | 1008 | 1012 | 1016 |

> If `int` = 4 bytes, addresses increase by 4 bytes.

---

## 🔹 7. Important Notes About 1D Arrays

1. **Index starts at 0** → first element = `array[0]`
2. **Last index = size-1**
3. **Array size must be known at compile time** (for static arrays)
4. **All elements must be of the same data type**
5. **Array name itself acts as a pointer** to first element

   * `numbers` ≈ `&numbers[0]`

---

### Example: Array as Pointer

```c
#include <stdio.h>
int main() {
    int numbers[3] = {10, 20, 30};
    printf("Address of first element: %p\n", numbers);
    printf("Address of first element using &: %p\n", &numbers[0]);
    return 0;
}
```

**Output:** (example addresses)

```
Address of first element: 0x7ffee1a5b98c
Address of first element using &: 0x7ffee1a5b98c
```

---

## 🔹 8. Common Mistakes

1. **Accessing out-of-bounds index** → Undefined behavior

```c
printf("%d", numbers[5]); // Invalid! max index = 4
```

2. **Using uninitialized array** → Garbage values

3. **Mixing data types** → Not allowed

---

## 🔹 9. Summary Table

| Concept        | Explanation                                              |
| -------------- | -------------------------------------------------------- |
| Declaration    | `data_type array_name[size];`                            |
| Initialization | `int arr[5] = {1,2,3,4,5};`                              |
| Access         | `array[index]`                                           |
| Index          | Starts at `0`, ends at `size-1`                          |
| Memory         | Contiguous memory, array name = pointer to first element |
| Loop Usage     | Commonly used with `for`/`while` for input/output        |

---
