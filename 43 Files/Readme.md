
---

# 🔹 **File Handling in C – Full Details**

---

## 🧠 1. Introduction to File Handling

* **Files** are permanent storage on disk (unlike variables which are temporary in memory).

* C provides **standard library functions** to **create, read, write, and manage files**.

* Two types of files:

  1. **Text Files** – contain readable characters (ASCII).
  2. **Binary Files** – contain raw data (int, float, structs, etc.).

* All file operations in C are done via **`FILE` pointer**:

```c
FILE *fp;
```

* Standard functions for file operations are in **`<stdio.h>`**.

---

## 🔹 2. Opening and Closing Files

**Syntax:**

```c
FILE *fopen(const char *filename, const char *mode);
int fclose(FILE *fp);
```

### Modes:

| Mode | Description                                  |
| ---- | -------------------------------------------- |
| "r"  | Read (file must exist)                       |
| "w"  | Write (creates file or truncates)            |
| "a"  | Append (write at end, creates if not exists) |
| "rb" | Read binary                                  |
| "wb" | Write binary                                 |
| "ab" | Append binary                                |
| "r+" | Read & write (text)                          |
| "w+" | Write & read (text)                          |
| "a+" | Append & read (text)                         |

**Example: Open a file for writing**

```c
FILE *fp = fopen("data.txt", "w");
if(fp == NULL){
    printf("Error opening file.\n");
    return 1;
}
// write to file
fclose(fp); // always close file
```

---

## 🔹 3. Reading and Writing Text Files

### a) Writing to a text file

```c
#include <stdio.h>

int main() {
    FILE *fp = fopen("data.txt", "w");
    if(fp == NULL){
        printf("Error opening file.\n");
        return 1;
    }

    fprintf(fp, "Hello, Farhad!\n"); // write formatted text
    fputs("Welcome to C Programming.\n", fp); // write string

    fclose(fp);
    return 0;
}
```

* **`fprintf`** = like `printf`, but writes to file.
* **`fputs`** = write string to file.

---

### b) Reading from a text file

```c
#include <stdio.h>

int main() {
    char str[100];
    FILE *fp = fopen("data.txt", "r");
    if(fp == NULL){
        printf("Error opening file.\n");
        return 1;
    }

    while(fgets(str, sizeof(str), fp) != NULL){
        printf("%s", str); // read line by line
    }

    fclose(fp);
    return 0;
}
```

* **`fgets`** reads one line at a time.
* **`fscanf`** can read formatted data like `scanf`.

---

## 🔹 4. Error Handling in File Operations

* Always **check if `fopen` returns NULL** → file may not exist or cannot be opened.
* **Check return values of read/write functions**:

```c
if(fputs("text", fp) == EOF)
    printf("Error writing to file.\n");
```

* Example:

```c
FILE *fp = fopen("data.txt", "r");
if(fp == NULL){
    perror("File open error"); // prints error reason
    return 1;
}
```

* `perror` prints the **system error message**.

---

## 🔹 5. Binary File Operations

* Binary files store **data in raw format**, not readable text.
* Useful for storing **integers, floats, structs**, etc.

### a) Writing to a binary file

```c
#include <stdio.h>

typedef struct {
    int id;
    char name[50];
    float marks;
} Student;

int main() {
    Student s1 = {1, "Farhad", 95.5};
    FILE *fp = fopen("student.bin", "wb"); // write binary
    if(fp == NULL){
        perror("Error opening file");
        return 1;
    }

    fwrite(&s1, sizeof(Student), 1, fp); // write struct
    fclose(fp);
    return 0;
}
```

* **`fwrite(pointer, size, count, file)`** writes raw bytes.
* **Parameters**:

  1. Address of data
  2. Size of each element
  3. Number of elements
  4. File pointer

---

### b) Reading from a binary file

```c
#include <stdio.h>

typedef struct {
    int id;
    char name[50];
    float marks;
} Student;

int main() {
    Student s1;
    FILE *fp = fopen("student.bin", "rb"); // read binary
    if(fp == NULL){
        perror("Error opening file");
        return 1;
    }

    fread(&s1, sizeof(Student), 1, fp); // read struct
    printf("%d %s %.2f\n", s1.id, s1.name, s1.marks);

    fclose(fp);
    return 0;
}
```

* **`fread(pointer, size, count, file)`** reads raw bytes.
* Binary files **preserve exact memory layout** (no formatting).

---

## 🔹 6. Error Handling in Binary Files

* Check `fread` and `fwrite` return values:

```c
if(fwrite(&s1, sizeof(Student), 1, fp) != 1)
    printf("Error writing data\n");

if(fread(&s1, sizeof(Student), 1, fp) != 1)
    printf("Error reading data\n");
```

* Helps **detect incomplete reads/writes**.

---

## 🔹 7. Advantages of Binary Files

1. Faster to read/write compared to text files
2. Exact storage of data types (int, float, struct)
3. Smaller file size (no formatting characters)

**Disadvantages:**

* Not human-readable
* Platform-dependent (due to endianness and struct padding)

---

## 🔹 8. Summary / Steps for File Handling

1. **Open file** → `fopen("file", "mode")`
2. **Check for errors** → `if(fp == NULL)`
3. **Read or write** → `fprintf/fscanf/fputs/fgets` for text, `fwrite/fread` for binary
4. **Close file** → `fclose(fp)`
5. **Optional** → check return values for **robust error handling**

---

Farhad, in simple words:

> * **Files** = permanent storage
> * **Text files** = readable characters
> * **Binary files** = raw memory bytes
> * **Error handling** = always check fopen/fread/fwrite return values
> * **fwrite/fread** = store/retrieve structs or other binary data exactly

---