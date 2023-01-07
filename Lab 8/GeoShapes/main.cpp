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

    virtual float calculateArea() = 0;
//    virtual float calculateArea()
//    {
//        cout<<"This is the GeoShape area function"<<endl;
//        return dim1 * dim2;
//    }
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
        cout<<"This is the Triangle area function"<<endl;
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
        cout<<"This is the Rectangle area function"<<endl;
        return dim1 * dim2;
    }
};

class Square : public Rectangle
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
        cout<<"This is the Square area function"<<endl;
        return dim1 *dim2;
    }
};

class Circle : public GeoShape
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
        cout<<"This is the Circle area function"<<endl;
        return 22.0 * dim1 * dim2 / 7;
    }
};

float sumAreas(GeoShape *p1, GeoShape *p2, GeoShape *p3)
{
    return p1->calculateArea() + p2->calculateArea() + p3->calculateArea();
}

float sumRectangleAreas(Rectangle *p1, Rectangle *p2)
{
    return p1->calculateArea() + p2->calculateArea();
}

int main()
{
    Triangle trig(3,7);
    cout<<trig.calculateArea()<<endl;

    Rectangle rect(5,3);
    cout<<rect.calculateArea()<<endl;

    Square sqr(9);
    cout<<sqr.calculateArea()<<endl;

    Circle circ(4);
    cout<<circ.calculateArea()<<endl;

    cout<<sumAreas(&trig, &sqr, &circ)<<endl;

    cout<<sumRectangleAreas(&rect, &sqr)<<endl;

    return 0;
}
