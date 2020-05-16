#define CATCH_CONFIG_RUNNER
#include "../external/catch-1.1/catch.hpp"
#include "vec2.hpp"


Vec2 a;
Vec2 b{5.1f, -9.3f};

//Aufgabe 2.2 - Default Memberinitialisierung testen
TEST_CASE("Vec2 Initialisierung", "[Vec2]"){
  REQUIRE(a.x == 0.0f);
  REQUIRE(a.y == 0.0f); 
  REQUIRE(5.1f == Approx(b.x));
  REQUIRE(-9.3f == Approx(b.y));
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
