## 🧭 1. What is `#include` in C?

`#include` is a **preprocessor directive** in C.

That means it is **handled before compilation** by the **C Preprocessor** — not by the compiler itself.

Its main job is to **include the contents of another file** (usually a *header file*) into your program **before the actual compilation starts**.

### 🔹 Syntax:

```c
#include <filename>
```

or

```c
#include "filename"
```

> 💡 In simple words:
> `#include` literally **copies the entire content** of the specified file into your source code *before* the compiler sees it.

---

## 🧩 2. Why Do We Need `#include`?

Because C is a **modular language** — code is divided into multiple files for clarity and reusability.

Header files contain **function declarations**, **macros**, **constants**, and **structure definitions** that are used by many programs.

So, instead of writing everything again and again, we simply use `#include` to bring existing code into our program.

### 🔹 Example:

```c
#include <stdio.h>

int main() {
    printf("Hello, Farhad!\n");
    return 0;
}
```

Here:

* `#include <stdio.h>` tells the preprocessor to include the **Standard Input Output header file**, which contains the **declaration of `printf()`**.
* Without it, the compiler wouldn’t know what `printf()` means.

---

## 🧠 3. What Are Header Files?

**Header files** are text files that contain:

* **Function declarations (prototypes)**
* **Macro definitions**
* **Constants**
* **Structure or type definitions**

They usually have the extension:

```
.h
```

### 🔹 Example: stdio.h

If you open `stdio.h`, you’ll see lines like:

```c
int printf(const char *format, ...);
int scanf(const char *format, ...);
```

These are **function prototypes** that tell the compiler what these functions look like (their names, parameters, and return types).

So, when you use `printf()` in your program, the compiler knows how to handle it.

---

## ⚙️ 4. How `#include` Works Internally

Let’s say you have this code:

```c
#include <stdio.h>
int main() {
    printf("Hello!\n");
    return 0;
}
```

When you compile it, the **preprocessor** does this internally:

1. Finds `#include <stdio.h>`
2. Opens the `stdio.h` file from your system’s standard library directory.
3. Copies all its contents into your source file.
4. The compiler then compiles that combined file.

So, effectively your program becomes one big source file that contains:

* All code from `stdio.h`
* Plus your own code

---

## 🧩 5. Types of `#include` Directives

There are **two types** of `#include` statements in C:

### 🔹 1. Angle Brackets (`< >`)

```c
#include <stdio.h>
```

✅ Used for **standard header files** (built-in C library headers).
The preprocessor searches for the file in **system directories** (like `/usr/include` on Linux).

---

### 🔹 2. Double Quotes (`" "`)

```c
#include "myheader.h"
```

✅ Used for **user-defined header files**.
The preprocessor first searches the **current directory** (where your source code is).
If not found, it then searches the **system directories**.

---

## 🧰 6. Example: User-Defined Header File

Let’s create your own header and see how it works.

### 🔹 Step 1: Create a header file — `myheader.h`

```c
// myheader.h
void greet();
```

### 🔹 Step 2: Create a source file — `myheader.c`

```c
// myheader.c
#include <stdio.h>

void greet() {
    printf("Hello Farhad! Welcome to C programming.\n");
}
```

### 🔹 Step 3: Use it in your main program — `main.c`

```c
#include "myheader.h"

int main() {
    greet();
    return 0;
}
```

### 🔹 Step 4: Compile both files

```bash
gcc main.c myheader.c -o program
```

When you run:

```bash
./program
```

Output:

```
Hello Farhad! Welcome to C programming.
```

✅ That’s how user-defined headers make your code modular and reusable.

---

## 📚 7. Common Standard Header Files in C

| Header File   | Purpose                   | Example Functions                            |
| ------------- | ------------------------- | -------------------------------------------- |
| `<stdio.h>`   | Standard Input/Output     | `printf()`, `scanf()`, `fopen()`, `fclose()` |
| `<stdlib.h>`  | General utilities         | `malloc()`, `free()`, `exit()`, `atoi()`     |
| `<string.h>`  | String handling           | `strcpy()`, `strlen()`, `strcmp()`           |
| `<math.h>`    | Mathematical functions    | `sqrt()`, `pow()`, `sin()`, `cos()`          |
| `<ctype.h>`   | Character handling        | `isalpha()`, `isdigit()`, `toupper()`        |
| `<time.h>`    | Time and date functions   | `time()`, `localtime()`, `clock()`           |
| `<stdbool.h>` | Boolean type support      | `true`, `false`                              |
| `<limits.h>`  | Limits of data types      | `INT_MAX`, `CHAR_MIN`                        |
| `<float.h>`   | Limits for floating-point | `FLT_MAX`, `DBL_MIN`                         |
| `<assert.h>`  | Debugging                 | `assert()`                                   |

---

## 🧠 8. What’s Inside a Header File?

Header files mostly contain:

* Function declarations (prototypes)
* Macro definitions
* Constants
* Type definitions (`typedef`)
* Structure declarations

### Example – inside `math.h`:

```c
#define M_PI 3.14159265358979323846
double sqrt(double x);
double pow(double x, double y);
```

So, when you use:

```c
#include <math.h>
```

The compiler knows what `sqrt()` or `pow()` are, even if their actual code is in a different library file.

---

## 🔗 9. Relationship Between Header Files and Library Files

There’s a common confusion:
Header files **declare** functions, while **library files** (like `.lib` or `.a`) **define** them.

| Type                         | Contains                           | Example                          |
| ---------------------------- | ---------------------------------- | -------------------------------- |
| **Header File (.h)**         | Declarations (function prototypes) | `printf()` declared in `stdio.h` |
| **Library File (.a / .lib)** | Definitions (actual compiled code) | `printf()` defined in `libc.a`   |

So, during:

* **Preprocessing:** Header file is included.
* **Linking:** Library file is linked (using linker).

---

## ⚡ 10. `#include` vs Other Preprocessor Directives

| Directive            | Purpose                                 |
| -------------------- | --------------------------------------- |
| `#include`           | Includes header files                   |
| `#define`            | Defines macros/constants                |
| `#undef`             | Undefines a macro                       |
| `#ifdef` / `#ifndef` | Conditional compilation                 |
| `#endif`             | Ends conditional compilation            |
| `#pragma`            | Provides compiler-specific instructions |

---

## 🧩 11. Avoiding Multiple Inclusion (Header Guards)

If you include a header file multiple times, it can cause **redefinition errors**.

### ❌ Example (problem):

```c
#include "myheader.h"
#include "myheader.h" // included twice
```

This may give errors like:

```
error: redefinition of ‘greet’
```

### ✅ Solution: Use Header Guards

You can prevent multiple inclusion by using the preprocessor directives:

```c
#ifndef MYHEADER_H
#define MYHEADER_H

void greet();

#endif
```

Explanation:

* `#ifndef` → "if not defined"
* `#define` → defines the name `MYHEADER_H`
* `#endif` → marks the end

So, if `myheader.h` is included again, it will be skipped.

---

## 📖 12. Step-by-Step of What Happens

Let’s visualize what happens when the compiler sees:

```c
#include <stdio.h>
```

1. The **preprocessor** runs before the compiler.
2. It finds the line `#include <stdio.h>`.
3. It searches the system include directories for `stdio.h`.
4. It copies the entire contents of `stdio.h` into your source file.
5. Then, the **compiler** compiles that merged file.
6. Finally, the **linker** links the compiled code with the standard library (`libc`) that contains the definitions of functions like `printf`.

---

## 🧩 13. Real Example Behind the Scenes

### Your code:

```c
#include <stdio.h>
int main() {
    printf("Hi!\n");
    return 0;
}
```

### Internally after preprocessing:

```c
// Entire contents of stdio.h copied here...
int printf(const char *format, ...);   // Declaration

int main() {
    printf("Hi!\n");
    return 0;
}
```

Then the compiler compiles this, and during **linking**, the system links your program with `libc` (the standard C library) where the actual code of `printf()` resides.

---

## 🧠 14. Summary Table

| Concept                  | Description                                    |
| ------------------------ | ---------------------------------------------- |
| **`#include`**           | Preprocessor directive to include files        |
| **Header file (.h)**     | Contains declarations (not actual code)        |
| **Angle brackets `< >`** | Used for system headers                        |
| **Double quotes `" "`**  | Used for user-defined headers                  |
| **Header guards**        | Prevent multiple inclusions                    |
| **Library files**        | Contain compiled definitions                   |
| **Preprocessor role**    | Expands includes and macros before compilation |
