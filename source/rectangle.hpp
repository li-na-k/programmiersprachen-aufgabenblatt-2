#ifndef RECTANGLE_HPP 
#define RECTANGLE_HPP
#include "color.hpp"
#include "vec2.hpp"

class Rectangle{
    public:
       Rectangle(Vec2 const& min, Vec2 const& max, Color const& clr); //eigener Konstruktor
       Rectangle() = default; //default-Konstruktor
       float circumference() const;
    
    private:
       Vec2 min_ = {0.0f, 0.0f};   // geht nicht weil ich eigenen Konstruktor habe? //linke untere Ecke      
       Vec2 max_ = {0.0f, 0.0f};   //rechte obere Ecke
       Color color_;
};
#endif