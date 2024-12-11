#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <ctime>
#include "bomb.h"

namespace checkers {
    bool count_checker(double const percent) {
        if (percent > 100000000) {
            throw std::invalid_argument("count of bombs is too high");
            return false;
        } else if (percent < 0) {
            throw std::invalid_argument("count of bombs is too small");
            return false;
        } else if (percent == 0) {
            std::cout << "there is no bomb on the field\n";
            return false;
        } else if (percent == 100000000) {
            std::cout << "all the bombs make a max row\n";
            return false;
        }
        return true;
    }

    bool r_checker(double const radius) {
        if (radius < 0) {
            throw std::invalid_argument("radius is too small");
            return false;
        } else if (radius >= 10000) {
            throw std::invalid_argument("radius is too high");
            return false;
        } else if (radius == 0) {
            std::cout << "max explosion length is 0";
            return false;
        } else if (radius == 10000) {
            std::cout << "max explosion length is all the bombs";
            return false;
        }
        return true;
    }
}

namespace b {

    bool is_in_radius(Bomb a, Bomb b, double r) {
        double distance_squared = (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
        return distance_squared <= r * r;
    }


    int simulate_chain_reaction(const std::vector<Bomb>& bombs, int start_index, double r) {
        std::vector<bool> visited(bombs.size(), false);
        std::queue<int> q;
        int detonated_count = 0;


        q.push(start_index);
        visited[start_index] = true;

        while (!q.empty()) {
            int current = q.front();
            q.pop();
            detonated_count++;


            for (int i = 0; i < bombs.size(); ++i) {
                if (!visited[i] && is_in_radius(bombs[current], bombs[i], r)) {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
        return detonated_count;
    }
}

