## 1. What “Ownership” Means in C (Fundamental Definition)

**Ownership** of dynamically allocated memory means:

> **Exactly one part of the program is responsible for freeing a block of memory.**

That’s it.
If more than one frees it → **undefined behavior**
If nobody frees it → **memory leak**

C does not track ownership.
**Ownership exists only in your design and discipline.**

---

## 2. Dynamic Memory Exists Outside Variable Lifetime

When you write:

```c
int *p = malloc(sizeof(int));
```

You create **two separate things**:

1. `p` → a local variable (stack)
2. `*p` → dynamically allocated memory (heap)

Important truth:

> **The heap memory does NOT belong to the variable.
> It belongs to whoever agrees to free it.**

When `p` goes out of scope:

* `p` disappears
* the allocated memory **does not**

That memory now becomes **orphaned** if not freed.

---

## 3. The Core Ownership Rule (Non-Negotiable)

### Rule #1: The allocator owns the memory until ownership is transferred.

If you call:

```c
int *p = malloc(sizeof(int));
```

Then **you own it**
You **must** eventually call:

```c
free(p);
```

Unless you **explicitly transfer ownership** to someone else.

---

## 4. Ownership vs Access (Very Important Distinction)

Many pointers can **access** memory.

Only **one owner** may **free** it.

Example:

```c
int *a = malloc(sizeof(int));
int *b = a;   // b can access memory
```

Ownership facts:

* `a` and `b` both point to the memory
* **Only one of them may free it**
* Freeing via either is allowed
* Freeing via both is fatal

Correct:

```c
free(a);
// or free(b), but not both
```

Wrong:

```c
free(a);
free(b);   // DOUBLE FREE → undefined behavior
```

---

## 5. Ownership Transfer (Explicit Responsibility Shift)

Ownership transfer happens when:

> One function allocates memory and **hands responsibility** to another.

### Example: Function returns owned memory

```c
int *create_number(void) {
    int *p = malloc(sizeof(int));
    *p = 42;
    return p;   // ownership transferred to caller
}
```

Caller:

```c
int *x = create_number();
// x OWNS the memory now
free(x);
```

**Rule:**

> If a function returns a dynamically allocated pointer, the caller owns it unless clearly documented otherwise.

---

## 6. Ownership Is a Contract, Not Syntax

C has no keywords for ownership.
It is enforced by **API design and documentation**.

Bad API (ownership unclear):

```c
int *get_data(void);
```

Good API (ownership clear by convention):

```c
// Caller must free returned pointer
int *data_create(void);

// Caller must NOT free returned pointer
const int *data_get(void);
```

Professional C relies on **naming conventions** and comments.

---

## 7. Who Frees Memory in Functions? (Golden Rule)

### Rule #2:

> **The function that allocates memory is NOT required to free it.
> The function that OWNS it must free it.**

Example (ownership stays with caller):

```c
void fill_array(int *arr, size_t n) {
    for (size_t i = 0; i < n; i++)
        arr[i] = i;
}

int main() {
    int *a = malloc(10 * sizeof(int));
    fill_array(a, 10);
    free(a);   // correct
}
```

The function `fill_array`:

* Uses memory
* Does NOT own it
* Must NOT free it

---

## 8. Functions That Allocate Internally (Danger Zone)

Example:

```c
void make_array(int **out, size_t n) {
    *out = malloc(n * sizeof(int));
}
```

Usage:

```c
int *a;
make_array(&a, 10);
// a OWNS the memory
free(a);
```

Ownership rules here:

* `make_array` allocates
* Caller becomes owner
* Caller must free

If the caller forgets → leak
If `make_array` frees → invalid memory

---

## 9. Ownership and `realloc`

`realloc` is **ownership-sensitive**.

Correct pattern:

```c
int *p = malloc(10 * sizeof(int));

int *tmp = realloc(p, 20 * sizeof(int));
if (tmp == NULL) {
    free(p);   // original still valid
    return;
}
p = tmp;
```

Rules:

* On success → ownership continues
* On failure → original owner still responsible
* Never overwrite original pointer blindly

Wrong:

```c
p = realloc(p, 20 * sizeof(int)); // if NULL → leak
```

---

## 10. Ownership and Structs (Composite Ownership)

Example:

```c
struct Person {
    char *name;
};
```

If you do:

```c
struct Person p;
p.name = malloc(100);
```

Ownership rules:

* `p` owns `name`
* When destroying `p`, you must free `name`

Correct destructor pattern:

```c
void person_destroy(struct Person *p) {
    free(p->name);
}
```

If the struct owns multiple pointers:

* It must free all of them

---

## 11. Ownership and Shallow Copies (Common Bug)

```c
struct Person a;
a.name = malloc(100);

struct Person b = a; // SHALLOW COPY
```

Now:

* `a.name` and `b.name` point to same memory
* Only ONE may free it

This leads to:

* Double free
* Or leak

Correct approach:

* Deep copy
* Or clearly define single owner

---

## 12. Ownership in Arrays of Pointers

Example:

```c
char **words = malloc(3 * sizeof(char *));
words[0] = malloc(10);
words[1] = malloc(20);
words[2] = malloc(30);
```

Ownership hierarchy:

* `words` owns the array
* Each `words[i]` owns its string

Correct cleanup:

```c
for (int i = 0; i < 3; i++)
    free(words[i]);
free(words);
```

If you free only `words` → leak
If you free only elements → leak

---

## 13. Ownership and Error Paths (Professional Discipline)

Every allocation must have a clear free path.

Bad:

```c
int *p = malloc(sizeof(int));
if (!p) return -1;
// error later
return -1;  // LEAK
```

Correct:

```c
int *p = malloc(sizeof(int));
if (!p) return -1;

if (error) {
    free(p);
    return -1;
}
```

Rule:

> Every successful allocation must be paired with exactly one free — even on failure paths.

---

## 14. Ownership and `const` (What It Means and What It Does NOT)

```c
const int *p = malloc(sizeof(int));
```

`const`:

* Does NOT affect ownership
* Does NOT prevent free
* Only restricts modification

Ownership is independent of `const`.

---

## 15. Absolute Rules You Must Memorize

1. **Every `malloc` must have exactly one `free`**
2. **Only the owner may call `free`**
3. **Ownership must be documented or obvious**
4. **Never free memory you did not allocate**
5. **Never free memory twice**
6. **Never use memory after free**
7. **Ownership transfer must be explicit**

---

## 16. Mental Model (Burn This Into Your Brain)

Think like this:

* Heap memory is a **resource**
* Ownership is a **legal contract**
* Freeing is **closing the contract**
* Violating ownership causes **undefined behavior**, not warnings

---

## 17. Final Ruthless Truth

C gives you **total control** and **zero protection**.

If you do not:

* define ownership
* follow ownership
* enforce ownership

Then your program is **incorrect**, even if it “seems to work”.
