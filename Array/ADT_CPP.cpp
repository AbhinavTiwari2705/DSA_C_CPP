#include <iostream>
using namespace std;
 
class myarray{
    int total_size;
    int used_size;
    int *ptr;


    public:
        myarray(int Tsize,int Usize){
            total_size=Tsize;
            used_size=Usize;
            ptr = new int[Tsize];
        }

        void set_arr(){
            for(int i=0;i<used_size;i++){
                cout<<"Enter the fucking value :",ptr[i];
                cin>>ptr[i];
            }
        }
        void show_arr()
        {
            for (int i = 0; i < used_size; i++)
            {
                cout << ptr[i]<<" ";
                
            }
        }

};

int main(){
    myarray arr(20,5);
    arr.set_arr();
    arr.show_arr();

    return 0;
}