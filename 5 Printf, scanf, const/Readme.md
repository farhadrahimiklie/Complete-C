
---

# 🧩 1. `printf()` Function — Complete Explanation

## 📘 What is `printf()`?

`printf()` stands for **“print formatted”** and is a **standard output function** in C.
It is declared inside the **`<stdio.h>`** header file.

It is used to **display data (output)** on the screen, typically on the console.

---

## ⚙️ Syntax:

```c
printf("format string", argument1, argument2, ...);
```

### Example:

```c
#include <stdio.h>

int main() {
    int age = 22;
    printf("Farhad is %d years old.\n", age);
    return 0;
}
```

### Output:

```
Farhad is 22 years old.
```

---

## 🧠 How `printf()` Works Internally

1. When you call `printf()`, the compiler looks for its **declaration** in `<stdio.h>`.
2. The **preprocessor** includes that declaration.
3. During **linking**, the **actual implementation** of `printf()` (inside the standard C library `libc`) is linked to your program.
4. At runtime, it **converts** the data you pass (like integers or floats) into **text form (characters)** and sends them to the **standard output buffer**.
5. The **operating system** then displays those characters on your console.

So, `printf()` is basically a **formatted text writer** to the standard output stream (`stdout`).

---

## 🧩 Format Specifiers in `printf()`

| Format Specifier | Meaning                     | Example Output |
| ---------------- | --------------------------- | -------------- |
| `%d`             | Integer (decimal)           | 10             |
| `%i`             | Integer (same as `%d`)      | 10             |
| `%f`             | Floating point number       | 3.141593       |
| `%.2f`           | Float with 2 decimal places | 3.14           |
| `%c`             | Single character            | A              |
| `%s`             | String                      | Farhad         |
| `%u`             | Unsigned integer            | 4294967295     |
| `%x`             | Hexadecimal (lowercase)     | ff             |
| `%X`             | Hexadecimal (uppercase)     | FF             |
| `%o`             | Octal                       | 77             |
| `%p`             | Pointer (address)           | 0x7fff4b1a     |
| `%%`             | Prints a literal `%`        | %              |

---

### 🔹 Example 1: Multiple Data Types

```c
#include <stdio.h>

int main() {
    int a = 10;
    float b = 5.25;
    char c = 'K';

    printf("a = %d, b = %.2f, c = %c\n", a, b, c);
    return 0;
}
```

Output:

```
a = 10, b = 5.25, c = K
```

---

### 🔹 Example 2: Formatting Width

```c
printf("%10d", 45);
```

Output:

```
        45   // right-aligned in 10 spaces
```

```c
printf("%-10d", 45);
```

Output:

```
45        // left-aligned
```

---

### 🔹 Example 3: Print Address of a Variable

```c
int x = 7;
printf("Address of x = %p\n", &x);
```

---

## ⚡ Important Notes

* Always include `<stdio.h>` for `printf()`.
* Format specifiers **must match** the variable type; otherwise, undefined behavior occurs.
* `\n` = newline
* `\t` = tab space

---

# 🧩 2. `scanf()` Function — Complete Explanation

## 📘 What is `scanf()`?

`scanf()` stands for **“scan formatted”** and is used to **take input** from the user.
It reads data from the **standard input (keyboard)**.

It’s also declared in the **`<stdio.h>`** header file.

---

## ⚙️ Syntax:

```c
scanf("format string", &variable1, &variable2, ...);
```

### Example:

```c
#include <stdio.h>

int main() {
    int age;
    printf("Enter your age: ");
    scanf("%d", &age);
    printf("Your age is %d.\n", age);
    return 0;
}
```

### Output:

```
Enter your age: 22
Your age is 22.
```

---

## 🧠 How `scanf()` Works Internally

1. `scanf()` reads **characters** from standard input (`stdin`).
2. It converts those characters into **values of specified data types** based on format specifiers.
3. It then stores those values into the **memory addresses** of the variables you pass using `&`.

> ⚠️ The **ampersand (&)** is very important.
> It gives the **address** of the variable, so `scanf()` can write the user’s input directly into memory.

---

## 🧩 Format Specifiers in `scanf()`

| Format Specifier | Meaning            | Example Input |
| ---------------- | ------------------ | ------------- |
| `%d`             | Integer            | 25            |
| `%f`             | Float              | 3.14          |
| `%c`             | Character          | A             |
| `%s`             | String (no spaces) | Farhad        |
| `%lf`            | Double             | 12.3456       |
| `%u`             | Unsigned int       | 100           |
| `%x`             | Hexadecimal input  | ff            |

---

### 🔹 Example 1: Multiple Inputs

```c
int a, b;
printf("Enter two numbers: ");
scanf("%d %d", &a, &b);
printf("Sum = %d\n", a + b);
```

---

### 🔹 Example 2: Input a Character

```c
char ch;
printf("Enter a character: ");
scanf(" %c", &ch); // Notice space before %c to ignore newline
printf("You entered: %c\n", ch);
```

---

### 🔹 Example 3: Input a String

```c
char name[20];
printf("Enter your name: ");
scanf("%s", name);  // No & needed because name is already an address
printf("Hello %s!\n", name);
```

> ⚠️ Limitation: `scanf("%s")` stops reading at the first space.
> To read full sentences, use:
>
> ```c
> fgets(name, sizeof(name), stdin);
> ```

---

## ⚠️ Common Mistakes with `scanf()`

1. Forgetting `&` → Causes segmentation fault or wrong values.
2. Mismatched format specifier → Undefined behavior.
3. Using `%s` for spaces → Reads only first word.
4. Using `scanf()` with `char` → Always use `" %c"` (note the space).

---

# 🧠 3. `const` Keyword — Complete Explanation

## 📘 What is `const`?

`const` in C is a **type qualifier** that makes a variable’s value **constant (read-only)** after initialization.

Once assigned, a `const` variable **cannot be changed** during the execution of the program.

---

## ⚙️ Syntax:

```c
const data_type variable_name = value;
```

### Example:

```c
#include <stdio.h>

int main() {
    const int x = 10;
    printf("x = %d\n", x);

    // x = 20;  ❌ Error: assignment of read-only variable
    return 0;
}
```

Output:

```
x = 10
```

---

## 🔹 Why Use `const`?

1. **Protects values** from accidental modification.
2. Makes your code **more reliable and readable**.
3. Allows **compiler optimizations** because the value is fixed.
4. Helps define **constants** like Pi, max limits, etc.

---

## 🧩 Types of `const` Usage

### 1️⃣ Constant Variables

```c
const int age = 25;
```

### 2️⃣ Constant Pointers

```c
int x = 10, y = 20;
const int *ptr = &x;  // Pointer to constant int
*ptr = 30;            // ❌ Error: can't modify value
ptr = &y;             // ✅ You can change where it points
```

### 3️⃣ Pointer to Constant Pointer

```c
int a = 10, b = 20;
int *const ptr = &a;  // Constant pointer to int
*ptr = 30;            // ✅ Allowed (value can change)
ptr = &b;             // ❌ Error: pointer address can't change
```

### 4️⃣ Both Constant Pointer and Constant Data

```c
const int *const ptr = &a; // Fully constant
```

---

## 🧠 Difference Between `#define` and `const`

| Feature       | `#define`            | `const`                  |
| ------------- | -------------------- | ------------------------ |
| Type checking | No                   | Yes                      |
| Scope         | Global (file-level)  | Block scope              |
| Storage       | No memory allocation | Memory allocated         |
| Debugging     | Harder               | Easier                   |
| Syntax        | `#define PI 3.14`    | `const float PI = 3.14;` |

---

## 🔹 Example: Using `const` in Real Code

```c
#include <stdio.h>

int main() {
    const float PI = 3.14159;
    float radius = 5.0;
    float area = PI * radius * radius;

    printf("Area = %.2f\n", area);
    return 0;
}
```

Output:

```
Area = 78.54
```

---

## ⚠️ Common Mistakes with `const`

1. Trying to modify a `const` variable:

   ```c
   const int x = 10;
   x = 20; // ❌ Error
   ```
2. Forgetting `const` in functions when parameters should not be changed.
3. Using `#define` for constants when `const` is safer.

---

# 🧩 4. Summary Table

| Concept    | Purpose                      | Header      | Example             |
| ---------- | ---------------------------- | ----------- | ------------------- |
| `printf()` | Prints formatted output      | `<stdio.h>` | `printf("%d", x);`  |
| `scanf()`  | Reads formatted input        | `<stdio.h>` | `scanf("%d", &x);`  |
| `const`    | Declares immutable variables | None        | `const int x = 10;` |

---

# 🧠 5. Combined Example

```c
#include <stdio.h>

int main() {
    const float PI = 3.14159;
    float radius;

    printf("Enter the radius: ");
    scanf("%f", &radius);

    float area = PI * radius * radius;

    printf("Area of circle = %.2f\n", area);
    return 0;
}
```

### Output:

```
Enter the radius: 5
Area of circle = 78.54
```

---