#include "circle.hpp"
#include "window.hpp"
#include "mat2.hpp"
#include "vec2.hpp"
#include <cmath>

Circle::Circle() :
  center_ {0.0f, 0.0f},
  radius_{1.0f},
  color_ {0.5f, 0.5f, 0.5f} 
  {}

Circle::Circle(Vec2 const& ctr, float r, Color const& clr) : 
   center_ {ctr}, 
   radius_ {r}, 
   color_ {clr} 
   {}

float Circle::circumference() const{
    return 2 * M_PI * radius_;
}

void Circle::draw(Window const& win, float thickness) const{
    Vec2 start_point {center_.x, center_.y + radius_};
    int ANZAHL_SEGMENTE = 500;
    Mat2 rotationsmatrix = make_rotation_mat2(360*M_PI/180/ANZAHL_SEGMENTE); //360 Grad in Bogenmaß / Anzahl der Segmente => Länge der Segmente
    for(int i = 0; i < ANZAHL_SEGMENTE; ++i){
      Vec2 end_point {start_point};
      end_point -= center_;
      end_point = rotationsmatrix * end_point;
      end_point += center_;
      win.draw_line(start_point.x, start_point.y, end_point.x, end_point.y, color_.r, color_.g, color_.b, thickness);
      start_point = end_point;
   }
}

bool Circle::is_inside(Vec2 const& point) const{  //auf Linie != inside
   Vec2 verbindung {point.x - center_.x, point.y - center_.y}; //Verbindunksvektor zw. Punkt u. Radius
   if((sqrt(pow(verbindung.x,2) + pow(verbindung.y,2))) < radius_){ //Laenge d. Verbindungsvektors < Radius?
      return true;
   }
   else{
      return false;
   }
}

