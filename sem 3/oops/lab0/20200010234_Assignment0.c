#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
struct student_struct
{
    char Name[50];
    char RollNo[10];
    float CGPA;
};

struct student_struct *ptr;
void addStudent(int i)
{
    printf("Enter Roll Number:\n");
    scanf("%s",(ptr+i)->RollNo);
    printf("Enter Name:\n");
    scanf("%s", (ptr+i)->Name);
    printf("Enter CGPA:\n");
    scanf("%f",&((ptr+i)->CGPA));
    printf("\nStudent has been added\n");
}

void findStudent_rollno(int q)
{
    printf("Enter Roll Number:\n");
    char roll[10];
    int flag = 0;
    scanf("%s", roll);
    for (int i = 0; i < q; i++)
    {
        if (strcmp(roll, (ptr+i)->RollNo)==0)
        {
            flag = 1;
            printf("-------------------------------------------------------------------------------------\n");
            printf("Student Found");
            printf("RollNo.:- %s\nName:- %s\nCGPA:- %f\n",(ptr+i)->RollNo,(ptr+i)->Name,(ptr+i)->CGPA);
            printf("\n");
            printf("-------------------------------------------------------------------------------------\n");
            return;
        }
    }
    if (flag == 0)
    {
        printf("No Student found \n");
    }
}
void displayall(int x)
{
    printf("-------------------------------------------------------------------------------------\n");
    printf("Student list:-\n");
    for (int i = 0; i < x; i++)
    {
        printf("Student %d\n",i+1);
        printf("RollNo.:- %s\nName:- %s\nCGPA:- %f\n",(ptr+i)->RollNo,(ptr+i)->Name,(ptr+i)->CGPA);
    }
    printf("-------------------------------------------------------------------------------------\n");
}
int main()
{
    int user_input;
    int studentcount=0;
    ptr = (struct student_struct*)malloc(10*sizeof(struct student_struct));
    do
    {
        printf("Menu for the Software is the following: \n");
        printf("-------------------------------------------------------------------------------------\n");
        printf("Option        Action\n");
        printf("  1           Add a Student to the list\n");
        printf("  2           Find a Student by Roll number\n");
        printf("  3           Display all Students\n");
        printf("  4           Quit The Software\n");
        printf("--------------------------------------------------------------------------------------\n");
        printf("Enter the Option of the Action you want to do\n");
        scanf("%d", &user_input);
        switch (user_input)
        {
        case 1:
            addStudent(studentcount);
            studentcount++;
            break;
        case 2:
            findStudent_rollno(studentcount);
            break;
        case 3:
            displayall(studentcount);
            break;
        case 4:
            return 0;
        default:
            printf("Wrong input\n");
            break;
        }
    } while (user_input != 4);
}