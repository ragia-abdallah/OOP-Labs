#include <iostream>
//#include <graphics.h>

using namespace std;

class Point
{
private:
    int x;
    int y;

public:
    Point()
    {
        x = 0;
        y = 0;
        cout<<"Point was created"<<endl;
    };

    Point(int X, int Y)
    {
        x = X;
        y = Y;
        cout<<"Point was created"<<endl;
    };


    void setX(int m)
    {
        x = m;
    };

    void setY(int n)
    {
        y = n;
    };


    int getX()
    {
        int out = x;
        return out;
    };

    int getY()
    {
        int out = y;
        return out;
    };

    ~Point()
    {
        cout<<"A point was destroyed"<<endl;
    };
};

class Shape
{
private:
    int color;

public:
    void setColor(int col)
    {
        color = col;
    };

    int getColor()
    {
        return color;
    };
};

class Line : public Shape
{
private:
    Point a;
    Point b;

public:
    Line() : a() , b()
    {
        //a = Point();
        //b = Point();
        cout<<"Line was created"<<endl;
    };

    Line(int a1, int a2, int b1, int b2)
    {
        a = Point(a1, a2);
        b = Point(b1, b2);
        cout<<"Line was created"<<endl;
    };

    void draw()
    {
        //line(a.getX(), a.getY(), b.getX(), b.getY());
    };

    ~Line()
    {
        cout<<"A line was destroyed"<<endl;
    };
};

class Rect : public Shape
{
private:
    Point ul;
    Point lr;

public:
    Rect()
    {
        ul = Point();
        lr = Point();
        cout<<"Rectangle was created"<<endl;
    };

    Rect(int ul1, int ul2, int lr1, int lr2)
    {
        ul = Point(ul1, ul2);
        lr = Point(lr1, lr2);
        cout<<"Rectangle was created"<<endl;
    };

    void draw()
    {
        //rectangle(ul.getX(), ul.getY(), lr.getX(), lr.getY());
    };

    ~Rect()
    {
        cout<<"A rectangle was destroyed"<<endl;
    };
};

class Circle : public Shape
{
private:
    Point cent;
    int rad;

public:
    Circle()
    {
        cent = Point();
        rad = 0;
        cout<<"Circle was created"<<endl;
    };

    Circle(int cx, int cy, int r)
    {
        cent = Point(cx, cy);
        rad = r;
        cout<<"Circle was created"<<endl;
    };

    void draw()
    {
        //Circle(cent.getX, cent.getY, rad);
    };

    ~Circle()
    {
        cout<<"A circle was destroyed"<<endl;
    };
};

class Picture
{
private:
    int lNum;
    int rNum;
    int cNum;

    Line *pLines;
    Rect *pRects;
    Circle *pCircs;

public:
    Picture()
    {
        lNum = 0;
        rNum = 0;
        cNum = 0;
        pLines = NULL;
        pRects = NULL;
        pCircs = NULL;
        cout<<"Picture was constructed"<<endl;
    };

    Picture(int ln, int rn, int cn, Line *pL, Rect *pR, Circle *pC)
    {
        lNum = ln;
        rNum = rn;
        cNum = cn;
        pLines = pL;
        pRects = pR;
        pCircs = pC;

        int i;
        for(i=0; i<lNum; i++)
        {
            pLines[i] = Line();
        }
        for(i=0; i<rNum; i++)
        {
            pRects[i] = Rect();
        }
        for(i=0; i<cNum; i++)
        {
            pCircs[i] = Circle();
        }
        cout<<"Picture was constructed"<<endl;
    };


    void setLines(int l, Line *pL)
    {
        lNum = l;
        pLines = pL;
    };

    void setRectangles(int r, Rect *pR)
    {
        rNum = r;
        pRects = pR;
    };

    void setCircles(int c, Circle *pC)
    {
        cNum = c;
        pCircs = pC;
    };

    void paint()
    {
        int i;
        for(i=0; i<lNum; i++)
        {
            pLines[i].draw();
        }
        for(i=0; i<rNum; i++)
        {
            pRects[i].draw();
        }
        for(i=0; i<cNum; i++)
        {
            pCircs[i].draw();
        }
    };

    ~Picture()
    {

        cout<<"Picture was destroyed"<<endl;
    };
};


int main()
{
    Picture myPic;

    Circle cArr[3]={Circle(50,50,50), Circle(200,100,100), Circle(420,50,30)};
    Rect rArr[2]={Rect(30,40,170,100), Rect(420,50,500,300)};
    Line lArr[2]={Line(420,50,300,300), Line(40,500,500,400)};

    myPic.setCircles(3, cArr);
    myPic.setRectangles(2, rArr);
    myPic.setLines(2, lArr);

    myPic.paint();

    Circle redCircle(200,200,10);
    redCircle.setColor(5); //assuming 5 is code for red
    cout<<redCircle.getColor()<<endl;

    return 0;
}
