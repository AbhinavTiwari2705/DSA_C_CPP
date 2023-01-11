#include <iostream>
using namespace std;

int binary_search(int arr[],int size,int key){
    int start=0;
    int end=size-1;

    int mid=(start+(end-start)/2);

    while(start<=end){
        if(arr[mid]==key){
            return mid;
        }
        else if(arr[mid]>key){
            end=mid-1;
        }
        else if(arr[mid]<key){
            start=mid+1;
        }


        mid=(start+((end-start)/2));

    }
    return -1; // key is not found in the given array



}

 
int main(){
    int arr[6]={2,4,6,8,12,18};
    int  size=sizeof(arr)/sizeof(int);
    cout<<binary_search(arr,size,18)+1<<endl;
    return 0;
}


// Time Complexity of this algo is O(logn)