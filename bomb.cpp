#include <iostream>
#include <vector>



double procent_checker(double const percent) {
    if(percent > 100) {
        throw std::invalid_argument("percent is too high");
    }
    else if(percent < 0) {
        throw std::invalid_argument("percent is too small");
    }
    else if(percent == 0) {
        std::cout<<"there is no bomb on the field\n";
        return 0;
    }
    else if(percent == 100) {
        std::cout<<"all the bombs make a max row\n";
        return 0;
    }

}



    namespace nag {

        struct Bomb {
            double x;
            double y;
        };


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





