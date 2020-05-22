#ifndef RECTANGLE_HPP 
#define RECTANGLE_HPP

#include "color.hpp"
#include "vec2.hpp"
#include "window.hpp"

namespace repo2{
    class Rectangle{
        public:
        Rectangle(Vec2 const& min, Vec2 const& max, Color const& clr);
        Rectangle();
        float circumference() const;
        void draw(Window const& win) const;
        void draw(Window const& win, float thickness) const;
        
        private:
        Vec2 min_; //linke untere Ecke      
        Vec2 max_; //rechte obere Ecke
        Color color_;
    };
}
#endif