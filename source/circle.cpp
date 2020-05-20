#include "circle.hpp"
#include <cmath>

Circle::Circle() :
  center_{0.0f, 0.0f},
  radius_{1.0f},
  color_ {0.5f, 0.5f, 0.5f} 
  {}

Circle::Circle(Vec2 const& ctr, float r, Color const& clr) : 
   center_ {ctr},  //Initialisierungsliste - Copy Konstruktoren werden aufgerufen! - Nicht aufgeführte Instanzvariablen werden Default-konstruiert -> braucht man dann den Default-Konstruktor überhaupt??
   radius_ {r}, 
   color_ {clr} 
   {}

float Circle::circumference() const{
    return 2 * M_PI * radius_;
}