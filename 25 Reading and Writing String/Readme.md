# 🔹 **Reading and Writing Strings in C – Full Details**

---

## 🧠 1. Strings in C

* Strings in C are **arrays of characters ending with `\0`**.
* To read or write them, you need to handle **null termination** and **array sizes** carefully.

---

## 🔹 2. Writing Strings (Output)

### 2.1 Using `printf()`

* The simplest way to output a string is using **`%s`** format specifier.

```c
#include <stdio.h>
int main() {
    char str[] = "Farhad";
    printf("My name is %s\n", str);
    return 0;
}
```

**Output:**

```
My name is Farhad
```

* **Notes:**

  * `printf()` prints until it encounters **`\0`**.
  * You can combine **strings and other data**:

```c
int age = 20;
printf("%s is %d years old\n", str, age);
```

---

### 2.2 Using `puts()`

* Another function to write strings is **`puts()`**.
* Automatically adds **newline at the end**.

```c
#include <stdio.h>
int main() {
    char str[] = "Hello World";
    puts(str);
    return 0;
}
```

**Output:**

```
Hello World
```

> ⚠️ Unlike `printf()`, you **cannot format** strings with `puts()`.

---

## 🔹 3. Reading Strings (Input)

### 3.1 Using `scanf()`

* Most basic method for string input.

```c
#include <stdio.h>
int main() {
    char name[20];
    printf("Enter your name: ");
    scanf("%s", name);
    printf("Hello %s\n", name);
    return 0;
}
```

**Output Example:**

```
Enter your name: Farhad
Hello Farhad
```

* **Important notes:**

  * Stops reading at **first space**.
  * Cannot read multi-word input (e.g., “Farhad KLIE”).

---

### 3.2 Using `gets()` (Deprecated)

```c
char str[50];
gets(str); // reads entire line including spaces
```

* **Dangerous**: Can cause **buffer overflow** → do **not use** in modern C.

---

### 3.3 Using `fgets()` (Recommended)

* Safest way to read a string with **spaces**.
* Syntax:

```c
fgets(array_name, size, stdin);
```

* Reads up to **size-1 characters** or until newline.
* **Includes the newline character `\n`** if Enter is pressed.

```c
#include <stdio.h>
int main() {
    char str[50];
    printf("Enter your full name: ");
    fgets(str, sizeof(str), stdin);
    printf("Hello %s", str); // newline already included
    return 0;
}
```

**Output Example:**

```
Enter your full name: Farhad KLIE
Hello Farhad KLIE
```

* Remove the newline if needed:

```c
str[strcspn(str, "\n")] = '\0';
```

---

## 🔹 4. Reading Multiple Strings in Loop

* Example: Reading 3 names and printing them:

```c
#include <stdio.h>
int main() {
    char names[3][20]; // 3 strings, max 19 chars each
    for(int i = 0; i < 3; i++) {
        printf("Enter name %d: ", i+1);
        fgets(names[i], sizeof(names[i]), stdin);
        names[i][strcspn(names[i], "\n")] = '\0'; // remove newline
    }

    printf("Names entered:\n");
    for(int i = 0; i < 3; i++) {
        printf("%s\n", names[i]);
    }
    return 0;
}
```

**Output Example:**

```
Enter name 1: Farhad
Enter name 2: KLIE
Enter name 3: Programming
Names entered:
Farhad
KLIE
Programming
```

---

## 🔹 5. Important Notes About Reading and Writing Strings

1. Strings are **character arrays** → always ensure enough size.
2. `scanf("%s", str)` → **no spaces allowed**.
3. `fgets(str, size, stdin)` → **safest**, reads spaces and avoids overflow.
4. `puts(str)` → automatically prints newline.
5. Always **remove newline** from `fgets()` if exact string needed.
6. Avoid using `gets()` → **unsafe**.
7. Strings are **null-terminated** → printing functions stop at `\0`.

---

## 🔹 6. Summary Table

| Task                   | Function                  | Notes                           |
| ---------------------- | ------------------------- | ------------------------------- |
| Read single word       | `scanf("%s", str)`        | Stops at space                  |
| Read line              | `fgets(str, size, stdin)` | Includes spaces, safer          |
| Read line (deprecated) | `gets(str)`               | Avoid using                     |
| Print string           | `printf("%s", str)`       | Can format with other variables |
| Print string           | `puts(str)`               | Adds newline automatically      |

---
