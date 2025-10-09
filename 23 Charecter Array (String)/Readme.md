
---

# 🔹 **Character Arrays (Strings) in C – Full Details**

---

## 🧠 1. What Is a String in C?

* A **string** in C is an **array of characters** terminated by a **special null character `'\0'`**.
* The **null character** indicates the **end of the string**.

> Example:

```c
char name[6] = {'F', 'a', 'r', 'h', 'a', 'd'};
```

* This is **not a valid string** because there is **no `'\0'`**, so C won’t know where the string ends.

Correct string:

```c
char name[6] = {'F', 'a', 'r', 'h', 'a', 'd', '\0'}; // needs 7 spaces
```

* Or easier:

```c
char name[] = "Farhad"; // automatically adds '\0'
```

---

## 🔹 2. Syntax of Character Array (String)

```c
char array_name[size];
```

* `array_name` → string name (identifier)
* `size` → number of characters including **null character `\0`**

---

### Example 1: Declaring Strings

```c
char str1[6] = "Hello";   // size = 6 (5 + 1 for '\0')
char str2[] = "World";    // size automatically = 6
```

---

## 🔹 3. Accessing Characters in a String

* Use **indexing**, starting from 0.

```c
#include <stdio.h>
int main() {
    char str[] = "Farhad";
    printf("First character: %c\n", str[0]);
    printf("Third character: %c\n", str[2]);
    return 0;
}
```

**Output:**

```
First character: F
Third character: r
```

---

## 🔹 4. Modifying a String

* Strings stored in **character arrays** can be **modified**.

```c
char str[] = "Hello";
str[0] = 'Y';  // now str = "Yello"
```

> ⚠️ If a string is **declared as `char *str = "Hello";`**, it is stored in **read-only memory**, and modification causes **undefined behavior**.

---

## 🔹 5. Input & Output Strings

### Using `scanf`

```c
#include <stdio.h>
int main() {
    char name[20];
    printf("Enter your name: ");
    scanf("%s", name);   // reads string until space
    printf("Hello %s\n", name);
    return 0;
}
```

> ⚠️ `scanf("%s", name)` **stops at space**. For full sentences, use `fgets`.

### Using `fgets` (Recommended for strings with spaces)

```c
#include <stdio.h>
int main() {
    char name[50];
    printf("Enter your full name: ");
    fgets(name, sizeof(name), stdin); // includes spaces
    printf("Hello %s\n", name);
    return 0;
}
```

---

## 🔹 6. String Length

* Count characters **before `\0`**.
* Use **`strlen()`** from `<string.h>`.

```c
#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "Farhad";
    printf("Length: %lu\n", strlen(str)); // 6
    return 0;
}
```

---

## 🔹 7. Common String Functions (`<string.h>`)

| Function                | Purpose                                          |
| ----------------------- | ------------------------------------------------ |
| `strlen(str)`           | Returns length of string (excluding `\0`)        |
| `strcpy(dest, src)`     | Copies `src` string to `dest`                    |
| `strcat(dest, src)`     | Concatenates `src` to end of `dest`              |
| `strcmp(str1, str2)`    | Compares two strings (0 if equal)                |
| `strncpy(dest, src, n)` | Copies first `n` characters                      |
| `strncat(dest, src, n)` | Concatenates first `n` characters                |
| `strchr(str, ch)`       | Returns pointer to first occurrence of `ch`      |
| `strstr(str, substr)`   | Returns pointer to first occurrence of substring |

---

### Example: String Copy and Concatenation

```c
#include <stdio.h>
#include <string.h>

int main() {
    char str1[20] = "Hello";
    char str2[] = "World";

    strcat(str1, str2); // concatenate
    printf("Concatenated: %s\n", str1);

    char str3[20];
    strcpy(str3, str2); // copy
    printf("Copied: %s\n", str3);

    return 0;
}
```

**Output:**

```
Concatenated: HelloWorld
Copied: World
```

---

## 🔹 8. Memory Layout of Strings

* Each character is stored in **contiguous memory**.
* Last element is always **`'\0'`**.

Example: `"Hi"`

| Index | 0 | 1 | 2  |
| ----- | - | - | -- |
| Value | H | i | \0 |

---

## 🔹 9. Important Notes

1. Strings in C are **1D char arrays** ending with `\0`.
2. Always **reserve space for `\0`** when declaring.
3. **Do not overflow** array size → undefined behavior.
4. **Use `fgets()`** for reading strings with spaces.
5. **String literals** stored in **read-only memory**, cannot be modified.

---

## 🔹 10. Summary Table

| Concept        | Explanation                                                                      |
| -------------- | -------------------------------------------------------------------------------- |
| Declaration    | `char str[10];` or `char str[] = "Hello";`                                       |
| Null Character | `'\0'` marks end of string                                                       |
| Access         | `str[index]`                                                                     |
| Modify         | `str[0] = 'X';` (if array, not literal)                                          |
| Input          | `scanf("%s", str)` → stops at space; `fgets(str, size, stdin)` → includes spaces |
| Functions      | `strlen`, `strcpy`, `strcat`, `strcmp`, etc.                                     |

---
