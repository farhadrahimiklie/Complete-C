What is <stddef.h>?

<stddef.h> provides definitions for:

size_t
ptrdiff_t
wchar_t (in C95/C99 depending on implementation)
NULL
offsetof()
max_align_t (C11)


Contents of <stddef.h>
Item	Purpose
size_t	Unsigned integer for object sizes
ptrdiff_t	Signed integer for pointer subtraction
NULL	Null pointer constant
offsetof()	Offset of a structure member
wchar_t	Wide character type
max_align_t	Maximum alignment type (C11)



1. size_t
What is it?

size_t is an unsigned integer type capable of storing the size of any object.

Almost every standard library function that deals with memory uses size_t.

Example:

size_t size = sizeof(int);

printf("%zu\n", size);

Output

4

(or 8 depending on platform)



#include <stdio.h>
#include <stddef.h>

int main()
{
    int arr[] = {1,2,3,4,5};

    size_t n = sizeof(arr)/sizeof(arr[0]);

    for(size_t i=0;i<n;i++)
    {
        printf("%d ", arr[i]);
    }
}




NULL

Represents a null pointer.

Example:

int *ptr = NULL;

if(ptr == NULL)
{
    printf("Pointer is NULL\n");
}

Output

Pointer is NULL



Example 4 — Safe Pointer
#include <stdio.h>
#include <stddef.h>

int main()
{
    char *name = NULL;

    if(name == NULL)
        printf("No name assigned\n");
}





offsetof()

One of the most powerful macros in C.

Syntax

offsetof(type, member)

Returns

Number of bytes from the beginning of a structure to a member.


struct Student
{
    int id;
    char grade;
    float marks;
};

printf("%zu\n", offsetof(struct Student, marks));

Possible Output

8




