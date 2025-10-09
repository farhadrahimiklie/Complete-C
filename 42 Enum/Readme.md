
---

# 🔹 **Enum in C – Full Details**

---

## 🧠 1. What is Enum?

* **`enum`** (short for enumeration) is a **user-defined data type** in C that **assigns names to integer constants**.
* Makes code **more readable** instead of using **magic numbers**.

**Syntax:**

```c
enum EnumName { CONSTANT1, CONSTANT2, CONSTANT3, ... };
```

* By default, `CONSTANT1 = 0`, `CONSTANT2 = 1`, … and so on.
* You can also **assign custom integer values**.

---

### Example:

```c
#include <stdio.h>

enum Weekday { Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday };

int main() {
    enum Weekday today;
    today = Wednesday;

    printf("Today is %d\n", today); // 3
    return 0;
}
```

* `Wednesday` corresponds to integer **3**.
* Makes code **clearer than using numbers directly**.

---

## 🔹 2. Enum with Custom Values

```c
enum ErrorCode { SUCCESS = 0, WARNING = 1, ERROR = 100, CRITICAL = 200 };

int main() {
    enum ErrorCode code = ERROR;
    printf("Error code: %d\n", code);
    return 0;
}
```

**Output:**

```
Error code: 100
```

* You can **assign any integer value** to enum members.

---

## 🔹 3. Enum with Switch Statement

* Enums are **commonly used with switch** for better readability.

### Example:

```c
#include <stdio.h>

enum Day { Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday };

int main() {
    enum Day today = Friday;

    switch(today) {
        case Sunday:
            printf("Today is Sunday\n"); break;
        case Monday:
            printf("Today is Monday\n"); break;
        case Tuesday:
            printf("Today is Tuesday\n"); break;
        case Wednesday:
            printf("Today is Wednesday\n"); break;
        case Thursday:
            printf("Today is Thursday\n"); break;
        case Friday:
            printf("Today is Friday\n"); break;
        case Saturday:
            printf("Today is Saturday\n"); break;
        default:
            printf("Invalid day\n");
    }

    return 0;
}
```

**Output:**

```
Today is Friday
```

* **Switch + Enum** improves readability compared to numbers.

---

## 🔹 4. Enum with Structure

* You can use **enum inside a structure** to represent **fixed sets of values**.

### Example:

```c
#include <stdio.h>
#include <string.h>

enum Gender { Male, Female, Other };

struct Person {
    char name[50];
    int age;
    enum Gender gender; // enum as member
};

int main() {
    struct Person p1;
    strcpy(p1.name, "Farhad");
    p1.age = 25;
    p1.gender = Male;

    printf("Name: %s, Age: %d, Gender: ", p1.name, p1.age);
    switch(p1.gender) {
        case Male: printf("Male\n"); break;
        case Female: printf("Female\n"); break;
        case Other: printf("Other\n"); break;
    }

    return 0;
}
```

**Output:**

```
Name: Farhad, Age: 25, Gender: Male
```

* **Enum inside structure** is useful for fields with **limited options**, e.g., gender, status, day of the week, etc.

---

## 🔹 5. Enum Size and Notes

* Enum members are **stored as integers**, usually **4 bytes** in 32-bit/64-bit systems.
* Enum type can be **used anywhere an integer is allowed**.
* Helps in **avoiding magic numbers** and improves **code clarity**.

---

## 🔹 6. Summary

| Feature        | Description                                                   |
| -------------- | ------------------------------------------------------------- |
| Enum           | User-defined type for named integer constants                 |
| Default values | Start from 0, increment by 1                                  |
| Custom values  | You can assign any integer value                              |
| Enum + Switch  | Makes code readable instead of numbers                        |
| Enum in struct | Useful for fields with limited options (status, type, gender) |
| Memory         | Usually same as int (4 bytes)                                 |

---

Farhad, in simple words:

> * **Enum** = named constants → more readable than numbers
> * **Switch + Enum** = cleaner conditional logic
> * **Enum in struct** = limits values to predefined set → safer programming

---