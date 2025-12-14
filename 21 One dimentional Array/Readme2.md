## 1. Introduction to Arrays

An array in C is a collection of elements of the same data type stored in contiguous memory locations. Arrays allow efficient storage and access of multiple values using a single variable name.

Key characteristics:

* Fixed size.
* Same data type for all elements.
* Indexed starting from 0.

---

## 2. One-Dimensional Arrays (1D Arrays)

A one-dimensional array represents a linear list of data.

### 2.1 Declaration of 1D Arrays

```c
int numbers[10];
```

This creates an integer array with 10 elements indexed from 0 to 9.

### 2.2 Initialization

```c
int a[5] = {10, 20, 30, 40, 50};

int b[5] = {0};  // all 5 elements set to 0
```

### 2.3 Accessing Elements

```c
printf("%d", a[2]);   // prints 30
```

### 2.4 Updating Elements

```c
a[1] = 100;  // second element becomes 100
```

### 2.5 Inputting and Outputting Elements

```c
int arr[5];
for(int i=0; i<5; i++) {
    scanf("%d", &arr[i]);
}

for(int i=0; i<5; i++) {
    printf("%d ", arr[i]);
}
```

### 2.6 Memory Layout of 1D Arrays

Elements are stored continuously:

```
index:  0   1   2   3   4
value: 10  20  30  40  50
```

---

## 3. Two-Dimensional Arrays (2D Arrays)

A two-dimensional array represents a table (matrix) of rows and columns.

### 3.1 Declaration

```c
int matrix[3][4];  // 3 rows, 4 columns
```

### 3.2 Initialization

```c
int m[2][3] = {
    {1, 2, 3},
    {4, 5, 6}
};
```

### 3.3 Accessing Elements

```c
printf("%d", m[1][2]);   // prints 6
```

### 3.4 Updating Elements

```c
m[0][1] = 20;
```

### 3.5 Inputting and Outputting 2D Arrays

```c
int arr[3][3];
for(int i=0; i<3; i++) {
    for(int j=0; j<3; j++) {
        scanf("%d", &arr[i][j]);
    }
}

for(int i=0; i<3; i++) {
    for(int j=0; j<3; j++) {
        printf("%d ", arr[i][j]);
    }
    printf("\n");
}
```

### 3.6 Memory Layout of 2D Arrays

C stores 2D arrays in row-major order:

```
Row 0: a00 a01 a02
Row 1: a10 a11 a12
```

Stored in memory as:
a00 a01 a02 a10 a11 a12

---

## 4. Passing Arrays to Functions

### 4.1 Passing 1D Arrays

```c
void printArray(int arr[], int size) {
    for(int i=0; i<size; i++) {
        printf("%d ", arr[i]);
    }
}
```

### 4.2 Passing 2D Arrays

```c
void printMatrix(int m[][3], int rows) {
    for(int i=0; i<rows; i++) {
        for(int j=0; j<3; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}
```

---

## 5. Common Mistakes to Avoid

1. Accessing out-of-range indexes.
2. Using uninitialized arrays.
3. Confusing rows and columns in 2D arrays.
4. Forgetting that arrays in C do not grow dynamically.

---

## 6. Practical Examples

### Example 1: Find the sum of elements in a 1D array

```c
int sum = 0;
for(int i=0; i<5; i++) sum += arr[i];
printf("Sum = %d", sum);
```

### Example 2: Matrix addition

```c
int c[2][3];
for(int i=0; i<2; i++) {
    for(int j=0; j<3; j++) {
        c[i][j] = a[i][j] + b[i][j];
    }
}
```
