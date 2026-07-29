Great choice. Before learning file handling (`fopen`, `fclose`, `fprintf`, etc.), you should first master **`write()`**, **`read()`**, and **`fflush()`** because they teach how data moves between your program and the operating system.

We'll learn them **one by one**, starting with **`write()`**. After you fully understand it, we can continue with `read()`, then `fflush()`, and finally build a project using all of them.

---

# Part 1: What is `write()` in C?

`write()` is a **system call** provided by the operating system (Linux/Unix/POSIX).

It writes bytes from your program into:

* A file
* The terminal (screen)
* A pipe
* A socket
* Any file descriptor

Unlike `printf()`, `write()` does **not** format text. It simply copies raw bytes.

---

# Header File

```c
#include <unistd.h>
```

---

# Function Prototype

```c
ssize_t write(int fd, const void *buffer, size_t count);
```

---

# Parameters

## 1. fd

File descriptor.

It tells Linux where to write.

Examples:

```text
0 -> stdin
1 -> stdout
2 -> stderr
```

Example:

```c
write(1, ...);      // terminal
```

---

## 2. buffer

Pointer to data.

Example

```c
char msg[] = "Hello";
```

Buffer points to

```
H
e
l
l
o
```

---

## 3. count

Number of bytes to write.

Example

```c
write(1, msg, 5);
```

Writes

```
Hello
```

---

# Return Value

Returns

```
Number of bytes written
```

or

```
-1
```

if an error occurs.

Example

```c
int n = write(1, "ABC", 3);
```

Result

```
n = 3
```

---

# Memory Diagram

Suppose

```c
char name[] = "John";
```

Memory

```
Address

100
101
102
103
104

 J
 o
 h
 n
 \0
```

Calling

```c
write(1, name, 4);
```

copies

```
J
o
h
n
```

to the terminal.

---

# Example 1 — Print Hello

```c
#include <unistd.h>

int main()
{
    write(1, "Hello\n", 6);

    return 0;
}
```

Output

```
Hello
```

---

# Example 2 — Print a Variable

```c
#include <unistd.h>

int main()
{
    char message[] = "Welcome!\n";

    write(1, message, 9);

    return 0;
}
```

Output

```
Welcome!
```

---

# Example 3 — Print Part of a String

```c
#include <unistd.h>

int main()
{
    char text[] = "Programming";

    write(1, text, 7);

    return 0;
}
```

Output

```
Program
```

Because only

```
7 bytes
```

were written.

---

# Example 4 — Print Characters One by One

```c
#include <unistd.h>

int main()
{
    char name[] = "CHATGPT";

    for(int i=0;i<7;i++)
        write(1, &name[i], 1);

    write(1,"\n",1);

    return 0;
}
```

Output

```
CHATGPT
```

Notice

```c
&name[i]
```

points to one character.

---

# Example 5 — Write to Standard Error

```c
#include <unistd.h>

int main()
{
    write(2,"Error!\n",7);

    return 0;
}
```

`2` means

```
stderr
```

Useful for error messages.

---

# Example 6 — Save Return Value

```c
#include <unistd.h>

int main()
{
    char msg[] = "ABCDE";

    int bytes = write(1,msg,5);

    return bytes;
}
```

The return value is

```
5
```

because 5 bytes were written.

---

# Example 7 — Write Binary Data

```c
#include <unistd.h>

int main()
{
    int number = 12345;

    write(1,&number,sizeof(number));

    return 0;
}
```

Output

```
Not readable
```

Why?

Because `write()` outputs the raw bytes representing the integer in memory, not its decimal text. To display `12345` as text, you would first convert it to a string (or use `printf()`).

---

# Example 8 — Multiple Writes

```c
#include <unistd.h>

int main()
{
    write(1,"Hello ",6);
    write(1,"World",5);
    write(1,"\n",1);

    return 0;
}
```

Output

```
Hello World
```

---

# Example 9 — Using `sizeof`

```c
#include <unistd.h>

int main()
{
    char text[] = "Linux\n";

    write(1,text,sizeof(text)-1);

    return 0;
}
```

Why

```c
-1
```

?

Because

```
sizeof(text)
```

includes the null terminator (`'\0'`), which you usually don't want to write to the terminal.

---

# Example 10 — Check for Errors

```c
#include <unistd.h>

int main()
{
    int result = write(-1,"Hello",5);

    if(result == -1)
    {
        write(2,"Write Failed\n",13);
    }

    return 0;
}
```

Passing an invalid file descriptor causes `write()` to fail.

---

# `write()` vs `printf()`

| Feature              | `write()`               | `printf()`                   |
| -------------------- | ----------------------- | ---------------------------- |
| Header               | `<unistd.h>`            | `<stdio.h>`                  |
| Type                 | System call             | Standard library function    |
| Formatting           | No                      | Yes (`%d`, `%f`, `%s`, etc.) |
| Buffering            | No user-space buffering | Buffered by the C library    |
| Speed                | Lower-level, direct     | Higher-level and convenient  |
| Uses file descriptor | Yes                     | Uses `FILE *` streams        |

Example:

```c
printf("%d", 100);
```

formats an integer as text.

```c
write(1, "100", 3);
```

writes the characters `'1'`, `'0'`, and `'0'` exactly as provided.

---

# Real-World Project: Simple Logger

This project writes log messages directly to the terminal using `write()`.

```c
#include <unistd.h>

int main()
{
    write(1, "Program Started\n", 16);

    write(1, "Loading Modules...\n", 19);

    write(1, "Initialization Complete\n", 24);

    return 0;
}
```

Output:

```text
Program Started
Loading Modules...
Initialization Complete
```

This illustrates how many low-level utilities produce output without relying on `printf()`.

---

# Key Points to Remember

* `write()` is a POSIX system call, not part of the ISO C standard.
* Include `<unistd.h>`.
* It writes raw bytes to a file descriptor.
* Standard file descriptors are:

  * `0` → `stdin`
  * `1` → `stdout`
  * `2` → `stderr`
* It returns the number of bytes written or `-1` on error.
* It does not perform formatting like `printf()`.

### Learning Roadmap

1. ✅ `write()` (completed)
2. ➜ `read()` — how to receive data from the keyboard and files.
3. ➜ `fflush()` — what buffering is, why it exists, and when to flush output.
4. ➜ A complete mini project (file copy utility) combining `read()`, `write()`, and `fflush()` where appropriate.












Excellent. Since you've learned `write()`, the natural next step is **`read()`**. Think of them as opposites:

* **`write()`** → sends data **from your program** to a file, terminal, or device.
* **`read()`** → receives data **into your program** from a file, terminal, or device.

---

# Part 1: What is `read()`?

`read()` is a **POSIX system call** that copies bytes from an input source into your program's memory.

It can read from:

* ⌨️ Keyboard (`stdin`)
* 📄 Files
* 🌐 Network sockets
* 📦 Pipes
* 💽 Devices (USB, serial ports, etc.)

---

# Header File

```c
#include <unistd.h>
```

---

# Function Prototype

```c
ssize_t read(int fd, void *buffer, size_t count);
```

---

# Parameters

## 1. `fd` (File Descriptor)

This tells the operating system **where to read from**.

Common file descriptors:

| File Descriptor | Meaning                   |
| --------------- | ------------------------- |
| `0`             | Standard Input (Keyboard) |
| `1`             | Standard Output (Screen)  |
| `2`             | Standard Error            |

Example:

```c
read(0, buffer, 100);
```

means:

> Read from the keyboard.

---

## 2. `buffer`

This is the memory where the data will be stored.

Example:

```c
char name[100];
```

Memory before reading:

```
+----+----+----+----+----+
| ?? | ?? | ?? | ?? | ?? |
+----+----+----+----+----+
```

After typing:

```
Hello
```

Memory becomes:

```
+----+----+----+----+----+
| H  | e  | l  | l  | o  |
+----+----+----+----+----+
```

---

## 3. `count`

Maximum number of bytes to read.

Example

```c
read(0, name, 100);
```

means:

> Read at most **100 bytes**.

---

# Return Value

`read()` returns:

| Return Value    | Meaning             |
| --------------- | ------------------- |
| Positive number | Bytes actually read |
| `0`             | End of file (EOF)   |
| `-1`            | Error               |

Example

```c
int n = read(0, buffer, 20);
```

If you type

```
Hello
```

and press Enter:

```
H e l l o \n
```

6 bytes are read.

So

```c
n == 6
```

---

# How `read()` Works Internally

Suppose you write

```c
char buffer[20];

read(0, buffer, 20);
```

You type

```
Apple
```

Memory before:

```
buffer

??
??
??
??
??
```

After pressing Enter:

```
buffer

A
p
p
l
e
\n
```

The operating system copied those bytes into your program.

---

# Example 1 — Read From Keyboard

```c
#include <unistd.h>

int main()
{
    char name[100];

    read(0, name, 100);

    write(1, name, 100);

    return 0;
}
```

Input

```
John
```

Output

```
John
```

**Problem:** It writes all 100 bytes, including unused memory.

---

# Example 2 — Correct Way

```c
#include <unistd.h>

int main()
{
    char name[100];

    int n = read(0, name, 100);

    write(1, name, n);

    return 0;
}
```

Input

```
John
```

Output

```
John
```

Now only the bytes actually read are written.

---

# Example 3 — Read One Character

```c
#include <unistd.h>

int main()
{
    char ch;

    read(0, &ch, 1);

    write(1, &ch, 1);

    return 0;
}
```

Input

```
A
```

Output

```
A
```

---

# Example 4 — Read Five Characters

```c
#include <unistd.h>

int main()
{
    char text[5];

    int n = read(0, text, 5);

    write(1, text, n);

    return 0;
}
```

Input

```
Programming
```

Output

```
Progr
```

Only the first 5 bytes are read.

---

# Example 5 — Read Until EOF

```c
#include <unistd.h>

int main()
{
    char ch;

    while(read(0, &ch, 1) > 0)
    {
        write(1, &ch, 1);
    }

    return 0;
}
```

Everything you type is echoed back until an EOF is sent (for example, **Ctrl+D** on most Unix/Linux terminals).

---

# Example 6 — Check for Errors

```c
#include <unistd.h>

int main()
{
    char data[10];

    int result = read(-1, data, 10);

    if(result == -1)
    {
        write(2, "Read Error\n", 11);
    }

    return 0;
}
```

Since `-1` is not a valid file descriptor, `read()` fails.

---

# Example 7 — Read Numbers as Text

```c
#include <unistd.h>

int main()
{
    char number[20];

    int n = read(0, number, 20);

    write(1, number, n);

    return 0;
}
```

Input

```
12345
```

Output

```
12345
```

Remember that `read()` receives **characters**, not integers. Converting `"12345"` into the integer `12345` requires additional parsing (for example, with `strtol()`).

---

# Example 8 — Read Into Different Buffers

```c
#include <unistd.h>

int main()
{
    char first[5];
    char second[5];

    read(0, first, 5);
    read(0, second, 5);

    write(1, first, 5);
    write(1, second, 5);

    return 0;
}
```

The first call fills `first`, and the second continues reading the remaining input.

---

# Example 9 — Read Binary Data

```c
#include <unistd.h>

int main()
{
    int value;

    read(0, &value, sizeof(value));

    return 0;
}
```

This is intended for binary input (for example, from another program or a binary file), not ordinary keyboard typing.

---

# Example 10 — Echo Program

```c
#include <unistd.h>

int main()
{
    char buffer[1024];

    int n;

    while((n = read(0, buffer, sizeof(buffer))) > 0)
    {
        write(1, buffer, n);
    }

    return 0;
}
```

This behaves like a simple version of the Unix `cat` command when reading from standard input.

---

# `read()` vs `scanf()`

| Feature           | `read()`          | `scanf()`                   |
| ----------------- | ----------------- | --------------------------- |
| Header            | `<unistd.h>`      | `<stdio.h>`                 |
| Type              | POSIX system call | C standard library function |
| Reads raw bytes   | ✅                 | ❌                           |
| Parses numbers    | ❌                 | ✅                           |
| Buffer management | Manual            | Automatic                   |
| File descriptor   | Uses `int fd`     | Uses `FILE *` streams       |

Example:

```c
read(0, buffer, 20);
```

Reads raw bytes into `buffer`.

```c
scanf("%d", &x);
```

Reads text and converts it into an integer.

---

# Real-World Use Cases

## 1. File Copy Programs

```text
Read 4096 bytes
↓

Write 4096 bytes
↓

Repeat until EOF
```

Utilities like `cp` and many backup tools follow this pattern.

---

## 2. Web Servers

When a browser sends a request:

```
GET /index.html HTTP/1.1
```

the server reads the incoming bytes using `read()` (or a related system call) before processing the request.

---

## 3. Chat Applications

```
Client
   │
   ▼
read(socket,...)
   │
Message arrives
   │
Display to user
```

Messaging programs continuously read from network sockets.

---

## 4. Linux Terminal

When you type:

```
ls
```

the shell first uses `read()` (or an equivalent input mechanism) to receive your command before executing it.

---

## 5. Embedded Systems

A microcontroller connected to a temperature sensor might repeatedly read bytes arriving over a serial port, interpret them, and update a display or control hardware.

---

# How `read()` and `write()` Work Together

```
Keyboard
   │
   ▼
read()
   │
Program Memory
   │
   ▼
write()
   │
Screen
```

Example:

```c
char buffer[100];

int n = read(0, buffer, sizeof(buffer));

write(1, buffer, n);
```

This is the foundation of many Unix utilities and network applications.

---

# Key Points to Remember

* `read()` is a **POSIX system call**, not part of the ISO C standard.
* Include `<unistd.h>`.
* It reads **raw bytes** into a memory buffer.
* Standard input (`stdin`) is file descriptor `0`.
* It returns:

  * Positive number → bytes read
  * `0` → end of file (EOF)
  * `-1` → error
* Always use the return value to know how many bytes were actually read.
* `read()` and `write()` are commonly used together for efficient data transfer.

## Next Lesson

The next important concept is **`fflush()`**, where you'll learn:

* What buffering is
* Why `printf()` sometimes delays output
* What `fflush(stdout)` actually does
* When `fflush()` is useful
* Common mistakes (such as using `fflush(stdin)`)
* Practical examples and a real-world project demonstrating buffered I/O.



