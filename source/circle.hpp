#ifndef CIRCLE_HPP 
#define CIRCLE_HPP
#include "color.hpp"
#include "vec2.hpp"
#include "window.hpp"

class Circle{
    public:
       Circle(Vec2 const& ctr, float r, Color const& clr);
       Circle();
       float circumference() const;
       void draw(Window& win, float thickness = 1.0f) const;
       bool is_inside(Vec2 const& point) const;
       

    private:
       Vec2 center_;
       float radius_;
       Color color_;
};
#endif