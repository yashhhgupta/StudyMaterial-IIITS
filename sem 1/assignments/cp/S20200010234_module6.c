//ques 1
/*#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
void replace(int argc, char **argv)
{
    // ./a.out filename.txt old_word new_word
    if (argc < 4)
    {
        printf("Proper usage:./a.out filename\n");
    }
    else
    {
        FILE *fp = fopen(argv[1], "r+");
        char c[25];
        while (fscanf(fp, "%s", c) != EOF)
        {
            if (strcmp(c, argv[2]) == 0)
            {
                fseek(fp, -1 * strlen(c), SEEK_CUR);
                fprintf(fp, "%s", argv[3]);
            }
        }
    }
}
int main(int argc, char **argv)
{

    replace(argc, argv);

    return 0;
}*/

//ques 3
/*#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void sol2(char *filename, char *stopword)
{
    FILE *fptr;
    FILE *cptr;
    FILE *sptr;

    char temp[50];
    char temp2[50];

    int check;

    cptr = fopen("temp.txt", "w");
    fclose(cptr);

    cptr = fopen("temp.txt", "a");
    fptr = fopen(filename, "r");
    sptr = fopen(stopword, "r");

    if (fptr == NULL || sptr == NULL)
    {
        printf("Can't open files for reading.\n");
        exit(1);
    }
    else
    {
        while (fscanf(fptr, "%s", temp) != EOF)
        {

            check = 0;

            while (fscanf(sptr, "%s", temp2) != EOF)
            {

                if (strcmp(temp, temp2) == 0)
                {
                    check = 1;

                    break;
                }
            }
            rewind(sptr);

            if (check == 0)
            {
                fprintf(cptr, "%s ", temp);
            }
        }
    }

    fclose(sptr);
    fclose(fptr);
    fclose(cptr);

    cptr = fopen("temp.txt", "r");
    fptr = fopen(filename, "w");

    while (fscanf(cptr, "%s", temp) != EOF)
    {
        fprintf(fptr, "%s ", temp);
    }

    fclose(cptr);
    fclose(fptr);
}
int main(int argc, char *argv[])
{

    char *filename;
    char *stopword;

    if (argc > 1)
        filename = argv[1];
    if (argc > 2)
        stopword = argv[2];

    sol2(filename, stopword);

    return 0;
}*/
//ques5
/*#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
  FILE *fp;
  int j, x, o;
  char stringarray[500][50];
  char element[50];
  char s[20];
  printf("enter file path");
  scanf("%s",s);
  fp = fopen(s,"r");
  if(fp == NULL)
    {
      printf("unable to open file\n");
      printf("please check you have read previleges\n");
      exit(1);
    }
  int a[500],i=0;
  for(i=0; i<500; i++)
    a[i] = 0;
  x = 0;
  while(fscanf(fp, "%s", element) != EOF)
  {
    j = strlen(element);
    if (ispunct(element[j - 1]))
      element[j-1] = '\0';
    o = 1;
    for(i=0; i<x && o; i++)
    {
      if(strcmp(stringarray[i],element)==0)
      o = 0;
    } 
    if(o)
    {
      strcpy(stringarray[x],element);
      a[x]++;
      x++;
    }
    else
    {
      a[i-1]++;
    }
  }  
  fclose(fp);
  for(i=0;i<x;i++)
    printf("%s repeated %d\n",stringarray[i],a[i]);
return 0;
}*/