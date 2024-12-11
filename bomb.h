#ifndef BOMB_H
#define BOMB_H
#include <iostream>
#include <vector>


double procent_checker(double const percent);
namespace nag{
    struct Bomb {
        double x;
        double y;
    };
    std::vector<Bomb> generateBombs(int rows, int cols, int ones_count);
    void printBombs(const std::vector<Bomb>& bombs);

}
#endif //BOMB_H