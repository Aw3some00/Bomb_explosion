#include <iostream>
#include "bomb.h"

int main() {
    double count;
    double r;
    std::cout << "Введите количество бомб: ";
    std::cin >> count;
    std::cout << "Введите радиус взрыва: ";
    std::cin >> r;


    bool count_checker = checkers::count_checker(count);
    bool r_checker = checkers::r_checker(r);

    if (count_checker && r_checker) {

        auto bombs = b::generateBombs(1000, 1000, count);

        std::cout << "Сгенерированные бомбы:\n";
        b::printBombs(bombs);

        // Выбор случайной бомбы для детонации
        int start_index = 0;

        int detonated_count = b::simulate_chain_reaction(bombs, start_index, r);

        std::cout << "Количество взорванных бомб: " << detonated_count << "\n";
    }

    return 0;
}
