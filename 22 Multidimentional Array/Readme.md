
---

# 🔹 **Two-Dimensional Arrays (2D Arrays) in C – Full Details**

---

## 🧠 1. What Is a 2D Array?

* A **2D array** is an **array of arrays**.
* Think of it as a **table with rows and columns**.
* Each element is accessed using **two indices**: `[row][column]`.

> Example: Storing marks of 3 students in 4 subjects:

```c
int marks[3][4];
```

* 3 → number of rows (students)
* 4 → number of columns (subjects)

---

## 🔹 2. Syntax of 2D Array

```c
data_type array_name[rows][columns];
```

* `data_type` → type of elements (int, float, char…)
* `array_name` → name of the array
* `rows` → number of rows
* `columns` → number of columns

---

### Example 1: Declaration

```c
int matrix[3][4]; // 3 rows, 4 columns
```

---

### Example 2: Initialization

#### Method 1: Row-wise

```c
int matrix[2][3] = {
    {1, 2, 3},
    {4, 5, 6}
};
```

* `matrix[0][0] = 1`, `matrix[0][1] = 2`, `matrix[0][2] = 3`
* `matrix[1][0] = 4`, `matrix[1][1] = 5`, `matrix[1][2] = 6`

#### Method 2: Single line

```c
int matrix[2][3] = {1, 2, 3, 4, 5, 6};
```

* C fills elements **row by row** automatically.

---

## 🔹 3. Accessing Elements

```c
matrix[row_index][column_index]
```

* Indexing starts at **0** for both row and column.

### Example

```c
#include <stdio.h>

int main() {
    int matrix[2][3] = {{1,2,3},{4,5,6}};
    printf("Element at [1][2]: %d\n", matrix[1][2]); // 6
    return 0;
}
```

---

## 🔹 4. Modifying Elements

```c
matrix[0][1] = 10;  // change second element of first row
```

---

## 🔹 5. Input & Output Using Loops

* Use **nested loops**: outer loop for rows, inner loop for columns.

### Example: Input Matrix

```c
#include <stdio.h>
int main() {
    int matrix[2][3];
    int i, j;

    // Input
    for(i = 0; i < 2; i++) {
        for(j = 0; j < 3; j++) {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    // Output
    printf("Matrix is:\n");
    for(i = 0; i < 2; i++) {
        for(j = 0; j < 3; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
```

---

## 🔹 6. Memory Layout

* Stored in **row-major order** (C stores **row by row**).
* Example: `int matrix[2][3] = { {1,2,3}, {4,5,6} };`

| Row\Col | 0 | 1 | 2 |
| ------- | - | - | - |
| 0       | 1 | 2 | 3 |
| 1       | 4 | 5 | 6 |

* Memory addresses increase **contiguously row by row**.

---

## 🔹 7. Multidimensional Arrays (>2D)

* You can create **3D or higher arrays**:

```c
int arr[2][3][4]; // 2 blocks, 3 rows, 4 columns
```

* Usually used for **complex data structures**, like **3D matrices, cubes, or images**.

---

## 🔹 8. Important Notes

1. **Index starts from 0** → last index = size-1
2. **Elements must be same data type**
3. **Rows and columns must be known at compile time** (static arrays)
4. **Use nested loops** for input/output
5. **Array name acts as pointer to first row**

### Example: Array as Pointer

```c
#include <stdio.h>
int main() {
    int matrix[2][3] = {{1,2,3},{4,5,6}};
    printf("Address of first row: %p\n", matrix);
    printf("Address of first element: %p\n", &matrix[0][0]);
    return 0;
}
```

---

## 🔹 9. Common Mistakes

1. **Accessing out-of-bounds indices** → Undefined behavior

```c
matrix[2][0]; // Invalid! max row index = 1
```

2. **Mixing data types** → Not allowed
3. **Forgetting nested loops for processing elements**

---

## 🔹 10. Summary Table

| Concept        | Explanation                                |
| -------------- | ------------------------------------------ |
| Declaration    | `data_type name[rows][columns];`           |
| Initialization | `int matrix[2][3] = {{1,2,3},{4,5,6}};`    |
| Access         | `matrix[i][j]`                             |
| Looping        | Nested loops (outer row, inner column)     |
| Memory         | Row-major order                            |
| Index          | Rows: 0 to rows-1, Columns: 0 to columns-1 |

---
