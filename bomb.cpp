#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <stdexcept>
#include <tuple>
#include <map>
#include <set>
#include <algorithm>

namespace checkers {
    bool borders_check(double x) {
        return x >= -10000 && x <= 10000;
    }

    bool count_checker(double count) {
        if (count < 0) {
            throw std::invalid_argument("Слишком мало бомб\n");
        } else if (count == 0) {
            std::cout << "Отсутствие бомб на поле\n";
            return false;
        }
        return true;
    }

    bool r_checker(double radius) {
        if (radius <= 0) {
            throw std::invalid_argument("Радиус должен быть больше 0\n");
        } else if (radius > 5000) {
            throw std::invalid_argument("Радиус слишком большой\n");
        }
        return true;
    }
}
namespace b {
    struct Bomb {
        double x;
        double y;
        double radius;
        bool exploded = false;
    };


    bool is_in_radius(const Bomb& a, const Bomb& b) {
        double distance_squared = (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
        double radius_sum = a.radius + b.radius;
        return distance_squared <= radius_sum * radius_sum && !b.exploded;
    }


    int simulate_chain_reaction(std::vector<Bomb>& bombs, int start_index) {
        int detonated_count = 0;
        std::queue<int> q;


        for (auto& bomb : bombs) {
            bomb.exploded = false;
        }


        q.push(start_index);
        bombs[start_index].exploded = true;
        detonated_count++;


        while (!q.empty()) {
            int current = q.front();
            q.pop();


            for (int i = 0; i < bombs.size(); ++i) {
                if (i != current && !bombs[i].exploded && is_in_radius(bombs[current], bombs[i])) {
                    bombs[i].exploded = true;
                    detonated_count++;
                    q.push(i);
                }
            }
        }

        return detonated_count;
    }


    double calculate_area_of_explosion(const std::vector<Bomb>& bombs) {
        double total_area = 0;
        for (const auto& bomb : bombs) {
            if (bomb.exploded) {
                total_area += M_PI * bomb.radius * bomb.radius;
            }
        }
        return total_area;
    }


    double calculate_total_area_with_chain_reaction(std::vector<Bomb>& bombs, int start_index) {

        simulate_chain_reaction(bombs, start_index);


        return calculate_area_of_explosion(bombs);
    }


    void find_indexes_of_max_chain_reaction(std::vector<Bomb>& bombs, std::vector<int>& max_indexes, double& max_area) {
        int max_count = 0;


        for (int i = 0; i < bombs.size(); ++i) {

            std::vector<Bomb> bombs_copy = bombs;


            int detonated_count = simulate_chain_reaction(bombs_copy, i);
            double area = calculate_area_of_explosion(bombs_copy);


            if (detonated_count > max_count) {
                max_count = detonated_count;
                max_area = area;
                max_indexes.clear();
                max_indexes.push_back(i);
            }

            else if (detonated_count == max_count && area > max_area) {
                max_area = area;
                max_indexes.clear();
                max_indexes.push_back(i);
            }

            else if (detonated_count == max_count && area == max_area) {
                max_indexes.push_back(i);
            }
        }
    }
}