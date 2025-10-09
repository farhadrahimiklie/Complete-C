
---

# 🔹 **C Header Files – Full Details**

Header files in C provide **predefined functions, macros, types, and constants** so you can use them without rewriting code. They are included in your program using:

```c
#include <header.h>  // standard library
#include "header.h"  // user-defined
```

---

## 1️⃣ **assert.h**

* Provides **`assert()` macro** for debugging.
* Checks assumptions during program execution; if condition fails, program **stops with an error message**.

**Example:**

```c
#include <assert.h>
int main() {
    int x = -5;
    assert(x > 0); // program aborts
    return 0;
}
```

---

## 2️⃣ **complex.h**

* Provides support for **complex numbers** in C (`float complex`, `double complex`).
* Functions: `cabs()`, `creal()`, `cimag()`, `cpow()` etc.

**Example:**

```c
#include <complex.h>
#include <stdio.h>

int main() {
    double complex z = 3 + 4*I;
    printf("Magnitude = %f\n", cabs(z));
    return 0;
}
```

---

## 3️⃣ **ctype.h**

* Provides **character handling functions**.
* Examples: `isalpha()`, `isdigit()`, `islower()`, `toupper()`, `tolower()`

**Example:**

```c
#include <ctype.h>
#include <stdio.h>

int main() {
    char c = 'a';
    if(isalpha(c)) printf("Letter\n");
    printf("%c\n", toupper(c));
    return 0;
}
```

---

## 4️⃣ **errno.h**

* Defines macros for **error handling**, particularly for **system/library calls**.
* `errno` variable indicates **error code**, e.g., `EDOM`, `ERANGE`.

**Example:**

```c
#include <stdio.h>
#include <errno.h>
#include <math.h>

int main() {
    errno = 0;
    double x = sqrt(-1);
    if(errno) printf("Error occurred: %d\n", errno);
    return 0;
}
```

---

## 5️⃣ **fenv.h**

* Provides **floating-point environment control**.
* Functions: `feclearexcept()`, `fetestexcept()`, `fegetround()` etc.
* Used in **advanced math and precision control**.

---

## 6️⃣ **float.h**

* Defines **macros for float/double precision limits**.
* Examples: `FLT_MAX`, `DBL_MIN`, `FLT_EPSILON`

**Example:**

```c
#include <float.h>
#include <stdio.h>

int main() {
    printf("Max float: %e\n", FLT_MAX);
    return 0;
}
```

---

## 7️⃣ **inttypes.h / stdint.h**

* Defines **fixed-width integer types** (`int8_t`, `int16_t`, `int32_t`)
* Useful for **portable programs across platforms**

**Example:**

```c
#include <stdint.h>
#include <stdio.h>

int main() {
    int32_t num = 100000;
    printf("%d\n", num);
    return 0;
}
```

---

## 8️⃣ **limits.h**

* Defines **limits of integer types**.
* Examples: `INT_MAX`, `CHAR_MIN`, `LONG_MAX`

---

## 9️⃣ **locale.h**

* Handles **localization**, formatting numbers, dates, currencies.
* Functions: `setlocale()`, `localeconv()`

**Example:**

```c
#include <locale.h>
#include <stdio.h>

int main() {
    setlocale(LC_ALL, "en_US.UTF-8");
    return 0;
}
```

---

## 🔟 **math.h**

* Provides **mathematical functions**.
* Examples: `sqrt()`, `pow()`, `sin()`, `cos()`, `fabs()`

---

## 1️⃣1️⃣ **signal.h**

* Provides **signal handling** (like interrupts or exceptions).
* Functions: `signal()`, `raise()`
* Signals: `SIGINT`, `SIGFPE`, `SIGSEGV`

**Example:**

```c
#include <stdio.h>
#include <signal.h>

void handler(int sig) {
    printf("Caught signal %d\n", sig);
}

int main() {
    signal(SIGINT, handler);
    while(1); // wait for Ctrl+C
    return 0;
}
```

---

## 1️⃣2️⃣ **stdbool.h**

* Provides **Boolean type (`bool`)**
* Constants: `true`, `false`

**Example:**

```c
#include <stdbool.h>
#include <stdio.h>

int main() {
    bool flag = true;
    if(flag) printf("True\n");
    return 0;
}
```

---

## 1️⃣3️⃣ **stdarg.h**

* Allows **functions to accept variable number of arguments**
* Macros: `va_start`, `va_arg`, `va_end`

**Example:**

```c
#include <stdio.h>
#include <stdarg.h>

int sum(int n, ...) {
    va_list args;
    va_start(args, n);
    int total = 0;
    for(int i=0;i<n;i++) total += va_arg(args, int);
    va_end(args);
    return total;
}

int main() {
    printf("%d\n", sum(3,1,2,3));
    return 0;
}
```

---

## 1️⃣4️⃣ **stddef.h**

* Defines **common types/macros**:

  * `size_t`, `ptrdiff_t`, `NULL`

---

## 1️⃣5️⃣ **stdio.h**

* Standard Input/Output functions:
* `printf`, `scanf`, `fopen`, `fclose`, `fgets`, `fputs`

---

## 1️⃣6️⃣ **stdlib.h**

* General utilities: memory, conversions, process control:
* Functions: `malloc`, `calloc`, `free`, `atoi`, `exit`, `system`

---

## 1️⃣7️⃣ **string.h**

* String manipulation functions:
* `strcpy`, `strcat`, `strlen`, `strcmp`, `memcpy`, `memset`

---

## 1️⃣8️⃣ **threads.h** (C11)

* Provides **multithreading support**: `thrd_create`, `thrd_join`, `mtx_lock`

---

## 1️⃣9️⃣ **time.h**

* Time and date functions:
* `time()`, `difftime()`, `clock()`, `localtime()`, `strftime()`

---

## 2️⃣0️⃣ **windows.h** (Platform-specific)

* Provides **Windows API functions**
* Functions: window creation, threads, file handling, timers
* Used in **system programming on Windows**

---

## 🔹 **Summary Table**

| Header                | Purpose                       |
| --------------------- | ----------------------------- |
| assert.h              | Debugging, check assumptions  |
| complex.h             | Complex number support        |
| ctype.h               | Character handling            |
| errno.h               | Error codes                   |
| fenv.h                | Floating-point environment    |
| float.h               | Float/double limits           |
| inttypes.h / stdint.h | Fixed-width integers          |
| limits.h              | Min/max values of types       |
| locale.h              | Localization                  |
| math.h                | Math functions                |
| signal.h              | Signal handling               |
| stdbool.h             | Boolean type                  |
| stdarg.h              | Variable arguments            |
| stddef.h              | Common types/macros           |
| stdio.h               | Input/Output                  |
| stdlib.h              | Utilities, memory, conversion |
| string.h              | String manipulation           |
| threads.h             | Multithreading (C11)          |
| time.h                | Time/date functions           |
| windows.h             | Windows-specific API          |

---

Farhad, in simple words:

> * **Header files** are like **toolboxes**: each has **ready-made tools** for different tasks.
> * Use the correct header to avoid **redefining functions or types**.
> * They make C programming **efficient, organized, and portable**.

---