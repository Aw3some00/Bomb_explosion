#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "bomb.h"
#include "bombs_input.h"



struct BombTest {
    bomb::Bomb bomb1{0, 0, 10, false};
    bomb::Bomb bomb2{5, 0, 10, false};
    bomb::Bomb bomb3{20, 20, 5, false};
    std::vector<bomb::Bomb> bombs{bomb1, bomb2, bomb3};
};

TEST_CASE("IsInRadius valid case") {
    BombTest test;
    CHECK(bomb::is_in_radius(test.bomb1, test.bomb2));
    CHECK_FALSE(bomb::is_in_radius(test.bomb1, test.bomb3));
}

TEST_CASE("IntersectionArea valid case") {
    double area = bomb::intersection_area(10, 10, 5);
    CHECK(area > 0);

    area = bomb::intersection_area(10, 10, 50);
    CHECK(area == 0);
}


TEST_CASE("RadiusChecker boundary test") {
    CHECK(checkers::r_checker(0));
    CHECK(checkers::r_checker(5000));
    CHECK_THROWS_AS(checkers::r_checker(11000), std::out_of_range);
    CHECK_THROWS_WITH(checkers::r_checker(-10),"Радиус должен быть больше 0");
}

TEST_CASE("Out of bounds access") {
    BombTest test;
    CHECK_THROWS_AS(bomb::simulate_chain_reaction(test.bombs, 10), std::out_of_range);
}

TEST_CASE("Invalid data types") {
    std::vector<bomb::Bomb> invalid_bombs;
    CHECK_THROWS_AS(bomb::simulate_chain_reaction(invalid_bombs, 0), std::invalid_argument);
}

TEST_CASE("Max array size") {
    std::vector<bomb::Bomb> large_bombs(10000);


    for (int i = 0; i < 10000; ++i) {
        large_bombs[i].x = i * 10;
        large_bombs[i].y = i * 20;
        large_bombs[i].radius = 10;
    }

    CHECK_NOTHROW(bomb::simulate_chain_reaction(large_bombs, 0));
}

TEST_CASE("Bomb radius exceeds limit") {
    bomb::Bomb bomb{0, 0, 10001, false};
    CHECK_THROWS_AS(bomb::is_in_radius(bomb, BombTest().bomb1), std::out_of_range);
}

TEST_CASE("Invalid bomb type") {
    CHECK_THROWS_AS(bomb::is_in_radius(BombTest().bomb1, BombTest().bomb1), std::invalid_argument);
}

TEST_CASE("SimulateChainReaction valid case") {
    BombTest test;
    int detonated_count = bomb::simulate_chain_reaction(test.bombs, 0);
    CHECK(detonated_count == 2);
}


TEST_CASE("FindIndexesOfMaxChainReaction valid case") {
    BombTest test;
    std::vector<int> max_indexes;
    double max_area = 0;

    bomb::find_indexes_of_max_chain_reaction(test.bombs, max_indexes, max_area);

    CHECK(!max_indexes.empty());
    CHECK(max_area > 0);
}

TEST_CASE("CountChecker invalid count") {
    CHECK_THROWS_AS(checkers::count_checker(-1), std::invalid_argument);
    CHECK_FALSE(checkers::count_checker(0));
    CHECK(checkers::count_checker(5));

}

TEST_CASE("is_duplicate tests") {
    std::vector<bomb::Bomb> bombs = {
            {0, 0, 5},
            {1, 1, 3}
    };

    bomb::Bomb bomb1 = {0, 0, 5};
    bomb::Bomb bomb2 = {2, 2, 4};

    CHECK(is_duplicate(bombs, bomb1));
    CHECK_FALSE(is_duplicate(bombs, bomb2));
}




TEST_CASE("simulate_chain_reaction tests") {
    std::vector<bomb::Bomb> bombs = {
            {0, 0, 5},
            {1, 1, 3},
            {5, 5, 1}
    };

    CHECK_EQ(bomb::simulate_chain_reaction(bombs, 0), 2);

    bombs[0].exploded = false;
    CHECK_EQ(bomb::simulate_chain_reaction(bombs, 1), 2);
}

