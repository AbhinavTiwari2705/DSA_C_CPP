#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int top;
    int size;
    char *arr;
};

int is_Empty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    return 0;
}

int is_Full(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    return 0;
}

void push(struct stack *ptr, char val)
{
    if (is_Full(ptr))
        printf("Stack is full!");
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

char pop(struct stack *ptr)
{
    if (is_Empty(ptr))
    {
        printf("STACK IS EMPTY");
        return -1;
    }
    else
    {
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int paranthes_is_matching(char *exp)
{
    struct stack sp;
    sp.size = 100;
    sp.top = -1;
    sp.arr = (char *)malloc(sp.size * sizeof(char));

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            push(&sp, '(');
        }

        else if (exp[i] == ')')
        {
            if (is_Empty(&sp))
            {
                return 0;
            }
            pop(&sp);
        }
    }

    return is_Empty(&sp);
}

int main()
{
    char *exp = "((8)(*--$$9))";
    // Check if stack is empty
    if (paranthes_is_matching(exp))
    {
        printf("The parenthesis is matching");
    }
    else
    {
        printf("The parenthesis is not matching");
    }

    return 0;
}
