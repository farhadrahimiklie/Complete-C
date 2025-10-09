
---

# 🔹 **Bitwise Programming in C – Full Details**

---

## 🧠 1. What is Bitwise Programming?

* Bitwise programming deals with **binary representation** of integers.
* Every integer is represented in **binary** (0s and 1s).
* Bitwise operators manipulate these **individual bits** directly.

Example:

```c
int x = 5; // binary: 00000101
int y = 3; // binary: 00000011
```

---

## 🔹 2. Bitwise Operators in C

| Operator | Name        | Description                      | Example           |    |        |
| -------- | ----------- | -------------------------------- | ----------------- | -- | ------ |
| `&`      | AND         | 1 if both bits are 1             | `5 & 3 = 1`       |    |        |
| `        | `           | OR                               | 1 if any bit is 1 | `5 | 3 = 7` |
| `^`      | XOR         | 1 if bits are different          | `5 ^ 3 = 6`       |    |        |
| `~`      | NOT         | Inverts bits                     | `~5 = -6`         |    |        |
| `<<`     | Left Shift  | Shift bits left, multiply by 2^n | `5 << 1 = 10`     |    |        |
| `>>`     | Right Shift | Shift bits right, divide by 2^n  | `5 >> 1 = 2`      |    |        |

---

## 🔹 3. Examples of Each Bitwise Operator

### a) Bitwise AND (`&`)

```c
#include <stdio.h>

int main() {
    int a = 5; // 0101
    int b = 3; // 0011
    printf("a & b = %d\n", a & b); // 0001 → 1
    return 0;
}
```

### b) Bitwise OR (`|`)

```c
printf("a | b = %d\n", a | b); // 0111 → 7
```

### c) Bitwise XOR (`^`)

```c
printf("a ^ b = %d\n", a ^ b); // 0110 → 6
```

### d) Bitwise NOT (`~`)

```c
printf("~a = %d\n", ~a); // ~0101 = 1010 (two's complement) → -6
```

### e) Left Shift (`<<`)

```c
printf("a << 1 = %d\n", a << 1); // 0101 << 1 = 1010 → 10
```

### f) Right Shift (`>>`)

```c
printf("a >> 1 = %d\n", a >> 1); // 0101 >> 1 = 0010 → 2
```

---

## 🔹 4. Applications of Bitwise Operators

1. **Set, Clear, Toggle, Check specific bits**:

```c
#include <stdio.h>

int main() {
    unsigned int x = 5; // 0101
    // Set 2nd bit (bit position 1)
    x = x | (1 << 1); // 0101 | 0010 = 0111 → 7
    printf("Set 2nd bit: %d\n", x);

    // Clear 3rd bit (bit position 2)
    x = x & ~(1 << 2); // 0111 & ~(0100) = 0011 → 3
    printf("Clear 3rd bit: %d\n", x);

    // Toggle 1st bit
    x = x ^ (1 << 0); // 0011 ^ 0001 = 0010 → 2
    printf("Toggle 1st bit: %d\n", x);

    // Check 2nd bit
    if(x & (1 << 1))
        printf("2nd bit is set\n");
    else
        printf("2nd bit is not set\n");

    return 0;
}
```

**Output:**

```
Set 2nd bit: 7
Clear 3rd bit: 3
Toggle 1st bit: 2
2nd bit is set
```

---

2. **Efficient Multiplication/Division by Powers of 2**

```c
int a = 5;
printf("Multiply by 2: %d\n", a << 1); // 10
printf("Divide by 2: %d\n", a >> 1);   // 2
```

* Much faster than `*` or `/` in low-level programming.

---

3. **Swapping Two Numbers Without Temporary Variable**

```c
int x = 5, y = 3;
x = x ^ y; // x = 6
y = x ^ y; // y = 5
x = x ^ y; // x = 3
printf("x = %d, y = %d\n", x, y);
```

* Uses **XOR properties** to swap values efficiently.

---

4. **Check if a Number is Even or Odd**

```c
int n = 7;
if(n & 1)
    printf("Odd\n");
else
    printf("Even\n");
```

* Only **least significant bit** matters: `1` → odd, `0` → even.

---

5. **Masking Bits**

* You can **extract specific bits** using a mask.

```c
int x = 0b10101100;
int last4 = x & 0x0F; // mask last 4 bits → 1100 → 12
printf("Last 4 bits: %d\n", last4);
```

---

## 🔹 5. Bit Fields in Structures

* C allows **bit fields** to **define structure members with specific bit sizes**:

```c
#include <stdio.h>

struct Flags {
    unsigned int isOn:1;
    unsigned int mode:2;
    unsigned int error:1;
};

int main() {
    struct Flags f = {1, 3, 0};
    printf("Size of struct: %lu bytes\n", sizeof(f));
    return 0;
}
```

* Saves **memory when storing multiple boolean or small range values**.

---

## 🔹 6. Advantages of Bitwise Programming

1. **High speed** → direct memory/bit manipulation
2. **Memory-efficient** → especially for flags/bit-fields
3. **Useful in embedded systems, network programming, encryption, graphics**

---

## 🔹 7. Summary of Bitwise Concepts

| Operator | Use Case                    |              |
| -------- | --------------------------- | ------------ |
| `&`      | Masking, checking bits      |              |
| `        | `                           | Setting bits |
| `^`      | Toggling bits, XOR logic    |              |
| `~`      | Inverting bits              |              |
| `<<`     | Multiply by 2^n, shift left |              |
| `>>`     | Divide by 2^n, shift right  |              |

**Key Bitwise Operations:**

* **Set a bit:** `x = x | (1 << n)`
* **Clear a bit:** `x = x & ~(1 << n)`
* **Toggle a bit:** `x = x ^ (1 << n)`
* **Check a bit:** `(x & (1 << n)) != 0`

---

Farhad, in simple words:

> * **Bitwise programming = controlling individual bits**
> * Very fast and memory-efficient
> * Widely used in **embedded systems, flags, encryption, and graphics**
> * Bitwise + bit fields = **memory optimization in structs**

---