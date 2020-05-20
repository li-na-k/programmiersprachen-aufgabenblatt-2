#include "rectangle.hpp"
#include <cmath>

Rectangle::Rectangle(Vec2 const& min, Vec2 const& max, Color const& clr) :
  min_ {min},  
  max_ {max}, 
  color_ {clr}
{}

//Default-K. von Compiler erzeugt

float Rectangle::circumference() const{
    return 2 * (max_.x - min_.x) + 2 * (max_.y - min_.y);
}
