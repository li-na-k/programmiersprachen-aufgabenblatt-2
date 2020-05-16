#include "vec2.hpp"
#include <iostream>

Vec2& Vec2::operator+=(Vec2 const& v){ //v wird nicht verändert, nur Objekt auf das aufgerufen
   x += v.x;
   y += v.y;
   return *this;
}

Vec2& Vec2::operator -=(Vec2 const& v){
    x -= v.x;
    y -= v.y;
    return *this;
}

Vec2& Vec2::operator*=(float s){
    x*=s;
    y*=s;
    return *this;
}

Vec2& Vec2::operator/=(float s){
    if(s == 0.0f){  //Division durch 0 abfangen
        std::cout<<"Division durch Null nicht erlaubt. Keine Division ausgeführt. /n"; 
        return *this;
    }
    else{
    x/=s;
    y/=s;
    return *this;
    }
    
}
