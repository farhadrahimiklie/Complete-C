
---

# 🔹 **Goto Statement in C (Full Details)**

---

## 🧠 1. What Is the `goto` Statement?

* The **`goto` statement** allows the program to **jump to a labeled statement** anywhere within the **same function**.
* It is **unconditional**, meaning the jump happens **regardless of any conditions**.
* Labels are defined using **identifier names followed by a colon (`:`)**.

> In simple words:
> “Go to this part of the code immediately.”

---

## 🔹 2. Syntax

```c
goto label;

... // other code

label:  // define the label
    // code to execute after jumping
```

* `label` → an **identifier** ending with a colon `:`
* `goto label;` → jumps to the statement where label is defined

---

## 🔹 3. How It Works

1. Program executes normally.
2. When `goto` is encountered → program **jumps immediately** to the label.
3. Execution continues from the label **until the end or next jump**.

---

## 🔹 4. Example 1: Basic Goto

```c
#include <stdio.h>

int main() {
    printf("Start of program\n");

    goto jump;  // Jump to label

    printf("This will be skipped\n");

jump:  // Label
    printf("This is after the jump\n");

    return 0;
}
```

**Output:**

```
Start of program
This is after the jump
```

> ✅ Explanation:

* `goto jump;` jumps **over the skipped printf** directly to the label `jump:`

---

## 🔹 5. Example 2: Using Goto with Loops

```c
#include <stdio.h>

int main() {
    int i = 1;

start:
    if (i <= 5) {
        printf("%d\n", i);
        i++;
        goto start;  // repeat loop
    }

    return 0;
}
```

**Output:**

```
1
2
3
4
5
```

> ✅ Here, `goto start;` acts like a **manual loop**.

---

## 🔹 6. Example 3: Using Goto for Error Handling

```c
#include <stdio.h>

int main() {
    int num;
    printf("Enter a positive number: ");
    scanf("%d", &num);

    if (num <= 0) {
        printf("Invalid input. Try again.\n");
        goto retry;
    }

    printf("You entered %d\n", num);
    return 0;

retry:
    scanf("%d", &num);
    printf("You entered %d\n", num);

    return 0;
}
```

> ✅ Here, `goto` is used for **error handling** to retry input.

---

## 🔹 7. Rules and Restrictions of `goto`

1. **Can only jump within the same function**

   * Cannot jump to a label in another function

2. **Label must be defined in the same function**

3. **Do not jump over variable initialization that requires constructor** (in C++)

   * Can cause undefined behavior

4. **Use sparingly**

   * Overusing `goto` makes code **hard to read and maintain**

---

## 🔹 8. When to Use `goto`?

* **Error handling** (like breaking out of multiple nested loops)
* **Jumping to cleanup code** at the end of a function
* **Rare cases**, but modern C prefers **loops, functions, or break/continue**

> ⚠️ Modern programming practice discourages excessive use of `goto` (spaghetti code)

---

## 🔹 9. Comparison With Loops

| Feature     | Goto                                | Loops (`for`, `while`)                    |
| ----------- | ----------------------------------- | ----------------------------------------- |
| Repetition  | Manual using labels                 | Automatic                                 |
| Readability | Low if overused                     | High                                      |
| Condition   | Optional                            | Required (except `for(;;)` infinite loop) |
| Use Case    | Error handling, escape nested loops | Regular repetition tasks                  |

---

### 🏁 Summary

| Concept       | Explanation                         |
| ------------- | ----------------------------------- |
| `goto label;` | Jump unconditionally to a label     |
| `label:`      | Identifier marking the destination  |
| Use case      | Error handling, retry, escape loops |
| Caution       | Avoid overuse, reduces readability  |
| Scope         | Must be in the **same function**    |

> ⚡ Tip: Use **loops and functions** for normal repetition, reserve `goto` for **rare special cases**.

---
