#include <iostream>

using namespace std;

class Complex
{
private:
    float real;
    float imag;
public:
    void setReal(float r);
    void setImag(float i);
    float getReal();
    float getImag();
    Complex add(Complex b);
    Complex sub(Complex b);
    void printComplext();
};

void Complex::setReal(float r)
{
    real = r;
};

void Complex::setImag(float i)
{
    imag = i;
};

float Complex::getReal()
{
    float r = real;
    return r;
};

float Complex::getImag()
{
    float i = imag;
    return i;
};

void Complex::printComplext()
{
    if(imag<0)
        cout<<real<<"-"<<abs(imag)<<"i"<<endl;
    else if (imag>0)
        cout<<real<<"+"<<abs(imag)<<"i"<<endl;
    else
        cout<<real<<endl;
};

Complex Complex::add(Complex b)
{
    Complex temp;
    temp.real=real+b.real;
    temp.imag=imag+b.imag;
    return temp;
};

Complex Complex::sub(Complex b)
{
    Complex temp;
    temp.real=real-b.real;
    temp.imag=imag-b.imag;
    return temp;
};

int main()
{
    Complex myComp1, myComp2, resultComp;
    float temp;

    cout << "Give me first real value: " << endl;
    cin >> temp;
    myComp1.setReal(temp);
    cout << "Give me first imaginary value: " << endl;
    cin >> temp;
    myComp1.setImag(temp);
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
