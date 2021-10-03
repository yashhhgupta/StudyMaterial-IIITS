#include <stdio.h>
#include <math.h>
#include <string.h>

typedef struct student_struct
{
    char FirstName[50];
    char LastName[50];
    int RollNumber;
    float CGPA;
    int courselen;
    int Courses[6];
} Student;

Student students[50];

void addStudent(int i)
{
    printf("Enter Roll Number:\n");
    int rollno;
    scanf("%d", &rollno);
    for (int q = 0; q < 50; q++)
    {
        if (rollno == students[q].RollNumber)
        {
            printf("Student already exists\n");
            return;
        }
    }
    students[i].RollNumber = rollno;
    printf("Enter First Name:\n");
    scanf("%s", students[i].FirstName);
    printf("Enter Last Name:\n");
    scanf("%s", students[i].LastName);
    printf("Enter CGPA:\n");
    scanf("%f", &students[i].CGPA);
    int courselen;
    printf("Enter the number of courses attending (101 to 106) :");
    scanf("%d", &courselen);
    students[i].courselen = courselen;
    printf("Enter the course IDs: \n");
    for (int p = 0; p < courselen; p++)
    {
        scanf("%d", &students[i].Courses[p]);
    }
    printf("\n Student has been added \n");
}

void findStudent_rollno()
{
    printf("Enter Roll Number:\n");
    int rollno;
    int flag = 0;
    scanf("%d", &rollno);
    for (int q = 0; q < 50; q++)
    {
        if (rollno == students[q].RollNumber)
        {
            flag = 1;
            printf("-------------------------------------------------------------------------------------\n");
            printf("Found student details\n");
            printf("Name: %s %s\n", students[q].FirstName, students[q].LastName);
            printf("Roll Number: %d\n", students[q].RollNumber);
            printf("CGPA: %f\n", students[q].CGPA);
            printf("Courses attended: \n");
            for (int p = 0; p < students[q].courselen; p++)
            {
                printf("%d ", students[q].Courses[p]);
            }
            printf("\n");
            printf("-------------------------------------------------------------------------------------\n");
        }
    }
    if (flag == 0)
    {
        printf("No Student found \n");
    }
}

void findStudent_firstname()
{
    printf("Enter First Name:\n");
    char name[50];
    int flag = 0;
    scanf("%s", name);
    for (int q = 0; q < 50; q++)
    {
        if (!strcmp(name, students[q].FirstName))
        {
            flag = 1;
            printf("-------------------------------------------------------------------------------------\n");
            printf("Found student details\n");
            printf("Name: %s %s\n", students[q].FirstName, students[q].LastName);
            printf("Roll Number: %d\n", students[q].RollNumber);
            printf("CGPA: %f\n", students[q].CGPA);
            printf("Courses attended: \n");
            for (int p = 0; p < students[q].courselen; p++)
            {
                printf("%d ", students[q].Courses[p]);
            }
            printf("\n");
            printf("-------------------------------------------------------------------------------------\n");
        }
    }
    if (flag == 0)
    {
        printf("No Student found \n");
    }
}

void findStudent_courses()
{
    printf("Enter Course IDs:\n");
    int id;
    int flag = 0;
    scanf("%d", &id);
    for (int q = 0; q < 50; q++)
    {
        for (int x = 0; x < 10; x++)
        {
            if (id == students[q].Courses[x])
            {
                flag = 1;
                printf("-------------------------------------------------------");
                printf("Found student details\n");
                printf("Name: %s %s\n", students[q].FirstName, students[q].LastName);
                printf("Roll Number: %d\n", students[q].RollNumber);
                printf("CGPA: %f\n", students[q].CGPA);
                printf("Courses attended: \n");
                for (int p = 0; p < students[q].courselen; p++)
                {
                    printf("%d ", students[q].Courses[p]);
                }
                printf("\n");
                printf("-------------------------------------------------------");
            }
        }
    }
    if (flag == 0)
    {
        printf("No Student found \n");
    }
}

void deleteStudent()
{
    printf("Enter Roll Number:\n");
    int rollno;
    int flag = 0;
    scanf("%d", &rollno);
    for (int q = 0; q < 50; q++)
    {
        if (rollno == students[q].RollNumber)
        {
            flag = 1;
            for (int r = q; r < 49; r++)
            {
                students[r] = students[r + 1];
            }
            printf("Student deleted \n");
        }
    }
    if (flag == 0)
    {
        printf("No Student found \n");
    }
}

void updateStudent()
{
    printf("Enter Roll Number:\n");
    int rollno;
    int flag = 0;
    int user_input;
    int courselen;
    scanf("%d", &rollno);
    for (int q = 0; q < 50; q++)
    {
        if (rollno == students[q].RollNumber)
        {
            printf("What details do you want to change? \n");
            do
            {
                printf("Menu for the Software is the following: \n");
                printf("-----------------------------------------------------------------------------\n");
                printf("Option        Action\n");
                printf("  0           Quit The Software\n");
                printf("  1           First Name\n");
                printf("  2           Last Name\n");
                printf("  3           CGPA\n");
                printf("  4           Courses\n");
                printf("-----------------------------------------------------------------------------\n");
                printf("Enter the Option of the Action you want to do\n");
                scanf("%d", &user_input);
                switch (user_input)
                {
                case 0:
                    return;
                case 1:
                    printf("Enter First Name:\n");
                    scanf("%s", students[q].FirstName);
                    break;
                case 2:
                    printf("Enter Last Name:\n");
                    scanf("%s", students[q].LastName);
                    break;
                case 3:
                    printf("Enter CGPA:\n");
                    scanf("%f", &students[q].CGPA);
                    break;
                case 4:
                    printf("Enter the number of courses attending (101 to 106) :");
                    scanf("%d", &courselen);
                    students[q].courselen = courselen;
                    printf("Enter the course IDs: \n");
                    for (int p = 0; p < courselen; p++)
                    {
                        scanf("%d", &students[q].Courses[p]);
                    }
                    break;
                default:
                    printf("Wrong input\n");
                    break;
                }
            } while (user_input != 0);
        }
    }
    if (flag == 0)
    {
        printf("No Student found \n");
    }
}

void PrintStudentStatistics(int l)
{

    float sum = 0;
    for (int i = 0; i < l; i++)
    {
        sum = sum + students[i].CGPA;
    }
    float mean = sum / l;
    l = l - 1;
    float median;
    if (l % 2 == 0)
    {
        median = students[l / 2].CGPA;
    }
    else
    {
        median = (students[l / 2].CGPA + students[l / 2 + 1].CGPA) / 2;
    }
    sum = 0;
    for (int i = 0; i < l; i++)
    {
        sum = sum + (students[i].CGPA * students[i].CGPA);
    }
    int var = sum / l - (mean * mean);
    float stddev = sqrt(var);
    printf("Student Statistics of students CGPA are: \n");
    printf("Mean : %f\n", mean);
    printf("Median : %f\n", median);
    printf("Standard Deviation : %f\n", stddev);
}

int main()
{
    int user_input = 0;
    int studentcount = 0;
    do
    {
        printf("Menu for the Software is the following: \n");
        printf("-------------------------------------------------------------------------------------\n");
        printf("Option        Action\n");
        printf("  0           Quit The Software\n");
        printf("  1           Add a Student to the list\n");
        printf("  2           Find a Student by Roll number\n");
        printf("  3           Find Students by their First name\n");
        printf("  4           Find Students by Course ID\n");
        printf("  5           Total Number of Students in the System\n");
        printf("  6           Delete a Particular Student By his/her Roll number\n");
        printf("  7           Update a Particular field of the Student By his roll number\n");
        printf("  8           Student Statistics\n");
        printf("  9           Course Summaries\n");
        printf("--------------------------------------------------------------------------------------\n");
        printf("Enter the Option of the Action you want to do\n");
        scanf("%d", &user_input);
        switch (user_input)
        {
        case 0:
            return 0;
        case 1:
            addStudent(studentcount);
            studentcount++;
            break;
        case 2:
            findStudent_rollno();
            break;
        case 3:
            findStudent_firstname();
            break;
        case 4:
            findStudent_courses();
            break;
        case 5:
            printf("Total students: %d \n", studentcount);
            break;
        case 6:
            deleteStudent();
            studentcount--;
            break;
        case 7:
            updateStudent();
            break;
        case 8:
            PrintStudentStatistics(studentcount);
            break;
        default:
            printf("Wrong input\n");
            break;
        }
    } while (user_input != 0);
    return 0;
}