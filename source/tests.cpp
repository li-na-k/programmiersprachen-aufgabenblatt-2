#define CATCH_CONFIG_RUNNER
#include "../external/catch-1.1/catch.hpp"
#include "vec2.hpp"
#include "mat2.hpp"



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
  Mat2 a {2,7,5,1};
  Mat2 b {0,2,-1,6};
  a*=b;
  REQUIRE(a.e_00 == Approx(-7.0f));
  REQUIRE(a.e_10 == Approx(46.0f));
  REQUIRE(a.e_01 == Approx(-1.0f));
  REQUIRE(a.e_11 == Approx(16.0f));
  Mat2 d {-2.2, 9.1, 6.45, 0.2};
  d *= b;
  REQUIRE(d.e_00 == Approx(-9.1f));
  REQUIRE(d.e_10 == Approx(50.2f));
  REQUIRE(d.e_01 == Approx(-0.2f));
  REQUIRE(d.e_11 == Approx(14.1f));
  d = {-2.2, 9.1, 6.45, 0.2};
  b *= d;
  REQUIRE(b.e_00 == Approx(12.9f));
  REQUIRE(b.e_10 == Approx(0.4f));
  REQUIRE(b.e_01 == Approx(40.9f));
  REQUIRE(b.e_11 == Approx(-7.9f));
}

TEST_CASE("FFunktion-Matrizen-Multiplikation", "[FFunktion-Matrizen-Multiplikation]"){
  Mat2 a {2,7,5,1};
  Mat2 b {0,2,-1,6};
  Mat2 c = a * b;
  REQUIRE(c.e_00 == Approx(-7.0f));
  REQUIRE(c.e_10 == Approx(46.0f));
  REQUIRE(c.e_01 == Approx(-1.0f));
  REQUIRE(c.e_11 == Approx(16.0f));
  Mat2 d {-2.2, 9.1, 6.45, 0.2};
  Mat2 e = d * b;
  REQUIRE(e.e_00 == Approx(-9.1f));
  REQUIRE(e.e_10 == Approx(50.2f));
  REQUIRE(e.e_01 == Approx(-0.2f));
  REQUIRE(e.e_11 == Approx(14.1f));
}

//Aufgabe 2.6
TEST_CASE("Determinante_berechnen", "[det]"){
  Mat2 a {2,7,5,1};
  Mat2 b {0,2,-1,6};
  Mat2 c {-2.2, 9.1, 6.45, 0.2};
  Mat2 d {123.4567, 2, -0.1, 0.5};
  REQUIRE(a.det() == Approx(-33.0f));
  REQUIRE(b.det() == Approx(2.0f));
  REQUIRE(c.det() == Approx(-59.135f));
  REQUIRE(d.det() == Approx(61.9284f));
}



int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}



