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
    else
        return 0;
}
int is_Full(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
        return 0;
}

void push(struct stack *ptr, char val)
{
    if (is_Full(ptr))
    {
        return;
    }
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
        return 0;
    }
    else
    {
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int match(char a, char b)
{
    if (a == '{' && b == '}')
    {
        return 1;
    }
    if (a == '(' && b == ')')
    {
        return 1;
    }
    if (a == '[' && b == ']')
    {
        return 1;
    }
    return 0;
}

int Multi_paranthesis(char *exp)
{

    struct stack *sp;
    sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 50;
    sp->top = -1;
    sp->arr = (char *)(malloc(sp->size * sizeof(char)));

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(sp, exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (is_Empty(sp))
            {
                return 0;
            }
            char popped_ch = pop(sp);
            if (!match(popped_ch, exp[i]))
            {
                return 0;
            }
        }
    }
    if (is_Empty(sp))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{

    char *exp = "[4-6]((8){(9-8)})";

    if (Multi_paranthesis(exp))
    {
        printf("The parenthesis is balanced");
    }
    else
    {
        printf("The parenthesis is not balanced");
    }

    return 0;
}
