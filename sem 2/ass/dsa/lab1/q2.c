#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/unistd.h>
#include <string.h>
int studentsnum;
int stid = 0;
void findmean(int i);
typedef struct iSiMS
{
    char name[50];
    int rollnumber;
    float marks1;
    float marks2;
    float marks3;
} Students;
Students studentlist[50];
void addStudent()
{
    printf("Enter name of Student: ");
    scanf("\n");
    scanf("%[^\n]%*c", &studentlist[stid].name);

    printf("Enter Roll number of Student: \n");
    printf("Example of A Roll number : 10100\n");
here:
    scanf("%d", &studentlist[stid].rollnumber);
    for (int i = 0; i < studentsnum; i++)
    {
        if (studentlist[stid].rollnumber == studentlist[i].rollnumber && stid != i)
        {
            printf("Roll number already occupies, Please Enter another Roll Number\n");
            goto here;
        }
    }
    printf("Enter marks(subject1) of the Student: ");
    scanf("%f", &studentlist[stid].marks1);
    printf("Enter marks(subject2) of the Student: ");
    scanf("%f", &studentlist[stid].marks2);
    printf("Enter marks(subject3) of the Student: ");
    scanf("%f", &studentlist[stid].marks3);
    stid++;
}
void studentbyroll()
{
    int temp, reff = 0;
    printf("Enter the Roll number of Student for which u want details: ");
    scanf("%d", &temp);
    for (int i = 0; i < studentsnum; i++)
    {
        if (studentlist[i].rollnumber == temp)
        {
            printf("Name of Student: %s\n", studentlist[i].name);
            printf("Roll number of the Student: %d\n", temp);
            printf("marks(subject1) Of the Student: %.1f\n", studentlist[i].marks1);
            printf("marks(subject2) Of the Student: %.1f\n", studentlist[i].marks2);
            printf("marks(subject3) Of the Student: %.1f\n", studentlist[i].marks3);
            findmean(i);
            reff++;
            break;
        }
    }
    if (reff == 0)
    {
        printf("There are no Students with Above roll number\n");
    }
}
void findmean(int i)
{

    float mean = (studentlist[i].marks1 + studentlist[i].marks2 + studentlist[i].marks3) / 3;
    printf("mean of student with roll no. %d is %.1f \n", studentlist[i].rollnumber, mean);
}
int main()
{
    printf("enter the number of studets you want to add\n");
    scanf("%d", &studentsnum);
    for (int i = 0; i < studentsnum; i++)
    {
        addStudent();
    }
    printf("----------------------------------------------\n");
    studentbyroll();
    printf("----------------------------------------------\n");
    for (int i = 0; i < studentsnum; i++)
    {
        findmean(i);
    }

    return 0;
}