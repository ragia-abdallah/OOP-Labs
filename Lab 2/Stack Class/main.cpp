#include <iostream>

using namespace std;

class Stack
{
    private:

    int Size;
    int tos;
    int* st;

    static int counter;

    public:

    Stack()
    {
        tos = 0;
        Size = 0;
        st = NULL;
        counter++;
        cout<<"Stack "<<counter<<"has been created"<<endl;
    };

    Stack(int s)
    {
        tos = 0;
        Size = s;
        st = new int[Size];
        counter++;
        cout<<"Stack "<<counter<<"has been created"<<endl;
    };

    ~Stack()
    {
        delete[] st;
        counter--;
        cout<<"Stack has been discarded. Total is "<<counter<<endl;
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

    int getCounter()
    {
        return counter;
    };

};

int Stack::counter = 0;

int main()
{
    //cout<<Stack::getCounter()<<endl;

    Stack s1(2);

    s1.push(5);
    s1.push(14);
    s1.push(20);

    cout<<s1.pop();

    Stack s2;

    s2.push(3);

    cout<<s1.getCounter()<<endl;

    cout<<"Gimme size of s3:"<<endl;
    int sz3;
    cin>>sz3;

    Stack s3(sz3);

    int i = 0;

    while(i<sz3)
    {
        i++;
        s3.push(i);
    }

    cout<<"Let's count down!"<<endl;

    i = 0;

    while(i<sz3)
    {
        cout<<s3.pop()<<endl;
        i++;
    }

    cout << "Bye bye world!" << endl;

    return 0;
}
