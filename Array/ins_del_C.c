#include<stdio.h>

void display(int arr[],int n){

    //traversal

    for(int i=0; i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int ins(int arr[],int size,int element,int capacity,int index){
    //code for insertion

    if (size>=capacity){
        return -1;
    }
    for(int i=size-1;i>=index;i--){
        arr[i+1]=arr[i];
    }
    arr[index]=element;

    return 1;

    
}
void del(int arr[],int index,int *size){
    
    // code for Deletion

    for(int i =index;i<*size;i++){
        arr[i]=arr[i+1];
    }
    size-=1;

}

int main()
{
    int arr[100] = {7, 8, 12, 27, 88};
    int size = 5, element = 45, index = 1;
    display(arr, size);
    ins(arr, size, element, 100, index);
    size += 1;
    display(arr, size);
    del(arr,1,&size);
    display(arr, size);
    return 0;
}