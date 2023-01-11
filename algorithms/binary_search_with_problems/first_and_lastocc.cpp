// Find first and last occurence of an element

#include <bits/stdc++.h>
#include <iostream>
using namespace std;
    

    int first_occ(vector<int> &arr, int size, int key)
{
    int start = 0;
    int end = size - 1;
    int ans = -1;

    int mid = (start + (end - start) / 2);

    while (start <= end)
    {
        if (arr[mid] == key)
        {
            ans = mid;
            end = mid - 1;
        }
        else if (arr[mid] > key)
        {
            end = mid - 1;
        }
        else if (arr[mid] < key)
        {
            start = mid + 1;
        }

        mid = (start + ((end - start) / 2));
    }
    return ans;
}

int last_occ(vector<int> &arr, int size, int key)
{
    int start = 0;
    int end = size - 1;
    int ans = -1;

    int mid = (start + (end - start) / 2);

    while (start <= end)
    {
        if (arr[mid] == key)
        {
            ans = mid;
            start = mid + 1;
        }
        else if (arr[mid] > key)
        {
            end = mid - 1;
        }
        else if (arr[mid] < key)
        {
            start = mid + 1;
        }

        mid = (start + ((end - start) / 2));
    }
    return ans;
}

int frequency(vector<int> arr,int size,int key){
    return last_occ(arr, size, key) - first_occ(arr, size, key)+1;
}


int main()
{
    vector<int> arr={1,2,3,3,3,3,4,56,66};
    cout<<first_occ(arr,sizeof(arr)/sizeof(int),3)<<endl;
    cout<<last_occ(arr,sizeof(arr)/sizeof(int),3)<<endl;
    cout << frequency(arr, sizeof(arr) / sizeof(int), 3)<<endl;

            return 0;
}