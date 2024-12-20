#include <iostream>
#include <vector>
#include <stdexcept>
#include "bomb.h"
#include "bomb.h"
#include <thread>
#include <chrono>


bool is_duplicate(const std::vector<b::Bomb>& bombs, const b::Bomb& new_bomb) {
    for (const auto& bomb : bombs) {
        if (bomb.x == new_bomb.x && bomb.y == new_bomb.y) {
            return true;
        }
    }
    return false;
}

void Animation() {
    std::cout << "Boom!  The chain reaction begins!\"\n";
    for (int i = 0; i < 10; ++i) {
        std::cout << i * 10 << "% ";
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        std::cout.flush();
    }
    std::cout << "\n";
    std::cout << "Ka-booooooom!\n";
}

void collect_info(std::vector<b::Bomb>& bombs) {
    double count;
    std::cout << "Введите количество бомб(Let's make some explosions!): ";
    std::cin >> count;

    if (std::cin.fail()) {
        throw std::invalid_argument("Введите число для количества бомб");
    }

    if (!checkers::count_checker(count)) {
        std::cerr << "Неверное количество бомб\n";
        throw std::invalid_argument("Неверное количество бомб");
    }

    b::Bomb bomb;
    for (int i = 0; i < count; i++) {
        std::cout << "Введите координаты и радиус бомбы под номером " << i + 1 << ":\n";
        std::cout << "Координата X: ";
        std::cin >> bomb.x;
        if (std::cin.fail()) {
            throw std::invalid_argument("Введите число для координаты X");
        }

        std::cout << "Координата Y: ";
        std::cin >> bomb.y;
        if (std::cin.fail()) {
            throw std::invalid_argument("Введите число для координаты Y");
        }

        std::cout << "Радиус: ";
        std::cin >> bomb.radius;
        if (std::cin.fail()) {
            throw std::invalid_argument("Введите число для радиуса");
        }

        if (checkers::r_checker(bomb.radius) &&
            checkers::borders_check(bomb.x) &&
            checkers::borders_check(bomb.y)) {


            if (is_duplicate(bombs, bomb)) {
                std::cout << "Ошибка! Бомба с такими координатами уже существует!\n";
                i--;
                continue;
            }

            bombs.push_back(bomb);
            std::cout << "Бомба добавлена! Координаты: (" << bomb.x << ", " << bomb.y << "), радиус: "
                      << bomb.radius << std::endl;
        } else {
            std::cout << "Ошибка в данных бомбы под номером " << i + 1 << ". Пожалуйста, введите данные снова.\n";
            i--;
        }
    }
}

void print_result(std::vector<b::Bomb>& bombs, std::vector<int>& max_indexes, double max_area) {
    std::cout << "\nВведенные вами данные:\n";
    for (size_t i = 0; i < bombs.size(); ++i) {
        std::cout << "Бомба " << i + 1 << " на (" << bombs[i].x << ", " << bombs[i].y
                  << ") с радиусом " << bombs[i].radius << "\n";
    }
    std::cout << "\n";

    std::cout << "Запуск поиска наибольшей цепной реакции...\n";
    Animation();
    b::find_indexes_of_max_chain_reaction(bombs, max_indexes, max_area);

    system("clear");

    std::cout << "Индекс максимальной цепной реакции: ";
    for (int index : max_indexes) {
        std::cout << index + 1 << " ";
    }
    std::cout << "\n";

    std::cout << "Площадь (взорванная) " << max_area << "\n";
}
