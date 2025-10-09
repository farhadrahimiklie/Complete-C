
---

# 🔹 **Bit Masking and Shifting in C – Full Details**

---

## 🧠 1. What is Bit Masking?

* **Bit masking** = process of **selectively modifying, clearing, setting, or reading specific bits** of a number.
* Uses **bitwise operators** (`&`, `|`, `^`, `~`) along with **masks**.

**Mask:** A number where **1s indicate bits of interest** and **0s indicate bits to ignore**.

---

### Example: Mask to extract last 4 bits

```c
#include <stdio.h>

int main() {
    unsigned char x = 0b10101100;
    unsigned char mask = 0x0F; // 00001111

    unsigned char last4 = x & mask;
    printf("Last 4 bits: %d\n", last4); // 1100 → 12
    return 0;
}
```

**Output:**

```
Last 4 bits: 12
```

* Here `& mask` extracts only the **bits of interest**.

---

## 🔹 2. Common Bit Masking Operations

### a) Set a Bit

* Make a specific bit **1** without changing others.

```c
x = x | (1 << n); // Set nth bit
```

**Example:**

```c
unsigned char x = 0b00001010; // 10
x = x | (1 << 2); // Set 3rd bit → 00001110 → 14
```

---

### b) Clear a Bit

* Make a specific bit **0** without changing others.

```c
x = x & ~(1 << n); // Clear nth bit
```

**Example:**

```c
unsigned char x = 0b00001110; // 14
x = x & ~(1 << 3); // Clear 4th bit → 00000110 → 6
```

---

### c) Toggle a Bit

* Invert a specific bit.

```c
x = x ^ (1 << n); // Toggle nth bit
```

**Example:**

```c
unsigned char x = 0b00000110; // 6
x = x ^ (1 << 1); // Toggle 2nd bit → 00000100 → 4
```

---

### d) Check a Bit

* Test if a specific bit is **1 or 0**.

```c
if(x & (1 << n))
    printf("Bit is set\n");
else
    printf("Bit is not set\n");
```

---

## 🔹 3. Bit Shifting in C

* **Bit Shifting** = moving bits **left or right** using `<<` and `>>`.
* Often used with **masking for efficient calculations**.

### a) Left Shift (`<<`)

* Moves bits **to the left**, fills with 0 on right.
* Equivalent to **multiplying by 2ⁿ**.

```c
unsigned char x = 5; // 00000101
unsigned char y = x << 1; // 00001010 → 10
```

---

### b) Right Shift (`>>`)

* Moves bits **to the right**, fills with 0 (unsigned) or sign bit (signed).
* Equivalent to **integer division by 2ⁿ**.

```c
unsigned char x = 10; // 00001010
unsigned char y = x >> 1; // 00000101 → 5
```

---

## 🔹 4. Combining Bit Masking and Shifting

* Masking and shifting together allows **extracting or inserting bits**.

### Example: Extract specific bits from a number

```c
#include <stdio.h>

int main() {
    unsigned char x = 0b10101100;

    // Extract bits 4-7 (upper nibble)
    unsigned char upper = (x & 0xF0) >> 4; // mask 11110000 and shift
    printf("Upper nibble: %d\n", upper); // 1010 → 10

    // Extract bits 0-3 (lower nibble)
    unsigned char lower = x & 0x0F; // mask 00001111
    printf("Lower nibble: %d\n", lower); // 1100 → 12

    return 0;
}
```

**Output:**

```
Upper nibble: 10
Lower nibble: 12
```

* **Masking** → selects the bits
* **Shifting** → moves them to LSB position for easier use

---

## 🔹 5. Practical Applications

1. **Flags and Status Registers** → store multiple boolean values in **one byte**
2. **Extracting or inserting data in network protocols**
3. **Working with colors in graphics** → RGB values packed in 24 bits
4. **Compression** → storing multiple small numbers in fewer bytes
5. **Embedded systems** → direct hardware control via bitwise operations

---

### Example: Using Byte as Flags

```c
#include <stdio.h>

int main() {
    unsigned char flags = 0;

    // Set bit 0 (Power On)
    flags |= (1 << 0);

    // Set bit 3 (Error)
    flags |= (1 << 3);

    // Check if Power On
    if(flags & (1 << 0)) printf("Power ON\n");

    // Clear Error
    flags &= ~(1 << 3);

    return 0;
}
```

* Only **1 byte** stores **multiple independent flags** efficiently.

---

## 🔹 6. Summary of Bit Masking & Shifting

| Operation     | Description                |             |
| ------------- | -------------------------- | ----------- |
| `x & mask`    | Extract bits               |             |
| `x            | (1<<n)`                    | Set nth bit |
| `x & ~(1<<n)` | Clear nth bit              |             |
| `x ^ (1<<n)`  | Toggle nth bit             |             |
| `x << n`      | Left shift, multiply by 2ⁿ |             |
| `x >> n`      | Right shift, divide by 2ⁿ  |             |

* **Masking** → selects bits
* **Shifting** → moves bits to correct positions
* **Combined** → powerful technique for **efficient low-level programming**

---

Farhad, in simple words:

> * **Bit Masking = select or modify specific bits**
> * **Shifting = move bits left or right**
> * Together → **efficiently manipulate data, flags, colors, and hardware registers**

---
