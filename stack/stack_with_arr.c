#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int top;
    int size;
    int *arr;

};

int isEmpty(struct stack *ptr){
    if(ptr->top==-1){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(struct stack * ptr){
    if(ptr->top == ptr->size-1){
        return 1;

    }
    else return 0;
}

void push(struct stack * ptr,int val){
    if(isFull(ptr)){
        printf("STACK OVERFLOW stack is full\n");
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top]=val;
    }
}

int pop(struct stack * ptr){
    if(isEmpty(ptr)){
        printf("STACK OVERFLOW cannot pop from the stack\n");
    }
    else{
        ptr->top--;
        int val=ptr->arr[ptr->top];
        return val;

    }
}

int peek(struct stack * ptr,int i){
    int array_index=ptr->top -i +1;
    if(array_index<0){
        printf("invalid position\n");
    }
    else{
        return ptr->arr[array_index];
    }
}

int stackBottom(struct stack * ptr){
    if(isEmpty(ptr)){
        printf("stack is empty\n");
        return -1;

    }
    else{
       return ptr->arr[0];
    }

}

int stackTop(struct stack* ptr){
    if (isEmpty(ptr))
    {
       printf("stack is empty\n");
       return -1;
    }

    else{
        return ptr->arr[ptr->top];
    }
}


int main()
{
    struct stack *ptr=(struct stack*) malloc(sizeof(struct stack));
    ptr->arr=(int*)malloc(ptr->size* sizeof(int));
    ptr->size=50;
    ptr->top=0;

    printf("Before pushing, Full: %d\n", isFull(ptr));
    printf("Before pushing, Empty: %d\n", isEmpty(ptr));
    push(ptr, 1);
    push(ptr, 23);
    push(ptr, 99);
    push(ptr, 75);
    push(ptr, 3);
    push(ptr, 64);
    push(ptr, 57);
    push(ptr, 46);
    push(ptr, 89);
    push(ptr, 6);
    push(ptr, 5);
    push(ptr, 75);

    // Printing values from the stack
    for (int j = 1; j <= ptr->top; j++)
    {
        printf("The value at position %d is %d\n", j, peek(ptr, j));
    }

    return 0;
}