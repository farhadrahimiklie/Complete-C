## 🧭 Overview: What Happens When You Run a C Program?

When you write a C program like this:

```c
#include <stdio.h>

int main() {
    printf("Hello, World!\n");
    return 0;
}
```

and then compile it using a compiler (like `gcc` or `clang`), the computer goes through **four major stages** before it produces an executable file.

Those stages are:

1. **Preprocessing**
2. **Compilation**
3. **Assembly**
4. **Linking**

Finally, you **execute** the program.

Let’s explore each stage in full detail 👇

---

## 🧩 1. Preprocessing (Preprocessor Stage)

### 🔹 What happens:

Before the actual compilation starts, a special program called the **C Preprocessor** (`cpp`) runs.
It processes all lines that begin with `#`, such as `#include`, `#define`, and `#ifdef`.

### 🔹 Main tasks of the preprocessor:

1. **Include header files**
   Example:

   ```c
   #include <stdio.h>
   ```

   This line literally copies the contents of the `stdio.h` file into your program before compilation.

2. **Macro expansion**
   Example:

   ```c
   #define PI 3.14
   ```

   Every occurrence of `PI` is replaced with `3.14` in the code.

3. **Conditional compilation**
   Example:

   ```c
   #ifdef DEBUG
       printf("Debug mode\n");
   #endif
   ```

   Code inside these blocks is compiled **only** if the condition is met.

4. **Remove comments**
   The preprocessor removes all comments before passing the code to the next stage.

### 🔹 Output:

After preprocessing, you get a **pure C code file** (no macros or includes left) — often named something like:

```
hello.i
```

---

## ⚙️ 2. Compilation (Compiler Stage)

### 🔹 What happens:

Now the **compiler** takes the preprocessed code (`hello.i`) and checks for:

* Syntax errors
* Type checking
* Semantic correctness

Then, it **translates** the C code into **assembly code**, which is a human-readable representation of machine instructions.

### 🔹 Example:

If your source file is `hello.c`, this stage produces:

```
hello.s
```

This `.s` file contains **assembly language** code for your program.

### 🔹 Example of Assembly Code:

```asm
    .section    .rodata
.LC0:
    .string "Hello, World!"
    .text
    .globl  main
main:
    pushq   %rbp
    movq    %rsp, %rbp
    leaq    .LC0(%rip), %rdi
    call    printf
    movl    $0, %eax
    popq    %rbp
    ret
```

This is what your program looks like before it turns into machine code!

---

## 🧠 3. Assembly (Assembler Stage)

### 🔹 What happens:

The **assembler** now converts the `.s` assembly code into **machine code** — a binary format that your CPU can understand.

This creates an **object file**:

```
hello.o
```

### 🔹 About object files:

* Contain **machine code**, but not yet a complete executable.
* Some parts (like function calls to libraries) are **unresolved** at this stage.

---

## 🔗 4. Linking (Linker Stage)

### 🔹 What happens:

Now the **linker** (`ld`) combines:

1. Your object file (`hello.o`)
2. Standard library object files (like `printf` from `stdio`)
3. Any other user-defined object files

It **resolves all references** (for example, where `printf()` actually lives in memory) and creates one final **executable file**.

On Linux:

```
a.out
```

or with GCC:

```
gcc hello.c -o hello
```

produces:

```
hello
```

On Windows:

```
hello.exe
```

### 🔹 If something is missing:

If the linker cannot find a required function or library, you’ll get a **linker error**, like:

```
undefined reference to 'printf'
```

---

## 🚀 5. Execution (Running the Program)

Finally, you **execute** the program by running:

```
./hello
```

or on Windows:

```
hello.exe
```

### 🔹 What happens during execution:

1. The program is loaded from storage into **RAM**.
2. The **CPU** starts executing instructions from the `main()` function.
3. When it reaches:

   ```c
   printf("Hello, World!\n");
   ```

   it calls the standard I/O library function to display the text on your screen.
4. When `return 0;` executes, the program sends an **exit status** (0 means successful execution) to the operating system.

---

## 🧰 Bonus: Visual Summary of the Process

```
Source Code (.c)
        |
        v
+-----------------+
| Preprocessor    |   → expands macros & includes headers
+-----------------+
        |
        v
Preprocessed Code (.i)
        |
        v
+-----------------+
| Compiler        |   → converts C to assembly (.s)
+-----------------+
        |
        v
Assembly Code (.s)
        |
        v
+-----------------+
| Assembler       |   → converts assembly to object (.o)
+-----------------+
        |
        v
Object Code (.o)
        |
        v
+-----------------+
| Linker          |   → combines all .o and libraries
+-----------------+
        |
        v
Executable File (a.out / .exe)
        |
        v
Execution (CPU runs the binary code)
```

---

## 🧠 Summary Table

| Stage         | Tool Used            | Input          | Output        | Description                       |
| ------------- | -------------------- | -------------- | ------------- | --------------------------------- |
| Preprocessing | Preprocessor (`cpp`) | .c file        | .i file       | Expands macros, includes headers  |
| Compilation   | Compiler (`gcc`)     | .i file        | .s file       | Converts C code to assembly       |
| Assembly      | Assembler (`as`)     | .s file        | .o file       | Converts assembly to machine code |
| Linking       | Linker (`ld`)        | .o + libraries | .exe or a.out | Produces final executable         |
| Execution     | OS/CPU               | .exe           | Output        | Runs program instructions         |

---

## 🧩 Example Command Breakdown (Linux/macOS)

Let’s see the commands step-by-step for the file `hello.c`:

```bash
# 1. Preprocessing
gcc -E hello.c -o hello.i

# 2. Compilation to Assembly
gcc -S hello.i -o hello.s

# 3. Assembly to Object Code
gcc -c hello.s -o hello.o

# 4. Linking to create Executable
gcc hello.o -o hello

# 5. Execute
./hello
```

Each stage creates a file that represents a transformation of your original code into something closer to machine code.

---

## ⚡ In Short

| Step | Action        | File Produced    | Description                     |
| ---- | ------------- | ---------------- | ------------------------------- |
| 1    | Preprocessing | `.i`             | Handle macros, includes         |
| 2    | Compilation   | `.s`             | Convert C → Assembly            |
| 3    | Assembly      | `.o`             | Convert Assembly → Machine code |
| 4    | Linking       | Executable       | Combine all into one program    |
| 5    | Execution     | Output on screen | Program runs                    |

---