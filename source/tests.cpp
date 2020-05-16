#define CATCH_CONFIG_RUNNER
#include "../external/catch-1.1/catch.hpp"
#include "vec2.hpp"

Vec2 a;
Vec2 b {5.1f, -9.3f};

//Aufgabe 2.2 - Default Memberinitialisierung testen
TEST_CASE("Vec2 Initialisierung", "[Vec2]"){
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
  b += c; //Kommutativität überprüfen
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

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
