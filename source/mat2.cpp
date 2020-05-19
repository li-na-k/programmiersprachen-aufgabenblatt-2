#include "mat2.hpp"
#include <cmath>

//Aufgabe 2.5
Mat2& Mat2::operator*=(Mat2 const& m){
    float e_00_temp = e_00 * m.e_00 + e_10 * m.e_01;
    float e_10_temp = e_00 * m.e_10 + e_10 * m.e_11;
    float e_01_temp = e_01 * m.e_00 + e_11 * m.e_01;
    float e_11_temp = e_01 * m.e_10 + e_11 * m.e_11;
    e_00 = e_00_temp;
    e_10 = e_10_temp;
    e_01 = e_01_temp;
    e_11 = e_11_temp;
    return *this;
}

//Aufgabe 2.6
float Mat2::det() const{
    return e_00 * e_11 - e_10 * e_01;
}

// freie Funktionen
//Aufgabe 2.5
Mat2 operator*(Mat2 const& m1, Mat2 const& m2){
    Mat2 result {m1};
    result *= m2;
    return result;
}

//Aufgabe 2.6
Vec2 operator*(Mat2 const& m, Vec2 const& v){
    Vec2 result;
    result.x = m.e_00 * v.x + m.e_10 * v.y;
    result.y = m.e_01 * v.x + m.e_11 * v.y;
    return result;
}

Vec2 operator*(Vec2 const& v, Mat2 const& m){
    return m*v;
}

Mat2 inverse(Mat2 const& m){
    float d = m.det();
    Mat2 result;
    result.e_00 = 1/d * m.e_11;
    result.e_10 = -1/d * m.e_10;
    result.e_01 = -1/d * m.e_01;
    result.e_11 = 1/d * m.e_00;
    return result;
}

Mat2 transpose(Mat2 const& m){
    Mat2 result;
    result.e_00 = m.e_00;
    result.e_10 = m.e_01;
    result.e_01 = m.e_10;
    result.e_11 = m.e_11;
    return result;
}

Mat2 make_rotation_mat2(float phi){
    Mat2 result;
    result.e_00 = cosf(phi);
    result.e_10 = -sinf(phi);
    result.e_01 = sinf(phi);
    result.e_11 = cosf(phi);
    return result;
}



