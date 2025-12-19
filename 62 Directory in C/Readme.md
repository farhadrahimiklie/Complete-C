# 1. What a Directory REALLY Is (No Myths)

A **directory is not a container**.
A directory is a **special file** that maps **names → inode numbers**.

* File → inode → metadata (permissions, owner, size, timestamps)
* Directory → table of `(filename, inode)`
* The kernel enforces rules. You do not “manage directories”; you **request** operations via syscalls.

In C, you interact with directories **only through system calls and libc wrappers**.

---

# 2. Core Headers You MUST Know

```c
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
```

If you do not know what each header gives you, you are not ready for production code.

---

# 3. Creating Directories (mkdir)

## 3.1 mkdir — The Only Way

```c
int mkdir(const char *pathname, mode_t mode);
```

* `mode` is **filtered by umask**
* Returns `0` on success, `-1` on failure
* Sets `errno`

### Example (Correct, Minimal)

```c
if (mkdir("logs", 0755) == -1) {
    perror("mkdir");
}
```

### Common Failures (You must handle these):

* `EEXIST` → already exists
* `EACCES` → permission denied
* `ENOENT` → parent does not exist
* `ENOSPC` → disk full

---

## 3.2 mkdir is NOT recursive

This **will fail** if parent directories do not exist.

```c
mkdir("a/b/c", 0755); // FAIL
```

You must implement recursion yourself.

---

# 4. Recursive Directory Creation (Production-Grade)

### Example 1 — `mkdir -p` Equivalent

```c
int mkdir_p(const char *path, mode_t mode) {
    char tmp[1024];
    char *p = NULL;
    size_t len;

    snprintf(tmp, sizeof(tmp), "%s", path);
    len = strlen(tmp);
    if (tmp[len - 1] == '/')
        tmp[len - 1] = 0;

    for (p = tmp + 1; *p; p++) {
        if (*p == '/') {
            *p = 0;
            if (mkdir(tmp, mode) && errno != EEXIST)
                return -1;
            *p = '/';
        }
    }
    if (mkdir(tmp, mode) && errno != EEXIST)
        return -1;

    return 0;
}
```

This is **mandatory knowledge** for backend engineers.

---

# 5. Deleting Directories

## 5.1 rmdir — EMPTY ONLY

```c
int rmdir(const char *pathname);
```

Fails if directory is not empty.

---

## 5.2 Recursive Delete (rm -rf)

### Example 2 — Recursive Directory Deletion

```c
int remove_recursive(const char *path) {
    DIR *d = opendir(path);
    struct dirent *entry;
    char fullpath[1024];

    if (!d) return -1;

    while ((entry = readdir(d)) != NULL) {
        if (!strcmp(entry->d_name, ".") ||
            !strcmp(entry->d_name, ".."))
            continue;

        snprintf(fullpath, sizeof(fullpath), "%s/%s", path, entry->d_name);

        if (entry->d_type == DT_DIR) {
            remove_recursive(fullpath);
        } else {
            unlink(fullpath);
        }
    }
    closedir(d);
    return rmdir(path);
}
```

If you cannot write this, you do not understand directories.

---

# 6. Reading Directory Contents

## 6.1 opendir / readdir / closedir

```c
DIR *opendir(const char *name);
struct dirent *readdir(DIR *dirp);
int closedir(DIR *dirp);
```

### dirent fields:

* `d_name` → filename
* `d_type` → file type (NOT portable, unreliable on some FS)

---

## Example 3 — List Directory (Correct Way)

```c
DIR *dir = opendir(".");
struct dirent *entry;

while ((entry = readdir(dir)) != NULL) {
    printf("%s\n", entry->d_name);
}
closedir(dir);
```

---

# 7. Determining File Type (Never Trust d_type)

### Use `stat`

```c
struct stat st;
stat(path, &st);

if (S_ISDIR(st.st_mode)) { }
if (S_ISREG(st.st_mode)) { }
```

This is **mandatory for production code**.

---

# 8. Changing Current Directory

## Example 4 — chdir + getcwd

```c
char cwd[1024];
getcwd(cwd, sizeof(cwd));
printf("Before: %s\n", cwd);

chdir("/tmp");

getcwd(cwd, sizeof(cwd));
printf("After: %s\n", cwd);
```

Changing working directory is **process-wide**.
In multi-threaded programs, this is dangerous.

---

# 9. Permissions and Ownership

## chmod / chown

```c
chmod("data", 0700);
chown("data", uid, gid);
```

Permissions apply to:

* Read → list directory
* Write → create/delete files
* Execute → enter directory

If you don’t understand this, you will create security bugs.

---

# 10. Production-Level Examples (10)

### Example 5 — Secure Temp Directory

```c
mkdir("/tmp/myapp", 0700);
```

---

### Example 6 — Log Directory Initialization

```c
if (mkdir_p("/var/log/myapp", 0755) == -1) {
    fprintf(stderr, "Cannot create log directory\n");
}
```

---

### Example 7 — Directory Traversal with Filtering

```c
if (S_ISREG(st.st_mode) && strstr(name, ".log")) {
    process_log(name);
}
```

---

### Example 8 — Disk Cleanup Tool

Deletes directories older than X days using `stat.st_mtime`.

---

### Example 9 — Plugin Loader

Scans `/usr/lib/myapp/plugins/` and loads `.so` files.

---

### Example 10 — Backup Tool

Replicates directory trees recursively using:

* `opendir`
* `stat`
* `mkdir`
* `open/read/write`

This is how **rsync-like tools start**.

---

# 11. Windows Reality (You Must Know)

POSIX APIs do NOT work on Windows.

Windows equivalents:

* `_mkdir`
* `FindFirstFile`
* `CreateDirectory`
* `RemoveDirectory`

If you want portability, use:

* Conditional compilation
* Or libraries like **libuv**

---

# 12. Hard Truths (No Sugarcoating)

1. Directory management is **kernel-controlled**
2. You never “edit” directories directly
3. Permissions matter more than code
4. Recursive operations are dangerous
5. Never trust user input paths
6. Always handle `errno`
7. Never assume filesystem behavior
8. Test on real filesystems, not tmpfs

---

# Final Verdict

If you now:

* Understand inode mapping
* Can write recursive mkdir/rmdir
* Can safely traverse directories
* Handle permissions correctly

Then you **actually understand directory management in C**.