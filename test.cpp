#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "bomb.h"
#include <vector>


struct BombTest {
    b::Bomb bomb1{0, 0, 10, false};
    b::Bomb bomb2{5, 0, 10, false};
    b::Bomb bomb3{20, 20, 5, false};
    std::vector<b::Bomb> bombs{bomb1, bomb2, bomb3};
};


TEST_CASE("IsInRadius") {
    BombTest test;
    CHECK(b::is_in_radius(test.bomb1, test.bomb2));
    CHECK_FALSE(b::is_in_radius(test.bomb1, test.bomb3));
}


TEST_CASE("CountChecker") {
    CHECK_THROWS_AS(checkers::count_checker(-1), std::invalid_argument);
    CHECK_FALSE(checkers::count_checker(0));
    CHECK(checkers::count_checker(5));
}


TEST_CASE("RadiusChecker") {
    CHECK_THROWS_AS(checkers::r_checker(-5), std::invalid_argument);
    CHECK_THROWS_AS(checkers::r_checker(6000), std::invalid_argument);
    CHECK(checkers::r_checker(50));
}

TEST_CASE("IntersectionArea") {
    double area = b::intersection_area(10, 10, 5);
    CHECK(area > 0);

    area = b::intersection_area(10, 10, 50);
    CHECK(area == 0);
}

TEST_CASE("SimulateChainReaction") {
    BombTest test;
    int detonated_count = b::simulate_chain_reaction(test.bombs, 0);
    CHECK(detonated_count == 2);
}


TEST_CASE("CalculateTotalAreaWithIntersections") {
    BombTest test;
    test.bombs[0].exploded = true;
    test.bombs[1].exploded = true;

    double total_area = b::calculate_total_area_with_chain_reaction(test.bombs, 0);
    CHECK(total_area > 0);
}


TEST_CASE("FindIndexesOfMaxChainReaction") {
    BombTest test;
    std::vector<int> max_indexes;
    double max_area = 0;

    b::find_indexes_of_max_chain_reaction(test.bombs, max_indexes, max_area);

    CHECK(!max_indexes.empty());
    CHECK(max_area > 0);
}
