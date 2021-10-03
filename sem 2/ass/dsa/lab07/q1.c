#include <stdio.h>
struct stud_record
{
    int roll_no;
    char name[20];
    float marks[3];
};

struct stud_record *record_search(struct stud_record record_array[], int n, int roll)
{
    int l = 0;
    int r = n - 1;
    int temp=0;
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (record_array[m].roll_no == roll)
        {
            temp=1;
            return record_array[m];
        }
        else if (record_array[m].roll_no > roll)
        {

            l = m + 1;
        }
        else
        {

            r = m - 1;
        }
    }
    if (temp==0)
    {
        return NULL;
    }
    
}


int main()
{
    struct stud_record student[] ={{5,"rahul",{5,5.8,7.6}},{4,"aman",{5,5.8,5.6}},{3,"ajay",{8,8.8,7.6}}};
    int n = sizeof(student) / sizeof(student[0]);
    struct stud_record *temp=record_search(student, n, 2);
}
