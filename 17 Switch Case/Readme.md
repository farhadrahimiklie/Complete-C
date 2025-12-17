# 🔹 **Switch-Case Statement in C (Full Details)**

---

## 🧠 1. What Is a Switch-Case Statement?

* The **switch-case statement** is a **multi-way branch statement**.
* It allows the program to **choose one block of code** among many options based on the **value of a variable**.
* It is **more readable than multiple if-else statements** when checking a single variable against many constant values.

> In simple words:
> “Check the value of a variable → execute the matching case → skip the rest.”

---

## 🔹 2. Syntax

```c
switch (expression) {
    case value1:
        // code executed if expression == value1
        break;
    case value2:
        // code executed if expression == value2
        break;
    case value3:
        // code executed if expression == value3
        break;
    ...
    default:
        // code executed if no case matches
}
```

* `expression` → integer, char, or enum (cannot be float or double)
* `case value:` → the value to compare with `expression`
* `break` → **terminates the switch** (prevents “fall through”)
* `default` → optional, executed if **no case matches**

---

## 🧩 3. How It Works

1. Evaluate the `expression`.
2. Compare it **with each case value** in order.
3. If a **match is found** → execute that case block.
4. If **`break` is used** → exit the switch.
5. If **no match** → execute `default` (if exists).

> ⚠️ If `break` is **omitted**, execution **falls through** to the next case.

---

## 🔹 4. Example 1: Basic Switch-Case

```c
#include <stdio.h>
int main() {
    int day;
    printf("Enter day number (1-7): ");
    scanf("%d", &day);

    switch (day) {
        case 1:
            printf("Monday\n");
            break;
        case 2:
            printf("Tuesday\n");
            break;
        case 3:
            printf("Wednesday\n");
            break;
        case 4:
            printf("Thursday\n");
            break;
        case 5:
            printf("Friday\n");
            break;
        case 6:
            printf("Saturday\n");
            break;
        case 7:
            printf("Sunday\n");
            break;
        default:
            printf("Invalid day\n");
    }

    return 0;
}
```

### Input/Output Example:

```
Enter day number (1-7): 3
Wednesday
```

---

## 🔹 5. Example 2: Using `char` in Switch

```c
#include <stdio.h>
int main() {
    char grade;
    printf("Enter grade (A/B/C/D/F): ");
    scanf(" %c", &grade);

    switch (grade) {
        case 'A':
            printf("Excellent\n");
            break;
        case 'B':
            printf("Good\n");
            break;
        case 'C':
            printf("Average\n");
            break;
        case 'D':
            printf("Poor\n");
            break;
        case 'F':
            printf("Fail\n");
            break;
        default:
            printf("Invalid grade\n");
    }

    return 0;
}
```

---

## 🔹 6. Example 3: Fall-Through Behavior

* If `break` is **omitted**, execution **falls through** to the next case.

```c
#include <stdio.h>
int main() {
    int num = 2;

    switch (num) {
        case 1:
            printf("One\n");
        case 2:
            printf("Two\n");
        case 3:
            printf("Three\n");
        default:
            printf("Default\n");
    }

    return 0;
}
```

**Output:**

```
Two
Three
Default
```

> ⚠️ Notice: Case 2 executed → then **fall through** to case 3 and default because **no break**.

---

## 🔹 7. Rules and Tips for Switch-Case

1. **Expression must be integer, char, or enum**

   * **Cannot use float, double, or string**

2. **Case values must be constant**

   * Variables or expressions **not allowed**

3. **`break` is optional**

   * Without break → fall-through occurs

4. **`default` is optional**

   * But it’s **good practice** to include it

5. **Multiple cases can share the same block**:

```c
switch (ch) {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
        printf("Vowel\n");
        break;
    default:
        printf("Consonant\n");
}
```

---

## 🔹 8. When to Use Switch vs If-Else Ladder

| Feature              | Switch                        | If-Else Ladder                                 |
| -------------------- | ----------------------------- | ---------------------------------------------- |
| Type of variable     | int, char, enum               | any type (int, float, char, string via strcmp) |
| Number of conditions | Many discrete constant values | Any number or range of conditions              |
| Readability          | Cleaner for many fixed values | Better for complex conditions or ranges        |
| Fall-through         | Possible                      | Not applicable                                 |

---

### 🏁 Summary

| Component            | Purpose                                      |
| -------------------- | -------------------------------------------- |
| `switch(expression)` | Evaluates a single variable                  |
| `case value:`        | Executes this block if `expression == value` |
| `break;`             | Exits the switch to prevent fall-through     |
| `default:`           | Executes if no case matches                  |

> ⚡ Tip: Always **use break** unless you intentionally want **fall-through** for multiple cases.

---
