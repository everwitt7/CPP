class Point
{
private:
    unsigned int x;
    unsigned int y;
public:
    Point();
    Point(unsigned int x, unsigned int y);
    ~Point();
    unsigned int getX();
    unsigned int getY();
};

class Rectangle
{
private:
    Point p1;
    Point p2;
    unsigned int area;
public:
    Rectangle(Point p1, Point p2);
    ~Rectangle();
    unsigned int getArea();
};
