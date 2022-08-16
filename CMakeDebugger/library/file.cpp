#include "file.hpp"
#include <cstdlib>

Point::Point()
{
    this->x = 5;
    this->y = 5;
}

Point::Point(unsigned int x, unsigned int y)
{
    this->x = x;
    this->y = y;
}

unsigned int Point::getX()
{
    return this->x;
}

unsigned int Point::getY()
{
    return this->y;
}

Rectangle::Rectangle(Point p1, Point p2)
{
    this->p1 = p1;
    this->p2 = p2;
}

unsigned int Rectangle::getArea()
{
    int width = abs((int)this->p1.getX() - (int)this->p2.getX());
    int height = abs((int)this->p1.getY() - (int)this->p2.getY());
    return width * height;
}
