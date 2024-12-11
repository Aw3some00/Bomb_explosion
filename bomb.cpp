#include <iostream>
#include <vector>
#include <math.h>

namespace checkers {
    bool count_checker(double const percent) {
        if(percent > 100000000) {
            throw std::invalid_argument("percent is too high");
            return false;
        }
        else if(percent < 0) {
            throw std::invalid_argument("percent is too small");
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

    }
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
    }
    namespace b {
        struct Bomb {

            double x;
            double y;
            bool is_exploded=false;
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

                double x = static_cast<double>(std::rand()) / RAND_MAX * rows;
                double y = static_cast<double>(std::rand()) / RAND_MAX * cols;

                bombs.push_back({x, y});
            }

            return bombs;
        }


        void printBombs(const std::vector<Bomb>& bombs) {
            for (const auto& bomb : bombs) {
                std::cout << "Bomb at (" << bomb.x << ", " << bomb.y << ")\n";
            }
        }
    }





