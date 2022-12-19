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
        cout<<"Complex has been dropped"<<endl;
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

    void printComplext()
    {
        if(imag<0)
            cout<<real<<"-"<<abs(imag)<<"i"<<endl;
        else if (imag>0)
            cout<<real<<"+"<<abs(imag)<<"i"<<endl;
        else
            cout<<real<<endl;
    };

};


int main()
{
    Complex myComp1(1), myComp2(1,2), resultComp;

    myComp1.printComplext();
    myComp2.printComplext();

    float temp, temp1, temp2;

    cout << "Give me first real value: " << endl;
    cin >> temp1;

    cout << "Give me first imaginary value: " << endl;
    cin >> temp2;

    myComp1.setComplex(temp1, temp2);

    cout << "Give me second real value: " << endl;
    cin >> temp;

    myComp2.setReal(temp);

    cout << "Give me second imaginary value: " << endl;
    cin >> temp;

    myComp2.setImag(temp);

    myComp1.printComplext();
    myComp2.printComplext();

    resultComp = myComp1.add(myComp2);
    resultComp.printComplext();

    resultComp = myComp1.sub(myComp2);
    resultComp.printComplext();

    return 0;
}
