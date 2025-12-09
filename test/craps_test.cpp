#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "die.h"

TEST_CASE("Verify Test Configuration", "verification") {
    REQUIRE(true == true);
}

TEST_CASE("Die rolls return values 1–6") {
    Die d;
    for(int i = 0; i < 10; i++) {
        int value = d.roll();
        REQUIRE(value >= 1);
        REQUIRE(value <= 6);
    }
}
