#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void traversal(struct Node *ptr)
{
    while (ptr != NULL)
    {

        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

int isEmpty(struct Node *top)
{
    if (top == NULL)
    {
        return 1;
    }

    else{
        return 0;
        }
}

int isFull(struct Node *top)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));

    if (ptr == NULL)
    {
        return 1;
    }
    else{
        return 0;}
}

struct Node *push(struct Node *top, int x)
{
    if (isFull(top))
    {
        printf("Stack Overflow\n");
    }
    else
    {
        struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
        ptr->data = x;
        ptr->next=top;
        top = ptr;
        return top;
    }
}

int pop(struct Node ** top)
{
    if (isEmpty(*top))
    {
        printf("Stack Underflow\n");
    }

    else
    {

        struct Node *n = *top;
        *top = (*top)->next;
        int x = n->data;
        free(n);
        return x;
    }
}

int main()
{
    struct Node *top = NULL;
    top = push(top, 78);
    top = push(top, 7);
    top = push(top, 6);
    top = push(top, 9);

    traversal(top);
    printf("\n");

    int elem = pop(&top);
    printf("Poped element is: %d\n", elem);
    // int elem2 = pop(&top);
    traversal(top);
    

    return 0;
}