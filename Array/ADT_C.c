#include<stdio.h>
#include<stdlib.h>


struct my_array{
    int total_size;
    int used_size;
    int *ptr;

};


void createArray(struct my_array *a,int t_size,int U_size){
    (*a).total_size=t_size;    
    (*a).used_size=U_size;    
    (*a).ptr=(int*)(malloc(t_size*(sizeof(int))));

    a->total_size=t_size;
    a->used_size=U_size;
    a->ptr=(int*)(malloc(t_size*(sizeof(int))));
}


void show(struct my_array*a){
    for(int i =0;i<a->used_size;i++){
        printf("%d",(a->ptr[i]));

    }
}

void set(struct my_array *a)
{
    for (int i = 0; i < a->used_size; i++)
    {
        int n;
        printf("enter fucking element %d",i);
        scanf("%d", &n);
        (a->ptr)[i]=n;


    }
}


int main(){
    struct my_array arr;
    createArray(&arr,10,2);
    set(&arr);
    show(&arr);
    return 0;

}