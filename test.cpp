#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "bomb.h"
#include "bombs_input.cpp"
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
    CHECK_FALSE(b::is_in_radius(test.bomb1, test.bomb3));
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
    CHECK_THROWS_AS(checkers::r_checker(6000), std::out_of_range);
    CHECK_THROWS_WITH(checkers::r_checker(-10),"Радиус должен быть больше 0");
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


    for (int i = 0; i < 10000; ++i) {
        large_bombs[i].x = i * 10;
        large_bombs[i].y = i * 20;
        large_bombs[i].radius = 10;
    }

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

TEST_CASE("is_duplicate tests") {
    std::vector<b::Bomb> bombs = {
            {0, 0, 5},
            {1, 1, 3}
    };

    b::Bomb bomb1 = {0, 0, 5};
    b::Bomb bomb2 = {2, 2, 4};

    CHECK(is_duplicate(bombs, bomb1));
    CHECK_FALSE(is_duplicate(bombs, bomb2));
}



TEST_CASE("Testing collect_info with input redirection") {
    std::vector<b::Bomb> bombs;

}



TEST_CASE("simulate_chain_reaction tests") {
    std::vector<b::Bomb> bombs = {
            {0, 0, 5},
            {1, 1, 3},
            {5, 5, 1}
    };

    CHECK_EQ(b::simulate_chain_reaction(bombs, 0), 2);

    bombs[0].exploded = false;
    CHECK_EQ(b::simulate_chain_reaction(bombs, 1), 2);
}

