#include <iostream>
#include<stdlib.h>
using namespace std;

int main(){
    int * ptr=(int *)malloc(6*sizeof(int));
    float *ptr2= (float *)malloc(6*sizeof(float));
    for (int i = 0; i < 6; i++)
    {
        cout<<"Enter the value of "<<i <<" elemnt: \n";
        cin>>ptr2[i];
    }

    for (int i = 0; i < 6; i++)
    {
        cout << "The value of "<<i<< "elemnt is :"<< ptr2[i]<<endl;

        
    }

    int* cptr=(int *)calloc(6,sizeof(int));
    for (int i = 0; i < 6; i++)
    {
        cout<<"Enter the value of "<<i <<" elemnt: \n";
        cin>>ptr2[i];
    }

    for (int i = 0; i < 6; i++)
    {
        cout << "The value of "<<i<< "elemnt is :"<< ptr2[i]<<endl;

        
    }

    ptr = (int*)realloc(ptr,10*sizeof(int));

    for (int i = 0; i < 10; i++)
    {
        cout << "Enter the value of " << i << " elemnt: \n";
        cin >> ptr2[i];
    }

    for (int i = 0; i < 10; i++)
    {
        cout << "The value of " << i << "elemnt is :" << ptr2[i] << endl;
    }
}

#include <iostream>
using namespace std;

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int x, y, z, num{0};
        cin >> x >> y >> z;
        int a[x];
        int k;
        k = z;
        for (int i = 0; i < x; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < x; i++)
        {

            if ((y - a[i] > z))
            {
                a[i] = y;
                num += z;
            }
        }

        int sum = 0;
        for (int i = 0; i < x; i++)
        {
            sum += a[i];
        }

        cout << sum - num << endl;
    }

    return 0;
}
