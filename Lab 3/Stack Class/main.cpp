#include <iostream>

using namespace std;

class Stack
{
    private:

    int Size;
    int tos;
    int *st;
    //Stack *ptr;

    static int constCounter;
    static int destCounter;

    public:

    Stack()
    {
        tos = 0;
        Size = 0;
        st = NULL;
        constCounter++;
        cout<<constCounter<<" stack(s) created."<<endl;
    };

    Stack(int s)
    {
        tos = 0;
        Size = s;
        st = new int[Size];
        constCounter++;
        cout<<constCounter<<" stack(s) created."<<endl;
    };

    Stack(Stack &z)//copy constructor
    {
        tos = 0;
        Size = z.Size;
        st = new int[Size];
        int i = 0;
        for(i=0;i<z.tos;i++)
        {
            push(z.st[i]);
        }
        constCounter++;
        cout<<constCounter<<" stack(s) created."<<endl;
    };

    ~Stack()
    {
        delete[] st;
        destCounter++;
        cout<<destCounter<<" stack(s) discarded."<<endl;
    };

    void setSize(int s)
    {
        Size = s;
        cout<<"Stack size was changed"<<endl;
    }

    int getSize()
    {
        return Size;
    }

    int getTos()
    {
        return tos;
    }

    void push(int x)
    {
        if (st == NULL)
        {
            st = new int[Size];
        }
        if(tos == Size)
        {
            cout<<"Stack is full"<<endl;
        }
        else
        {
            tos++;
            st[tos] = x;
            cout<<"Item was pushed"<<endl;
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

    int getConstCounter()
    {
        return constCounter;
    };

    int getDestCounter()
    {
        return destCounter;
    };

    friend void viewContent(Stack &x);
    friend void viewContentCopy(Stack x);

};

int Stack::constCounter = 0;
int Stack::destCounter = 0;

void viewContent(Stack &x)
{
    int t = x.tos;
    while (t > 0)
        {
            //cout<<x.st[--t]<<endl; --> syntax not working
            cout<<x.st[t]<<endl;
            t--;
        }
}

void viewContentCopy(Stack x)
{
    int t = x.tos;
    while (t > 0)
        {
            cout<<x.pop()<<endl;
            t--;
        }
}

int main()
{

    Stack s1(2);

    s1.push(5);
    s1.push(14);

    cout<<"Viewing s1 using reference"<<endl;
    viewContent(s1);

    Stack s2(2);

    s2.push(5);
    s2.push(14);

    cout<<"Viewing s2 using copy const."<<endl;
    viewContentCopy(s2);

    cout<<"Gimme size of s3:"<<endl;
    int sz3;
    cin>>sz3;

    Stack s3(sz3);

    int i = 0;

    while(i<s3.getSize())
    {
        i++;
        s3.push(i);
    }

    cout<<"Let's count down!"<<endl;

    i = 0;

    while(i<=s3.getTos())
    {
        cout<<s3.pop()<<endl;
        i++;
    }

    cout << "Bye bye world!" << endl;

    return 0;
}
