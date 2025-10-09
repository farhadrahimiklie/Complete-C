
---

# 🔹 **Jump Statements in C (Full Details)**

---

## 🧠 1. What Are Jump Statements?

* **Jump statements** are statements that **transfer control to another part of the program**, temporarily **skipping the normal sequence**.
* C provides **three main jump statements**:

1. **`break`** → exits loops or switch-case
2. **`continue`** → skips current iteration of a loop
3. **`return`** → exits a function and optionally returns a value

---

## 🔹 2. The `break` Statement

### Purpose

* Terminates the **nearest enclosing loop** (`for`, `while`, `do-while`) or **switch-case** immediately.

### Syntax

```c
break;
```

### Example 1: Break in a For Loop

```c
#include <stdio.h>
int main() {
    for(int i = 1; i <= 5; i++) {
        if(i == 3) break;
        printf("%d\n", i);
    }
    return 0;
}
```

**Output:**

```
1
2
```

✅ Explanation:

* When `i == 3`, `break` terminates the loop → 3, 4, 5 skipped.

---

### Example 2: Break in Switch-Case

```c
#include <stdio.h>
int main() {
    int day = 2;
    switch(day) {
        case 1: printf("Monday\n"); break;
        case 2: printf("Tuesday\n"); break;
        case 3: printf("Wednesday\n"); break;
        default: printf("Invalid\n");
    }
    return 0;
}
```

**Output:**

```
Tuesday
```

✅ Without `break`, execution would **fall through** to the next cases.

---

## 🔹 3. The `continue` Statement

### Purpose

* Skips **current iteration** of the nearest enclosing loop and moves control to **next iteration**.

### Syntax

```c
continue;
```

### Example 1: Continue in a For Loop

```c
#include <stdio.h>
int main() {
    for(int i = 1; i <= 5; i++) {
        if(i == 3) continue;
        printf("%d\n", i);
    }
    return 0;
}
```

**Output:**

```
1
2
4
5
```

✅ Explanation:

* When `i == 3`, `continue` skips printing → goes to next iteration (`i=4`).

---

### Example 2: Continue in While Loop

```c
#include <stdio.h>
int main() {
    int i = 0;
    while(i < 5) {
        i++;
        if(i == 2) continue;
        printf("%d\n", i);
    }
    return 0;
}
```

**Output:**

```
1
3
4
5
```

---

## 🔹 4. The `return` Statement

### Purpose

* **Exits a function** immediately.
* Optionally **returns a value** to the calling function (if not `void`).

### Syntax

```c
return;        // for void functions
return value;  // for functions returning a type
```

---

### Example 1: Return in Void Function

```c
#include <stdio.h>
void display() {
    printf("Hello\n");
    return;
    printf("This will not execute\n");
}
int main() {
    display();
    return 0;
}
```

**Output:**

```
Hello
```

✅ Explanation:

* `return;` exits the function → code after `return` **never executes**.

---

### Example 2: Return with Value

```c
#include <stdio.h>
int add(int a, int b) {
    return a + b;
}
int main() {
    int sum = add(5, 3);
    printf("Sum = %d\n", sum);
    return 0;
}
```

**Output:**

```
Sum = 8
```

✅ Explanation:

* `return a + b;` exits the function and **sends value to caller**.

---

## 🔹 5. Summary Table

| Jump Statement | Purpose                | Use Case                      | Scope          |
| -------------- | ---------------------- | ----------------------------- | -------------- |
| `break`        | Exit loop or switch    | Stop loop early               | Loops / Switch |
| `continue`     | Skip current iteration | Skip unwanted iteration       | Loops only     |
| `return`       | Exit function          | End function and return value | Functions      |

---

## 🔹 6. Key Notes & Tips

1. **`break` in nested loops**

   * Only exits **the innermost loop** where it is used.
   * Use `goto` if you want to exit **multiple loops**.

2. **`continue` skips iteration**

   * Useful for **skipping invalid cases** in loops.

3. **`return` ends function immediately**

   * Important in `main()` as it ends the program.

4. Avoid overusing **`break` and `continue`** to maintain **readable code**.

---
