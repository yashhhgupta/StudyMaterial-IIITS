#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

int Stacktop(struct stack *ptr)
{
    return ptr->arr[ptr->top];
}

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack *ptr, char val)
{
    if (isFull(ptr))
    {
        printf("Stack overflow.");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

char pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow.");
        return -1;
    }
    else
    {
        char temp = ptr->arr[ptr->top];
        ptr->top--;
        return temp;
    }
}

int isOperator(char a)
{
    if (a == '+' || a == '-' || a == '/' || a == '*' || a == '%')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int precedence(char a)
{
    if (a == '*' || a == '/' || a == '%')
    {
        return 3;
    }
    else if (a == '+' || a == '-')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}

char *intopost(char *infix)
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 20;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));

    char *postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));
    int i = 0; //for infix
    int j = 0; //for postfix
    int x = 0; 

    while (infix[i] != '\0')
    {
        if (!isOperator(infix[i]))
        {
            postfix[j] = infix[i];
            i++;
            j++;
        }
        else if (infix[i] == '(')
            push(sp, '(');
        else if (infix[i] == ')')
            while ((x = pop(sp)) != '(')
                postfix[j++] = x;
        else
        {
            if (precedence(infix[i]) > precedence(Stacktop(sp)))
            {
                push(sp, infix[i]);
                i++;
            }
            else
            {
                postfix[j] = pop(sp);
                j++;
            }
        }
    }

    while (!isEmpty(sp))
    {
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}

int main(){
        char *infix = "(a–(b/c)*d+e)*f%g";
    printf("postfix is %s\n", intopost(infix));
}