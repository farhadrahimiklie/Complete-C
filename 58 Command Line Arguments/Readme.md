## 1. What Are Command Line Arguments in C?

Command line arguments allow a program to receive input **at the time it is executed**, rather than during runtime via `scanf`.

They are passed to the `main` function.

### Standard Signature

```c
int main(int argc, char *argv[])
```

### Meaning

| Parameter | Description                          |
| --------- | ------------------------------------ |
| `argc`    | Argument Count (number of arguments) |
| `argv`    | Argument Vector (array of strings)   |

Important rules:

* `argv[0]` is **always the program name**
* All arguments are passed as **strings**
* `argc >= 1` always

---

## 2. Basic Example: Printing All Arguments

### Example 1: Display All Arguments

```c
#include <stdio.h>

int main(int argc, char *argv[])
{
    for (int i = 0; i < argc; i++)
    {
        printf("argv[%d] = %s\n", i, argv[i]);
    }
    return 0;
}
```

### Run

```
./app hello world 123
```

### Output

```
argv[0] = ./app
argv[1] = hello
argv[2] = world
argv[3] = 123
```

---

## 3. Checking Required Arguments

### Example 2: Require Exactly One Argument

```c
#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    printf("Filename: %s\n", argv[1]);
    return 0;
}
```

**Used in:** tools, compilers, file utilities

---

## 4. Converting Arguments to Numbers

Command line arguments are strings. Use conversion functions.

### Example 3: Convert String to Integer (`atoi`)

```c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: %s num1 num2\n", argv[0]);
        return 1;
    }

    int a = atoi(argv[1]);
    int b = atoi(argv[2]);

    printf("Sum = %d\n", a + b);
    return 0;
}
```

---

## 5. Safer Conversion Using `strtol`

### Example 4: Robust Integer Parsing

```c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char *end;

    long value = strtol(argv[1], &end, 10);

    if (*end != '\0')
    {
        printf("Invalid number\n");
        return 1;
    }

    printf("Value = %ld\n", value);
    return 0;
}
```

**Best practice for production code**

---

## 6. Using Flags (Options)

### Example 5: Simple Flags (`-v`, `-h`)

```c
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    for (int i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "-h") == 0)
        {
            printf("Help message\n");
        }
        else if (strcmp(argv[i], "-v") == 0)
        {
            printf("Version 1.0\n");
        }
    }
    return 0;
}
```

**Used in:** `gcc`, `git`, `ls`, `curl`

---

## 7. Flags With Values

### Example 6: Option + Value (`-o filename`)

```c
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    for (int i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "-o") == 0 && i + 1 < argc)
        {
            printf("Output file: %s\n", argv[i + 1]);
            i++;
        }
    }
    return 0;
}
```

---

## 8. Handling Multiple Files

### Example 7: Process Multiple Inputs

```c
#include <stdio.h>

int main(int argc, char *argv[])
{
    for (int i = 1; i < argc; i++)
    {
        printf("Processing file: %s\n", argv[i]);
    }
    return 0;
}
```

**Used in:** compilers, image processors, text tools

---

## 9. Boolean Options

### Example 8: Enable/Disable Behavior

```c
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int debug = 0;

    for (int i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "--debug") == 0)
        {
            debug = 1;
        }
    }

    if (debug)
        printf("Debug mode enabled\n");

    return 0;
}
```

---

## 10. Using `argc` for Validation

### Example 9: Minimum Arguments Required

```c
#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        printf("Error: At least two arguments required\n");
        return 1;
    }

    printf("Arguments are valid\n");
    return 0;
}
```

---

## 11. Real-World Mini Tool (Complete Example)

### Example 10: Calculator Tool

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("Usage: %s <num1> <op> <num2>\n", argv[0]);
        return 1;
    }

    int a = atoi(argv[1]);
    int b = atoi(argv[3]);

    if (strcmp(argv[2], "+") == 0)
        printf("%d\n", a + b);
    else if (strcmp(argv[2], "-") == 0)
        printf("%d\n", a - b);
    else if (strcmp(argv[2], "*") == 0)
        printf("%d\n", a * b);
    else if (strcmp(argv[2], "/") == 0)
        printf("%d\n", a / b);
    else
        printf("Unknown operator\n");

    return 0;
}
```
