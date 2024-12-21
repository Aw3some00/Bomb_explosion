#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <stdexcept>
#include "bomb.h"


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
        if (radius < 0) {
            throw std::out_of_range("Радиус должен быть больше 0\n");
        } else if (radius > 5000) {
            throw std::out_of_range("Радиус слишком большой\n");
        }
        return true;
    }
}
namespace b {

    bool is_in_radius(const Bomb a, const Bomb b) {
        if(a.x==b.x && a.y==b.y && a.radius==b.radius){
            throw std::invalid_argument("одинаковые точки");
        }
        if(checkers::r_checker(a.radius)<5000 && checkers::r_checker(b.radius)) {
            double distance_squared = (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
            return distance_squared <= a.radius * a.radius && !b.exploded;
        }
        else{
            throw std::out_of_range("радиус слишком большой");
        }
    }

    double intersection_area(double R1, double R2,double d) {

        if (d >= R1 + R2 || d <= fabs(R1 - R2)) {
            return 0.0;
        }


        double part1 = R1 * R1 * acos((d * d + R1 * R1 - R2 * R2) / (2 * d * R1));
        double part2 = R2 * R2 * acos((d * d + R2 * R2 - R1 * R1) / (2 * d * R2));
        double part3 = sqrt((-d + R1 + R2) * (d + R1 - R2) * (d - R1 + R2) * (d + R1 + R2));

        return part1 + part2 - part3;
    }

    int simulate_chain_reaction(std::vector<Bomb>& bombs, int start_index) {
        if (bombs.empty()) {
            throw std::invalid_argument("Вектор бомб пуст");
        }

        if (start_index < 0 || start_index >= bombs.size()) {
            throw std::out_of_range("Индекс начала реакции выходит за пределы вектора бомб");
        }

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

double circle_area(double R1){
return M_Pi*R1*R1;
}



    double calculate_total_area_with_intersections(std::vector<Bomb>& bombs) {
        double total_area = 0;
        int count=0;
        for (int i = 0; i < bombs.size(); ++i) {
            if (bombs[i].exploded) {
                total_area += M_PI * bombs[i].radius * bombs[i].radius;

                for (int j = i + 1; j < bombs.size(); ++j) {
                    if (bombs[j].exploded) {
                        double distance = sqrt((bombs[i].x - bombs[j].x) * (bombs[i].x - bombs[j].x) +
                                           (bombs[i].y - bombs[j].y) * (bombs[i].y - bombs[j].y));
                        if (distance < bombs[i].radius + bombs[j].radius) {

                            total_area -= intersection_area(bombs[i].radius, bombs[j].radius,distance);
                        else if(distance < fabs(bombs[i].radius-bombs[j].radius)){
                            total_area-=circle_area(std::min(bombs[i].radius,bombs[j].radius));
                            
                        }
                    }
                }
            }
        }
        return total_area;
    }

    void find_indexes_of_max_chain_reaction(std::vector<Bomb>& bombs, std::vector<int>& max_indexes, double& max_area) {
        int max_count = 0;

        for (int i = 0; i < bombs.size(); ++i) {
            std::vector<Bomb> bombs_copy = bombs;

            int detonated_count = simulate_chain_reaction(bombs_copy, i);
            double area = calculate_total_area_with_intersections(bombs_copy);

            if (detonated_count > max_count) {
                max_count = detonated_count;
                max_area = area;
                max_indexes.clear();
                max_indexes.push_back(i);
            }

            else if (detonated_count == max_count && area > max_area) {
                max_area = area;
                max_indexes.push_back(i);
            }

            else if (detonated_count == max_count && area == max_area) {
                max_indexes.push_back(i);
            }
        }
    }
}