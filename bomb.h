#ifndef BOMB_H
#define BOMB_H

#include <iostream>
#include <vector>

namespace checkers {
    bool count_checker(double const percent);
    bool r_checker(double const r);
}

namespace b {
    struct Bomb {
        double x;
        double y;
        bool exploded;
    };

    bool is_in_radius(Bomb a, Bomb b, double r);
    std::vector<Bomb> generateBombs(int rows, int cols, int ones_count);
    void printBombs(const std::vector<Bomb>& bombs);
    int simulate_chain_reaction(const std::vector<Bomb>& bombs, int start_index, double r);
    double findbest(std::vector<Bomb> bombs,double r);

    // Функция для симуляции детонации
    int simulate_chain_reaction(const std::vector<Bomb>& bombs, int start_index, double r);
}

#endif // BOMB_H
