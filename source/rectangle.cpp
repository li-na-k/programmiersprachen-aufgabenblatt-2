#include "rectangle.hpp"
#include <cmath>
#include "window.hpp"

namespace repo2{
    Rectangle::Rectangle(Vec2 const& min, Vec2 const& max, Color const& clr) : 
        min_ {min},
        max_ {max}, 
        color_ {clr}
    {}

    Rectangle::Rectangle() :
        min_ {0.0f, 0.0f},
        max_ {1.0f, 1.0f}, 
        color_ {0.1f, 0.1f, 0.1f}
    {}

    float Rectangle::circumference() const{
        return 2 * (max_.x - min_.x) + 2 * (max_.y - min_.y);
    }

    void Rectangle::draw(Window const& win) const{
        win.draw_line(min_.x, min_.y, max_.x, min_.y, color_.r,color_.g, color_.b);
        win.draw_line(min_.x, min_.y, min_.x, max_.y, color_.r,color_.g, color_.b);
        win.draw_line(min_.x, max_.y, max_.x, max_.y, color_.r,color_.g, color_.b);
        win.draw_line(max_.x, max_.y, max_.x, min_.y, color_.r,color_.g, color_.b);
    }

    void Rectangle::draw(Window const& win, float thickness) const{
        win.draw_line(min_.x, min_.y, max_.x, min_.y, color_.r,color_.g, color_.b, thickness);
        win.draw_line(min_.x, min_.y, min_.x, max_.y, color_.r,color_.g, color_.b, thickness);
        win.draw_line(min_.x, max_.y, max_.x, max_.y, color_.r,color_.g, color_.b, thickness);
        win.draw_line(max_.x, max_.y, max_.x, min_.y, color_.r,color_.g, color_.b, thickness);
    }
}
