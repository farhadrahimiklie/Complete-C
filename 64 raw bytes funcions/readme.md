Perfect. Since you want to learn **low-level (POSIX) file I/O**, I will explain each function exactly the same way:

1. **What is it?**
2. **Header file**
3. **Prototype**
4. **Parameters**
5. **Return value**
6. **Real-world usage**
7. **Complete working example**
8. **Output**
9. **Common mistakes**

We will start with **open()**.

---

# 1. open()

`open()` opens a file and returns a **file descriptor**.

Everything else like `read()`, `write()`, `lseek()`, and `close()` needs a file descriptor.

Think of it like this:

```
File on Disk
     │
     │ open()
     ▼
File Descriptor (int)
     │
     ├── read()
     ├── write()
     ├── lseek()
     └── close()
```

Without `open()`, you cannot use the other low-level functions.

---

# Header

```c
#include <fcntl.h>
#include <unistd.h>
```

---

# Prototype

```c
int open(const char *pathname, int flags);
```

or

```c
int open(const char *pathname, int flags, mode_t mode);
```

The third parameter is only used when creating a new file.

---

# Parameters

## First parameter

```c
const char *pathname
```

The file path.

Example:

```c
"test.txt"
```

or

```c
"/home/user/data.txt"
```

---

## Second parameter

```c
flags
```

This tells Linux how to open the file.

Common flags:

### Read only

```c
O_RDONLY
```

```
Can read
Cannot write
```

---

### Write only

```c
O_WRONLY
```

```
Can write
Cannot read
```

---

### Read and Write

```c
O_RDWR
```

```
Can read
Can write
```

---

### Create file

```c
O_CREAT
```

If the file does not exist,

Linux creates it.

---

### Truncate file

```c
O_TRUNC
```

Deletes all existing contents.

Example

Before

```
Hello World
```

After opening

```
(empty)
```

---

### Append

```c
O_APPEND
```

Always writes at the end.

---

Flags can be combined.

Example

```c
O_WRONLY | O_CREAT | O_TRUNC
```

Meaning

```
Write only

Create if missing

Erase previous content
```

---

## Third parameter

Only used with

```c
O_CREAT
```

Example

```c
0644
```

Meaning

Owner

```
Read
Write
```

Others

```
Read only
```

---

# Return Value

Success

```c
>=0
```

Example

```c
3
```

This is the file descriptor.

Failure

```c
-1
```

Always check.

```c
if(fd==-1)
{
    perror("open");
}
```

---

# Complete Example 1

Open an existing file.

```c
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd;

    fd = open("test.txt", O_RDONLY);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    printf("File Descriptor = %d\n", fd);

    close(fd);

    return 0;
}
```

---

Output

```
File Descriptor = 3
```

---

# Example 2

Create a file.

```c
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd;

    fd = open("newfile.txt",
              O_WRONLY | O_CREAT,
              0644);

    if(fd==-1)
    {
        perror("open");
        return 1;
    }

    printf("Created Successfully\n");

    close(fd);

    return 0;
}
```

---

Output

```
Created Successfully
```

---

# Example 3

Erase previous file contents.

Suppose

```
test.txt
```

contains

```
Hello
```

Program

```c
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd;

    fd = open("test.txt",
              O_WRONLY | O_TRUNC);

    if(fd==-1)
    {
        perror("open");
        return 1;
    }

    close(fd);

    return 0;
}
```

After running

```
test.txt
```

becomes

```
(empty)
```

---

# Example 4

Append mode

Suppose

```
Hello
```

already exists.

Open

```c
fd = open("test.txt",
          O_WRONLY | O_APPEND);
```

Later

```c
write(fd," World",6);
```

Result

```
Hello World
```

---

# Real Project Example

Simple logger.

```c
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int fd;

    fd = open("log.txt",
              O_WRONLY | O_CREAT | O_APPEND,
              0644);

    if(fd==-1)
    {
        perror("open");
        return 1;
    }

    char message[] = "Program Started\n";

    write(fd, message, strlen(message));

    close(fd);

    return 0;
}
```

Every run

```
Program Started
Program Started
Program Started
```

is appended.

---

# Common Errors

Opening a missing file without

```c
O_CREAT
```

```c
fd=open("abc.txt",O_RDONLY);
```

Result

```
No such file or directory
```

---

Forgetting

```c
close(fd);
```

Can leak file descriptors.

---

Not checking

```c
fd==-1
```

Always check.

---

# Summary

| Item          | Description                                                        |
| ------------- | ------------------------------------------------------------------ |
| Function      | `open()`                                                           |
| Header        | `<fcntl.h>`                                                        |
| Returns       | File descriptor or `-1`                                            |
| Used Before   | `read()`, `write()`, `lseek()`, `pread()`, `pwrite()`, `close()`   |
| Common Flags  | `O_RDONLY`, `O_WRONLY`, `O_RDWR`, `O_CREAT`, `O_TRUNC`, `O_APPEND` |
| Most Used For | Opening or creating files for low-level I/O                        |

---

Next comes **2. `close()`**, where you'll learn how to properly release a file descriptor, what happens if you forget to close it, and complete real-world examples before moving on to `read()`, `write()`, `lseek()`, `pread()`, and `pwrite()`.








Perfect. Now let's learn **`read()`** completely. This is one of the most important POSIX system calls in C.

---

# read()

## What is `read()`?

`read()` reads **raw bytes** from a file descriptor into memory (a buffer).

It **does not** understand text, lines, words, or numbers. It only copies bytes.

For example, if a file contains:

```text
Hello
```

The actual bytes are:

| Character | ASCII |  Hex |
| --------- | ----: | ---: |
| H         |    72 | 0x48 |
| e         |   101 | 0x65 |
| l         |   108 | 0x6C |
| l         |   108 | 0x6C |
| o         |   111 | 0x6F |

`read()` copies these bytes into your buffer.

---

# Header Files

```c
#include <unistd.h>
#include <fcntl.h>
```

---

# Prototype

```c
ssize_t read(int fd, void *buf, size_t count);
```

---

# Parameters

## 1. fd

```c
int fd
```

The **file descriptor** returned by `open()`.

Example:

```c
int fd = open("test.txt", O_RDONLY);
```

---

## 2. buf

```c
void *buf
```

The memory where the bytes will be stored.

Usually:

```c
char buffer[100];
```

Then:

```c
read(fd, buffer, 100);
```

Before reading:

```
buffer

+----+----+----+----+----+
| ?? | ?? | ?? | ?? | ?? |
+----+----+----+----+----+
```

After reading "Hello":

```
buffer

+----+----+----+----+----+
| H  | e  | l  | l  | o  |
+----+----+----+----+----+
```

---

## 3. count

```c
size_t count
```

Maximum number of bytes to read.

Example:

```c
read(fd, buffer, 5);
```

Only reads up to 5 bytes.

If the file has

```
Hello World
```

only

```
Hello
```

is read.

---

# Return Value

```c
ssize_t
```

Three possible results:

### Success

Returns number of bytes actually read.

Example:

```c
char buf[100];

ssize_t n = read(fd, buf, 100);
```

Suppose file contains

```
Hello
```

Then

```
n = 5
```

---

### End of File (EOF)

Returns

```c
0
```

Meaning:

> There is nothing left to read.

Example:

```
File size = 10 bytes
```

If you already read all 10 bytes:

```c
read(fd, buf, 100);
```

returns

```
0
```

---

### Error

Returns

```c
-1
```

Always check:

```c
if (n == -1)
{
    perror("read");
}
```

---

# Memory Example

Suppose file contains

```
ABCDE
```

Buffer before reading:

```
+----+----+----+----+----+
| ?? | ?? | ?? | ?? | ?? |
+----+----+----+----+----+
```

After

```c
read(fd, buffer, 5);
```

Memory becomes

```
+----+----+----+----+----+
| A  | B  | C  | D  | E  |
+----+----+----+----+----+
```

Nothing magical happens.

It simply copies bytes.

---

# Example 1 — Read Entire Small File

Suppose `test.txt` contains:

```
Hello World
```

Program:

```c
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
    int fd = open("test.txt", O_RDONLY);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    char buffer[100];

    ssize_t bytes = read(fd, buffer, sizeof(buffer) - 1);

    if (bytes == -1)
    {
        perror("read");
        close(fd);
        return 1;
    }

    buffer[bytes] = '\0';

    printf("Read %zd bytes\n", bytes);
    printf("%s\n", buffer);

    close(fd);

    return 0;
}
```

Output:

```
Read 11 bytes
Hello World
```

---

# Why `buffer[bytes] = '\0';`?

`read()` copies **raw bytes**.

It **does not** add the string terminator.

Without:

```c
buffer[bytes] = '\0';
```

printing with

```c
printf("%s", buffer);
```

is undefined behavior because `%s` expects a null-terminated C string.

Example:

```
Memory after read

+---+---+---+---+----+
| H | i | ? | ? | ?  |
+---+---+---+---+----+
```

After adding:

```
+---+---+----+
| H | i | \0 |
+---+---+----+
```

Now it is a proper C string.

---

# Example 2 — Read Only 5 Bytes

Suppose file contains

```
Hello World
```

Program:

```c
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
    int fd = open("test.txt", O_RDONLY);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    char buffer[6];

    ssize_t n = read(fd, buffer, 5);

    if (n == -1)
    {
        perror("read");
        close(fd);
        return 1;
    }

    buffer[n] = '\0';

    printf("%s\n", buffer);

    close(fd);

    return 0;
}
```

Output:

```
Hello
```

Only 5 bytes are read.

---

# Example 3 — Read in Chunks (Real-World Style)

This is how large files are usually read.

```c
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
    int fd = open("test.txt", O_RDONLY);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    char buffer[8];
    ssize_t n;

    while ((n = read(fd, buffer, sizeof(buffer))) > 0)
    {
        fwrite(buffer, 1, n, stdout);
    }

    if (n == -1)
    {
        perror("read");
    }

    close(fd);

    return 0;
}
```

Suppose the file contains:

```
ABCDEFGHIJKLMNOPQRSTUVWXYZ
```

The reads happen like this:

```
Read #1

ABCDEFGH

Read #2

IJKLMNOP

Read #3

QRSTUVWX

Read #4

YZ
```

The loop stops when:

```
read()

↓

0
```

which means end-of-file.

---

# Real-World Uses of `read()`

`read()` is used in many system programs because it works with raw bytes:

* Reading text files (`.txt`)
* Reading binary files (`.exe`, `.png`, `.pdf`)
* Copying files (`cp`-like utilities)
* Reading data from pipes
* Reading from sockets (network communication)
* Reading from terminals (keyboard input via file descriptor `0`)
* Reading device files (e.g., `/dev/random`, `/dev/tty` on POSIX systems)

---

# Common Mistakes

### 1. Ignoring the return value

Wrong:

```c
read(fd, buffer, 100);
```

Correct:

```c
ssize_t n = read(fd, buffer, 100);
```

---

### 2. Forgetting the null terminator when treating data as a string

Wrong:

```c
printf("%s", buffer);
```

Correct:

```c
buffer[n] = '\0';
printf("%s", buffer);
```

---

### 3. Assuming `read()` fills the entire buffer

Wrong assumption:

```
Requested 100 bytes

↓

Always gets 100 bytes
```

Reality:

It may return:

```
100

or

60

or

12

or

1

or

0
```

Always use the returned value to know how many bytes were actually read.

---

# Summary

| Item       | Description                                                                                           |
| ---------- | ----------------------------------------------------------------------------------------------------- |
| Function   | `read()`                                                                                              |
| Header     | `<unistd.h>`                                                                                          |
| Prototype  | `ssize_t read(int fd, void *buf, size_t count);`                                                      |
| `fd`       | File descriptor to read from                                                                          |
| `buf`      | Memory buffer where bytes are stored                                                                  |
| `count`    | Maximum number of bytes to read                                                                       |
| Returns    | Number of bytes read, `0` for EOF, `-1` on error                                                      |
| Works With | Text files, binary files, pipes, sockets, terminals, and devices                                      |
| Important  | `read()` reads raw bytes only; it does **not** add a `'\0'` terminator or interpret the data as text. |












Great. Now let's learn **`write()`** completely.

`write()` is the opposite of `read()`. It copies **raw bytes from memory** into a file (or another output such as a terminal, pipe, or socket).

---

# write()

## What is `write()`?

`write()` writes **raw bytes** from your program's memory to a file descriptor.

It does **not** know anything about strings, integers, or text. It simply copies bytes.

For example:

```text
Memory
+---+---+---+---+---+
| H | e | l | l | o |
+---+---+---+---+---+
         |
         | write()
         V
File
Hello
```

---

# Header Files

```c
#include <unistd.h>
#include <fcntl.h>
```

---

# Prototype

```c
ssize_t write(int fd, const void *buf, size_t count);
```

---

# Parameters

## 1. fd

```c
int fd
```

The file descriptor returned by `open()`.

Example:

```c
int fd = open("test.txt", O_WRONLY);
```

---

## 2. buf

```c
const void *buf
```

The memory containing the bytes to write.

Example:

```c
char message[] = "Hello World";
```

Then:

```c
write(fd, message, 11);
```

---

## 3. count

```c
size_t count
```

The number of bytes to write.

Example:

```c
write(fd, message, 5);
```

Only writes:

```text
Hello
```

---

# Return Value

```c
ssize_t
```

### Success

Returns the number of bytes actually written.

Example:

```c
ssize_t n = write(fd, message, 11);
```

If successful:

```text
n = 11
```

---

### Error

Returns:

```c
-1
```

Always check:

```c
if (n == -1)
{
    perror("write");
}
```

---

# Memory Example

Program memory:

```text
+---+---+---+---+---+
| H | e | l | l | o |
+---+---+---+---+---+
```

After:

```c
write(fd, buffer, 5);
```

File becomes:

```text
Hello
```

---

# Example 1 — Write a String to a File

```c
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
    int fd = open("test.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    char message[] = "Hello World";

    ssize_t bytes = write(fd, message, 11);

    if (bytes == -1)
    {
        perror("write");
        close(fd);
        return 1;
    }

    printf("Wrote %zd bytes\n", bytes);

    close(fd);

    return 0;
}
```

Contents of `test.txt`:

```text
Hello World
```

Output:

```text
Wrote 11 bytes
```

---

# Example 2 — Write Only Part of a String

```c
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
    int fd = open("test.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    char message[] = "Hello World";

    write(fd, message, 5);

    close(fd);

    return 0;
}
```

File contents:

```text
Hello
```

Only the first 5 bytes are written.

---

# Example 3 — Write Multiple Times

```c
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
    int fd = open("test.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    write(fd, "Hello", 5);
    write(fd, " ", 1);
    write(fd, "World", 5);

    close(fd);

    return 0;
}
```

File contents:

```text
Hello World
```

Each `write()` starts where the previous one ended because the file offset moves forward automatically.

---

# Example 4 — Write Binary Data

`write()` is not limited to text.

```c
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
    int fd = open("numbers.bin", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    int numbers[] = {10, 20, 30, 40, 50};

    ssize_t bytes = write(fd, numbers, sizeof(numbers));

    if (bytes == -1)
    {
        perror("write");
    }

    close(fd);

    return 0;
}
```

This writes the **raw binary representation** of the integers, **not** the text:

```text
10 20 30 40 50
```

If each `int` is 4 bytes:

```text
5 × 4 = 20 bytes
```

are written to the file.

---

# Example 5 — Write to the Terminal

The terminal itself is a file descriptor.

Standard output (`stdout`) has file descriptor `1`.

```c
#include <unistd.h>

int main(void)
{
    write(1, "Hello Terminal\n", 15);

    return 0;
}
```

Output:

```text
Hello Terminal
```

This prints directly to the terminal without using `printf()`.

---

# File Offset

Suppose the file is empty.

First call:

```c
write(fd, "ABC", 3);
```

File:

```text
ABC
 ^
 Offset = 3
```

Second call:

```c
write(fd, "DEF", 3);
```

File:

```text
ABCDEF
      ^
 Offset = 6
```

The file offset automatically advances after each successful `write()`.

---

# Real-World Uses

`write()` is used for:

* Writing text files
* Writing binary files
* Creating log files
* Saving images and PDFs
* Sending data through sockets
* Writing to pipes
* Writing to the terminal (`stdout`)
* Writing to device files

---

# Common Mistakes

### 1. Ignoring the return value

Wrong:

```c
write(fd, buffer, 100);
```

Correct:

```c
ssize_t n = write(fd, buffer, 100);

if (n == -1)
{
    perror("write");
}
```

---

### 2. Using the wrong byte count

Wrong:

```c
char msg[] = "Hello";

write(fd, msg, 100);
```

This attempts to write 100 bytes even though the array contains only 6 bytes (`'H'`, `'e'`, `'l'`, `'l'`, `'o'`, `'\0'`).

Correct:

```c
write(fd, msg, 5);
```

or

```c
#include <string.h>

write(fd, msg, strlen(msg));
```

---

### 3. Opening a file without write permission

Wrong:

```c
int fd = open("test.txt", O_RDONLY);

write(fd, "Hello", 5);
```

This fails because the file was opened **read-only**.

Correct:

```c
int fd = open("test.txt", O_WRONLY);
```

---

# `write()` vs `printf()`

| `write()`                      | `printf()`                                       |
| ------------------------------ | ------------------------------------------------ |
| System call                    | Standard C library function                      |
| Writes raw bytes               | Formats output (e.g., `%d`, `%f`, `%s`)          |
| No buffering                   | Usually buffered                                 |
| Faster for low-level I/O       | More convenient for formatted text               |
| Works with any file descriptor | Primarily used with `stdout` or `FILE *` streams |

---

# Summary

| Item      | Description                                                                                           |
| --------- | ----------------------------------------------------------------------------------------------------- |
| Function  | `write()`                                                                                             |
| Header    | `<unistd.h>`                                                                                          |
| Prototype | `ssize_t write(int fd, const void *buf, size_t count);`                                               |
| `fd`      | File descriptor to write to                                                                           |
| `buf`     | Memory containing the bytes to write                                                                  |
| `count`   | Number of bytes to write                                                                              |
| Returns   | Number of bytes written, or `-1` on error                                                             |
| Important | `write()` writes raw bytes exactly as they exist in memory; it does not format or interpret the data. |

The next function in the sequence is **`lseek()`**, which lets you move the file position (offset) before reading or writing.












Excellent. Now let's learn **`lseek()`**, one of the most powerful POSIX system calls.

Unlike `read()` and `write()`, `lseek()` **does not read or write any data**. It only **moves the file offset (also called the file pointer or cursor)**.

---

# lseek()

## What is `lseek()`?

Every open file has a **current file offset**.

When you call:

```c
read(fd, buffer, 10);
```

the operating system reads 10 bytes and automatically moves the offset forward by 10 bytes.

Likewise,

```c
write(fd, buffer, 10);
```

writes 10 bytes and moves the offset forward by 10 bytes.

`lseek()` lets you **change that offset manually**.

Think of it like the cursor in a text editor.

```
File:

H e l l o   W o r l d
0 1 2 3 4 5 6 7 8 9 10

Current Offset
      ^
      2
```

After:

```c
lseek(fd, 6, SEEK_SET);
```

The offset becomes:

```
H e l l o   W o r l d
0 1 2 3 4 5 6 7 8 9 10

Current Offset
            ^
            6
```

The next `read()` or `write()` starts at byte 6.

---

# Header Files

```c
#include <unistd.h>
#include <fcntl.h>
```

---

# Prototype

```c
off_t lseek(int fd, off_t offset, int whence);
```

---

# Parameters

## 1. fd

```c
int fd
```

The file descriptor returned by `open()`.

Example:

```c
int fd = open("test.txt", O_RDONLY);
```

---

## 2. offset

```c
off_t offset
```

How many bytes to move.

Examples:

```c
10
```

Move 10 bytes.

```c
-5
```

Move backward 5 bytes (when allowed).

```c
0
```

Don't move.

---

## 3. whence

This tells Linux **where the movement starts**.

There are three values.

---

## SEEK_SET

Start counting from the beginning of the file.

```c
lseek(fd, 5, SEEK_SET);
```

File

```
ABCDEFGHIJ
0123456789
```

Offset becomes

```
ABCDE|FGHIJ
     ^
     5
```

---

## SEEK_CUR

Start counting from the current position.

Suppose current offset is 5.

```
ABCDE|FGHIJ
     ^
```

Then

```c
lseek(fd, 2, SEEK_CUR);
```

becomes

```
ABCDEFG|HIJ
       ^
       7
```

Moving backwards:

```c
lseek(fd, -3, SEEK_CUR);
```

becomes

```
ABCD|EFGHIJ
    ^
    4
```

---

## SEEK_END

Start counting from the end of the file.

Suppose

```
Hello World
```

Length = 11 bytes.

```
Hello World|
           ^
         End
```

Example

```c
lseek(fd, 0, SEEK_END);
```

Moves to the end.

Example

```c
lseek(fd, -5, SEEK_END);
```

Moves back 5 bytes.

```
Hello |World
      ^
```

---

# Return Value

```c
off_t
```

Success:

Returns the **new file offset**.

Example

```c
off_t pos = lseek(fd, 10, SEEK_SET);
```

```
pos = 10
```

Failure:

```c
-1
```

Always check:

```c
if (lseek(fd, 0, SEEK_SET) == -1)
{
    perror("lseek");
}
```

---

# Example 1 — Read from the Middle of a File

Suppose `test.txt` contains:

```
Hello World
```

Program:

```c
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
    int fd = open("test.txt", O_RDONLY);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    if (lseek(fd, 6, SEEK_SET) == -1)
    {
        perror("lseek");
        close(fd);
        return 1;
    }

    char buffer[6];

    ssize_t n = read(fd, buffer, 5);

    if (n == -1)
    {
        perror("read");
        close(fd);
        return 1;
    }

    buffer[n] = '\0';

    printf("%s\n", buffer);

    close(fd);

    return 0;
}
```

Output:

```
World
```

Explanation:

```
Hello World
01234567890

Offset moved to 6

Next read()

↓

World
```

---

# Example 2 — Skip the First 5 Bytes

Suppose

```
ABCDEFGHIJK
```

Program:

```c
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
    int fd = open("test.txt", O_RDONLY);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    lseek(fd, 5, SEEK_SET);

    char buffer[100];

    ssize_t n = read(fd, buffer, sizeof(buffer) - 1);

    if (n == -1)
    {
        perror("read");
        close(fd);
        return 1;
    }

    buffer[n] = '\0';

    printf("%s\n", buffer);

    close(fd);

    return 0;
}
```

Output:

```
FGHIJK
```

---

# Example 3 — Find the File Size

One of the most common uses of `lseek()`.

```c
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
    int fd = open("test.txt", O_RDONLY);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    off_t size = lseek(fd, 0, SEEK_END);

    if (size == -1)
    {
        perror("lseek");
        close(fd);
        return 1;
    }

    printf("File size = %lld bytes\n", (long long)size);

    close(fd);

    return 0;
}
```

Suppose the file contains:

```
Hello World
```

Output:

```
File size = 11 bytes
```

---

# Example 4 — Overwrite Part of a File

Suppose the file contains:

```
Hello World
```

Program:

```c
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
    int fd = open("test.txt", O_WRONLY);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    lseek(fd, 6, SEEK_SET);

    write(fd, "Linux", 5);

    close(fd);

    return 0;
}
```

File becomes:

```
Hello Linux
```

Explanation:

Original:

```
Hello World
      ^
```

Move to byte 6.

Then:

```c
write(fd, "Linux", 5);
```

overwrites:

```
World
```

with:

```
Linux
```

---

# Example 5 — Create a Sparse File

```c
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
    int fd = open("sparse.bin",
                  O_WRONLY | O_CREAT | O_TRUNC,
                  0644);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    lseek(fd, 1024, SEEK_SET);

    write(fd, "A", 1);

    close(fd);

    return 0;
}
```

The resulting file has:

* 1024 empty bytes (a "hole")
* followed by the byte `'A'`

Many file systems store these holes efficiently without allocating disk blocks for all the skipped bytes.

---

# Real-World Uses

`lseek()` is commonly used for:

* Jumping to a specific position in a file
* Skipping file headers
* Editing part of a file without rewriting everything
* Finding the size of a file (`SEEK_END`)
* Creating sparse files
* Random-access reading and writing

---

# Common Mistakes

### 1. Forgetting to check for errors

Wrong:

```c
lseek(fd, 100, SEEK_SET);
```

Correct:

```c
if (lseek(fd, 100, SEEK_SET) == -1)
{
    perror("lseek");
}
```

---

### 2. Using `lseek()` on objects that don't support seeking

For example, pipes and sockets generally do **not** support seeking.

```c
lseek(pipe_fd, 0, SEEK_SET);
```

Usually fails with:

```
ESPIPE
```

("Illegal seek")

---

### 3. Forgetting that `write()` overwrites existing bytes

If the file contains:

```
Hello World
```

and you do:

```c
lseek(fd, 6, SEEK_SET);
write(fd, "Linux", 5);
```

The result is:

```
Hello Linux
```

It does **not** insert `"Linux"` and shift the remaining bytes. It simply replaces the existing bytes starting at the current offset.

---

# `lseek()` vs `pread()`/`pwrite()`

| Function   | Changes file offset?           | Reads/Writes data? |
| ---------- | ------------------------------ | ------------------ |
| `lseek()`  | ✅ Yes                          | ❌ No               |
| `read()`   | ✅ Yes (advances automatically) | ✅ Yes              |
| `write()`  | ✅ Yes (advances automatically) | ✅ Yes              |
| `pread()`  | ❌ No                           | ✅ Yes              |
| `pwrite()` | ❌ No                           | ✅ Yes              |

---

# Summary

| Item      | Description                                               |
| --------- | --------------------------------------------------------- |
| Function  | `lseek()`                                                 |
| Header    | `<unistd.h>`                                              |
| Prototype | `off_t lseek(int fd, off_t offset, int whence);`          |
| `fd`      | File descriptor                                           |
| `offset`  | Number of bytes to move                                   |
| `whence`  | `SEEK_SET`, `SEEK_CUR`, or `SEEK_END`                     |
| Returns   | New file offset, or `-1` on error                         |
| Purpose   | Move the file offset without reading or writing any bytes |

The next functions are **`pread()`** and **`pwrite()`**, which combine seeking with reading or writing **without changing the file's current offset**. They are especially useful for random-access file operations and multithreaded programs.










Excellent. Now we will learn **`pread()`** and **`pwrite()`** together because they are closely related.

They are like a combination of:

* `lseek()`
* `read()` or `write()`

**But there is one very important difference:**

> **`pread()` and `pwrite()` DO NOT change the current file offset.**

This is why they are heavily used in databases, operating systems, multithreaded servers, and file systems.

---

# Why were `pread()` and `pwrite()` created?

Suppose a file contains:

```text
ABCDEFGHIJKLMNOPQRSTUVWXYZ
```

Normally, if you want to read from byte 10, you would write:

```c
lseek(fd, 10, SEEK_SET);
read(fd, buffer, 5);
```

This works.

But notice what happened.

The file offset changed.

Before:

```text
Offset
^

ABCDEFGHIJKLMNOPQRSTUVWXYZ
```

After `lseek(fd, 10, SEEK_SET)`:

```text
          Offset
            ^

ABCDEFGHIJKLMNOPQRSTUVWXYZ
```

After `read(fd, buffer, 5)`:

```text
               Offset
                 ^

ABCDEFGHIJKLMNOPQRSTUVWXYZ
```

The offset is now 15.

Sometimes this is exactly what you want.

Sometimes it is not.

That is why POSIX provides `pread()`.

---

# pread()

## What is it?

`pread()` reads bytes from a **specific position** in the file **without changing the current file offset**.

Think of it like this:

```text
Current offset
      |
      v
ABCDEFGHIJKLMNOPQRSTUVWXYZ

pread(fd, ..., 10)

Reads here
          ^

Current offset never moves.
```

---

# Header Files

```c
#include <unistd.h>
#include <fcntl.h>
```

---

# Prototype

```c
ssize_t pread(int fd, void *buf, size_t count, off_t offset);
```

---

# Parameters

## 1. fd

```c
int fd
```

The file descriptor returned by `open()`.

Example

```c
int fd = open("test.txt", O_RDONLY);
```

---

## 2. buf

```c
void *buf
```

Where the data will be stored.

Example

```c
char buffer[20];
```

---

## 3. count

```c
size_t count
```

Maximum bytes to read.

Example

```c
5
```

Reads at most five bytes.

---

## 4. offset

```c
off_t offset
```

The exact byte position where reading begins.

Example

```c
10
```

Read starting at byte 10.

---

# Return Value

Success

Returns number of bytes read.

```c
5
```

End of file

```c
0
```

Error

```c
-1
```

Always check.

---

# Complete Example 1

Suppose `test.txt` contains

```text
Hello World
```

Program

```c
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
    int fd = open("test.txt", O_RDONLY);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    char buffer[6];

    ssize_t n = pread(fd, buffer, 5, 6);

    if (n == -1)
    {
        perror("pread");
        close(fd);
        return 1;
    }

    buffer[n] = '\0';

    printf("%s\n", buffer);

    close(fd);

    return 0;
}
```

Output

```text
World
```

Notice:

We never called

```c
lseek()
```

---

# Does pread() change the offset?

Let's prove it.

```c
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
    int fd = open("test.txt", O_RDONLY);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    off_t before = lseek(fd, 0, SEEK_CUR);

    char buffer[6];

    pread(fd, buffer, 5, 6);

    off_t after = lseek(fd, 0, SEEK_CUR);

    printf("Before = %lld\n", (long long)before);
    printf("After  = %lld\n", (long long)after);

    close(fd);

    return 0;
}
```

Output

```text
Before = 0
After  = 0
```

The offset never changed.

---

# What would happen with read()?

```c
lseek(fd, 6, SEEK_SET);

read(fd, buffer, 5);
```

Now

```text
Offset

11
```

because `read()` advances the offset.

---

# pwrite()

Now let's learn the opposite.

---

# What is pwrite()?

`pwrite()` writes bytes at a **specific position** in the file **without changing the current file offset**.

Prototype

```c
ssize_t pwrite(int fd,
               const void *buf,
               size_t count,
               off_t offset);
```

Notice the extra parameter.

```text
offset
```

Exactly like `pread()`.

---

# Parameters

## fd

File descriptor.

---

## buf

Memory containing bytes.

Example

```c
char message[] = "Linux";
```

---

## count

Number of bytes.

Example

```c
5
```

---

## offset

Position where writing begins.

Example

```c
6
```

---

# Return Value

Success

Returns bytes written.

Example

```text
5
```

Failure

```text
-1
```

---

# Complete Example

Suppose

```text
Hello World
```

Program

```c
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
    int fd = open("test.txt", O_WRONLY);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    ssize_t n = pwrite(fd, "Linux", 5, 6);

    if (n == -1)
    {
        perror("pwrite");
        close(fd);
        return 1;
    }

    close(fd);

    return 0;
}
```

Result

```text
Hello Linux
```

Notice

We never used

```c
lseek()
```

---

# Does pwrite() move the offset?

Let's test.

```c
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
    int fd = open("test.txt", O_WRONLY);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    printf("Before = %lld\n",
           (long long)lseek(fd, 0, SEEK_CUR));

    pwrite(fd, "ABC", 3, 5);

    printf("After = %lld\n",
           (long long)lseek(fd, 0, SEEK_CUR));

    close(fd);

    return 0;
}
```

Output

```text
Before = 0
After = 0
```

Offset did not change.

---

# Real-World Example

Suppose a database file contains:

```text
User1
User2
User3
User4
User5
```

Thread A wants to read **User2**.

Thread B wants to update **User5**.

If both threads use

```c
lseek()
```

followed by

```c
read()
```

or

```c
write()
```

they share the same file offset, which can lead to race conditions if they use the same file descriptor.

Using `pread()` and `pwrite()`:

```c
pread(fd, buffer, size, user2_offset);

pwrite(fd, new_data, size, user5_offset);
```

Each operation specifies its own offset, so the shared file offset is never modified.

---

# When are pread() and pwrite() used?

They are common in:

* Database engines (e.g., page-based storage)
* File systems
* Operating systems
* Multithreaded servers
* Random-access binary files
* Virtual disk images
* Large data processing applications

---

# read() vs pread()

| Feature                                  | `read()`        | `pread()` |
| ---------------------------------------- | --------------- | --------- |
| Reads data                               | ✅ Yes           | ✅ Yes     |
| Needs `lseek()` to read another location | Usually yes     | No        |
| Changes file offset                      | ✅ Yes           | ❌ No      |
| Thread-safe for shared file descriptors  | ❌ Not by itself | ✅ Yes     |
| Reads from a specified offset            | ❌ No            | ✅ Yes     |

---

# write() vs pwrite()

| Feature                             | `write()` | `pwrite()` |
| ----------------------------------- | --------- | ---------- |
| Writes data                         | ✅ Yes     | ✅ Yes      |
| Changes file offset                 | ✅ Yes     | ❌ No       |
| Needs `lseek()` for random writes   | Yes       | No         |
| Writes at a specified offset        | ❌ No      | ✅ Yes      |
| Better for concurrent random writes | ❌         | ✅          |

---

# `lseek() + read()` vs `pread()`

Suppose you want to read `"World"` from `"Hello World"`.

Using `lseek()` + `read()`:

```c
lseek(fd, 6, SEEK_SET);
read(fd, buffer, 5);
```

Offset changes from:

```text
0 → 6 → 11
```

Using `pread()`:

```c
pread(fd, buffer, 5, 6);
```

Offset stays:

```text
0 → 0
```

---

# `lseek() + write()` vs `pwrite()`

Using `lseek()`:

```c
lseek(fd, 6, SEEK_SET);
write(fd, "Linux", 5);
```

Offset:

```text
0 → 6 → 11
```

Using `pwrite()`:

```c
pwrite(fd, "Linux", 5, 6);
```

Offset:

```text
0 → 0
```

---

# Summary

| Function   | Purpose                       | Changes Offset? | Uses Offset Parameter? |
| ---------- | ----------------------------- | --------------- | ---------------------- |
| `read()`   | Read sequentially             | ✅ Yes           | ❌ No                   |
| `write()`  | Write sequentially            | ✅ Yes           | ❌ No                   |
| `lseek()`  | Move file offset              | ✅ Yes           | ✅ Yes                  |
| `pread()`  | Read from a specific position | ❌ No            | ✅ Yes                  |
| `pwrite()` | Write to a specific position  | ❌ No            | ✅ Yes                  |

## Rule to Remember

* Use **`read()`** and **`write()`** when processing a file sequentially from beginning to end.
* Use **`lseek()`** when you want to move the current file position before the next operation.
* Use **`pread()`** and **`pwrite()`** when you need random access to a file **without disturbing the current file offset**, especially in multithreaded or concurrent programs.
