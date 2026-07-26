#include <stdio.h>

typedef struct {
    int id;
    float score;
    char grade;
}Student;

int main(){
    FILE *ptr = fopen("file.bin", "wb");
    if (!ptr) {
        printf("cannot open file for writing data.\n");
        return 1;
    }

    Student student;

    for (int i = 0; i < 5; i++) {
        student.id = i + 1;
        student.score = 78.1f + i;
        student.grade = 'A' + i;
        fwrite(&student, sizeof(Student), 1, ptr);
    }
    fclose(ptr);

    ptr = fopen("file.bin", "rb");
    if (!ptr) {
        printf("cannot open file for reading.\n");
        return 1;
    }


    // reading the all sturcts in the binary file method 1 with while loop better approach is this...
    //Student ss;

    // while (fread(&ss, sizeof(Student), 1, ptr) == 1) {
    //printf("ID: %d\n", ss.id);
    //}

    //fclose(ptr);


    // reading the all sturcts in the binary file method 2 with for loop this is second best approach...

    Student ss;

    for (int i = 0; i < 5; i++) {
        fread(&ss, sizeof(Student), 1, ptr);

        printf("ID    : %d\n", ss.id);
        printf("Score : %.2f\n", ss.score);
        printf("Grade : %c\n", ss.grade);
        printf("-----------------\n");
    }

    fclose(ptr);

    return 0;
}
