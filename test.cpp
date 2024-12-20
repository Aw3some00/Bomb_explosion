#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "bomb.h"
#include <vector>

TEST_SUITE("checkers::count_checker tests") {
    TEST_CASE("Valid counts") {
        CHECK(checkers::count_checker(1) == true);
        CHECK(checkers::count_checker(50000000) == true);
        CHECK(checkers::count_checker(99999999) == true);
    }

    TEST_CASE("Invalid counts - exceptions") {
        CHECK_THROWS_AS(checkers::count_checker(-1), std::invalid_argument);
        CHECK_THROWS_AS(checkers::count_checker(100000001), std::invalid_argument);
    }

    TEST_CASE("Edge cases") {
        CHECK_FALSE(checkers::count_checker(0));
        CHECK_FALSE(checkers::count_checker(100000000));
    }
}

TEST_SUITE("checkers::r_checker tests") {
    TEST_CASE("Valid radii") {
        CHECK(checkers::r_checker(1) == true);
        CHECK(checkers::r_checker(5000.5) == true);
        CHECK(checkers::r_checker(9999.9) == true);
    }

    TEST_CASE("Invalid radii - exceptions") {
        CHECK_THROWS_AS(checkers::r_checker(-1), std::invalid_argument);
        CHECK_THROWS_AS(checkers::r_checker(10000), std::invalid_argument);
    }

    TEST_CASE("Edge cases") {
        CHECK_FALSE(checkers::r_checker(0));
    }
}

TEST_SUITE("b::generateBombs tests") {
    TEST_CASE("Generate bombs on a large map") {
        int bomb_count = 10000;
        auto bombs = b::generateBombs(10000, 10000, bomb_count);
        CHECK(bombs.size() == bomb_count);

        for (const auto& bomb : bombs) {
            CHECK(bomb.x >= 0);
            CHECK(bomb.x <= 10000);
            CHECK(bomb.y >= 0);
            CHECK(bomb.y <= 10000);
        }
    }
}

TEST_SUITE("b::simulate_chain_reaction tests") {
    TEST_CASE("Bombs in chain reaction on large map") {
        std::vector<b::Bomb> bombs = {
            {0, 0}, {10, 10}, {20, 20}, {30, 30}
        };
        double radius = 15.0;
    //  CHECK(b::simulate_chain_reaction(bombs, 0, radius) == 4);
    }

    TEST_CASE("Bombs isolated on large map") {
        std::vector<b::Bomb> bombs = {
            {0, 0}, {5000, 5000}, {10000, 10000}
        };
        double radius = 100.0;
     // CHECK(b::simulate_chain_reaction(bombs, 0, radius) == 1);
    }
}

TEST_SUITE("b::findbest tests") {
    TEST_CASE("Find best explosion effect on large map") {
        std::vector<b::Bomb> bombs = {
            {0, 0}, {100, 100}, {200, 200}, {300, 300}
        };
        double radius = 150.0;
        double expected_area = 4 * M_PI * radius * radius;
        CHECK(b::findbest(bombs, radius) == doctest::Approx(expected_area));
    }

    TEST_CASE("Isolated bombs on large map") {
        std::vector<b::Bomb> bombs = {
            {0, 0}, {5000, 5000}, {9999, 9999}
        };
        double radius = 100.0;
        double expected_area = M_PI * radius * radius;
        CHECK(b::findbest(bombs, radius) == doctest::Approx(expected_area));
    }
}
