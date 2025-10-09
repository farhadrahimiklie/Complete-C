
---

# 🔹 **If, Else If, Else Ladder in C (Full Details)**

---

## 🧠 1. What Is an If-Else Ladder?

* An **if-else ladder** is a **series of conditional statements** that allows the program to **choose exactly one path** among multiple possibilities.
* It’s called a **ladder** because conditions are **checked from top to bottom**, one by one.

> In simple words:
> “Check a condition → if true, execute this → else check the next → continue … → else execute default.”

---

## 🔹 2. Syntax

```c
if (condition1) {
    // code executed if condition1 is true
} 
else if (condition2) {
    // code executed if condition2 is true
} 
else if (condition3) {
    // code executed if condition3 is true
} 
else {
    // code executed if none of the above conditions are true
}
```

* **`if`** → first condition
* **`else if`** → additional conditions (optional, can have many)
* **`else`** → default block (optional)

---

## 🔹 3. How It Works

1. Evaluate `if` condition:

   * If **true** → execute its block → skip all remaining blocks
   * If **false** → check next `else if`
2. Continue checking each `else if` in order
3. If **none** are true → execute `else` block (if exists)

> ⚠️ Only **one block** is executed in an if-else ladder.

---

## 🔹 4. Example 1: Basic If-Else Ladder

```c
#include <stdio.h>

int main() {
    int marks;
    printf("Enter marks: ");
    scanf("%d", &marks);

    if (marks >= 90) {
        printf("Grade A\n");
    } 
    else if (marks >= 75) {
        printf("Grade B\n");
    } 
    else if (marks >= 60) {
        printf("Grade C\n");
    } 
    else {
        printf("Fail\n");
    }

    return 0;
}
```

### Input/Output Example:

```
Enter marks: 82
Grade B
```

> ✅ Explanation:

* 82 < 90 → first `if` false
* 82 >= 75 → second `else if` true → executes → rest skipped

---

## 🔹 5. Example 2: Using Else If Ladder With Characters

```c
#include <stdio.h>

int main() {
    char grade;
    printf("Enter your grade (A/B/C/D/F): ");
    scanf(" %c", &grade);  // note space before %c

    if (grade == 'A') {
        printf("Excellent\n");
    } 
    else if (grade == 'B') {
        printf("Good\n");
    } 
    else if (grade == 'C') {
        printf("Average\n");
    } 
    else if (grade == 'D') {
        printf("Poor\n");
    } 
    else {
        printf("Fail\n");
    }

    return 0;
}
```

### Input/Output Example:

```
Enter your grade: B
Good
```

---

## 🔹 6. Rules and Tips for If-Else Ladder

1. **Order matters**

   * Always check **higher conditions first**.
   * Example: Check `marks >= 90` **before** `marks >= 75`.

2. **`else if` is optional**

   * You can have just `if` and `else`.

3. **`else` is optional**

   * If no `else`, nothing happens if all conditions are false.

4. **Only one block executes**

   * Once a true condition is found, rest are skipped.

5. **Use logical operators** if needed

   * Combine conditions: `if (marks >= 75 && marks < 90)`

---

## 🔹 7. Example 3: Using Logical Operators in If-Else Ladder

```c
#include <stdio.h>

int main() {
    int marks;
    printf("Enter marks: ");
    scanf("%d", &marks);

    if (marks >= 90 && marks <= 100) {
        printf("Grade A\n");
    } 
    else if (marks >= 75 && marks < 90) {
        printf("Grade B\n");
    } 
    else if (marks >= 60 && marks < 75) {
        printf("Grade C\n");
    } 
    else if (marks >= 50 && marks < 60) {
        printf("Grade D\n");
    } 
    else {
        printf("Fail\n");
    }

    return 0;
}
```

* Ensures **no overlapping conditions**
* Safer when **multiple ranges** exist

---

### 🏁 Summary

| Concept                     | Explanation                                          |
| --------------------------- | ---------------------------------------------------- |
| `if`                        | Checks the **first condition**                       |
| `else if`                   | Checks **additional conditions** in order            |
| `else`                      | Executes if **none of the conditions are true**      |
| Only **one block** executes | Once a condition is true, rest are skipped           |
| Order is important          | Always check **highest priority condition first**    |
| Logical operators           | Can combine multiple conditions in `if` or `else if` |

> ⚡ Tip: Always use **proper indentation** to **avoid mistakes**.

---