#include <iostream>
using namespace std;
 
class my_arr{

    public:

    int t_size;
    int u_size;
    int* ptr;

    my_arr(int t_size,int u_size){

        t_size=t_size;
        u_size=u_size;
        ptr=new int[t_size];

    }

    int ins(int element,int index){
        bool flag =true;

        if (u_size >= t_size)
        {
            cout << "OUT OF CAPACITY\n";
            flag =false;

            return -1;
            
            
            
        }

        for(int i=u_size-1;i>=index;i--){
            if (flag){
            ptr[i+1]=ptr[i];}

            else{
                break;
            }
        }
        ptr[index]=element;
        u_size+=1;

        return 1;

        // cout<<"ins ka u_size : "<<u_size<<endl;
    }

    void val(){
        // cout<<"val chal rha \n";
        for(int i=0;i<5;i++){
            cout<<i<<endl;
            scanf("%i", &ptr[i]);
            // cout<<i<<endl;
        }
    }

    void del( int index)
    {
       
        for (int i = u_size - 1; i >= index; i--)
        {
            ptr[i] = ptr[i+1];
        }
        
        u_size -= 1;
        //cout << "del ka u_size : " << u_size << endl;
    }

    void display(){
        for(int i=0;i<6;i++){
            cout<<ptr[i]<<" ";
        }
        cout<<"\n";
    }
};

int main(){
    my_arr arr(10,5);
    arr.val();
    arr.display();
    arr.ins(69,2);
    arr.display();
    arr.del(2);
    arr.display();


}