#include <array> 

struct Mat2 {
    // matrix layout:
    // e_00 e_10
    // e_01 e_11
    float e_00 = 1.0f; 
    float e_10 = 0.0f;
    float e_01 = 0.0f; 
    float e_11 = 1.0f;
    
    //Memberfunktion
    Mat2& operator*=(Mat2 const& m); 

};

// freie Funktion
Mat2 operator*(Mat2 const& m1, Mat2 const& m2);