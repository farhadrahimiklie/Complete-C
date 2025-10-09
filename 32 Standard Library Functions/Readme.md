
---

# 🔹 **Standard Library Functions in C – Full Details**

---

## 🧠 1. What Are Standard Library Functions?

* Standard library functions are **predefined functions in C** that perform **common tasks** like:

  * Input/output
  * String manipulation
  * Mathematical calculations
  * Memory allocation
  * Date/time operations

* They are provided in **header files**, so you **don’t need to write them manually**.

---

## 🔹 2. Header Files and Standard Library Functions

### 2.1 What is a Header File?

* A **header file** contains **function declarations, macros, constants, and data type definitions**.
* Included using `#include <header.h>` at the top of your program.

**Common Header Files:**

| Header File  | Purpose                                                |
| ------------ | ------------------------------------------------------ |
| `<stdio.h>`  | Input/output (`printf`, `scanf`, `getchar`, `putchar`) |
| `<stdlib.h>` | General utilities (`malloc`, `free`, `exit`, `rand`)   |
| `<string.h>` | String functions (`strlen`, `strcpy`, `strcmp`)        |
| `<math.h>`   | Math functions (`sqrt`, `pow`, `sin`, `cos`)           |
| `<time.h>`   | Date & time (`time`, `clock`)                          |
| `<ctype.h>`  | Character handling (`toupper`, `isdigit`)              |

---

## 🔹 3. Types of Standard Library Functions

### 3.1 Input/Output Functions (`<stdio.h>`)

| Function         | Description            | Example                  |
| ---------------- | ---------------------- | ------------------------ |
| `printf`         | Print formatted output | `printf("Hello %d", x);` |
| `scanf`          | Read formatted input   | `scanf("%d", &x);`       |
| `getchar`        | Read single character  | `char c = getchar();`    |
| `putchar`        | Write single character | `putchar(c);`            |
| `gets` / `fgets` | Read string            | `fgets(str, 50, stdin);` |
| `puts`           | Print string           | `puts("Hello");`         |

---

### 3.2 String Handling Functions (`<string.h>`)

| Function                     | Description              |
| ---------------------------- | ------------------------ |
| `strlen(str)`                | Returns length of string |
| `strcpy(dest, src)`          | Copy string              |
| `strcat(dest, src)`          | Concatenate strings      |
| `strcmp(str1, str2)`         | Compare strings          |
| `strstr(haystack, needle)`   | Find substring           |
| `strrev(str)` (non-standard) | Reverse string           |

**Example:**

```c
#include <stdio.h>
#include <string.h>
int main() {
    char str1[20] = "Hello";
    char str2[20];
    strcpy(str2, str1);
    printf("Copied string: %s\n", str2);
    printf("Length: %lu\n", strlen(str1));
    return 0;
}
```

---

### 3.3 Math Functions (`<math.h>`)

| Function                 | Description             |
| ------------------------ | ----------------------- |
| `sqrt(x)`                | Square root             |
| `pow(x, y)`              | x raised to power y     |
| `ceil(x)`                | Round up                |
| `floor(x)`               | Round down              |
| `abs(x)`                 | Absolute value          |
| `sin(x), cos(x), tan(x)` | Trigonometric functions |

**Example:**

```c
#include <stdio.h>
#include <math.h>
int main() {
    double x = 9;
    printf("Square root = %.2f\n", sqrt(x));
    printf("Power = %.2f\n", pow(2,3));
    return 0;
}
```

---

### 3.4 General Utility Functions (`<stdlib.h>`)

| Function          | Description                           |
| ----------------- | ------------------------------------- |
| `malloc(size)`    | Allocate memory dynamically           |
| `calloc(n, size)` | Allocate memory and initialize with 0 |
| `free(ptr)`       | Free allocated memory                 |
| `rand()`          | Generate random number                |
| `srand(seed)`     | Seed random number generator          |
| `exit(status)`    | Terminate program                     |

**Example:**

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr = (int*) malloc(3 * sizeof(int));
    ptr[0] = 10; ptr[1] = 20; ptr[2] = 30;
    for(int i=0;i<3;i++) printf("%d ", ptr[i]);
    free(ptr); // free memory
    return 0;
}
```

---

### 3.5 Character Handling (`<ctype.h>`)

| Function     | Description           |
| ------------ | --------------------- |
| `isalpha(c)` | Check if alphabet     |
| `isdigit(c)` | Check if digit        |
| `isalnum(c)` | Check if alphanumeric |
| `toupper(c)` | Convert to uppercase  |
| `tolower(c)` | Convert to lowercase  |

**Example:**

```c
#include <stdio.h>
#include <ctype.h>
int main() {
    char ch = 'a';
    if(isalpha(ch)) printf("%c is a letter\n", ch);
    printf("Uppercase: %c\n", toupper(ch));
    return 0;
}
```

---

### 3.6 Time Functions (`<time.h>`)

| Function           | Description                     |
| ------------------ | ------------------------------- |
| `time(NULL)`       | Returns current time in seconds |
| `clock()`          | Processor time used by program  |
| `difftime(t1, t2)` | Difference in seconds           |

**Example:**

```c
#include <stdio.h>
#include <time.h>

int main() {
    time_t t;
    time(&t);
    printf("Current time: %s", ctime(&t));
    return 0;
}
```

---

## 🔹 4. Advantages of Standard Library Functions

1. **Saves time** → don’t need to write code from scratch.
2. **Reliable & tested** → reduces bugs.
3. **Portable** → works across compilers and systems.
4. **Easy to learn & use** → just include the correct header file.

---

## 🔹 5. How to Use Standard Library Functions

1. Include the **appropriate header file** using `#include`.
2. Call the function with **required arguments**.
3. Understand **return type** and handle it properly.

```c
#include <stdio.h>
#include <string.h>

int main() {
    char str[50] = "C Programming";
    printf("Length: %lu\n", strlen(str));
    return 0;
}
```

---

## 🔹 6. Summary Table

| Category     | Header File  | Example Functions                          |
| ------------ | ------------ | ------------------------------------------ |
| Input/Output | `<stdio.h>`  | `printf`, `scanf`, `getchar`, `puts`       |
| String       | `<string.h>` | `strlen`, `strcpy`, `strcat`, `strcmp`     |
| Math         | `<math.h>`   | `sqrt`, `pow`, `abs`, `sin`, `cos`         |
| General      | `<stdlib.h>` | `malloc`, `free`, `rand`, `exit`           |
| Character    | `<ctype.h>`  | `isalpha`, `isdigit`, `toupper`, `tolower` |
| Time         | `<time.h>`   | `time`, `clock`, `difftime`, `ctime`       |

---

Farhad, in **simple words**:

> Standard library functions are **ready-made tools** in C. You **don’t reinvent the wheel** — just include the right header and use them.

---
