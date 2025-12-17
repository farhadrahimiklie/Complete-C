# 🔹 **Structures in C – Full Details**

---

## 🧠 1. What is a Structure?

* A **structure (`struct`)** is a **user-defined data type** in C that **groups different types of variables** under a single name.
* Unlike arrays, which store elements of the **same type**, structures can store **different types together**.

**Syntax:**

```c
struct Person {
    char name[50];
    int age;
    float salary;
};
```

* Here, `Person` is a **structure type**, and it contains three members: `name`, `age`, `salary`.

---

## 🔹 2. Declaring Structure Variables

```c
struct Person p1, p2;
```

* `p1` and `p2` are **variables of type `struct Person`**.
* Members are accessed using the **dot operator (`.`)**:

```c
p1.age = 25;
strcpy(p1.name, "Farhad");
p1.salary = 5000.50;
```

---

## 🔹 3. Array of Structures

* Useful when storing **multiple records** of the same type.

### Example:

```c
#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    int roll;
    float marks;
};

int main() {
    struct Student s[3]; // array of 3 students

    strcpy(s[0].name, "Ali"); s[0].roll = 1; s[0].marks = 80.5;
    strcpy(s[1].name, "Sara"); s[1].roll = 2; s[1].marks = 90.0;
    strcpy(s[2].name, "Omar"); s[2].roll = 3; s[2].marks = 85.5;

    for(int i=0;i<3;i++)
        printf("%s - %d - %.2f\n", s[i].name, s[i].roll, s[i].marks);

    return 0;
}
```

**Output:**

```
Ali - 1 - 80.50
Sara - 2 - 90.00
Omar - 3 - 85.50
```

---

## 🔹 4. Pointer to Structure

* Pointers can also **point to structures**.
* Access members using the **arrow operator (`->`)** instead of dot (`.`).

### Example:

```c
#include <stdio.h>
#include <string.h>

struct Person {
    char name[50];
    int age;
};

int main() {
    struct Person p1;
    struct Person *ptr = &p1;

    strcpy(ptr->name, "Farhad");
    ptr->age = 25;

    printf("Name: %s, Age: %d\n", ptr->name, ptr->age);
    return 0;
}
```

**Output:**

```
Name: Farhad, Age: 25
```

---

## 🔹 5. Passing Structures to Functions

* **Structures can be passed to functions** by **value** or **by reference (pointer)**.

### a) Pass by Value

```c
#include <stdio.h>
#include <string.h>

struct Person {
    char name[50];
    int age;
};

void printPerson(struct Person p) {
    printf("%s - %d\n", p.name, p.age);
}

int main() {
    struct Person p1;
    strcpy(p1.name, "Farhad");
    p1.age = 25;

    printPerson(p1); // pass by value
    return 0;
}
```

* **Pass by value** copies the whole structure → changes inside function **do not affect original**.

---

### b) Pass by Reference (Using Pointer)

```c
#include <stdio.h>
#include <string.h>

struct Person {
    char name[50];
    int age;
};

void updateAge(struct Person *p) {
    p->age += 1; // modifies original structure
}

int main() {
    struct Person p1;
    strcpy(p1.name, "Farhad");
    p1.age = 25;

    updateAge(&p1); 
    printf("%s - %d\n", p1.name, p1.age); // age updated
    return 0;
}
```

**Output:**

```
Farhad - 26
```

* Using pointer avoids copying large structures → more **memory efficient**.

---

## 🔹 6. Nested Structure

* A structure can contain **another structure as a member**.
* Useful for modeling **complex data**.

### Example:

```c
#include <stdio.h>
#include <string.h>

struct Date {
    int day, month, year;
};

struct Person {
    char name[50];
    struct Date dob; // nested structure
};

int main() {
    struct Person p1;
    strcpy(p1.name, "Farhad");
    p1.dob.day = 8;
    p1.dob.month = 10;
    p1.dob.year = 2025;

    printf("%s - %02d/%02d/%d\n", p1.name, p1.dob.day, p1.dob.month, p1.dob.year);
    return 0;
}
```

**Output:**

```
Farhad - 08/10/2025
```

---

## 🔹 7. Summary of Structure Concepts

| Feature                       | Description                                       |
| ----------------------------- | ------------------------------------------------- |
| Structure                     | User-defined data type for grouping variables     |
| Array of structures           | Store multiple records of same type               |
| Pointer to structure          | Access structure via pointer, use `->` operator   |
| Passing structure to function | By value → copies, by pointer → original modified |
| Nested structure              | Structure inside structure for complex data       |

---

## 🔹 8. Memory Notes

* Structure size = **sum of all member sizes** + padding (alignment by compiler)
* Pointers to structures occupy **fixed memory** (e.g., 4 or 8 bytes depending on system)
* Passing by pointer = **more efficient for large structures**

---
