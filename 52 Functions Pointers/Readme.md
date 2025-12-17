# 🔹 **Function Pointers in C – Full Details**

---

## 🧠 1. What is a Function Pointer?

* A **function pointer** is a **pointer that points to the address of a function** instead of a variable.
* It allows you to **call a function indirectly** through the pointer.

### Basic Syntax:

```c
return_type (*pointer_name)(parameter_types);
```

* `return_type` → type of value the function returns
* `pointer_name` → name of the function pointer
* `parameter_types` → parameters of the function

---

## 🔹 2. Example of a Simple Function Pointer

```c
#include <stdio.h>

// Function
int add(int a, int b) {
    return a + b;
}

int main() {
    // Declare function pointer
    int (*funcPtr)(int, int);

    // Assign function address to pointer
    funcPtr = add;

    // Call function using pointer
    int result = funcPtr(5, 3);
    printf("Result: %d\n", result);

    return 0;
}
```

**Output:**

```
Result: 8
```

**Explanation:**

* `funcPtr` stores the **address of `add` function**
* `funcPtr(5, 3)` calls `add(5, 3)` indirectly

---

## 🔹 3. Alternative Syntax

* You can also write:

```c
int result = (*funcPtr)(5, 3);
```

* Both `funcPtr(5,3)` and `(*funcPtr)(5,3)` are valid

---

## 🔹 4. Function Pointer as Parameter

* Function pointers can be **passed to another function** → useful for **callbacks**.

### Example:

```c
#include <stdio.h>

int add(int a, int b) { return a + b; }
int multiply(int a, int b) { return a * b; }

void operate(int x, int y, int (*operation)(int, int)) {
    printf("Result: %d\n", operation(x, y));
}

int main() {
    operate(5, 3, add);       // call add via pointer
    operate(5, 3, multiply);  // call multiply via pointer
    return 0;
}
```

**Output:**

```
Result: 8
Result: 15
```

* **`operate` function** takes a function pointer as argument
* Makes the code **flexible and reusable**

---

## 🔹 5. Array of Function Pointers

* You can have an **array of function pointers** for **menu-driven programs**.

### Example:

```c
#include <stdio.h>

int add(int a,int b){ return a+b; }
int sub(int a,int b){ return a-b; }
int mul(int a,int b){ return a*b; }

int main() {
    int (*operations[3])(int,int) = {add, sub, mul};

    for(int i=0; i<3; i++) {
        printf("Result %d: %d\n", i, operations[i](10, 5));
    }

    return 0;
}
```

**Output:**

```
Result 0: 15
Result 1: 5
Result 2: 50
```

* **Array of function pointers** allows **dynamic selection of functions**

---

## 🔹 6. Function Pointer and Dynamic Behavior

* Function pointers allow **dynamic function calling** at runtime.
* Example: Choose function based on **user input or configuration**

```c
#include <stdio.h>

int add(int a,int b){ return a+b; }
int sub(int a,int b){ return a-b; }

int main() {
    int choice;
    int (*func)(int,int);

    printf("Enter 0 for add, 1 for sub: ");
    scanf("%d",&choice);

    func = (choice == 0) ? add : sub;

    printf("Result: %d\n", func(10,5));
    return 0;
}
```

* Here, **function is chosen dynamically at runtime**

---

## 🔹 7. Function Pointer to Void Functions

* Function pointers work for **void functions** too:

```c
#include <stdio.h>
void greet() { printf("Hello!\n"); }

int main() {
    void (*ptr)() = greet;
    ptr(); // call greet via pointer
    return 0;
}
```

**Output:**

```
Hello!
```

---

## 🔹 8. Key Points / Advantages

1. **Flexibility** → choose function at runtime
2. **Callback mechanism** → pass function as argument
3. **Efficient code** → reduces `if-else` or `switch` chains
4. **Array of function pointers** → easy for **menus or dynamic dispatch**
5. **Used in system programming** → device drivers, event handling

---

## 🔹 9. Summary

| Concept          | Explanation                                              |
| ---------------- | -------------------------------------------------------- |
| Function Pointer | Pointer that stores the address of a function            |
| Syntax           | `return_type (*ptr)(param_types)`                        |
| Call             | `ptr(args)` or `(*ptr)(args)`                            |
| As Parameter     | Allows callbacks and dynamic execution                   |
| Array            | Array of function pointers can implement menus or tables |
| Advantage        | Flexible, dynamic, reusable code                         |

---

Farhad, in simple words:

> * A **function pointer is like a remote control for a function**.
> * You can **store, pass, and call functions dynamically**.
> * Useful in **callbacks, menus, and dynamic behavior**.

---
