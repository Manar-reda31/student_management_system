#include <stdio.h>
#include <string.h>

struct student
{
    int id;
    char name[50];
    float grades[5];
    float average;
};
struct student CLASS_STUDENTS[50];
int studentcount = 0;

void addstudent()
{

    struct student STUDENT;

    STUDENT.id = studentcount + 1;
    printf("Enter Student Name: ");
    scanf(" %[^\n]", STUDENT.name);

    for (int i = 0; i < 5; i++)
    {
        STUDENT.grades[i] = 0;
    }
    STUDENT.average = 0;
    CLASS_STUDENTS[studentcount] = STUDENT;
    studentcount++;

    printf("Student Added Successfully! \nid= %d\n", STUDENT.id);
}

void entergrades()
{
    int id;
    printf("Enter Student's Id:");
    scanf(" %d", &id);
    if (id < 1 || id > studentcount)
    {
        printf(" Invalid Id! \n");
        return;
    }

    int index = id - 1;
    float sum = 0;
    for (int i = 0; i < 5; i++)
    {
        printf("Enter Grade %d: ", i + 1);
        scanf(" %f", &CLASS_STUDENTS[index].grades[i]);
        sum += CLASS_STUDENTS[index].grades[i];
    }
    CLASS_STUDENTS[index].average = sum / 5;
    printf("Grades Added Successfully.\n");
}

void searchbyname()
{
    char NAME[50];
    printf("Enter Student Name: ");
    scanf(" %[^\n]", NAME);
    for (int i = 0; i < studentcount; i++)
    {
        if (strcmp(CLASS_STUDENTS[i].name, NAME) == 0)
        {
            printf("\nStudent Found! \n");
            printf("Id: %d\n", CLASS_STUDENTS[i].id);
            printf("Name: %s\n", CLASS_STUDENTS[i].name);
            printf("Grades: ");
            for (int j = 0; j < 5; j++)
            {
                printf("%.2f\t", CLASS_STUDENTS[i].grades[j]);
            }
            printf(" \naverage: %.2f\n", CLASS_STUDENTS[i].average);
            return;
        }
    }

    printf("Student Not Found! \n");
}

void classreport()
{
    if (studentcount == 0)
    {
        printf("NO STUDENTS YET!");
        return;
    }
    printf(" \n ____Class Report____ \n");
    printf(" \n%-5s %-15s %-10s\n", "ID", "NAME", "AVERAGE");
    printf(" ________________________________\n ");
    for (int i = 0; i < studentcount; i++)
    {
        printf("\n%-5d %-15s %-10.2f\n", CLASS_STUDENTS[i].id, CLASS_STUDENTS[i].name, CLASS_STUDENTS[i].average);
    }
}

int main()
{
    int choice;
    while (1)
    {
        printf("\n  ____School Management System Menu____\n");
        printf("\n1. Add New Student\n");
        printf("2. Enter Grades For a Student\n");
        printf("3. Search For a Student By Name\n");
        printf("4. View Class Report For All \n");
        printf("5. exit \n");
        printf("\nENTER YOUR CHOICE: ");
        scanf(" %d", &choice);

        switch (choice)
        {
        case 1:
            addstudent();
            break;
        case 2:
            entergrades();
            break;
        case 3:
            searchbyname();
            break;
        case 4:
            classreport();
            break;
        case 5:
            printf("Goodbye <3\n ");
            return 0;
            break;
        default:
            printf("Invalid choice, try again.\n");
        }
    }
    return 0;
}
