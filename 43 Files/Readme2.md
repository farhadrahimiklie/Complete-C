
## 1. Introduction to File Handling

- Files are used to store data permanently.
- In C, files are handled using **streams** represented by `FILE *` pointers.
- You can perform operations like reading, writing, and moving around inside the file.

---

## 2. File Pointer (`FILE *`)

- `FILE` is a structure that holds information about a file.
- When you open a file, you get a pointer to this `FILE` structure.
- All file operations use this pointer.

```c
FILE *fp;  // file pointer
3. Opening and Closing Files
Opening Files: fopen
FILE *fopen(const char *filename, const char *mode);
filename: the name of the file to open.

mode: how you want to open the file (read, write, append, etc.).

Modes:

Mode	Description
"r"	Open for reading (file must exist)
"w"	Open for writing (create/truncate)
"a"	Open for appending (create if needed)
"r+"	Open for reading and writing
"w+"	Open for reading and writing (truncate)
"a+"	Open for reading and appending
Example:
FILE *fp = fopen("file.txt", "r");
if (fp == NULL) {
    printf("Error opening file\n");
    return 1;
}
Closing Files: fclose
int fclose(FILE *stream);
Closes the file and flushes buffers.

Always close files after finishing.

4. Reading from Files
Several functions to read from files:

fgetc - Read a single character
int fgetc(FILE *stream);
Returns the character read or EOF if end of file or error.

fgets - Read a line (string)
char *fgets(char *str, int n, FILE *stream);
Reads up to n-1 characters or until newline.

Stores result in str with null terminator.

fread - Read binary data
size_t fread(void *ptr, size_t size, size_t count, FILE *stream);
Reads count elements of size bytes into ptr.

5. Writing to Files
Functions to write data:

fputc - Write a single character
int fputc(int char, FILE *stream);
fputs - Write a string
int fputs(const char *str, FILE *stream);
fwrite - Write binary data
size_t fwrite(const void *ptr, size_t size, size_t count, FILE *stream);
6. File Positioning Functions
Used to move the file cursor or get its position.

fseek - Move file cursor
int fseek(FILE *stream, long offset, int whence);
offset: number of bytes to move.

whence: position from where to move:

Constant	Meaning
SEEK_SET	Beginning of the file
SEEK_CUR	Current position
SEEK_END	End of the file
Example:

fseek(fp, 0, SEEK_SET); // Move to start of file
ftell - Get current position
long ftell(FILE *stream);
Returns current file position (in bytes).

Returns -1L on error.

rewind - Move to start of file
void rewind(FILE *stream);
Equivalent to fseek(stream, 0, SEEK_SET) but also clears error indicators.

7. Error Handling with Files
Check if file pointer is NULL after fopen.

Use feof(FILE *stream) to check if end of file is reached.

Use ferror(FILE *stream) to check if error occurred.

8. Binary vs Text Files
Text files: store characters, use functions like fgetc, fgets.

Binary files: store raw bytes, use fread and fwrite.

When opening files in binary mode, add "b" to the mode, e.g., "rb", "wb".

9. Example Program: Read and Write Text File
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char buffer[100];

    // Open file for writing
    fp = fopen("test.txt", "w");
    if (fp == NULL) {
        printf("Error opening file for writing\n");
        return 1;
    }
    fputs("Hello, world!\n", fp);
    fclose(fp);

    // Open file for reading
    fp = fopen("test.txt", "r");
    if (fp == NULL) {
        printf("Error opening file for reading\n");
        return 1;
    }

    // Read line by line
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s", buffer);
    }

    fclose(fp);
    return 0;
}
10. Summary
Files are accessed via FILE * pointers.

Use fopen and fclose to open and close files.

Read using fgetc, fgets, fread.

Write using fputc, fputs, fwrite.

Use fseek, ftell, and rewind to manage file cursor.

Always check for errors.

Know difference between binary and text files.

End of File Handling Guide