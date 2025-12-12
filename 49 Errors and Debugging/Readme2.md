# Complete Guide: Errors and Debugging in C

---

## 1. What Are Errors in C?

Errors in programming mean something is wrong and your program can't run or works incorrectly. They fall into three main types:

* **Syntax errors (Compile-time errors)**: Mistakes in the code grammar that stop the program from compiling.
* **Runtime errors**: Errors that happen while the program runs (e.g., dividing by zero, file not found).
* **Logical errors**: The program runs but gives wrong results because of a bug in logic.

---

## 2. How to Read and Understand Compile-Time Errors

When you compile a C program using a compiler (like `gcc`), the compiler checks your code for syntax errors and reports them. Example:

```bash
gcc myprogram.c -o myprogram
```

If there’s a syntax error, you get an error message like:

```
myprogram.c:10:5: error: expected ';' before 'return'
```

This means:

* File: `myprogram.c`
* Line: 10
* Column: 5
* Description: Compiler expected a semicolon before the `return` statement

**How to fix:** Go to that line and add the missing semicolon.

---

## 3. Printing Error Messages in C

When your program runs, you might want to print error messages to inform the user or yourself about what went wrong.

### Using `fprintf(stderr, ...)`

Standard output (`printf`) goes to normal output, but errors should go to **standard error** to separate them.

```c
#include <stdio.h>

int main() {
    fprintf(stderr, "Error: File not found!\n");
    return 1;  // Return non-zero to indicate error
}
```

---

## 4. Using `errno` for System Error Codes

The C library provides a global variable `errno` to indicate error codes from system calls or library functions.

Example:

```c
#include <stdio.h>
#include <errno.h>
#include <string.h>

int main() {
    FILE *f = fopen("nonexistent.txt", "r");
    if (f == NULL) {
        // errno is set by fopen on failure
        fprintf(stderr, "Error opening file: %s\n", strerror(errno));
        return 1;
    }
    fclose(f);
    return 0;
}
```

* `errno` holds error code (set by system calls on failure).
* `strerror(errno)` returns human-readable error message.

---

## 5. Error Handling in File Operations (Important for Git)

When working with files (like binary files for Git), always check the return value of file functions:

```c
FILE *file = fopen("data.bin", "rb");
if (!file) {
    fprintf(stderr, "Error opening file: %s\n", strerror(errno));
    return 1;
}
```

Always **check return values** and print meaningful errors.

---

## 6. Debugging Tools and Techniques in C

### 6.1. Using `printf` Debugging

Add `printf` statements to check variables or program flow:

```c
printf("Value of x: %d\n", x);
```

Simple but effective, especially for beginners.

---

### 6.2. Using Debuggers (`gdb`)

`gdb` is a powerful debugger for C programs.

Basic usage:

```bash
gcc -g myprogram.c -o myprogram  # compile with debug info
gdb ./myprogram                  # start gdb
```

Useful commands in gdb:

* `break main` — set breakpoint at main function
* `run` — start running the program
* `next` — go to next line (step over function calls)
* `step` — step into function
* `print x` — print value of variable x
* `backtrace` — show call stack on crash
* `continue` — resume execution

---

### 6.3. Using `assert` to Check Assumptions

Include `<assert.h>` and use `assert()` to check critical conditions:

```c
#include <assert.h>

int divide(int a, int b) {
    assert(b != 0); // program aborts if b == 0
    return a / b;
}
```

---

### 7. Common Runtime Errors and How to Detect Them

* **Segmentation Fault (Segfault)**: Accessing memory that is not yours (e.g., dereferencing NULL pointer).
* **Buffer Overflow**: Writing outside array bounds.
* **Memory leaks**: Not freeing dynamically allocated memory.

Use tools like **Valgrind** to detect memory errors:

```bash
valgrind ./myprogram
```

---

### 8. How to Print Custom Error Messages with Codes

You can define your own error codes and print error messages:

```c
#define ERR_FILE_NOT_FOUND 1
#define ERR_READ_FAILED 2

void print_error(int err_code) {
    switch (err_code) {
        case ERR_FILE_NOT_FOUND:
            fprintf(stderr, "Error: File not found\n");
            break;
        case ERR_READ_FAILED:
            fprintf(stderr, "Error: Failed to read file\n");
            break;
        default:
            fprintf(stderr, "Unknown error\n");
    }
}
```

---

### 9. Using `perror` for Quick Error Prints

`perror` prints the last system error message based on `errno`:

```c
FILE *f = fopen("file.bin", "r");
if (!f) {
    perror("Failed to open file");
    return 1;
}
```

Output might be:

```
Failed to open file: No such file or directory
```

---

### 10. Handling Errors Gracefully

* Check return values for every function that can fail.
* Print meaningful error messages.
* Clean up resources (close files, free memory) before exiting on error.
* Return appropriate exit status (0 = success, non-zero = error).

---

### 11. Example: Reading and Writing Binary File with Error Handling

```c
#include <stdio.h>
#include <errno.h>
#include <string.h>

typedef struct {
    int id;
    char name[20];
} Record;

int main() {
    FILE *file = fopen("data.bin", "wb");
    if (!file) {
        fprintf(stderr, "Error opening file for writing: %s\n", strerror(errno));
        return 1;
    }

    Record r = {1, "Test"};
    if (fwrite(&r, sizeof(Record), 1, file) != 1) {
        fprintf(stderr, "Error writing to file: %s\n", strerror(errno));
        fclose(file);
        return 1;
    }
    fclose(file);

    file = fopen("data.bin", "rb");
    if (!file) {
        perror("Error opening file for reading");
        return 1;
    }

    Record r2;
    if (fread(&r2, sizeof(Record), 1, file) != 1) {
        if (feof(file)) {
            fprintf(stderr, "End of file reached unexpectedly\n");
        } else {
            fprintf(stderr, "Error reading file: %s\n", strerror(errno));
        }
        fclose(file);
        return 1;
    }

    printf("Read record: id=%d, name=%s\n", r2.id, r2.name);
    fclose(file);

    return 0;
}
```

---

### 12. Summary and Best Practices

* Always check return values of functions, especially file, memory, and system calls.
* Use `errno` and `strerror()` or `perror()` for system errors.
* Print errors to `stderr` using `fprintf(stderr, ...)`.
* Use `assert()` for debug checks.
* Use `gdb` or other debuggers to step through your code.
* Add `printf` debugging for quick variable checks.
* Use tools like Valgrind for memory errors.
* Return meaningful exit codes from `main()`.
* Clean up resources on error before exiting.

---