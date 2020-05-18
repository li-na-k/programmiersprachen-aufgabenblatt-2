#include "vec2.hpp"
#include <iostream>


// Methoden (Aufgabe 2.3)
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
        std::cout<<"Division durch Null nicht erlaubt. Keine Division ausgeführt. \n"; 
        return *this;
    }
    else{
    x/=s;
    y/=s;
    return *this;
    }
}

//Freie Funktionen (Aufgabe 2.4)
Vec2 operator+(Vec2 const& u, Vec2 const& v){
    Vec2 result {u};
    result += v;
    return result;
}

Vec2 operator- (Vec2 const& u, Vec2 const& v){
    Vec2 result {u};
    result -= v;
    return result;
}

Vec2 operator* (Vec2 const& v, float s){
    Vec2 result {v};
    result *= s;
    return result;
}

Vec2 operator/ (Vec2 const& v, float s){
    if(s == 0.0f){
        std::cout << "Division durch Null nicht erlaubt. Keine Division ausgeführt. \n";
        return v;
    }
    else{
        Vec2 result {v};
        result /= s;
        return result;
    }
    
}

Vec2 operator* (float s, Vec2 const& v){
    return v*s;
}
