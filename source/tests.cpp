#define CATCH_CONFIG_RUNNER
#include "../external/catch-1.1/catch.hpp"
#include "vec2.hpp"
#include "mat2.hpp"
#include "color.hpp"
#include "circle.hpp"
#include "rectangle.hpp"

//Aufgabe 2.2 - Default Memberinitialisierung testen
TEST_CASE("Vec2 Initialisierung", "[Vec2]"){
  Vec2 a;
  Vec2 b {5.1f, -9.3f};
  REQUIRE(a.x == 0.0f);
  REQUIRE(a.y == 0.0f); 
  REQUIRE(5.1f == Approx(b.x));
  REQUIRE(-9.3f == Approx(b.y));
}

//Aufgabe 2.3 - Addition, Subtraktion zweier Vektoren + Multiplikation / Division mit float
TEST_CASE("Vektoren-Addition", "[Addition]"){
  Vec2 a {1.0f, 0.0f};
  Vec2 b {7.3f, -1.2f};
  a += b;
  REQUIRE(a.x == Approx(8.3f));
  REQUIRE(a.y == Approx(-1.2f));
  Vec2 c {1.0f, 0.0f};
  b += c; //Kommutativitaet überprüfen
  REQUIRE(b.x == Approx(8.3f));
  REQUIRE(b.y == Approx(-1.2f));
  Vec2 d {-3.12f, -0.1f};
  Vec2 e {-1.45f, 9.9f};
  d+=e;
  REQUIRE(d.x == Approx(-4.57f));
  REQUIRE(d.y == Approx(9.8f));
  d+=a;
}


TEST_CASE("Vektoren-Subtraktion", "[Subtraktion]"){
  Vec2 a {4.21f, 0.0f}; 
  Vec2 b {0.01f, -8.8f};
  a -= b;
  REQUIRE(a.x == Approx(4.2f));
  REQUIRE(a.y == Approx(8.8f));
  Vec2 c {-4.2f, 7.98f};
  Vec2 d {0.0f, -0.5f};
  d-=c;
  REQUIRE(d.x == Approx(4.2f));
  REQUIRE(d.y == Approx(-8.48f));
  REQUIRE(c.x == Approx(-4.2f));
  REQUIRE(c.y == Approx(7.98f));
  c-=d;
  REQUIRE(c.x == Approx(-8.4f));
  REQUIRE(c.y == Approx(16.46f));
}


TEST_CASE("Mulitplikation_mit_float", "[Mulitplikation-mit_float]"){
  Vec2 a {4.21f, 0.0f}; 
  Vec2 b {0.1f, -8.8f};
  Vec2 c {5.1f, 2.6f};
  float f1 = 0.0f;
  float f2 = -4.5f;
  float f3 = 2.4f;
  float f4 = 1.0f;
  a *= f2;
  REQUIRE(a.x == Approx(-18.945f));
  REQUIRE(a.y == 0.0f);
  b *= f3;
  REQUIRE(b.x == Approx(0.24f));
  REQUIRE(b.y == Approx(-21.12f));
  c *= f1;
  REQUIRE(c.x == 0.0f);
  REQUIRE(c.y == 0.0f);
  c *= f4;
  REQUIRE(c.x == 0.0f);
  REQUIRE(c.y == 0.0f);
}


TEST_CASE("Division_durch_float", "[Division_durch_float]"){
  Vec2 a {4.21f, 0.0f}; 
  Vec2 b {0.1f, -8.8f};
  float f1 = 0.0f;
  float f2 = -4.5f;
  float f3 = 2.4f;
  float f4 = 1.0f;
  a /= f1;
  REQUIRE(a.x == Approx(4.21f));
  REQUIRE(a.y == Approx(0.0f));
  a /= f2;
  REQUIRE(a.x == Approx(-0.93555f));
  REQUIRE(a.y == 0.0f);
  b /= f3;
  REQUIRE(b.x == Approx(0.041666f));
  REQUIRE(b.y == Approx(-3.66666f));
  b /= f4;
  REQUIRE(b.x == Approx(0.041666f));
  REQUIRE(b.y == Approx(-3.66666f));
}

//Aufgabe 2.4 - Freie Funktionen
TEST_CASE("Freie_Funktion_Addition", "[Freie_Funktion_Addition]"){
  Vec2 a {5.71f, 0.0f}; 
  Vec2 b {7.2f, -10.8f};
  Vec2 e1 = a + b;
  REQUIRE(e1.x == Approx(12.91f));
  REQUIRE(e1.y == Approx(-10.8f));
  Vec2 c {7.44f, 0.9f};
  Vec2 e2 = b + c;
  Vec2 e3 = c + b; //Kommutativitaet testen
  REQUIRE(e2.x == Approx(14.64f));
  REQUIRE(e2.y == Approx(-9.9f));
  REQUIRE(e3.x == Approx(14.64f));
  REQUIRE(e3.y == Approx(-9.9f));
  Vec2 d {1.49f, 2.98f};
  Vec2 e4 = d + c;
  REQUIRE(e4.x == Approx(8.93f));
  REQUIRE(e4.y == Approx(3.88f));
}

TEST_CASE("Freie_Funktion_Subtraktion", "[Freie_Funktion_Subtraktion]"){
  Vec2 a {5.71f, 0.0f}; 
  Vec2 b {7.2f, -10.8f};
  Vec2 e1 = a - b;
  REQUIRE(e1.x == Approx(-1.49f));
  REQUIRE(e1.y == Approx(10.8f));
  Vec2 e2 = a - a;
  REQUIRE(e2.x == 0.0f);
  REQUIRE(e2.y == 0.0f);
  Vec2 c {7.44f, 0.9f};
  Vec2 e3 = a - c ;
  REQUIRE(e3.x == Approx(-1.73f));
  REQUIRE(e3.y == Approx(-0.9f));
  Vec2 e4 = b - a;
  REQUIRE(e4.x == Approx(1.49f));
  REQUIRE(e4.y == Approx(-10.8f));
}

TEST_CASE("Freie_Funktion_Multiplikation", "[Freie_Funktion_Multiplikation]"){
  Vec2 a {5.71f, 0.0f}; 
  Vec2 b {7.2f, -10.8f};
  float f1 = 0.5f;
  float f2 = 0.0f;
  float f3 = -3.1f;
  Vec2 e1 = a * f1;
  Vec2 e2 = b * f2;
  Vec2 e3 = a * f2;
  Vec2 e4 = b * f3;
  REQUIRE(e1.x == Approx(2.855f));
  REQUIRE(e1.y == 0.0f);
  REQUIRE(e2.x == 0.0f);
  REQUIRE(e2.y == 0.0f);
  REQUIRE(e3.x == 0.0f);
  REQUIRE(e3.y == 0.0f);
  REQUIRE(e4.x == Approx(-22.32f));
  REQUIRE(e4.y == Approx(33.48f));
}

TEST_CASE("Freie_Funktion_Division", "[Freie_Funktion_Division]"){
  Vec2 a {5.71f, 0.0f}; 
  Vec2 b {7.2f, -10.8f};
  float f1 = 0.5f;
  float f2 = 0.0f;
  float f3 = -3.1f;
  Vec2 e1 = a / f1;
  Vec2 e2 = b / f2;
  Vec2 e3 = a / f2;
  Vec2 e4 = b / f3;
  REQUIRE(e1.x == Approx(11.42f));
  REQUIRE(e1.y == 0.0f);
  REQUIRE(e2.x == Approx(7.2f));
  REQUIRE(e2.y == Approx(-10.8f));
  REQUIRE(e3.x == Approx(5.71f));
  REQUIRE(e3.y == 0.0f);
  REQUIRE(e4.x == Approx(-2.32258f));
  REQUIRE(e4.y == Approx(3.48387f));
}

TEST_CASE("Freie_Funktion_Multiplikation2", "[Freie_Funktion_Multiplikation2]"){
  Vec2 a {5.71f, 0.0f}; 
  Vec2 b {7.2f, -10.8f};
  float f1 = 0.5f;
  float f2 = 0.0f;
  float f3 = -3.1f;
  Vec2 e1 = f1 * a;
  Vec2 e2 = f2 * b;
  Vec2 e3 = f2 * a;
  Vec2 e4 = f3 * b;
  REQUIRE(e1.x == Approx(2.855f));
  REQUIRE(e1.y == 0.0f);
  REQUIRE(e2.x == 0.0f);
  REQUIRE(e2.y == 0.0f);
  REQUIRE(e3.x == 0.0f);
  REQUIRE(e3.y == 0.0f);
  REQUIRE(e4.x == Approx(-22.32f));
  REQUIRE(e4.y == Approx(33.48f));
}


//Aufgabe 2.5 - Matrizenmultiplikation
TEST_CASE("Methode-Matrizen-Multiplikation", "[Methode-Matrizen-Multiplikation]"){
  Mat2 a {2.0f,7.0f,5.0f,1.0f};
  Mat2 b {0.0f,2.0f,-1.0f,6.0f};
  a*=b;
  REQUIRE(a.e_00 == Approx(-7.0f));
  REQUIRE(a.e_10 == Approx(46.0f));
  REQUIRE(a.e_01 == Approx(-1.0f));
  REQUIRE(a.e_11 == Approx(16.0f));
  Mat2 d {-2.2f, 9.1f, 6.45f, 0.2f};
  d *= b;
  REQUIRE(d.e_00 == Approx(-9.1f));
  REQUIRE(d.e_10 == Approx(50.2f));
  REQUIRE(d.e_01 == Approx(-0.2f));
  REQUIRE(d.e_11 == Approx(14.1f));
  d = {-2.2f, 9.1f, 6.45f, 0.2f};
  b *= d;
  REQUIRE(b.e_00 == Approx(12.9f));
  REQUIRE(b.e_10 == Approx(0.4f));
  REQUIRE(b.e_01 == Approx(40.9f));
  REQUIRE(b.e_11 == Approx(-7.9f));
  Mat2 e {8.3, 0, 0, 0};
  e *= d;
  REQUIRE(e.e_00 == Approx(-18.26f));
  REQUIRE(e.e_10 == Approx(75.53f));
  REQUIRE(e.e_01 == 0.0f);
  REQUIRE(e.e_11 == 0.0f);
}

TEST_CASE("FFunktion-Matrizen-Multiplikation", "[FFunktion-Matrizen-Multiplikation]"){
  Mat2 a {2.0f,7.0f,5.0f,1.0f};
  Mat2 b {0.0f,2.0f,-1.0f,6.0f};
  Mat2 c = a * b;
  REQUIRE(c.e_00 == Approx(-7.0f));
  REQUIRE(c.e_10 == Approx(46.0f));
  REQUIRE(c.e_01 == Approx(-1.0f));
  REQUIRE(c.e_11 == Approx(16.0f));
  Mat2 d {-2.2f, 9.1f, 6.45f, 0.2f};
  Mat2 e = d * b;
  REQUIRE(e.e_00 == Approx(-9.1f));
  REQUIRE(e.e_10 == Approx(50.2f));
  REQUIRE(e.e_01 == Approx(-0.2f));
  REQUIRE(e.e_11 == Approx(14.1f));
  Mat2 f = b * a; //Matrizenmultiplikation nicht kommutativ
  REQUIRE(f.e_00 == Approx(10.0f));
  REQUIRE(f.e_10 == Approx(2.0f));
  REQUIRE(f.e_01 == Approx(28.0f));
  REQUIRE(f.e_11 == Approx(-1.0f));
  Mat2 g {8.3, 0, 0, 0};
  Mat2 h = d * g;
  REQUIRE(f.e_00 == Approx(10.0f));
  REQUIRE(f.e_10 == Approx(2.0f));
  REQUIRE(f.e_01 == Approx(28.0f));
  REQUIRE(f.e_11 == Approx(-1.0f));
}

//Aufgabe 2.6
TEST_CASE("Determinante_berechnen", "[det]"){
  Mat2 a {2.0f,7.0f,5.0f,1.0f};
  Mat2 b {0.0f,2.0f,-1.0f,6.0f};
  Mat2 c {-2.2f, 9.1f, 6.45f, 0.2f};
  Mat2 d {123.4567f, 2.0f, -0.1f, 0.5f};
  REQUIRE(a.det() == Approx(-33.0f));
  REQUIRE(b.det() == Approx(2.0f));
  REQUIRE(c.det() == Approx(-59.135f));
  REQUIRE(d.det() == Approx(61.9284f));
}

TEST_CASE("Matrix-Vektor-Multiplikation", "[Matrix-Vektor-Multiplikation]"){
  Mat2 a {2.0f,7.0f,5.0f,1.0f};
  Mat2 b {0.0f,2.0f,-1.0f,6.0f};
  Mat2 c {-2.2f, 9.1f, 6.45f, 0.2f};
  Mat2 d {123.4567f, 2.0f, -0.1f, 0.5f};
  Vec2 v1 {1.0f,2.0f};
  Vec2 v2 {0.0f,-5.2f};
  Vec2 v3 {2.1f, 3.6f};
  Vec2 e1 = a * v1;
  REQUIRE(e1.x == Approx(16.0f));
  REQUIRE(e1.y == Approx(7.0f));
  Vec2 e2 = b * v2;
  REQUIRE(e2.x == Approx(-10.4f));
  REQUIRE(e2.y == Approx(-31.2f));
  Vec2 e3 = c * v2;
  REQUIRE(e3.x == Approx(-47.32f));
  REQUIRE(e3.y == Approx(-1.04f));
  Vec2 e4 = d * v3;
  REQUIRE(e4.x == Approx(266.46f));
  REQUIRE(e4.y == Approx(1.59f));
}

TEST_CASE("Vektor-Matrix-Multiplikation", "[Vektor-Matrix-Multiplikation]"){
  Mat2 a {2.0f,7.0f,5.0f,1.0f};
  Mat2 b {0.0f,2.0f,-1.0f,6.0f};
  Mat2 c {-2.2f, 9.1f, 6.45f, 0.2f};
  Mat2 d {123.4567f, 2.0f, -0.1f, 0.5f};
  Vec2 v1 {1.0f,2.0f};
  Vec2 v2 {0.0f,-5.2f};
  Vec2 v3 {2.1f, 3.6f};
  Vec2 e1 = v1 * a;
  REQUIRE(e1.x == Approx(16.0f));
  REQUIRE(e1.y == Approx(7.0f));
  Vec2 e2 = v2 * b;
  REQUIRE(e2.x == Approx(-10.4f));
  REQUIRE(e2.y == Approx(-31.2f));
  Vec2 e3 = v2 * c;
  REQUIRE(e3.x == Approx(-47.32f));
  REQUIRE(e3.y == Approx(-1.04f));
  Vec2 e4 = v3 * d;
  REQUIRE(e4.x == Approx(266.46f));
  REQUIRE(e4.y == Approx(1.59f));
}


TEST_CASE("Inverse", "[inverse]"){
  Mat2 a {1.0f,2.0f,-2.0f,1.0f};
  Mat2 b {0.0f,2.0f,-1.0f,6.0f};
  Mat2 c {-2.2f, 9.1f, 6.45f, 0.2f};
  Mat2 d {123.4567f, 2.0f, -0.1f, 0.5f};
  Mat2 erg1 = inverse(a);
  REQUIRE(erg1.e_00 == Approx(0.2f));
  REQUIRE(erg1.e_10 == Approx(-0.4f));
  REQUIRE(erg1.e_01 == Approx(0.4f));
  REQUIRE(erg1.e_11 == Approx(0.2f));
  Mat2 erg2 = inverse(b);
  REQUIRE(erg2.e_00 == Approx(3.0f));
  REQUIRE(erg2.e_10 == Approx(-1.0f));
  REQUIRE(erg2.e_01 == Approx(0.5f));
  REQUIRE(erg2.e_11 == 0.0f);
  Mat2 erg3 = inverse(c);
  REQUIRE(erg3.e_00 == Approx(-0.00338f));
  REQUIRE(erg3.e_10 == Approx(0.15389f));
  REQUIRE(erg3.e_01 == Approx(0.10907f));
  REQUIRE(erg3.e_11 == Approx(0.0372f));
  Mat2 erg4 = inverse(d);
  REQUIRE(erg4.e_00 == Approx(0.00807f));
  REQUIRE(erg4.e_10 == Approx(-0.0323f));
  REQUIRE(erg4.e_01 == Approx(0.00161f));
  REQUIRE(erg4.e_11 == Approx(1.99354f));
}


TEST_CASE("Transpose_Matrix", "[transpose]"){
  Mat2 a {1.0f,2.0f,-2.0f,1.0f};
  Mat2 b {0.0f,2.0f,-1.0f,6.0f};
  Mat2 c {-2.2f, 9.1f, 6.45f, 0.2f};
  Mat2 d {123.4567f, 2.0f, -0.1f, 0.5f};
  Mat2 erg1 = transpose(a);
  REQUIRE(erg1.e_00 == Approx(1.0f));
  REQUIRE(erg1.e_10 == Approx(-2.0f));
  REQUIRE(erg1.e_01 == Approx(2.0f));
  REQUIRE(erg1.e_11 == Approx(1.0f));
  Mat2 erg2 = transpose(b);
  REQUIRE(erg2.e_00 == 0.0f);
  REQUIRE(erg2.e_10 == Approx(-1.0f));
  REQUIRE(erg2.e_01 == Approx(2.0f));
  REQUIRE(erg2.e_11 == Approx(6.0f));
  Mat2 erg3 = transpose(c);
  REQUIRE(erg3.e_00 == Approx(-2.2f));
  REQUIRE(erg3.e_10 == Approx(6.45f));
  REQUIRE(erg3.e_01 == Approx(9.1f));
  REQUIRE(erg3.e_11 == Approx(0.2f));
  Mat2 erg4 = transpose(d);
  REQUIRE(erg4.e_00 == Approx(123.456f));
  REQUIRE(erg4.e_10 == Approx(-0.1f));
  REQUIRE(erg4.e_01 == Approx(2.0f));
  REQUIRE(erg4.e_11 == Approx(0.5f));
}


TEST_CASE("Rotationsmatrix", "[make_rotation_mat2]"){
  Mat2 a = make_rotation_mat2 (2 * M_PI); //360 Grad
  REQUIRE(Approx(a.e_00) == 1.0f);
  REQUIRE(Approx(a.e_10) == 0.0f);
  REQUIRE(Approx(a.e_01) == 0.0f);
  REQUIRE(Approx(a.e_11) == 1.0f);

  Mat2 b = make_rotation_mat2(1.570796327); //90 Grad
  REQUIRE(b.e_00 == Approx(0.0f));
  REQUIRE(b.e_10 == Approx(-1.0f));
  REQUIRE(b.e_01 == Approx(1.0f));
  REQUIRE(b.e_11 == Approx(0.0f));

  Mat2 c = make_rotation_mat2(0.0174533); //1 Grad: 1/180 * M_PI
  REQUIRE(c.e_00 == Approx(0.9998476f));
  REQUIRE(c.e_10 == Approx(-0.017452f));
  REQUIRE(c.e_01 == Approx(0.017452f));
  REQUIRE(c.e_11 == Approx(0.999847f));

  Mat2 d = make_rotation_mat2(-5.0f); 
  REQUIRE(d.e_00 == Approx(0.28366f));
  REQUIRE(d.e_10 == Approx(-0.958924f));
  REQUIRE(d.e_01 == Approx(0.958924f));
  REQUIRE(d.e_11 == Approx(0.28366f));

  Mat2 e = make_rotation_mat2(1.973f); 
  REQUIRE(e.e_00 == Approx(-0.39144f));
  REQUIRE(e.e_10 == Approx(-0.92020f));
  REQUIRE(e.e_01 == Approx(0.92020f));
  REQUIRE(e.e_11 == Approx(-0.39144f));
}

TEST_CASE("color_rgb_initialierung", "[color_rgb]"){
  Color a;
  REQUIRE(a.r == Approx(0.63f));
  REQUIRE(a.g == Approx(0.63f));
  REQUIRE(a.b == Approx(0.63f));
  Color b {0.1f,0.54f,0.1f};
  REQUIRE(b.r == Approx(0.1f));
  REQUIRE(b.g == Approx(0.54f));
  REQUIRE(b.b == Approx(0.1f));
  Color c {1.0f,1.0f,1.0f};
  REQUIRE(c.r == Approx(1.0f));
  REQUIRE(c.g == Approx(1.0f));
  REQUIRE(c.b == Approx(1.0f));
  Color d {0.0f,0.4f};
  REQUIRE(d.r == Approx(0.0f));
  REQUIRE(d.g == Approx(0.4f));
  REQUIRE(d.b == Approx(0.63f));
}

TEST_CASE("circle_circumference", "[circle_circumference]"){
  Circle c1 {{0.5f,0.5f},0.5f,{0.2f,0.6f,0.1f}}; 
  float a = c1.circumference();
  REQUIRE(a == Approx(M_PI));
  Circle c2 {{0.0f,0.0f},20.0f,{0.4f,0.1f,0.7f}};
  float b = c2.circumference();
  REQUIRE(b == Approx(125.663706f));
  Circle c3 {{0.9f,0.12f},0.0f,{0.2f,0.1f,0.7f}};
  float c = c3.circumference();
  REQUIRE(c == 0.0f);
  Circle c4 {{0.9f,0.12f},-7.0f,{0.2f,0.1f,0.7f}}; //
  float d = c4.circumference();
  REQUIRE(c == 0.0f);
}

TEST_CASE("rectangle_circumference", "[rectangle_circumference]"){
  repo2::Rectangle rect1{{100.0f, 100.0f}, {200.0f, 200.0f}, {0.3f, 0.2f, 0.1f}};
  float a = rect1.circumference();
  REQUIRE(a == Approx(400.0f));
  repo2::Rectangle rect2{{123.8f, 123.8f}, {226.0f, 200.0f}, {0.3f, 0.2f, 0.1f}};
  float b = rect2.circumference();
  REQUIRE(b == Approx(356.79999f));
  repo2::Rectangle rect3{{0.0f, -100.0f}, {100.0, 200.0f}, {0.2f, 0.2f, 0.9f}};
  float c = rect3.circumference();
  REQUIRE(c == Approx(800.0f));
  repo2::Rectangle rect4{{0.0, 27.1f}, {199.0f, 650.0f}, {0.4f, 0.9f, 0.9f}};
  float d = rect4.circumference();
  REQUIRE(d == Approx(1643.8f));
}

TEST_CASE("is_inside_rectangle", "[is_inside_rectangle]"){
  repo2::Rectangle rect1{{100.0f, 200.0f}, {300.0f, 400.0f}, {0.9f, 0.0f, 0.0f}};
  Vec2 point1 {200.0f, 300.0f};
  bool a = rect1.is_inside(point1);
  REQUIRE(a == true);
  Vec2 point2 {200.0f, 412.0f};
  bool b = rect1.is_inside(point2);
  REQUIRE(b == false);
  Vec2 point3 {200.0f, 200.0f}; //genau auf Linie
  bool c = rect1.is_inside(point3);
  REQUIRE(c == false);
  Vec2 point4 {200.0f, 199.9f}; //knapp neben Linie
  bool d = rect1.is_inside(point4);
  REQUIRE(d == false);
}

TEST_CASE("is_inside_circle", "[is_inside_circle]"){
  Circle c1 {{0.5f,0.5f},12.0f,{0.2f,0.6f,0.1f}}; 
  Vec2 point1 {1.3f, 2.1f};
  bool a = c1.is_inside(point1);
  REQUIRE(a == true);
  Vec2 point2 {25.0f, 2.1f};
  bool b = c1.is_inside(point2);
  REQUIRE(b == false);
  Circle c2 {{0.0f,0.0f},0.5f,{0.2f,0.6f,0.1f}}; 
  Vec2 point3 {0.5f, 0.0f}; //auf Linie
  bool c = c2.is_inside(point3);
  REQUIRE(c == false);
  Vec2 point4 {0.49f, 0.0f}; //knapp drinnen
  bool d = c2.is_inside(point4);
  REQUIRE(d == true);
  Vec2 point5 {0.51f, 0.0f}; //knapp außen
  bool e = c2.is_inside(point5);
  REQUIRE(e == false);
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}



