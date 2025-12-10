#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "come_out_phase.h"
#include "point_phase.h"
#include "roll.h"
#include "die.h"
#include <shooter.h>

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

TEST_CASE("Roll returns 2–12") {
    Die d1, d2;
    Roll r(d1, d2);

    for(int i = 0; i < 10; i++) {
        r.roll_dice();
        REQUIRE(r.roll_value() >= 2);
        REQUIRE(r.roll_value() <= 12);
    }
}

TEST_CASE("Shooter generates valid rolls") {
    Die d1, d2;
    Shooter shooter;

    for(int i = 0; i < 10; i++) {
        Roll* roll = shooter.throw_dice(d1, d2);
        REQUIRE(roll->roll_value() >= 2);
        REQUIRE(roll->roll_value() <= 12);
    }
}

TEST_CASE("ComeOutPhase outcome tests") {
    ComeOutPhase phase;
    Die d1, d2;

    Roll r1(d1, d2); r1.roll_dice();
    REQUIRE((phase.get_outcome(&r1) == RollOutcome::natural ||
             phase.get_outcome(&r1) == RollOutcome::craps ||
             phase.get_outcome(&r1) == RollOutcome::point));
}

TEST_CASE("PointPhase outcome tests") {
    Die d1, d2;
    PointPhase phase(5);

    Roll r1(d1, d2); r1.roll_dice();
    REQUIRE((phase.get_outcome(&r1) == RollOutcome::point ||
             phase.get_outcome(&r1) == RollOutcome::seven_out ||
             phase.get_outcome(&r1) == RollOutcome::nopoint));
}