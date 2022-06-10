#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "shapes.h"

shapes::Shape::color parse_color(std::string color)
{
    if (color == "Red") return shapes::Shape::color::RED;
    if (color == "Blue") return shapes::Shape::color::BLUE;
    if (color == "Green") return shapes::Shape::color::GREEN;

    return shapes::Shape::color::NONE;
};

int main(int, char**) {
    std::cout << "------------------\n";
    std::cout << "\tshapes\n";    
    std::cout << "------------------\n";
    std::cout << "Command list:\n";
    std::cout << "\tcircle\n";
    std::cout << "\tsqare\n";
    std::cout << "\ttriangle\n";
    std::cout << "\trectangle\n";
    std::cout << "------------------\n";
    std::cout << "Enter your commad: ";

    std::string command;
    std::cin >> command;
    if (command == "circle")
    {
        std::cout << "please enter circle centre (x y): ";
        shapes::point centre;
        std::cin >> centre.x >> centre.y;
        std::cout << "plase enter circle radius: ";
        double rad;
        std::cin >> rad;
        std::cout << "plase enter color(Red, Blue, Green): " ;
        std::string color;
        std::cin >> color;
        shapes::Circle circle(centre,rad,parse_color(color));

        std::cout << "circle sqare: " << circle.get_sqare() << std::endl;
        std::cout << "circle color: " << circle.get_color() << std::endl;
        shapes::Rectangle rec = circle.get_rectangle();
        shapes::point size;
        size = rec.get_size();
        std::cout << "rectangle size: " << size.x << " " << size.y;
        return 0;
    }
    if (command == "sqare")
    {
        std::cout << "please enter sqare centre (x y): ";
        shapes::point centre;
        std::cin >> centre.x >> centre.y;
        std::cout << "plase enter sqare side size: ";
        double size_size;
        std::cin >> size_size;
        std::cout << "plase enter color(Red, Blue, Green): " ;
        std::string color;
        std::cin >> color;
        shapes::Rectangle sqare(centre,size_size,parse_color(color));

        std::cout << "sqare sqare: " << sqare.get_sqare() << std::endl;
        std::cout << "sqare color: " << sqare.get_color() << std::endl;
        shapes::Rectangle rec = sqare.get_rectangle();
        shapes::point size;
        size = rec.get_size();
        std::cout << "rectangle size: " << size.x << " " << size.y;
        return 0;
    }
    if (command == "rectangle")
    {
        std::cout << "please enter rectangle centre (x y): ";
        shapes::point centre;
        std::cin >> centre.x >> centre.y;
        std::cout << "plase enter rectangle size (width height): ";
        shapes::point sizes;
        std::cin >> sizes.x >> sizes.y;
        std::cout << "plase enter color(Red, Blue, Green): " ;
        std::string color;
        std::cin >> color;
        shapes::Rectangle rectangle(centre,sizes,parse_color(color));

        std::cout << "rectangle sqare: " << rectangle.get_sqare() << std::endl;
        std::cout << "rectangle color: " << rectangle.get_color() << std::endl;
        shapes::Rectangle rec = rectangle.get_rectangle();
        shapes::point size;
        size = rec.get_size();
        std::cout << "rectangle size: " << size.x << " " << size.y;
        return 0;
    }
    if (command == "triangle")
    {
        std::cout << "please enter triangle centre (x y): ";
        shapes::point centre;
        std::cin >> centre.x >> centre.y;
        std::cout << "plase enter triangle side size: ";
        double size_size;
        std::cin >> size_size;
        std::cout << "plase enter color(Red, Blue, Green): " ;
        std::string color;
        std::cin >> color;
        shapes::Triangle triangle(centre,size_size,parse_color(color));

        std::cout << "triangle sqare: " << triangle.get_sqare() << std::endl;
        std::cout << "triangle color: " << triangle.get_color() << std::endl;
        shapes::Rectangle rec = triangle.get_rectangle();
        shapes::point size;
        size = rec.get_size();
        std::cout << "rectangle size: " << size.x << " " << size.y;
        return 0;
    }

    std::cout << "Error: wrong command!\n";
    return 1;
}

