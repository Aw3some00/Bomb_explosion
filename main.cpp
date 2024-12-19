#include <iostream>
#include<vector>
#include "bomb.h"
#include <thread>
#include <chrono>
#include <sstream>
#include <string>
#include <cstdlib>
void Animation(){
        std::cout << "Загрузка\n";
        for (int i = 0; i < 10; ++i) {
            std::cout << i*10<<"% ";
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            std::cout.flush();
        }
        std::cout<<"\n";
        std::cout << "Загрузка завершена!\n";
    }

int main() {
    double count;
    std::vector<double> radii;
    std::cout << "Введите количество бомб ";
    std::cin >> count;
    if (std::cin.fail()) {
        throw std::invalid_argument("введите число");

    }

    bool count_checker = checkers::count_checker(count);
    std::vector<b::Bomb> bombs;
    if (count_checker) {
        b::Bomb bomb;
        for (int i = 0; i < count; i++) {
            std::cout << "Введите координаты и радиус бомбы под номером " << i + 1 << ":\n";
            std::cout << "Координата X: ";
            std::cin >> bomb.x;
            if (std::cin.fail()) {
                throw std::invalid_argument("введите число в переменную x");

            }
            std::cout << "Координата Y: ";
            std::cin >> bomb.y;
            if (std::cin.fail()) {
                throw std::invalid_argument("введите число в переменную y");

            }
            std::cout << "Радиус: ";
            std::cin >> bomb.radius;
            if (std::cin.fail()) {
                throw std::invalid_argument("введите число в радиус");

            }

            try {
                std::cout << "\n";

                if (checkers::r_checker(bomb.radius) &&
                    checkers::borders_check(bomb.x) &&
                    checkers::borders_check(bomb.y)) {
                    bombs.push_back(bomb);
                    std::cout << "Бомба добавлена! Координаты: (" << bomb.x << ", " << bomb.y << "), радиус: "
                              << bomb.radius << std::endl;
                } else {
                    std::cout << "Ошибка в данных бомбы под номером " << i + 1 << std::endl;
                    std::cout << "введите данные снова \n";
                    i--;

                }

            } catch (const std::exception &e) {
                std::cerr << "Произошла ошибка: " << e.what() << std::endl;
                return 1;
            }
        }

    }
    std::cout << "\n";
    std::cout << "Введенные вами данные{:\n";
    for (size_t i = 0; i < bombs.size(); ++i) {
        std::cout << "бомба" << i + 1 << " на (" << bombs[i].x << ", " << bombs[i].y
                  << ") с радиусом " << bombs[i].radius << "\n";
    }
    std::cout << "}\n\n\n\n";

    std::cout << "запуск поиска наибольшей цепной реакции...\n";
      Animation();
    std::vector<int> max_indexes;
    double max_area = 0;


    b::find_indexes_of_max_chain_reaction(bombs, max_indexes, max_area);

    system("clear");
    
    std::cout << "Индекс макс цепной: ";
    for (int index : max_indexes) {
        std::cout << index+1 << " ";
    }
    std::cout << "\n";

    std::cout << "Площадь(взорванная) " << max_area << "\n";

    return 0;



}