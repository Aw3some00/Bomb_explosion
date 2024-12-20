#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "bomb.h"
#include <vector>
#include <stdexcept>
#include <cmath>

struct BombTest {
    b::Bomb bomb1{0, 0, 10, false};
    b::Bomb bomb2{5, 0, 10, false};
    b::Bomb bomb3{20, 20, 5, false};
    std::vector<b::Bomb> bombs{bomb1, bomb2, bomb3};
};

TEST_CASE("IsInRadius valid case") {
    BombTest test;
    CHECK(b::is_in_radius(test.bomb1, test.bomb2));
}

TEST_CASE("IntersectionArea valid case") {
    double area = b::intersection_area(10, 10, 5);
    CHECK(area > 0);

    area = b::intersection_area(10, 10, 50);
    CHECK(area == 0);
}

TEST_CASE("RadiusChecker boundary test") {
    CHECK(checkers::r_checker(0));
    CHECK(checkers::r_checker(5000));
    CHECK_THROWS_AS(checkers::r_checker(6000), std::invalid_argument);
}

TEST_CASE("Empty Bomb vector") {
    std::vector<b::Bomb> empty_bombs;
    CHECK_THROWS_AS(b::simulate_chain_reaction(empty_bombs, 0), std::out_of_range);
}

TEST_CASE("Out of bounds access") {
    BombTest test;
    CHECK_THROWS_AS(b::simulate_chain_reaction(test.bombs, 10), std::out_of_range);
}

TEST_CASE("Invalid data types") {
    std::vector<b::Bomb> invalid_bombs;
    CHECK_THROWS_AS(b::simulate_chain_reaction(invalid_bombs, 0), std::invalid_argument);
}

TEST_CASE("Max array size") {
    std::vector<b::Bomb> large_bombs(10000);
    CHECK_NOTHROW(b::simulate_chain_reaction(large_bombs, 0));
}

TEST_CASE("Bomb radius exceeds limit") {
    b::Bomb bomb{0, 0, 10000, false};
    CHECK_THROWS_AS(b::is_in_radius(bomb, BombTest().bomb1), std::out_of_range);
}

TEST_CASE("Invalid bomb type") {
    CHECK_THROWS_AS(b::is_in_radius(BombTest().bomb1, BombTest().bomb1), std::invalid_argument);
}

TEST_CASE("SimulateChainReaction valid case") {
    BombTest test;
    int detonated_count = b::simulate_chain_reaction(test.bombs, 0);
    CHECK(detonated_count == 2);
}

TEST_CASE("CalculateTotalAreaWithIntersections valid case") {
    BombTest test;
    test.bombs[0].exploded = true;
    test.bombs[1].exploded = true;

    double total_area = b::calculate_total_area_with_chain_reaction(test.bombs, 0);
    CHECK(total_area > 0);
}

TEST_CASE("FindIndexesOfMaxChainReaction valid case") {
    BombTest test;
    std::vector<int> max_indexes;
    double max_area = 0;

    b::find_indexes_of_max_chain_reaction(test.bombs, max_indexes, max_area);

    CHECK(!max_indexes.empty());
    CHECK(max_area > 0);
}

TEST_CASE("CountChecker invalid count") {
    CHECK_THROWS_AS(checkers::count_checker(-1), std::invalid_argument);
    CHECK_FALSE(checkers::count_checker(0));
    CHECK(checkers::count_checker(5));
}
