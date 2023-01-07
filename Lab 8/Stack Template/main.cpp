#include <iostream>

using namespace std;

template <class T>
class Stack
{
private:
    int top;
    int Size;
    T *ptr;
    static int counter;

public:
    Stack();
    Stack(int n);
    ~Stack();

    static int getCounter();
    Stack(Stack&);

    void push(T);
    T pop();

    Stack& operator= (Stack&);
    friend void viewContent(Stack);

};

template <class T>
int Stack<T>::counter = 0;

template <class T>
Stack<T>::Stack()
{
    top = 0;
    Size = 10;
    ptr = new T[Size];
    counter++;
}



int main()
{
    Stack<int> s1;

//    cout<<"Number of Integer Stacks: "<< Stack<int>::getCounter()<<endl;
//
//    s1.push(10);
//    s1.push(3);
//    s1.push(2);
//
//    cout<<"1st int : "<<s1.pop()<<endl;
//    cout<<"2nd int : "<<s1.pop()<<endl;

    Stack<char> s2;

//    cout<<"Number of Character Stacks: "<< Stack<int>::getCounter()<<endl;
//
//    s2.push('q');
//    s2.push('r');
//    s2.push('s');
//
//    viewContent(s2);
//
//    cout<<"1st char : "<<s2.pop()<<endl;
//    cout<<"2nd char : "<<s2.pop()<<endl;

    return 0;
}
