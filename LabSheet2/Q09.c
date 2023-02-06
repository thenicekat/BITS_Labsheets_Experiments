#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct student
{
    char email[1000];
    char branch[1000];
    char id[1000];
} Student;

void generateIDNumber(Student *stu)
{
    for (int i = 0; i < 4; i++)
    {
        stu->id[i] = stu->email[i + 1];
    }

    if (stu->branch[1] == 'S')
    {
        stu->id[4] = 'A';
        stu->id[5] = '7';
    }
    else if (stu->branch[1] == 'C')
    {
        stu->id[4] = 'A';
        stu->id[5] = 'A';
    }
    else if (stu->branch[1] == 'E')
    {
        stu->id[4] = 'A';
        stu->id[5] = '3';
    }

    stu->id[6] = 'P';
    stu->id[7] = 'S';

    for (int i = 0; i < 4; i++)
    {
        stu->id[i + 8] = stu->email[i + 5];
    }

    stu->id[12] = 'H';
}

void main()
{
    Student *student1 = (Student *)malloc(sizeof(Student));
    fgets(student1->email, 1000, stdin);
    fgets(student1->branch, 1000, stdin);

    generateIDNumber(student1);

    printf("%s", student1->id);
}