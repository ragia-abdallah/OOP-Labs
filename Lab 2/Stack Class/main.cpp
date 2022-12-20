#include <iostream>

using namespace std;

class Stack
{
    private:

    int Size;
    int tos;
    int* st;

    public:

    Stack(int s=10)
    {
        tos = 0;
        Size = s;
        st = new int[Size];
    };

    ~Stack()
    {
        delete[] st;
        cout<<"Stack has been discarded"<<endl;
    };

    void push(int x)
    {
        if(tos == Size)
        {
            cout<<"Stack is full"<<endl;
        }
        else
        {
            tos++;
            st[tos] = x;
        }
    };

    int pop()
    {
        int top = -1;
        if(tos == 0)
        {
            cout<<"Stack is empty"<<endl;
        }
        else
        {
            top = st[tos];
            tos--;
        }
        return top;
    };

};


int main()
{



    cout << "Hello world!" << endl;
    return 0;
}
