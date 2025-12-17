# 🔹 **Strings and String Functions in C – Full Details**

---

## 🧠 1. What Is a String in C?

* A **string** is a **sequence of characters** stored in a **1D character array**.
* Strings **end with a special null character `\0`**, which marks the end of the string.

> Example:

```c
char str[] = "Farhad"; // automatically adds '\0'
```

---

## 🔹 2. Declaring Strings

### Method 1: Fixed-size array

```c
char str[10] = "Hello"; // space for 9 characters + '\0'
```

### Method 2: Automatic size

```c
char str[] = "Hello"; // size = 6 (includes '\0')
```

### Method 3: Using character list

```c
char str[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
```

---

## 🔹 3. Input/Output of Strings

### Using `scanf()`

```c
char name[20];
scanf("%s", name); // reads until space
```

> ⚠️ Stops reading at **space**, so use `fgets()` for full line input.

### Using `fgets()`

```c
fgets(name, sizeof(name), stdin); // reads spaces
```

---

## 🔹 4. Accessing and Modifying Strings

* Access: `str[index]` (0-based)
* Modify: `str[0] = 'X';` (only for arrays, not string literals)

---

## 🔹 5. String Functions in `<string.h>`

C provides **many functions** for strings. Here’s the **full detailed list**:

---

### 1️⃣ `strlen()`

* Returns the **length of the string** (number of characters **excluding `\0`**)

```c
#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "Farhad";
    printf("Length: %lu\n", strlen(str));
    return 0;
}
```

**Output:**

```
6
```

---

### 2️⃣ `strcpy(dest, src)`

* Copies **source string** into **destination**

```c
char str1[20], str2[] = "Hello";
strcpy(str1, str2);
```

**Output:** `str1 = "Hello"`

> ⚠️ Make sure `dest` has enough space.

---

### 3️⃣ `strncpy(dest, src, n)`

* Copies **first n characters** from `src` to `dest`

```c
char str1[10];
strncpy(str1, "Farhad", 3); // copies "Far"
str1[3] = '\0'; // add null character
```

---

### 4️⃣ `strcat(dest, src)`

* Concatenates `src` to **end of dest**

```c
char str1[20] = "Hello ";
char str2[] = "World";
strcat(str1, str2);
printf("%s\n", str1); // Hello World
```

---

### 5️⃣ `strncat(dest, src, n)`

* Concatenates **first n characters** of `src` to `dest`

```c
char str1[20] = "Hello ";
strncat(str1, "Farhad", 3); // "Hello Far"
```

---

### 6️⃣ `strcmp(str1, str2)`

* Compares **two strings**
* Returns:

  * `0` → if equal
  * `<0` → if str1 < str2
  * `>0` → if str1 > str2

```c
strcmp("abc", "abd"); // returns negative
strcmp("abc", "abc"); // returns 0
```

---

### 7️⃣ `strncmp(str1, str2, n)`

* Compares **first n characters** of two strings

```c
strncmp("abcdef", "abcxyz", 3); // returns 0
```

---

### 8️⃣ `strchr(str, ch)`

* Returns **pointer to first occurrence** of character `ch` in string
* Returns `NULL` if not found

```c
char *ptr = strchr("Farhad", 'a'); 
printf("%c\n", *ptr); // 'a'
```

---

### 9️⃣ `strrchr(str, ch)`

* Returns **pointer to last occurrence** of `ch` in string

```c
char *ptr = strrchr("Farhad", 'a');
printf("%c\n", *ptr); // 'a' (last 'a')
```

---

### 🔟 `strstr(str, substr)`

* Returns **pointer to first occurrence** of substring

```c
char *ptr = strstr("Hello Farhad", "Far");
printf("%s\n", ptr); // Farhad
```

---

### 1️⃣1️⃣ `sprintf()` and `sscanf()`

* `sprintf()` → write formatted string to **character array**
* `sscanf()` → read formatted data from **string**

```c
char str[50];
int num = 10;
sprintf(str, "Number = %d", num); // str = "Number = 10"
```

---

### 1️⃣2️⃣ `strtok()`

* Splits string into **tokens** based on delimiters

```c
char str[] = "Farhad,KLIE,Programming";
char *token = strtok(str, ",");
while(token != NULL) {
    printf("%s\n", token);
    token = strtok(NULL, ",");
}
```

**Output:**

```
Farhad
KLIE
Programming
```

---

## 🔹 6. Important Notes About Strings

1. Always **reserve space for `\0`**
2. Strings are **arrays of characters** → can use **loops** to process
3. Functions from `<string.h>` make manipulation **easier and faster**
4. Be careful with **buffer overflow** (always ensure array has enough space)
5. **String literals** are read-only → cannot modify them directly

---

## 🔹 7. Summary Table of String Functions

| Function                | Purpose                  | Example                 |
| ----------------------- | ------------------------ | ----------------------- |
| `strlen(str)`           | Length of string         | `strlen("Farhad") → 6`  |
| `strcpy(dest, src)`     | Copy string              | `strcpy(a,b)`           |
| `strncpy(dest, src, n)` | Copy n chars             | `strncpy(a,b,3)`        |
| `strcat(dest, src)`     | Concatenate              | `strcat(a,b)`           |
| `strncat(dest, src, n)` | Concatenate n chars      | `strncat(a,b,3)`        |
| `strcmp(str1,str2)`     | Compare strings          | `strcmp(a,b)`           |
| `strncmp(str1,str2,n)`  | Compare first n chars    | `strncmp(a,b,3)`        |
| `strchr(str,ch)`        | First occurrence of char | `strchr(a,'a')`         |
| `strrchr(str,ch)`       | Last occurrence of char  | `strrchr(a,'a')`        |
| `strstr(str,substr)`    | Find substring           | `strstr(a,"abc")`       |
| `sprintf(str,...)`      | Format into string       | `sprintf(a,"Num=%d",x)` |
| `sscanf(str,...)`       | Read from string         | `sscanf(a,"%d",&x)`     |
| `strtok(str, delim)`    | Tokenize string          | `strtok(a,",")`         |

---
