#include <iostream>
#include <vector>
#include <math.h>
#include <cmath>
#include <map>
#include <set>
namespace checkers {
    bool count_checker(double const percent) {
        if(percent > 100000000) {
            throw std::invalid_argument("count of bombs is too high");
            return false;
        }
        else if(percent < 0) {
            throw std::invalid_argument("count of bombs is too small");
            return false;
        }
        else if(percent == 0) {
            std::cout<<"there is no bomb on the field\n";
            return false;
        }
        else if(percent == 100000000) {
            std::cout<<"all the bombs make a max row\n";
            return false;
        }
        return true;

    }

    bool r_checker(double const radius) {
        if(radius < 0) {
            throw std::invalid_argument("radius is too small");
            return false;
        }
        else if(radius >=10000) {
            throw std::invalid_argument("radius is too high");
            return false;
        }
        else if(radius == 0) {
            std::cout<<"max explosion lenght is 0";
            return false;
        }
        else if(radius == 10000) {
            std::cout<<"max explosion lenght it is all the bombs";
            return false;
        }
        return true;
    }
}
    namespace b {
    struct Bomb {

        double x;
        double y;
        bool exploded=false;
    };

    bool is_in_radius(Bomb a,Bomb b,double r) {
        double ds= (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
        if(ds<=r*r) {
            return true;
        }
        else {
            return false;
        }
    }

    std::vector<Bomb> generateBombs(int rows, int cols, int ones_count) {
        std::vector<Bomb> bombs;


        std::srand(std::time(nullptr));

        while (bombs.size() < ones_count) {

            double x = static_cast<double>(std::rand()) /RAND_MAX * rows;
            double y = static_cast<double>(std::rand()) /RAND_MAX * cols;

            bombs.push_back({x, y});
        }

        return bombs;
    }

    int simulate_chain_reaction(std::vector<Bomb>& bombs, int start_index, double r) {
        int detonated_count = 0;

        for (auto& bomb : bombs) {
            bomb.exploded = false;
        }

        std::queue<int> q;
        q.push(start_index);
        bombs[start_index].exploded = true;
        detonated_count++;


        while (!q.empty()) {
            int current = q.front();
            q.pop();

            for (int i = 0; i < bombs.size(); ++i) {
                if (!bombs[i].exploded && is_in_radius(bombs[current], bombs[i], r)) {
                    bombs[i].exploded = true;
                    detonated_count++;
                    q.push(i);
                }
            }
        }

        return detonated_count;
    }


    double findbest(std::vector<Bomb> bombs, double r) {
        int max = 0;
        std::multimap<int, int, std::greater<int>> index_of_max_exp;;
        for (int i = 0; i < bombs.size(); ++i) {
            for (auto& bomb : bombs) {
                bomb.exploded = false;
            }

            int detonated = simulate_chain_reaction(bombs, i, r);
            index_of_max_exp.insert(std::make_pair(detonated, i));
            if (detonated > max) {
                max = detonated;
            }

        }
    std::cout<<"индексы бомб с максимальной цеанной реакцией \n";
        for (const auto& entry : index_of_max_exp) {
            if (entry.first == max) {
                std::cout<<entry.second + 1 << ' ';
            } else {
                break;
            }
        }

std::cout<<"\nМаксимальный радиус поражения: ";
return M_PI*r*r*max;
    }







    void printBombs(const std::vector<Bomb>& bombs) {
            for (const auto& bomb : bombs) {
                std::cout << "Bomb at (" << bomb.x << ", " << bomb.y << ")\n";
            }
        }
    }





