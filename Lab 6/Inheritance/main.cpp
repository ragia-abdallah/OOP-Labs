#include <iostream>

using namespace std;

class Base
{
private:
    int a;

protected:
    int b;

public:
    Base()
    {
        a = b = 0;
    };

    Base(int n)
    {
        a = b = n;
    };

    Base(int A, int B)
    {
        a = A;
        b = B;
    };

    void setA(int A)
    {
        a = A;
    };

    void setB(int B)
    {
        b = B;
    };

    int getA()
    {
        return a;
    };

    int getB()
    {
        return b;
    };

    int productAB()
    {
        return a * b;
    };

    int product()
    {
        return a * b;
    }

};

class Derived : public Base
{
private:
    int c;

public:
    Derived() : Base()
    {
        c = 0;
    };

    Derived(int n) : Base(n)
    {
        c = n;
    };

    Derived(int C, int A, int B) : Base(A, B)
    {
        c = C;
    };

    void setC(int C)
    {
        c = C;
    };

    int getC()
    {
        return c;
    };

    int productABC()
    {
        return productAB() * c;
    };

    int product()
    {
        return Base::product() * c;
    };
};

class SecondDerived : public Derived
{
private:
    int d;
public:
    SecondDerived() : Derived()
    {
        d = 0;
    };

    SecondDerived(int n) : Derived(n)
    {
        d = n;
    };

    SecondDerived(int D, int n) : Derived(n)
    {
        d = D;
    };

    SecondDerived(int D, int C, int A, int B) : Derived(C, A, B)
    {
        d = D;
    };

    void setD(int D)
    {
        d = D;
    };

    int getD()
    {
        return d;
    };

    int productABCD()
    {
        return getA() * b * getC() * d;
    }

    int product()
    {
        return Derived::product() * d;
    };
};

int main()
{
    Derived obj1;
    obj1.setA(3);
    obj1.setB(7);
    obj1.setC(1);

    cout<<obj1.productAB()<<endl;
    cout<<obj1.productABC()<<endl;

    Base bo1(5,4);
    Derived obj2(3,5,4);

    cout<<bo1.product()<<endl;
    cout<<obj2.product()<<endl;

    cout << "Hello world!" << endl;
    return 0;
}
