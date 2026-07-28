```c
#include <time.h>
```

The `<time.h>` header provides functions, types, and macros for manipulating calendar time and processor time.

---

# Why use `<time.h>`?

It helps you:

* Get current date and time
* Calculate elapsed time
* Measure program speed
* Format dates
* Convert timestamps
* Create clocks
* Seed random numbers
* Build logging systems
* Make games with timers
* Develop scheduling software

---

# Main Data Types

## 1. `time_t`

Stores calendar time.

```c
time_t now;
```

Usually stores the number of seconds since:

```
January 1, 1970
00:00:00 UTC
```

Example

```c
#include <stdio.h>
#include <time.h>

int main()
{
    time_t now;

    time(&now);

    printf("%ld\n", now);

    return 0;
}
```

Possible Output

```
1722154321
```

---

## 2. `struct tm`

Stores broken-down time.

```c
struct tm
{
    int tm_sec;
    int tm_min;
    int tm_hour;
    int tm_mday;
    int tm_mon;
    int tm_year;
    int tm_wday;
    int tm_yday;
    int tm_isdst;
};
```

Meaning

| Member   | Description               |
| -------- | ------------------------- |
| tm_sec   | Seconds (0–60)            |
| tm_min   | Minutes                   |
| tm_hour  | Hours                     |
| tm_mday  | Day of month              |
| tm_mon   | Month (0–11)              |
| tm_year  | Years since 1900          |
| tm_wday  | Day of week               |
| tm_yday  | Day of year               |
| tm_isdst | Daylight Saving Time flag |

---

## 3. `clock_t`

Stores CPU processor time.

```c
clock_t start;
```

Used with

```c
clock()
```

---

# Important Functions

| Function             | Purpose                     |
| -------------------- | --------------------------- |
| time()               | Current calendar time       |
| ctime()              | Convert time to string      |
| localtime()          | Convert to local time       |
| gmtime()             | Convert to UTC              |
| asctime()            | Convert struct tm to string |
| strftime()           | Format date/time            |
| mktime()             | Convert struct tm to time_t |
| difftime()           | Difference between times    |
| clock()              | CPU time                    |
| timespec_get() (C11) | High-resolution time        |

---

# Example 1 – Get Current Time

```c
#include <stdio.h>
#include <time.h>

int main()
{
    time_t now;

    time(&now);

    printf("%ld\n", now);

    return 0;
}
```

Output

```
1722154321
```

---

# Example 2 – Print Current Date

```c
#include <stdio.h>
#include <time.h>

int main()
{
    time_t now = time(NULL);

    printf("%s", ctime(&now));

    return 0;
}
```

Output

```
Sun Jul 28 14:40:20 2024
```

---

# Example 3 – Using `localtime()`

```c
#include <stdio.h>
#include <time.h>

int main()
{
    time_t now = time(NULL);

    struct tm *t = localtime(&now);

    printf("Year : %d\n", t->tm_year + 1900);
    printf("Month: %d\n", t->tm_mon + 1);
    printf("Day  : %d\n", t->tm_mday);
    printf("Hour : %d\n", t->tm_hour);
    printf("Min  : %d\n", t->tm_min);
    printf("Sec  : %d\n", t->tm_sec);

    return 0;
}
```

---

# Example 4 – UTC Time

```c
#include <stdio.h>
#include <time.h>

int main()
{
    time_t now = time(NULL);

    struct tm *utc = gmtime(&now);

    printf("%d:%d:%d\n",
           utc->tm_hour,
           utc->tm_min,
           utc->tm_sec);

    return 0;
}
```

---

# Example 5 – Formatting Time

```c
#include <stdio.h>
#include <time.h>

int main()
{
    char buffer[100];

    time_t now = time(NULL);

    struct tm *t = localtime(&now);

    strftime(buffer,
             sizeof(buffer),
             "%d/%m/%Y %H:%M:%S",
             t);

    printf("%s\n", buffer);

    return 0;
}
```

Output

```
28/07/2024 15:10:30
```

Common `strftime()` format specifiers:

| Specifier | Meaning                       |
| --------- | ----------------------------- |
| `%Y`      | Year (e.g., 2026)             |
| `%y`      | Last two digits of year       |
| `%m`      | Month (01–12)                 |
| `%d`      | Day of month                  |
| `%H`      | Hour (24-hour)                |
| `%I`      | Hour (12-hour)                |
| `%M`      | Minute                        |
| `%S`      | Second                        |
| `%A`      | Full weekday name             |
| `%a`      | Abbreviated weekday           |
| `%B`      | Full month name               |
| `%b`      | Abbreviated month             |
| `%p`      | AM/PM                         |
| `%j`      | Day of year                   |
| `%U`      | Week number                   |
| `%c`      | Locale-specific date and time |
| `%%`      | Literal `%`                   |

---

# Example 6 – Time Difference

```c
#include <stdio.h>
#include <time.h>

int main()
{
    time_t start = time(NULL);

    for(long i=0;i<100000000;i++);

    time_t end = time(NULL);

    printf("Elapsed = %.0f seconds\n",
           difftime(end, start));

    return 0;
}
```

---

# Example 7 – CPU Execution Time

```c
#include <stdio.h>
#include <time.h>

int main()
{
    clock_t start = clock();

    for(long i=0;i<100000000;i++);

    clock_t end = clock();

    double cpu =
        (double)(end - start) / CLOCKS_PER_SEC;

    printf("CPU Time = %f seconds\n", cpu);

    return 0;
}
```

---

# Example 8 – Create a Specific Date

```c
#include <stdio.h>
#include <time.h>

int main()
{
    struct tm t = {0};

    t.tm_year = 2025 - 1900;
    t.tm_mon = 11;
    t.tm_mday = 25;

    time_t date = mktime(&t);

    printf("%s", ctime(&date));

    return 0;
}
```

---

# Example 9 – Seed the Random Number Generator

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand((unsigned)time(NULL));

    printf("%d\n", rand());

    return 0;
}
```

Each execution typically produces a different random number because the current time is used as the seed.

---

# Example 10 – Stopwatch

```c
#include <stdio.h>
#include <time.h>

int main()
{
    clock_t start = clock();

    for(long i=0;i<500000000;i++);

    clock_t end = clock();

    printf("Time = %.3f seconds\n",
           (double)(end-start)/CLOCKS_PER_SEC);

    return 0;
}
```

---

# Common Macros

| Macro            | Meaning                          |
| ---------------- | -------------------------------- |
| `CLOCKS_PER_SEC` | Number of clock ticks per second |
| `TIME_UTC` (C11) | Used with `timespec_get()`       |

Example:

```c
struct timespec ts;

timespec_get(&ts, TIME_UTC);
```

---

# Real-World Project 1: Digital Event Logger

**Goal:** Record the date and time of important events in an application.

**Features:**

* Timestamp each log entry with `time()`.
* Convert to local time with `localtime()`.
* Format with `strftime()`.
* Save entries to a log file.

Sample output:

```text
[2026-07-28 14:35:10] User logged in
[2026-07-28 14:40:25] File uploaded
[2026-07-28 14:42:18] User logged out
```

**Concepts used:** `time()`, `localtime()`, `strftime()`, `FILE` I/O.

---

# Real-World Project 2: Simple Task Scheduler

**Goal:** Execute scheduled tasks at specific times.

**Features:**

* Read target times from a configuration.
* Compare the current time using `time()` and `difftime()`.
* Trigger tasks when the scheduled time is reached.
* Display remaining time until execution.

**Concepts used:** `time()`, `mktime()`, `difftime()`, `struct tm`.

---

# Best Practices

* Use `time(NULL)` to retrieve the current calendar time.
* Use `localtime()` for local time and `gmtime()` for UTC.
* Use `strftime()` instead of manually formatting dates.
* Use `clock()` only for measuring CPU time, not wall-clock elapsed time.
* Use `difftime()` instead of directly subtracting `time_t` values for portable code.
* Use `timespec_get()` (C11) when higher-resolution timestamps are needed.

---

# Summary

| Item             | Purpose                     |
| ---------------- | --------------------------- |
| `time_t`         | Calendar time               |
| `struct tm`      | Broken-down date/time       |
| `clock_t`        | CPU processor time          |
| `time()`         | Current calendar time       |
| `ctime()`        | Convert `time_t` to string  |
| `localtime()`    | Local date/time             |
| `gmtime()`       | UTC date/time               |
| `strftime()`     | Custom date/time formatting |
| `mktime()`       | `struct tm` → `time_t`      |
| `difftime()`     | Time difference             |
| `clock()`        | Measure CPU execution time  |
| `timespec_get()` | High-resolution time (C11)  |

Mastering `<time.h>` is essential for systems programming, logging, benchmarking, games, scheduling, networking, embedded systems, and many other real-world C applications.
