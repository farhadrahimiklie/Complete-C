## 1. Introduction to Character Arrays

A character array in C is a sequence of characters stored in contiguous memory. It is commonly used to store text or strings.

### Example

```c
char name[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
```

---

## 2. Memory Layout of Character Arrays

* Stored in **contiguous bytes**.
* Each character occupies **1 byte**.
* A string must end with a **null terminator '\0'**.

### Visual Layout

```
Index:   0   1   2   3   4   5
Value:   H   e   l   l   o  \0
```

---

## 3. Declaring Character Arrays

### Method 1: Explicit Size

```c
char city[20];
```

### Method 2: Initialization

```c
char word[] = "Computer";
```

### Method 3: Without Null Terminator (Not a String)

```c
char codes[3] = {'A', 'B', 'C'}; // Not a string
```

---

## 4. Input and Output with Character Arrays

### Using `scanf`

```c
char name[30];
scanf("%s", name);   // Stops at space
```

### Using `gets` (Unsafe)

Avoid using `gets()` because it is unsafe.

### Using `fgets` (Safe)

```c
fgets(name, sizeof(name), stdin);
```

### Printing

```c
printf("Your name: %s", name);
```

---

## 5. Common String Functions (string.h)

### 1. `strlen`

```c
int len = strlen(name);
```

### 2. `strcpy`

```c
strcpy(dest, source);
```

### 3. `strncpy`

```c
strncpy(dest, source, n);
```

### 4. `strcat`

```c
strcat(dest, source);
```

### 5. `strcmp`

```c
strcmp(str1, str2);
```

---

## 6. Character Array vs String Literal

### Character Array (Editable)

```c
char text[] = "Hello";
text[0] = 'M';
```

### String Literal (Read‑Only)

```c
char *msg = "Hello";  // Do NOT modify msg
```

---

## 7. Iterating Over Character Arrays

### Looping Through Characters

```c
for(int i = 0; name[i] != '\0'; i++) {
    printf("%c\n", name[i]);
}
```

---

## 8. Multidimensional Character Arrays (Array of Strings)

```c
char languages[3][10] = {
    "C",
    "Python",
    "Go"
};
```

Access an element:

```c
printf("%s", languages[1]); // Python
```

---

## 9. Passing Character Arrays to Functions

### Example

```c
void printMsg(char msg[]) {
    printf("%s", msg);
}
```

Call:

```c
printMsg("Welcome");
```

---

## 10. Common Errors and Pitfalls

### Missing Null Terminator

```c
char a[5] = {'H','e','l','l','o'}; // Missing '\0'
```

### Buffer Overflow

```c
char b[5];
strcpy(b, "HelloWorld"); // Unsafe
```

---

## 11. Advanced Topic: Pointer to Character Arrays

```c
char name[] = "Ali";
char *ptr = name;

while (*ptr != '\0') {
    printf("%c", *ptr);
    ptr++;
}
```

---

## 12. Advanced Topic: Array of Pointers to Strings

```c
char *countries[] = {
    "Iran",
    "USA",
    "Japan"
};
```

---

## 13. Practical Mini‑Project: Simple Username Validator

```c
#include <stdio.h>
#include <string.h>

int main() {
    char username[30];

    printf("Enter username: ");
    fgets(username, sizeof(username), stdin);

    if (strlen(username) < 5) {
        printf("Username too short");
    } else {
        printf("Valid username");
    }

    return 0;
}
```

---

## 14. Summary

This course covered:

* Character array basics
* Memory layout
* Input/output techniques
* String functions
* Multidimensional arrays
* Pointers and arrays
* Practical example
