
---

# 🔹 **Functions in C – Full Details**

---

## 🧠 1. What Is a Function?

* A **function** is a **block of code** that performs a specific task.
* Functions can **take inputs**, **perform operations**, and **return outputs**.
* Syntax:

```c
return_type function_name(parameters) {
    // body of function
}
```

---

## 🔹 2. Structure of a Function

1. **Function Declaration (Prototype)**

   * Tells the compiler about the function **name, return type, and parameters**.

```c
int add(int, int);  // function declaration
```

2. **Function Definition**

   * Actual code of the function.

```c
int add(int a, int b) {  // function definition
    return a + b;
}
```

3. **Function Call**

   * Executes the function.

```c
int result = add(5, 3);  // function call
```

---

## 🔹 3. Function Parameters and Arguments

### 3.1 Parameter

* A **parameter** is a **variable in the function definition** that receives the value when the function is called.
* Example:

```c
int add(int a, int b) // a, b are parameters
```

### 3.2 Argument

* An **argument** is the **actual value passed** to the function when called.
* Example:

```c
int result = add(5, 3); // 5 and 3 are arguments
```

> **Rule:** Number and type of arguments must match number and type of parameters.

---

## 🔹 4. Types of Functions in C

### 4.1 Based on Return Type and Parameters

| Type   | Return Type                   | Parameters               | Example                  |
| ------ | ----------------------------- | ------------------------ | ------------------------ |
| Type 1 | No return, no parameters      | `void func(void)`        | `void greet(void)`       |
| Type 2 | No return, with parameters    | `void func(int a)`       | `void printNum(int num)` |
| Type 3 | Return value, no parameters   | `int func(void)`         | `int getRandom(void)`    |
| Type 4 | Return value, with parameters | `int func(int a, int b)` | `int add(int a, int b)`  |

---

### 4.2 Examples of Each Type

#### Type 1: No return, no parameters

```c
#include <stdio.h>
void greet(void) {
    printf("Hello Farhad!\n");
}

int main() {
    greet();  // call function
    return 0;
}
```

#### Type 2: No return, with parameters

```c
#include <stdio.h>
void printSquare(int num) {
    printf("Square = %d\n", num * num);
}

int main() {
    printSquare(5); // argument = 5
    return 0;
}
```

#### Type 3: Return value, no parameters

```c
#include <stdio.h>
int getNumber(void) {
    return 10;
}

int main() {
    int x = getNumber();
    printf("Number = %d\n", x);
    return 0;
}
```

#### Type 4: Return value, with parameters

```c
#include <stdio.h>
int add(int a, int b) {
    return a + b;
}

int main() {
    int sum = add(5, 3); // arguments 5,3
    printf("Sum = %d\n", sum);
    return 0;
}
```

---

## 🔹 5. Passing Arguments to Functions

### 5.1 Call by Value

* **Copies the value** of argument into parameter.
* Modifying the parameter **does not change the original argument**.

```c
void increment(int x) {
    x = x + 1;
}

int main() {
    int num = 5;
    increment(num);
    printf("%d\n", num); // 5, original unchanged
}
```

### 5.2 Call by Reference (Using Pointers)

* Pass the **address** of the variable.
* Modifying parameter **changes the original argument**.

```c
#include <stdio.h>
void increment(int *x) {
    *x = *x + 1;
}

int main() {
    int num = 5;
    increment(&num);
    printf("%d\n", num); // 6, original changed
}
```

---

## 🔹 6. Function Scope and Lifetime

* **Local Variables**: Declared inside function → exist **only during function execution**, destroyed afterward.
* **Global Variables**: Declared outside → accessible by all functions.

```c
#include <stdio.h>
int globalVar = 10; // global

void func() {
    int localVar = 5; // local
    printf("%d %d\n", localVar, globalVar);
}

int main() {
    func();
    // printf("%d", localVar); // Error! localVar not accessible
    return 0;
}
```

---

## 🔹 7. Recursion (Function Calling Itself)

* Functions can call themselves → useful for **factorial, fibonacci, etc.**

```c
#include <stdio.h>
int factorial(int n) {
    if(n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}

int main() {
    printf("Factorial of 5 = %d\n", factorial(5));
    return 0;
}
```

---

## 🔹 8. Function Prototype Importance

* **Tells the compiler** about function **before main()**.
* Helps in **type checking** and **prevents warnings**.

```c
int add(int, int); // prototype
int main() { ... }
int add(int a, int b) { ... } // definition
```

---

## 🔹 9. Key Points About Functions

1. Functions **avoid code repetition** → modular programming.
2. **Parameters** are variables in function definition.
3. **Arguments** are values passed when calling the function.
4. Functions can **return value** or **not return (void)**.
5. Can pass **by value** (default) or **by reference** (using pointers).
6. Scope of local variables → **inside function only**, global variables → **accessible by all functions**.

---

## 🔹 10. Summary Table

| Concept           | Explanation                                                                                  |
| ----------------- | -------------------------------------------------------------------------------------------- |
| Function          | Block of code performing a task                                                              |
| Parameter         | Variable in definition to receive input                                                      |
| Argument          | Actual value passed to function                                                              |
| Return Type       | Value function returns (int, float, void…)                                                   |
| Types             | 1. No return, no param  2. No return, with param  3. Return, no param  4. Return, with param |
| Call by Value     | Copies value, original not changed                                                           |
| Call by Reference | Pass address, original changed                                                               |
| Scope             | Local (inside function), Global (outside function)                                           |
| Prototype         | Declares function before main() for type checking                                            |

---