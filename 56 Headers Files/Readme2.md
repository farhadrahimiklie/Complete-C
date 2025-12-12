# C Standard Libraries – Complete List with Examples

This document provides a comprehensive list of all C standard library headers along with **five example usages** for each header. All examples are written in C and focus on practical, real‑world usage.

---

## 1. `<assert.h>` – Diagnostics

### Example Usages

```c
#include <assert.h>
int main() {
    int x = 5;
    assert(x == 5);
}
```

```c
#include <assert.h>
int main() {
    int *ptr = NULL;
    assert(ptr != NULL);
}
```

```c
#include <assert.h>
void test(int n) {
    assert(n > 0);
}
```

```c
#include <assert.h>
int main() {
    assert(sizeof(int) == 4);
}
```

```c
#include <assert.h>
int divide(int a, int b) {
    assert(b != 0);
    return a / b;
}
```

---

## 2. `<ctype.h>` – Character Handling

### Example Usages

```c
#include <ctype.h>
char c = 'a';
int result = isalpha(c);
```

```c
#include <ctype.h>
char c = ' ';
int result = isspace(c);
```

```c
#include <ctype.h>
char c = 'G';
c = tolower(c);
```

```c
#include <ctype.h>
char c = '9';
int result = isdigit(c);
```

```c
#include <ctype.h>
char c = '!';
int result = ispunct(c);
```

---

## 3. `<errno.h>` – Error Codes

### Example Usages

```c
#include <errno.h>
#include <stdio.h>
#include <string.h>
FILE *f = fopen("nofile.txt", "r");
if (!f) printf("Error: %s", strerror(errno));
```

```c
#include <errno.h>
int e = errno;
```

```c
#include <errno.h>
printf("Current errno: %d", errno);
```

```c
#include <errno.h>
errno = 0;
```

```c
#include <errno.h>
printf("Domain error code: %d", EDOM);
```

---

## 4. `<fenv.h>` – Floating‑Point Environment

### Example Usages

```c
#include <fenv.h>
fesetround(FE_UPWARD);
```

```c
#include <fenv.h>
feraiseexcept(FE_DIVBYZERO);
```

```c
#include <fenv.h>
feclearexcept(FE_ALL_EXCEPT);
```

```c
#include <fenv.h>
int flags = fetestexcept(FE_OVERFLOW);
```

```c
#include <fenv.h>
fenv_t env; fegetenv(&env);
```

---

## 5. `<float.h>` – Floating‑Point Limits

### Example Usages

```c
#include <float.h>
printf("Max float: %f", FLT_MAX);
```

```c
#include <float.h>
printf("Min double: %g", DBL_MIN);
```

```c
#include <float.h>
printf("Precision: %d", FLT_DIG);
```

```c
#include <float.h>
printf("Radix: %d", FLT_RADIX);
```

```c
#include <float.h>
printf("Epsilon: %g", FLT_EPSILON);
```

---

## 6. `<inttypes.h>` – Format Macros for Integers

### Example Usages

```c
#include <inttypes.h>
printf("%" PRId32 "", (int32_t)100);
```

```c
#include <inttypes.h>
intmax_t v = 123;
printf("%jd", v);
```

```c
#include <inttypes.h>
uint64_t x = 5000;
printf("%" PRIu64, x);
```

```c
#include <inttypes.h>
int32_t a = 10;
printf("0x%" PRIx32, a);
```

```c
#include <inttypes.h>
printf("Parse: %" SCNd32, &a);
```

---

## 7. `<iso646.h>` – Alternative Operator Tokens

### Example Usages

```c
#include <iso646.h>
if (1 and 1) {}
```

```c
#include <iso646.h>
if (0 or 1) {}
```

```c
#include <iso646.h>
if (not 0) {}
```

```c
#include <iso646.h>
int c = a bitand b;
```

```c
#include <iso646.h>
int c = a bitor b;
```

---

## 8. `<limits.h>` – Integer Limits

### Example Usages

```c
#include <limits.h>
printf("Max int: %d", INT_MAX);
```

```c
#include <limits.h>
printf("Min long: %ld", LONG_MIN);
```

```c
#include <limits.h>
printf("Max char: %d", CHAR_MAX);
```

```c
#include <limits.h>
printf("Max unsigned: %u", UINT_MAX);
```

```c
#include <limits.h>
printf("Bits in char: %d", CHAR_BIT);
```

---

## 9. `<locale.h>` – Localization

### Example Usages

```c
#include <locale.h>
setlocale(LC_ALL, "");
```

```c
#include <locale.h>
struct lconv *lc = localeconv();
```

```c
#include <locale.h>
setlocale(LC_NUMERIC, "en_US");
```

```c
#include <locale.h>
setlocale(LC_TIME, "fr_FR");
```

```c
#include <locale.h>
setlocale(LC_MONETARY, "de_DE");
```

---

## 10. `<math.h>` – Mathematics

### Example Usages

```c
#include <math.h>
double x = sqrt(16);
```

```c
#include <math.h>
double y = pow(2, 8);
```

```c
#include <math.h>
double z = sin(3.14);
```

```c
#include <math.h>
double r = log(10);
```

```c
#include <math.h>
double v = fabs(-4.3);
```

---

## 11. `<setjmp.h>` – Jump Handling

### Example Usages

```c
#include <setjmp.h>
jmp_buf env;
```

```c
#include <setjmp.h>
if (setjmp(env) == 0) {}
```

```c
#include <setjmp.h>
longjmp(env, 1);
```

```c
#include <setjmp.h>
void test() { longjmp(env, 2); }
```

```c
#include <setjmp.h>
int state = setjmp(env);
```

---

## 12. `<signal.h>` – Signals

### Example Usages

```c
#include <signal.h>
signal(SIGINT, handler);
```

```c
#include <signal.h>
raise(SIGTERM);
```

```c
#include <signal.h>
sig_atomic_t flag = 0;
```

```c
#include <signal.h>
signal(SIGABRT, SIG_IGN);
```

```c
#include <signal.h>
signal(SIGFPE, handler);
```

---

## 13. `<stdarg.h>` – Variable Arguments

### Example Usages

```c
#include <stdarg.h>
void f(int n, ...) {}
```

```c
#include <stdarg.h>
va_list args;
```

```c
#include <stdarg.h>
va_start(args, n);
```

```c
#include <stdarg.h>
int x = va_arg(args, int);
```

```c
#include <stdarg.h>
va_end(args);
```

---

## 14. `<stdbool.h>` – Boolean Type

### Example Usages

```c
#include <stdbool.h>
bool flag = true;
```

```c
#include <stdbool.h>
bool check = false;
```

```c
#include <stdbool.h>
if (flag) {}
```

```c
#include <stdbool.h>
bool b = (5 > 3);
```

```c
#include <stdbool.h>
bool arr[3] = {true, false, true};
```

---

## 15. `<stddef.h>` – Common Definitions

### Example Usages

```c
#include <stddef.h>
size_t n = sizeof(int);
```

```c
#include <stddef.h>
ptrdiff_t d;
```

```c
#include <stddef.h>
wchar_t wc;
```

```c
#include <stddef.h>
offsetof(struct T, field);
```

```c
#include <stddef.h>
NULL;
```

---

## 16. `<stdint.h>` – Fixed‑Width Integers

### Example Usages

```c
#include <stdint.h>
uint8_t x = 255;
```

```c
#include <stdint.h>
int64_t y = -1000;
```

```c
#include <stdint.h>
uint32_t z = 50000;
```

```c
#include <stdint.h>
uint16_t a = 100;
```

```c
#include <stdint.h>
int_fast8_t b = 5;
```

---

## 17. `<stdio.h>` – Input/Output

### Example Usages

```c
#include <stdio.h>
printf("Hello");
```

```c
#include <stdio.h>
scanf("%d", &x);
```

```c
#include <stdio.h>
FILE *fp = fopen("test.txt", "r");
```

```c
#include <stdio.h>
fgets(buffer, 20, fp);
```

```c
#include <stdio.h>
fclose(fp);
```

---

## 18. `<stdlib.h>` – General Utilities

### Example Usages

```c
#include <stdlib.h>
int *p = malloc(10 * sizeof(int));
```

```c
#include <stdlib.h>
free(p);
```

```c
#include <stdlib.h>
int r = rand();
```

```c
#include <stdlib.h>
exit(0);
```

```c
#include <stdlib.h>
qsort(arr, n, sizeof(int), cmp);
```

---

## 19. `<string.h>` – String Handling

### Example Usages

```c
#include <string.h>
strcpy(a, b);
```

```c
#include <string.h>
strlen(s);
```

```c
#include <string.h>
strcmp(a, b);
```

```c
#include <string.h>
memcpy(a, b, 10);
```

```c
#include <string.h>
strcat(a, b);
```

---

## 20. `<tgmath.h>` – Type‑Generic Math

### Example Usages

```c
#include <tgmath.h>
float x = sqrt(25.0f);
```

```c
#include <tgmath.h>
double y = pow(2, 4);
```

```c
#include <tgmath.h>
double z = fabs(-3.2);
```

```c
#include <tgmath.h>
complex c = csin(1);
```

```c
#include <tgmath.h>
long double v = log(5.0L);
```

---

## 21. `<time.h>` – Date and Time

### Example Usages

```c
#include <time.h>
time_t t = time(NULL);
```

```c
#include <time.h>
struct tm *info = localtime(&t);
```

```c
#include <time.h>
printf("%s", asctime(info));
```

```c
#include <time.h>
printf("%s", ctime(&t));
```

```c
#include <time.h>
clock_t start = clock();
```

---

## 22. `<wchar.h>` – Wide Characters

### Example Usages

```c
#include <wchar.h>
wchar_t wc = L'A';
```

```c
#include <wchar.h>
wprintf(L"%lc", wc);
```

```c
#include <wchar.h>
wcscpy(a, b);
```

```c
#include <wchar.h>
wcslen(a);
```

```c
#include <wchar.h>
wmemcmp(a, b, 10);
```

---

## 23. `<wctype.h>` – Wide Character Classification

### Example Usages

```c
#include <wctype.h>
int r = iswalpha(L'A');
```

```c
#include <wctype.h>
wint_t c = towlower(L'Z');
```

```c
#include <wctype.h>
iswspace(L' ');
```

```c
#include <wctype.h>
iswdigit(L'5');
```

```c
#include <wctype.h>
int r = iswpunct(L'?');
```

---

# End of Document
