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
        tos = z.tos;
        Size = z.Size;
        st = new int[Size];
        for(int i=0;i<=tos;i++)
        {
            st[i] = z.st[i];
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

    void operator = (const Stack &s)
    {
        delete[] this->st;

        this->tos = s.tos;
        this->Size = s.Size;
        this->st = new int[Size];
        for (int i=0; i<=tos; i++)
        {
            this->st[i] = s.st[i];
        }
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
        int top = NULL;
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

    friend void viewContentbyRef(Stack &x);
    friend void viewContentbyCopy(Stack x);

};

int Stack::constCounter = 0;
int Stack::destCounter = 0;

void viewContentbyRef(Stack &x)
{
    int t = x.tos;
    for (t;t>0;t--)
    {
        cout<<x.st[t]<<endl;
    }
}

void viewContentbyCopy(Stack x)
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

    Stack s1(5);

    s1.push(5);
    s1.push(14);
    s1.push(39);
    s1.push(21);
    s1.push(144);

    viewContentbyRef(s1);

    Stack s2(5);

    s2.push(349);
    s2.push(25);
    s2.push(184);

    s2 = s1;

    viewContentbyRef(s2);


    cout << "Bye bye world!" << endl;

    return 0;
}
