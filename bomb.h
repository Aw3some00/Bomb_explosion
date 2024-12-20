#ifndef BOMB_H
#define BOMB_H
#include <iostream>
#include <vector>
#include <algorithm>

namespace checkers {
    bool count_checker(double const percent);
    bool r_checker(double const r);
    bool borders_check(double const x);
}
namespace b{
    struct Bomb {
        double x;
        double y;
        double radius;
        bool exploded;
    };
    bool is_in_radius(Bomb a,Bomb b);
    std::vector<Bomb> generateBombs(int rows, int cols, int ones_count, double min_radius, double max_radius);
    void printBombs(const std::vector<Bomb>& bombs);
    double intersection_area(double R1, double R2, double d);
    int simulate_chain_reaction(const std::vector<Bomb>& bombs, int start_index);
    double calculate_area_of_explosion(const std::vector<Bomb>& bombs);
    double calculate_total_area_with_chain_reaction(std::vector<Bomb>& bombs, int start_index);
    void find_indexes_of_max_chain_reaction(std::vector<Bomb>& bombs, std::vector<int>& max_indexes, double& max_area);

}

#endif //BOMB_H