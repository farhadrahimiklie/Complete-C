# 🔹 **Union in C – Full Details**

---

## 🧠 1. What is a Union?

* A **union** is a **user-defined data type**, like a structure, that **can store different types of data** in the **same memory location**.
* Only **one member can hold a value at a time**.

**Syntax:**

```c
union Data {
    int i;
    float f;
    char c;
};
```

* Here, `Data` is a union with three members: `i`, `f`, `c`.
* **All members share the same memory location**, so changing one member **overwrites** the others.

---

## 🔹 2. Declaring Union Variables

```c
union Data d1;
d1.i = 10;
printf("%d\n", d1.i);

d1.f = 3.14; // now overwrites i
printf("%f\n", d1.f);
```

* After assigning `d1.f`, the value of `d1.i` is **undefined**, because both **share the same memory**.

---

## 🔹 3. Memory Layout of Union vs Structure

### Structure:

```c
struct Example {
    int i;   // 4 bytes
    float f; // 4 bytes
    char c;  // 1 byte + padding
};
```

* **Memory allocated = sum of all members (+ padding)**
* Each member has **its own memory location**

### Union:

```c
union Example {
    int i;   // 4 bytes
    float f; // 4 bytes
    char c;  // 1 byte
};
```

* **Memory allocated = size of largest member**
* All members **share the same memory location**

---

### Diagram:

```
Structure:       Union:
+------+         +------+
|  i   | 4B      |  i   | 4B
+------+         +------+
|  f   | 4B      |  f   |  (same as i)
+------+         +------+
|  c   | 1B      |  c   |  (same as i)
+------+         +------+
```

* **Structure** → each member independent
* **Union** → all members overlap

---

## 🔹 4. Accessing Union Members

* Use **dot operator (`.`)** for regular variable, **arrow operator (`->`)** for pointer to union.

```c
#include <stdio.h>

union Data {
    int i;
    float f;
    char c;
};

int main() {
    union Data d;
    d.i = 10;
    printf("i = %d\n", d.i);

    d.f = 3.14;
    printf("f = %f\n", d.f);

    d.c = 'A';
    printf("c = %c\n", d.c);

    return 0;
}
```

**Output (memory overlapping):**

```
c = A
```

> Notice `i` and `f` values are now **overwritten**.

---

## 🔹 5. Pointer to Union

```c
union Data d;
union Data *ptr = &d;
ptr->i = 100;
printf("%d\n", ptr->i);
```

* Works like **structure pointers**, using **`->`** operator.

---

## 🔹 6. Nested Union and Typedef

```c
typedef union Data {
    int i;
    float f;
    char c;
} Data;

Data d1;
d1.i = 50;
```

* Using **typedef** simplifies variable declaration.

---

## 🔹 7. When to Use Union

1. When **only one member is needed at a time** → saves memory.
2. For **low-level programming** (embedded systems, device drivers).
3. Useful in **variant records** (e.g., a struct that can hold int or float depending on a type flag).

---

## 🔹 8. Structure vs Union – Key Differences

| Feature           | Structure                             | Union                               |
| ----------------- | ------------------------------------- | ----------------------------------- |
| Memory Allocation | Sum of all members (+ padding)        | Size of largest member              |
| Members Storage   | Each member has separate memory       | All members share the same memory   |
| Usage             | Store all members at the same time    | Store only one member at a time     |
| Access            | All members accessible simultaneously | Only last assigned member is valid  |
| Size              | Larger (sum)                          | Smaller (largest member)            |
| Example           | `struct {int i; float f;}` → 8 bytes  | `union {int i; float f;}` → 4 bytes |

---

## 🔹 9. Example – Union in Real Life

```c
#include <stdio.h>

typedef union Data {
    int i;
    float f;
    char c;
} Data;

int main() {
    Data d;
    char type;

    printf("Enter type (i/f/c): ");
    scanf(" %c", &type);

    if(type == 'i') {
        d.i = 100;
        printf("Integer: %d\n", d.i);
    } else if(type == 'f') {
        d.f = 3.14;
        printf("Float: %f\n", d.f);
    } else {
        d.c = 'A';
        printf("Char: %c\n", d.c);
    }

    return 0;
}
```

* Only **one type is stored at a time**, saving memory.

---

## 🔹 10. Summary

* **Structure** → store multiple data members **simultaneously**, independent memory
* **Union** → store multiple data members **one at a time**, shared memory
* **Use union** when memory optimization is needed and **only one member is required at a time**
* **Use structure** for storing all data together
