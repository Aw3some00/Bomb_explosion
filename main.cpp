#include <iostream>
#include <vector>
#include "bomb.h"
#include "bombs_input.cpp"

int main() {
    try {
        std::vector<bomb::Bomb> bombs;

        collect_info(bombs);


        std::vector<int> max_indexes;
        double max_area = 0;


        print_result(bombs, max_indexes, max_area);
    } catch (const std::exception &e) {
        std::cerr << "Произошла ошибка: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
