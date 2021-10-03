#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct stud_record
{
    int roll_no;
    char name[20];
    float marks[3];
} student;
struct stud_record *record_search(struct stud_record *record_array[], int n, int roll)
{
    int r = 0, l = n - 1, temp = 0;
    while (r <= l)
    {
        int m = (r + l) / 2;
        if (record_array[m]->roll_no == roll)
        {
            temp = 1;
            return record_array[m];
        }
        else if (record_array[m]->roll_no < roll)
        {
            l = m - 1;
        }
        else
        {
            r = m + 1;
        }
    }
    if (temp == 0)
        return NULL;
}
int check_string(char arr[])
{
    int j = 0, temp = 1, temp2 = 0;
    for (int i = 0; i < strlen(arr); i++)
    {
        if (arr[i] == '1')
        {
            j += 1;
            if (temp == 1)
            {
                temp2 += 1;
                temp = 0;
            }
        }
        else
        {
            temp = 1;
        }
    }
    if (j == 0)
    {
        return 0;
    }
    else
    {
        if (temp2 == 1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}
int modified_binary_search(int arr[], int n, int key, int k)
{
    int l, hi;
    if (key >= arr[0])
    {
        l = 0;
        hi = k - 1;
        while (l <= hi)
        {
            int m = (l + hi) / 2;
            if (key == arr[m])
                return m;
            else if (key > arr[m])
                l = m + 1;

            else
                hi = m - 1;
        }
    }
    if (key < arr[0])
    {
        l = k;
        hi = n - 1;
        while (l <= hi)
        {
            int m = (l + hi) / 2;
            if (key == arr[m])
                return m;
            else if (key > arr[m])
                l = m + 1;

            else
                hi = m - 1;
        }
    }
    return -1;
}
int main()
{
    //question1
    printf("Q1\n");
    student *arr[4];

    student *s1 = (student *)malloc(sizeof(student));
    s1->roll_no = 12;
    strcpy(s1->name, "aman");
    s1->marks[0] = 8;
    s1->marks[1] = 7;
    s1->marks[2] = 9;
    arr[0] = s1;

    student *s2 = (student *)malloc(sizeof(student));
    s2->roll_no = 8;
    strcpy(s2->name, "ajay");
    s2->marks[0] = 8;
    s2->marks[1] = 6;
    s2->marks[2] = 8;
    arr[1] = s2;

    student *s3 = (student *)malloc(sizeof(student));
    s3->roll_no = 4;
    strcpy(s3->name, "rahul");
    s3->marks[0] = 7;
    s3->marks[1] = 6;
    s3->marks[2] = 9;
    arr[2] = s3;

    student *s4 = (student *)malloc(sizeof(student));
    s4->roll_no = 1;
    strcpy(s4->name, "akash");
    s4->marks[0] = 7;
    s4->marks[1] = 6;
    s4->marks[2] = 9;
    arr[3] = s4;

    int n = 4;
    
    struct stud_record *ans = record_search(arr, n, 4);
    if (ans != NULL)
    {
        printf("%d\n", ans->roll_no);
        printf("%s\n", ans->name);
        printf("%.2f\n", ans->marks[0]);
        printf("%.2f\n", ans->marks[1]);
        printf("%.2f\n", ans->marks[2]);
    }
    //================================================================
    //question2
    printf("Q2\n");
    char arr1[100] = "0111110000";
    // printf("Enter string\n");
    // scanf("%s",&arr);

    printf("%d \n", check_string(arr1));

    //================================================================
    //question3
    printf("Q3\n");
    int num = 5;
    int arr3[5] = {3, 4, 5, 1, 2};
    int key = 4;
    int k = 3;
    printf("%d", modified_binary_search(arr3, num, key, k));
    return 0;
}