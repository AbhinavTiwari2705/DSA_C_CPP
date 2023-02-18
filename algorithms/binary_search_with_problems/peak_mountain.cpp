//wont work if the elements are repeated


#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int findPeakElement(vector<int> &nums)
{

    int start = 0;
    // int size=sizeof(arr)/sizeof(int);
    int end = nums.size() - 1;

    int mid = start + (end - start) / 2;

    while (start < end)
    {
        if (nums[mid] < nums[mid + 1])
        {
            start = mid + 1;
        }
        else
        {
            end = mid;
        }
        mid = start + (end - start) / 2;
    }

    return start;
}

int main()
{
    vector<int> arr = {1, 2, 3, 3, 3, 3, 4, 56, 66};
    cout<<findPeakElement(arr);

    return 0;
}