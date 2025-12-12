# Dynamic Memory Allocation in C — README

## Purpose

This document explains dynamic memory allocation in C from first principles through practical patterns you need to confidently implement data structures and small systems (for example: linked lists, dynamic arrays/vectors, memory pools, and the building blocks for a simple Git-like object store). It focuses on correctness, safety, performance, and debugging techniques.

> Target reader: C programmer who understands basic C (variables, pointers, structs, functions) and now wants to master dynamic memory.

---

## Table of Contents

1. Introduction and key concepts
2. The `malloc` family (`malloc`, `calloc`, `realloc`, `free`)
3. Ownership, lifetimes, and rules
4. Common mistakes and how to avoid them
5. Practical patterns

   * Dynamic arrays (vector)
   * Singly / doubly linked lists
   * String buffers and safe string handling
   * Memory pools and arenas
6. Building blocks for a simple Git-like object store (conceptual + practical tips)
7. Debugging and tools (valgrind, AddressSanitizer, heap profiling)
8. Design checklist and best practices
9. Exercises and small projects
10. References and further reading

---

## 1. Introduction and key concepts

Dynamic memory allocation gives you control to allocate memory at runtime using the heap. Unlike stack memory (local variables), heap memory persists until you explicitly free it.

Key terms:

* **Heap**: runtime memory region for dynamic allocations.
* **Allocator**: the runtime code/library that services `malloc`/`free`.
* **Pointer**: variable that stores an address (often a heap block address).
* **Ownership**: which part of the code is responsible for `free`-ing an allocation.
* **Lifetime**: period between allocation and `free`.

Mental model: every allocation returns a pointer to a contiguous block with a known size. You must not access outside that block. You must `free` every allocation exactly once (unless using shared ownership schemes).

---

## 2. The `malloc` family

### `void *malloc(size_t size)`

* Allocates `size` bytes and returns a pointer to the beginning of the block.
* Returns `NULL` on allocation failure (always check the result).
* Memory contents are indeterminate (garbage).

Example:

```c
int *arr = malloc(10 * sizeof *arr);
if (!arr) { perror("malloc"); exit(EXIT_FAILURE); }
```

### `void *calloc(size_t nmemb, size_t size)`

* Allocates `nmemb * size` bytes and initializes them to zero.
* Safer when you need zeroed memory.

Example:

```c
char *buf = calloc(256, 1); // 256 zeroed bytes
```

### `void *realloc(void *ptr, size_t new_size)`

* Resizes an existing allocation `ptr` to `new_size`.
* If `ptr == NULL`, behaves like `malloc(new_size)`.
* If `new_size == 0`, behavior is implementation-defined (often frees and returns `NULL`): prefer `free(ptr)` explicitly.
* The returned pointer may be the same or different; you must use the returned pointer.

Example growing a buffer:

```c
char *s = malloc(16);
/* ... fill s ... */
char *s2 = realloc(s, 32);
if (!s2) { free(s); /* handle error */ }
s = s2;
```

### `free(void *ptr)`

* Releases memory previously allocated by `malloc/calloc/realloc`.
* Passing `NULL` is safe.
* After `free`, pointer becomes a **dangling** pointer. Set it to `NULL` if it might be reused.

---

## 3. Ownership, lifetimes, and rules

Rules of thumb:

1. Every allocation should have a clear owner who is responsible for `free`.
2. Document ownership in function contracts (who allocates, who frees).
3. Prefer single-ownership or reference-counted ownership; avoid shared mutable ownership unless necessary.
4. Avoid returning pointers to freed memory or to local stack variables.

Function conventions:

* `T *create_T(...)` : allocate and return ownership to caller. Caller must `free`.
* `void destroy_T(T *p)` : free and clean up.
* `int fill_buffer(char **out, size_t *out_sz)` : allocate inside and transfer ownership to caller; document it.

---

## 4. Common mistakes and how to avoid them

* **Not checking `malloc` return**: always check for `NULL`.
* **Memory leak**: forgetting `free`.
* **Double free**: `free`-ing the same pointer twice.
* **Use-after-free**: accessing memory after `free`.
* **Buffer overflow**: writing past allocation boundary.
* **Wrong `sizeof`**: using `sizeof(type*)` instead of `sizeof *ptr`.

Examples of safer `sizeof` usage:

```c
int *a = malloc(n * sizeof *a); // safe even if type of a changes
struct foo *f = malloc(sizeof *f);
```

---

## 5. Practical patterns

### 5.1 Dynamic array (vector)

A simple, reusable dynamic array implementation (single-file example).

```c
// vector.h - minimal vector for int (illustrative)
#include <stdlib.h>
#include <string.h>

typedef struct {
    size_t size;     // number of elements used
    size_t capacity; // allocated capacity (in elements)
    int *data;
} int_vector;

void vec_init(int_vector *v) {
    v->size = 0;
    v->capacity = 0;
    v->data = NULL;
}

int vec_reserve(int_vector *v, size_t new_cap) {
    if (new_cap <= v->capacity) return 0;
    int *tmp = realloc(v->data, new_cap * sizeof *v->data);
    if (!tmp) return -1;
    v->data = tmp;
    v->capacity = new_cap;
    return 0;
}

int vec_push(int_vector *v, int value) {
    if (v->size == v->capacity) {
        size_t new_cap = v->capacity ? v->capacity * 2 : 4;
        if (vec_reserve(v, new_cap) != 0) return -1; // allocation error
    }
    v->data[v->size++] = value;
    return 0;
}

void vec_free(int_vector *v) {
    free(v->data);
    v->data = NULL;
    v->size = v->capacity = 0;
}
```

Notes:

* Doubling strategy amortizes push cost.
* Handle allocation failure gracefully.
* Use `memcpy` when copying blocks of elements.

### 5.2 Singly linked list (manual memory management)

```c
// sll.h
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

Node *sll_create_node(int v) {
    Node *n = malloc(sizeof *n);
    if (!n) return NULL;
    n->value = v;
    n->next = NULL;
    return n;
}

void sll_free_all(Node *head) {
    while (head) {
        Node *next = head->next;
        free(head);
        head = next;
    }
}
```

Tips:

* Keep list invariants simple and document them.
* Avoid deep recursion to free long lists — use iterative `while` loop.
* For performance-critical workloads, consider pooling nodes.

### 5.3 Memory pool / arena allocator

When allocation pattern is many small short-lived objects with same lifetime, an arena is faster and simpler to free (one big `free`).

Basic idea:

* Allocate a large block (arena), return slices from it.
* No per-object `free`; free entire arena at once.

Simple arena sketch:

```c
typedef struct {
    unsigned char *buf;
    size_t capacity;
    size_t used;
} arena;

int arena_init(arena *a, size_t capacity) {
    a->buf = malloc(capacity);
    if (!a->buf) return -1;
    a->capacity = capacity; a->used = 0; return 0;
}

void *arena_alloc(arena *a, size_t size) {
    size = (size + 7) & ~7; // align to 8
    if (a->used + size > a->capacity) return NULL;
    void *p = a->buf + a->used;
    a->used += size;
    return p;
}

void arena_free_all(arena *a) { free(a->buf); a->buf = NULL; a->used = a->capacity = 0; }
```

Use-cases: parsing, temporary buffers, building intermediate structures.

## 6. Building blocks for a simple Git-like object store

This is a conceptual outline with practical suggestions. A real Git implementation includes compression (zlib), SHA-1 hashing, packfiles, references, and a complex object model. Here we focus on how dynamic memory fits into a small prototype.

### Minimal object store idea

* Objects are blobs (raw bytes) with a header: `<type> <size>\0<body>` — same idea as Git blobs.
* Compute a hash (e.g. SHA-1 or SHA-256) of the header+body to identify the object.
* Store objects on disk under their hash (e.g. `objects/ab/cdef...`).

Memory concerns and patterns:

* Reading files: use `stat` to get size then `malloc(size+1)` and `read` into buffer.
* Building headers: use `snprintf` into a pre-allocated buffer or `asprintf`-like pattern (manually `malloc(strlen)+1+...`).
* Avoid loading huge files wholly into memory if not necessary—use streaming/temporary buffers.

Example: reading a file into memory safely

```c
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

char *read_file(const char *path, size_t *out_size) {
    struct stat st;
    if (stat(path, &st) != 0) return NULL;
    off_t size = st.st_size;
    int fd = open(path, O_RDONLY);
    if (fd < 0) return NULL;
    char *buf = malloc(size + 1);
    if (!buf) { close(fd); return NULL; }
    ssize_t r = read(fd, buf, size);
    close(fd);
    if (r != size) { free(buf); return NULL; }
    buf[size] = '\0';
    if (out_size) *out_size = (size_t)size;
    return buf;
}
```

Security note: be cautious with untrusted input sizes and use limits.

---

## 7. Debugging and tools

* **Valgrind**: find leaks, invalid reads/writes, use-after-free. Command: `valgrind --leak-check=full ./your_program`
* **AddressSanitizer (ASan)**: compile-time instrumentation: `gcc -fsanitize=address -g -O1`.
* **UndefinedBehaviorSanitizer (UBSan)**: compiler sanitizer for undefined ops.
* **GDB**: inspect pointers and memory at runtime.

Testing strategy:

* Create small unit tests that intentionally exercise allocation failure (mocking `malloc`), boundaries, and freeing paths.
* Use ASan during development and Valgrind for longer tests.

---

## 8. Design checklist and best practices

* Always check allocation results.
* Prefer `sizeof *p` rather than `sizeof(type)` when allocating for `p`.
* Document ownership: map each pointer to the function/module that owns it.
* Set pointers to `NULL` after freeing if they may be reused.
* Use RAII-style patterns in C with `struct` + `init`/`destroy` functions.
* Use tools: ASan, Valgrind, static analyzers.
* Prefer clear interfaces over micro-optimizations early on.

---

## 9. Exercises and small projects

1. Implement `int_vector` with `push`, `pop`, `reserve`, and `shrink_to_fit` and write unit tests.
2. Implement a singly linked list supporting `insert_after`, `remove`, `find`, and `free_all`. Test with long lists (>100k nodes).
3. Implement an arena allocator and rewrite a parser to allocate all temporary nodes from the arena, then free in one call.
4. Build a tiny object store:

   * Read a file, compute a SHA-1/SHA-256 digest (use a library), create a header, write the object to disk under the hash, and implement lookup.
   * Make the store work with streaming large files to avoid `malloc`-ing huge buffers.
5. Implement a safe `getline`-like function that returns a dynamically allocated line buffer (handles arbitrarily long lines).

---

## 10. References and further reading

* The C standard library documentation for `malloc`/`free`.
* Valgrind manual and AddressSanitizer docs.
* Articles on memory allocators, arenas, and memory pooling.

---

## Appendix: Quick reference code snippets

### Safe allocation helper

```c
void *xmalloc(size_t size) {
    void *p = malloc(size);
    if (!p) { fprintf(stderr, "Out of memory\n"); exit(EXIT_FAILURE); }
    return p;
}

char *xstrdup(const char *s) {
    size_t n = strlen(s) + 1;
    char *p = malloc(n);
    if (!p) return NULL;
    memcpy(p, s, n);
    return p;
}
```

### Safe reallocation pattern

```c
void *safe_realloc(void *ptr, size_t new_size) {
    void *tmp = realloc(ptr, new_size);
    if (!tmp) {
        /* realloc failed; original ptr still valid */
        return NULL;
    }
    return tmp;
}
```

---

## If you want next steps

* I can provide complete `.c` and `.h` files for any of the patterns above (vector, linked list, arena) with tests.
* I can walk you step-by-step through implementing the tiny object store, including a streaming file read, hashing, and on-disk layout.

If you want, tell me which concrete example you want first (vector, linked list, arena, or object store) and I will create full code with explanations and tests.

---

*End of document.*
