#include <stdio.h>
#include <string.h>

struct Student
{
    int roll;
    char name[50];
    int age;
    float marks;
};

struct Student students[100];
int count = 0;


// Add Student
void addStudent()
{
    printf("\nEnter Roll No: ");
    scanf("%d", &students[count].roll);

    printf("Enter Name: ");
    scanf(" %[^\n]", students[count].name);

    printf("Enter Age: ");
    scanf("%d", &students[count].age);

    printf("Enter Marks: ");
    scanf("%f", &students[count].marks);

    count++;

    printf("\nStudent added successfully!\n");
}


// Display Students
void displayStudents()
{
    if(count == 0)
    {
        printf("\nNo students found.\n");
        return;
    }

    printf("\n--- Student List ---\n");

    for(int i = 0; i < count; i++)
    {
        printf("\nRoll No: %d", students[i].roll);
        printf("\nName: %s", students[i].name);
        printf("\nAge: %d", students[i].age);
        printf("\nMarks: %.2f\n", students[i].marks);
    }
}


// Search Student
void searchStudent()
{
    int roll;

    printf("\nEnter Roll No to search: ");
    scanf("%d", &roll);

    for(int i = 0; i < count; i++)
    {
        if(students[i].roll == roll)
        {
            printf("\nStudent Found!\n");
            printf("Name: %s\n", students[i].name);
            printf("Age: %d\n", students[i].age);
            printf("Marks: %.2f\n", students[i].marks);
            return;
        }
    }

    printf("\nStudent not found.\n");
}


// Main
int main()
{
    int choice;

    while(1)
    {
        printf("\n===== Student Management System =====\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                addStudent();
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                printf("\nThank you!\n");
                return 0;

            default:
                printf("\nInvalid choice!\n");
        }
    }

    return 0;
}