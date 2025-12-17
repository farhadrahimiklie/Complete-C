#include <stdio.h>
#include <string.h>

typedef struct
{
    char name[25];
    int id;
    float score;
} person;

void Write_Person(const char *filename, person *p, size_t count)
{
    FILE *ptr = fopen(filename, "wb");
    if (ptr == NULL)
    {
        perror("Erorr Accur While Writing File. ");
        return;
    }
    fwrite(p, sizeof(person), count, ptr);
    printf("File Writed to File permenently. \n");
    fclose(ptr);
}

void Read_Person(const char *filename, person *p, size_t count)
{
    FILE *ptr = fopen(filename, "rb+");
    if (ptr == NULL)
    {
        perror("Erorr Accur While Reading File. ");
        return;
    }
    int found = 0;
    fread(p, sizeof(person), count, ptr);
    fclose(ptr);

    for (int i = 0; i < 4; i++)
    {
        if (p[i].id == 2)
        {
            p[i].score = 100.0;
            found = 1;
        }
        printf("Name: %s, Age: %d and Score: %.2f \n", p[i].name, p[i].id, p[i].score);
    }
    if (found)
    {
        printf("Record Updated Successfully. \n");
    }
    else
    {
        printf("Record not found. \n");
    }
}

int main()
{
    person p[4] = {
        {"Farhad Rahimi Klie", 1, 90.56},
        {"Hashmatullah Ishan", 2, 17.45},
        {"Rustam Hayat Elbegi", 3, 67.23},
        {"Shaher Ishan", 4, 81.3},
    };

    // Write_Person("data.bin", p, 4);
    Read_Person("data.bin", p, 4);
    return 0;
}
