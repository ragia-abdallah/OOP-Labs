#include <iostream>

using namespace std;

class GeoShape
{
protected:
    float dim1;
    float dim2;

public:
    GeoShape()
    {
        dim1 = dim2 = 0;
    }

    GeoShape(float x)
    {
        dim1 = dim2 = x;
    }

    GeoShape(float x, float y)
    {
        dim1 = x;
        dim2 = y;
    }

    void setDim1(float x)
    {
        dim1 = x;
    }

    void setDim2(float y)
    {
        dim2 = y;
    }

    float getDim1()
    {
        return dim1;
    }

    float getDim2()
    {
        return dim2;
    }

    float calculateArea()
    {
        return 0;
    }
};

class Triangle : public GeoShape
{
public:
    Triangle() : GeoShape()
    {    }

    Triangle(float base, float height) : GeoShape(base, height)
    {    }

    float calculateArea()
    {
        return 0.5 * dim1 * dim2;
    }
};

class Rectangle : public GeoShape
{
public:
    Rectangle() : GeoShape()
    {   }

    Rectangle(float x, float y) : GeoShape(x,y)
    {   }

    float calculateArea()
    {
        return dim1 * dim2;
    }
};

class Square : private Rectangle
{
public:
    Square() :Rectangle()
    {   }

    Square(float x) :Rectangle(x,x)
    {   }

    void setSquareDim(float x)
    {
        dim1 = dim2 = x;
    }

    float getSquareDim()
    {
        return dim1;
    }

    float calculateArea()
    {
        return Rectangle::calculateArea();
    }
};

class Circle : private GeoShape
{
public:
    Circle() : GeoShape()
    {   }

    Circle(float r) : GeoShape(r)
    {    }

    void setRadius(float r)
    {
        dim1 = dim2 = r;
    }

    float getRadius()
    {
        return dim1;
    }

    float calculateArea()
    {
        return 22.0 * dim1 * dim2 / 7;
    }
};

int main()
{
    Triangle trig;
    cout<<trig.calculateArea()<<endl;

    trig.setDim1(3);
    trig.setDim2(7);
    cout<<trig.getDim1()<<endl;
    cout<<trig.getDim2()<<endl;
    cout<<trig.calculateArea()<<endl;

    Rectangle rect(5,3);
    cout<<rect.calculateArea()<<endl;

    Square sqr;
    cout<<sqr.getSquareDim()<<endl;
    cout<<sqr.calculateArea()<<endl;

    sqr.setSquareDim(9);
    cout<<sqr.getSquareDim()<<endl;
    cout<<sqr.calculateArea()<<endl;

    Circle circ(4);
    cout<<circ.calculateArea()<<endl;

    circ.setRadius(7);
    cout<<circ.getRadius()<<endl;
    cout<<circ.calculateArea()<<endl;

    return 0;
}
