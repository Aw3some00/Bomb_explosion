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


TEST_CASE("is_in_radius tests") {
    BombTest test;
    CHECK(b::is_in_radius(test.bomb1, test.bomb2));
    CHECK_FALSE(b::is_in_radius(test.bomb1, test.bomb3)); 
}

// Проверка расчета площади пересечения
TEST_CASE("intersection_area tests") {

    double area = b::intersection_area(10, 10, 5);
    CHECK(area > 0);

    area = b::intersection_area(10, 10, 50);
    CHECK(area == 0);
}

// Проверка функции r_checker
TEST_CASE("r_checker boundary tests") {
    CHECK(checkers::r_checker(1));  
    CHECK(checkers::r_checker(5000));  
    CHECK_THROWS_AS(checkers::r_checker(6000), std::out_of_range); 
    CHECK_THROWS_AS(checkers::r_checker(-10), std::invalid_argument); 
}

// Проверка  цепной реакции
TEST_CASE("simulate_chain_reaction tests") {
    BombTest test;
    int detonated_count = b::simulate_chain_reaction(test.bombs, 0);

    CHECK_EQ(detonated_count, 2);

    for (auto& bomb : test.bombs) {
        bomb.exploded = true;
    }
    CHECK_EQ(b::simulate_chain_reaction(test.bombs, 0), 0);
}

// Проверка поиска индексов максимальной цепной реакции
TEST_CASE("find_indexes_of_max_chain_reaction tests") {
    BombTest test;
    std::vector<int> max_indexes;
    double max_area = 0;

    b::find_indexes_of_max_chain_reaction(test.bombs, max_indexes, max_area);


    CHECK_FALSE(max_indexes.empty());
    CHECK_GT(max_area, 0);
}


TEST_CASE("Error handling tests") {
    // Проверка на недопустимый радиус
    CHECK_THROWS_AS(checkers::r_checker(10000), std::out_of_range);

    // Проверка на пустой массив бомб
    std::vector<b::Bomb> empty_bombs;
    CHECK_THROWS_AS(b::simulate_chain_reaction(empty_bombs, 0), std::invalid_argument);

    // Проверка на дублирующиеся бомбы
    std::vector<b::Bomb> bombs = {{0, 0, 10}, {0, 0, 10}};
    CHECK(is_duplicate(bombs, b::Bomb{0, 0, 10}));
}


TEST_CASE("Large array tests") {
    std::vector<b::Bomb> large_bombs(10000);
    for (int i = 0; i < 10000; ++i) {
        large_bombs[i] = {i * 10, i * 20, 10, false};
    }


    CHECK_NOTHROW(b::simulate_chain_reaction(large_bombs, 0));
}
