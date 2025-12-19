# 1. What a Directory Really Is (At OS Level)

Before touching C code, you must understand the abstraction.

* A **directory is a special file** that maps **names → inode numbers** (on Unix-like systems).
* The kernel, **not C**, performs directory operations.
* C interacts with directories via **system calls and libc wrappers**.

Key consequences:

* You **never manipulate directory bytes directly**
* You **always go through OS APIs**
* Errors come from the OS, not C logic

---

# 2. Headers You Must Know (Non-Negotiable)

```c
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
```

Purpose:

* `sys/stat.h` → create directories, permissions
* `dirent.h` → open/read directories
* `unistd.h` → remove, change directory
* `errno.h` → error handling

If you do not understand **every one of these**, you are not ready for a large project.

---

# 3. Creating Directories

## 3.1 mkdir() — The Foundation

### Prototype

```c
int mkdir(const char *pathname, mode_t mode);
```

### What it does

* Asks the kernel to create a directory entry
* Assigns permissions (filtered by umask)

### Example (Correct, Production-Safe)

```c
if (mkdir("logs", 0755) == -1) {
    perror("mkdir failed");
}
```

### Permissions Breakdown

```
0755
Owner: read write execute
Group: read execute
Other: read execute
```

**Execute permission on a directory = ability to enter it**

### Critical Notes

* Parent directory **must exist**
* Fails if directory already exists (`EEXIST`)
* Permissions are affected by `umask`

---

## 3.2 mkdirat() — Advanced / Secure Creation

Used in sandboxing and large systems.

```c
int mkdirat(int dirfd, const char *pathname, mode_t mode);
```

Why it matters:

* Prevents race conditions
* Used in secure systems (containers, compilers)

You should learn it once you understand file descriptors deeply.

---

# 4. Removing Directories

## 4.1 rmdir() — Only Empty Directories

### Prototype

```c
int rmdir(const char *pathname);
```

### Example

```c
if (rmdir("logs") == -1) {
    perror("rmdir failed");
}
```

Rules:

* Directory **must be empty**
* Cannot remove `.` or `..`
* No recursive deletion

If you try to remove a directory with files inside, **you are doing it wrong**.

---

# 5. Opening and Reading Directories

This is where real projects live.

---

## 5.1 DIR * — Directory Stream

Think of `DIR*` as `FILE*`, but for directories.

```c
DIR *opendir(const char *name);
```

### Example

```c
DIR *dir = opendir(".");
if (!dir) {
    perror("opendir failed");
}
```

---

## 5.2 readdir() — Iterating Entries

### Prototype

```c
struct dirent *readdir(DIR *dirp);
```

### struct dirent (Important Fields)

```c
struct dirent {
    ino_t d_ino;
    char  d_name[];
};
```

### Example (Correct Loop)

```c
struct dirent *entry;

while ((entry = readdir(dir)) != NULL) {
    printf("%s\n", entry->d_name);
}
```

### Reality Check

* `.` = current directory
* `..` = parent directory
* You **must filter them manually**

---

## 5.3 closedir()

You leak kernel resources if you skip this.

```c
closedir(dir);
```

---

# 6. Determining Entry Type (Critical Skill)

`readdir()` does **NOT** give full type information reliably.

You must use `stat()` or `lstat()`.

---

## 6.1 stat() — Resolve Symlinks

```c
struct stat st;
stat(path, &st);
```

### Checking Type

```c
if (S_ISDIR(st.st_mode)) { }
if (S_ISREG(st.st_mode)) { }
```

---

## 6.2 lstat() — Do NOT Follow Symlinks

Mandatory for secure file tools.

---

# 7. Recursive Directory Traversal (NON-OPTIONAL)

Every serious project needs this.

---

### Full Recursive Example (Production-Grade)

```c
void walk(const char *path) {
    DIR *dir = opendir(path);
    if (!dir) return;

    struct dirent *entry;
    char fullpath[1024];

    while ((entry = readdir(dir)) != NULL) {
        if (!strcmp(entry->d_name, ".") ||
            !strcmp(entry->d_name, ".."))
            continue;

        snprintf(fullpath, sizeof(fullpath),
                 "%s/%s", path, entry->d_name);

        struct stat st;
        if (stat(fullpath, &st) == -1) continue;

        if (S_ISDIR(st.st_mode)) {
            walk(fullpath);
        } else {
            printf("FILE: %s\n", fullpath);
        }
    }

    closedir(dir);
}
```

This pattern is **industry standard**.

---

# 8. Changing and Tracking Directories

---

## 8.1 chdir()

```c
chdir("/var/log");
```

Danger:

* Global process state
* Breaks multithreaded logic
* Avoid in libraries

---

## 8.2 getcwd()

```c
char buf[1024];
getcwd(buf, sizeof(buf));
```

Used for:

* Logging
* Debugging
* Relative path resolution

---

# 9. Permissions and Metadata

---

## 9.1 chmod()

```c
chmod("logs", 0700);
```

---

## 9.2 umask()

```c
umask(0022);
```

This silently modifies permissions — **many bugs come from here**.

---

# 10. Error Handling (Non-Optional Discipline)

Always inspect `errno`.

```c
if (mkdir("data", 0755) == -1) {
    if (errno == EEXIST) {
        // directory already exists
    } else {
        perror("mkdir");
    }
}
```

Never ignore errors in filesystem code.

---

# 11. Real Production Use-Cases

Here are **10 serious, real-world directory use cases**:

1. Log rotation systems
2. Recursive file indexers
3. Build systems (make, ninja)
4. Backup tools
5. Package managers
6. Language compilers
7. Media scanners
8. File synchronization tools
9. Web servers
10. Version control systems

Every one of these relies on **precise directory handling**.

---

# 12. Common Mistakes (Do NOT Make These)

* Assuming `readdir()` gives file type
* Forgetting to close DIR*
* Not handling `.` and `..`
* Using `chdir()` in libraries
* Building paths unsafely
* Ignoring symlinks
* No recursion limits

---

# 13. Mental Model You Must Adopt

Think like this:

> “Directories are graphs, not lists.”

Large projects:

* Traverse
* Filter
* Validate
* Secure
* Fail safely

---

# 14. What You Should Master Next

If you want **true project-level mastery**, your next steps are:

1. Path normalization
2. Symbolic link handling
3. Secure recursive deletion
4. Cross-platform abstractions (Windows vs POSIX)
5. File descriptor-based traversal
6. Thread-safe directory walking