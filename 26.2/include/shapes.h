#pragma once

#include<string>


namespace shapes
{
    struct point
    {
        double x;
        double y;
    };
    
    class Shape
    {
        public:
            enum class color
            {
                NONE,
                RED,
                BLUE,
                GREEN
            };
            
            Shape();
            point get_centre();
            std::string get_color();    
        protected:
            point myCentre;
            color myShapeColor;
    };

    class Rectangle : public Shape
    {
        public:
            Rectangle(point centre, point size, color shapeColor = color::NONE);
            Rectangle(point centre, double sideLenght, color shapeColor = color::NONE);
            double get_sqare();
            Rectangle get_rectangle();
            point get_size();
        private:
            point mySize;
    };

    class Circle : public  Shape
    {
        public:
            Circle(point centre, double radius, color shapeColor = color::NONE);
            double get_sqare();
            Rectangle get_rectangle();
        private:
            double myRadius;
    };

    class Triangle : public  Shape
    {
        public:
            Triangle(point centre, double sideLenght, color shapeColor = color::NONE);
            double get_sqare();
            Rectangle get_rectangle();
        private:
            double mySideLingth;
    };
} // namespace shapes