#include <iostream>

using namespace std;

class Complex
{
private:

    float real;
    float imag;

public:
    Complex()
    {
        real = 0;
        imag = 0;
    };

    Complex(float x)
    {
        real = x;
        imag = x;
    };

    Complex(float r, float i)
    {
        real = r;
        imag = i;
    };

    ~Complex()
    {
        //cout<<"Complex has been dropped"<<endl;
    };

    void setReal(float r)
    {
        real = r;
    };

    void setImag(float i)
    {
        imag = i;
    };

    void setComplex(float r, float i)
    {
        real = r;
        imag = i;
    };


    float getReal()
    {
        float r = real;
        return r;
    };

    float getImag()
    {
        float i = imag;
        return i;
    };

    Complex add(Complex b)
    {
        Complex temp;
        temp.real=real+b.real;
        temp.imag=imag+b.imag;
        return temp;
    };

    Complex sub(Complex b)
    {
        Complex temp;
        temp.real=real-b.real;
        temp.imag=imag-b.imag;
        return temp;
    };

    void printComplex()
    {
        if(imag<0)
            cout<<real<<"-"<<abs(imag)<<"i"<<endl;
        else if (imag>0)
            cout<<real<<"+"<<abs(imag)<<"i"<<endl;
        else
            cout<<real<<endl;
    };

    Complex operator + (Complex c)
    {
        Complex op;
        op.real = real + c.real;
        op.imag = imag + c.imag;
        return op;

    };

    Complex operator - (Complex c)
    {
        Complex op;
        op.real = real - c.real;
        op.imag = imag - c.imag;
        return op;

    };

    Complex operator + (float x)
    {
        Complex op;
        op.real = real + x;
        op.imag = imag;
        return op;

    };

    Complex operator - (float x)
    {
        Complex op;
        op.real = this->real - x;
        op.imag = this->imag;
        return op;

    };

    int operator == (Complex c)
    {
        if(real == c.real && imag == c.imag)
            return 1;
        else
            return 0;
    };

    Complex operator += (Complex c)
    {
        real += c.real;
        imag += c.imag;
        return *this;
    };

    Complex operator -= (Complex c)
    {
        real -= c.real;
        imag -= c.imag;
        return *this;
    };

    Complex operator ++ ()
    {
        real++;
        return *this;
    };

    Complex operator ++ (int)
    {
        Complex op = *this;
        real++;
        return op;
    };

    Complex operator -- ()
    {
        real--;
        return *this;
    };

    Complex operator -- (int)
    {
        Complex op = *this;
        real--;
        return op;
    };

    operator float()
    {
        return real;
    };

    friend Complex operator + (float x, Complex c);
    friend Complex operator - (float x, Complex c);

};

Complex operator + (float x, Complex c)
{
    Complex op;

    op.real = c.real + x;
    op.imag = c.imag;

    return op;
};

Complex operator - (float x, Complex c)
{
    Complex op;

    op.real = x - c.real;
    op.imag = c.imag;

    return op;
};

int main()
{
    Complex c1(1,9), c2(1,2), c3(4,6), c4(2,7);

    c3 = c1 + c2;
    c3.printComplex();

    c3 = c1 - c2;
    c3.printComplex();

    c3 = c1 + 5;
    c3.printComplex();

    c3 = c1 - 5;
    c3.printComplex();

    c3 = 5 + c1;
    c3.printComplex();

    c3 = 5 - c1;
    c3.printComplex();

    if(c1 == c2)
        cout<<"== operator returned true"<<endl;
    else
        cout<<"== operator returned false"<<endl;

    c1 += c2;
    c1.printComplex();

    c1 -= c2;
    c1.printComplex();

    c3 = ++c1;
    c3.printComplex();
    c1.printComplex();

    c3 = --c1;
    c3.printComplex();
    c1.printComplex();

    c3++;
    c3.printComplex();

    c3--;
    c3.printComplex();

    cout<<(float)c3<<endl;

    return 0;
}
