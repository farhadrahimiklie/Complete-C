## 1. What Is a 2D Array?

A **2D array** is an array of arrays. It represents data in rows and columns, similar to a table or matrix.

Example of a 3x3 2D structure:

```
[ 1 2 3 ]
[ 4 5 6 ]
[ 7 8 9 ]
```

In C, a 2D array stores data in **row-major order** (row by row in memory).

---

## 2. Declaring a 2D Array (Without Pointers)

A static 2D array has fixed rows and columns.

### Syntax

```c
int arr[rows][cols];
```

### Example

```c
#include <stdio.h>

int main() {
    int arr[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}
```

### Key Points

* Memory is allocated automatically.
* Size is fixed at compile time.
* Fast and simple to use.
* Stored in a single continuous block of memory.

---

## 3. Accessing 2D Array Elements

Use the syntax:

```c
arr[row][column]
```

Example:

```c
int x = arr[1][2];   // gets '6'
```

---

## 4. 2D Arrays Using Pointers (Dynamic Allocation)

This allows creating 2D arrays at **runtime** and provides flexibility for large or variable-size data.

There are **two major methods**:

### Method A: Pointer to Pointer (`int **arr`)

Each row is allocated separately.

#### Example

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows = 3, cols = 3;
    int **arr = malloc(rows * sizeof(int*));

    for (int i = 0; i < rows; i++) {
        arr[i] = malloc(cols * sizeof(int));
    }

    // Fill the array
    int value = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = value++;
        }
    }

    // Print the array
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    // Free memory
    for (int i = 0; i < rows; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}
```

#### Characteristics

* Rows may be non-contiguous in memory.
* Very flexible.
* You must free memory manually.

---

### Method B: Single Block Allocation (`int *arr` but used like 2D)

Allocate a single continuous block, then index manually.

#### Example

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows = 3, cols = 3;
    int *arr = malloc(rows * cols * sizeof(int));

    int value = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i * cols + j] = value++;
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", arr[i * cols + j]);
        }
        printf("\n");
    }

    free(arr);
    return 0;
}
```

#### Characteristics

* Memory is contiguous.
* Slightly faster due to cache locality.
* More complex indexing.

---

## 5. Pros and Cons Comparison

| Approach                      | Memory Layout  | Flexible Size | Difficulty | Notes                         |
| ----------------------------- | -------------- | ------------- | ---------- | ----------------------------- |
| Static 2D Array               | Contiguous     | No            | Easy       | Fixed size at compile time    |
| Pointer-to-Pointer (`int **`) | Non-contiguous | Yes           | Medium     | Each row allocated separately |
| Single Block (`int *`)        | Contiguous     | Yes           | Hard       | Best for performance          |

---

## 6. When To Use What

* **Use static 2D arrays** for small, fixed matrix sizes.
* **Use `int **` dynamic arrays** when rows or columns must be variable at runtime.
* **Use single-block allocation** for performance-sensitive applications.
