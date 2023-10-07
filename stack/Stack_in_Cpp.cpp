#include <iostream>

using namespace std;

class Stack
{
public:
    int *arr;
    int top;
    int size;

    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int element)
    {
        if (top == size - 1)
        {
            cout << "Stack is full" << endl;
        }
        else
        {
            top++;
            arr[top] = element;
        }
    }

    int pop()
    {
        if (top == -1)
        {
            cout << "Stack is empty" << endl;
            return -1; // Return a sentinel value to indicate an error condition.
        }
        else
        {
            int poppedElement = arr[top];
            top--;
            return poppedElement;
        }
    }

    int peek()
    {
        if (top == -1)
        {
            cout << "Stack is empty" << endl;
            return -1; // Return a sentinel value to indicate an error condition.
        }
        else
        {
            return arr[top];
        }
    }

    bool isEmpty()
    {
        return top == -1;
    }

    void display()
    {
        for (int i = 0; i <= top; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    ~Stack()
    {
        delete[] arr; // Destructor to release memory when the object is destroyed.
    }
};

int main()
{
    Stack stack(5);

    stack.push(1);
    stack.push(2);
    stack.push(3);

    cout << "Stack: ";
    stack.display();

    cout << "Top element: " << stack.peek() << endl;

    stack.pop();
    cout << "Popped element" << endl;

    cout << "Stack: ";
    stack.display();

    cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
