#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

int stackTop(struct stack * sp){
    return sp->arr[sp->top];
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

int isEmpty(struct stack* sp){
    if(sp->top==-1){
        return 1;
    }
    else{
        return 0;
    }
}

int push(struct stack * sp,int val){
    if(isFull(sp)){
        printf("Stack Overflow!");
    }
    else{
        sp->top++;
        sp->arr[sp->top]=val;
    }
}


int pop(struct stack* ptr){
    if(isEmpty(ptr)){
        printf("stack underflow!");

    }
    else{
        char val=ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int precedence(char ch){
    if (ch == '*' || ch=='/')
      return 3;
    else if(ch=='+'|| ch=='-') 
      return 2;
    else 
      return 0;
}

int isOperator(char ch){
    if(ch=='+'||ch=='-'||ch=='/'||ch=='*'){
        return 1;
    }
    else return 0;
}

char * infinixToPostfix(char* infix){
    struct stack * sp = (struct stack *) malloc(sizeof(struct stack));
    sp->size=sizeof(infix)/sizeof(char);
    sp->top=-1;
    sp->arr=(char *) malloc(sp->size* sizeof(char));
    char *postfix = (char *)malloc((sizeof(infix) / sizeof(char)) * sizeof(char));
    int j=0; //Track infix traversal
    int i=0; //Track postfix addition

    while(infix[i]!='\0'){
        if(!isOperator(infix[i])){
            postfix[j]=infix[i];
            j++;
            i++;
        }
        else{
            if(precedence(infix[i])>precedence(stackTop(sp))){
                push(sp,infix[i]);
                i++;
            }
            else{
                postfix[j]=pop(sp);
                j++;
            }
        }
    }
    while(!isEmpty(sp)){
        postfix[j]=pop(sp);
        j++;
    }
    postfix[j]='\0';
    return postfix;
    
}




int main()
{
    char* infix="x-y/z-k*d";
    printf("postfix is %s",infinixToPostfix(infix));


return 0;
}