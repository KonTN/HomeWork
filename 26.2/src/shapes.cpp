#include "shapes.h"

#include <math.h>

shapes::Shape::Shape()
{
    myCentre = {0,0};
    myShapeColor = color::NONE;
};
shapes::point shapes::Shape::get_centre()
{
    return myCentre;
};
std::string shapes::Shape::get_color()
{
    switch (myShapeColor)
    {
    case color::NONE:
        return "None";
        break;
    case color::RED:
        return "Red";
        break;
    case color::BLUE:
        return "Blue";
        break;
    case color::GREEN:
        return "Green";
        break;
    }
};



shapes::Rectangle::Rectangle(point centre, point size, color shapeColor)
{
    mySize = size;
    myCentre = centre;
    myShapeColor = shapeColor;
};
shapes::Rectangle::Rectangle(point centre,double sideLenght, color shapeColor)
{
    mySize = {sideLenght,sideLenght};
    myCentre = centre;
    myShapeColor = shapeColor;
};
double shapes::Rectangle::get_sqare()
{
    return mySize.x * mySize.y;
};
shapes::Rectangle shapes::Rectangle::get_rectangle()
{
    return *this;
};
shapes::point shapes::Rectangle::get_size()
{
    return mySize;
}


shapes::Circle::Circle(point centre, double radius, color shapeColor)
{
    myCentre = centre;
    myRadius = radius;
    myShapeColor = shapeColor;
};
double shapes::Circle::get_sqare()
{
    return atan(1) * 4 * myRadius;
};
shapes::Rectangle shapes::Circle::get_rectangle()
{
    shapes::Rectangle retRec(myCentre,myRadius*2);
    return retRec;
};

shapes::Triangle::Triangle(point centre, double sideLenght, color shapeColor)
{
    myCentre = centre;
    mySideLingth = sideLenght;
    myShapeColor = shapeColor;
};
double shapes::Triangle::get_sqare()
{
    return mySideLingth * mySideLingth * std::sqrt(3) / 4;
};
shapes::Rectangle shapes::Triangle::get_rectangle()
{
    shapes::Rectangle retRec(myCentre,mySideLingth);
    return retRec;
};