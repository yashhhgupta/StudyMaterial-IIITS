#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stud_record
{
    int roll_no;
    char name[20];
    float marks[3];
} studs;

struct stud_record *record_search(struct stud_record *record_array[], int n, int roll)
{
    int r = 0, l = n - 1, flag = 0;
    while (r <= l)
    {
        int mid = (r + l) / 2;
        if (record_array[mid]->roll_no == roll)
        {
            flag = 1;
            return record_array[mid];
        }
        else if (record_array[mid]->roll_no < roll)
        {
            l = mid - 1;
        }
        else
        {
            r = mid + 1;
        }
    }
    if (flag == 0)
        return NULL;
}

int main()
{
    printf("Q1\n");
    studs *arr[4];
    //{{5,"john",{50,45.8,70.6}},{4,"jony",{50,55.8,50.6}},{3,"alex",{80,85.8,70.6}},{2,"samu",{50.89,45.86,70.6}}};

    studs *s1 = (studs *)malloc(sizeof(studs));
    s1->roll_no = 42;
    strcpy(s1->name, "abc");
    s1->marks[0] = 78.00;
    s1->marks[1] = 67.00;
    s1->marks[2] = 90.00;
    arr[0] = s1;

    studs *s2 = (studs *)malloc(sizeof(studs));
    s2->roll_no = 38;
    strcpy(s2->name, "abc");
    s2->marks[0] = 78.00;
    s2->marks[1] = 67.00;
    s2->marks[2] = 90.00;
    arr[1] = s2;

    studs *s3 = (studs *)malloc(sizeof(studs));
    s3->roll_no = 34;
    strcpy(s3->name, "abc");
    s3->marks[0] = 78.00;
    s3->marks[1] = 67.00;
    s3->marks[2] = 90.00;
    arr[2] = s3;

    studs *s4 = (studs *)malloc(sizeof(studs));
    s4->roll_no = 30;
    strcpy(s4->name, "abc");
    s4->marks[0] = 78.00;
    s4->marks[1] = 67.00;
    s4->marks[2] = 90.00;
    arr[3] = s4;

    int n = 4;
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", arr[i]->roll_no);
        printf("%s\n", arr[i]->name);
        for (int j = 0; j < 3; j++)
        {
            printf("%.2f ", arr[i]->marks[j]);
        }
        printf("\n");
    }
    struct stud_record *ans = record_search(arr, n, 34);
    if (ans != NULL)
    {
        printf("%d\n", ans->roll_no);
        printf("\n%s\n", ans->name);
    }
    return 0;
}