#ifndef CIRCLE_HPP 
#define CIRCLE_HPP
#include "color.hpp"
#include "vec2.hpp"

class Circle{
    public:
       Circle(Vec2 const& ctr, float r, Color const& clr);
       Circle();
       float circumference() const;

    private:
       Vec2 center_;
       float radius_;
       Color color_;
};
#endif