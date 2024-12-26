#include <iostream>
#include <vector>
#include <stdexcept>
#include "bomb.h"
#include "bombs_input.h"
#include <thread>
#include <iomanip>
#include <cctype>
bool is_int(const std::string& str) {
    if (str.empty()) return false;

    size_t start = 0;
    if (str[0] == '-') {
         return false;
    }

    for (size_t i = start; i < str.size(); ++i) {
        if (!isdigit(str[i])) {
            return false;
        }
    }

    return true;
}

bool is_valid_input(const std::string& input) {
    size_t dot_count = 0;
    for (char c: input) {
        if (c == '.') {
            dot_count++;
        } else if (!isdigit(c) && c != '-') {
            return false;
        }
    }
    return dot_count <= 1;
}

double strrtodbl(const std::string& input) {
    if (!is_valid_input(input)) {
        throw std::invalid_argument("Некорректный формат числа");
    }
    return std::stod(input);
}

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
        std::cout << i*10 << "% ";
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
        std::cout.flush();
    }
    std::cout << "\n";
    std::cout << "Ka-booooooom!\n";
}







void collect_info(std::vector<b::Bomb>& bombs) {
    std::string count;
    std::cout << "Введите количество бомб(Let's make some explosions!): ";
    std::cin >> count;
    if(count.size()>12){
        throw std::invalid_argument("слишком много цифр для работы с ними ");
    }
    else
        if (is_int(count)) {
            if (std::cin.fail()) {
                throw std::invalid_argument("Введите число для количества бомб");
            }

            if (!checkers::count_checker(std::stoi(count))) {
                throw std::invalid_argument("Неверное количество бомб");
            }

            b::Bomb bomb;
            for (int i = 0; i < std::stoi(count); i++) {
                std::cout << "Введите координаты и радиус бомбы под номером " << i + 1 << ":\n";
                std::string input;
                while (true) {
                    if (input.size() < 15) {
                        std::cout << "Координата X: ";
                        std::cin >> input;
                        try {
                            bomb.x = strrtodbl(input);
                            break;
                        } catch (const std::invalid_argument &e) {
                            std::cout << "Ошибка: " << e.what() << "\n";
                            std::cout << "Попробуйте снова \n";
                        }
                    } else {
                        throw std::invalid_argument(
                                "cлишком большое,слишком близкое к нулю или слишком маленькое число для X");
                    }
                }
                while (true) {
                    std::cout << "Координата Y: ";
                    std::cin >> input;
                    if (input.size() < 15) {
                        try {
                            bomb.y = strrtodbl(input);
                            break;
                        } catch (const std::invalid_argument &e) {
                            std::cout << "Ошибка: " << e.what() << "\n";
                            std::cout << "Попробуйте снова.\n";
                        }
                    } else {
                        throw std::invalid_argument(
                                "cлишком большое,слишком близкое к нулю или слишком маленькое число для Y");
                    }
                }

                while (true) {
                    std::cout << "Радиус: ";
                    std::cin >> input;
                    if (input.size() < 15) {
                        try {
                            bomb.radius = strrtodbl(input);
                            break;
                        } catch (const std::invalid_argument &e) {
                            std::cout << "Ошибка: " << e.what() << "\n";
                            std::cout << "Попробуйте снова.\n";
                        }
                    } else {
                        throw std::invalid_argument(
                                "cлишком большое,слишком близкое к нулю или слишком маленькое число для радиуса");
                    }

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
                    std::cout << "Бомба добавлена! Координаты: (" << std::setprecision(15) << bomb.x << ", "
                              << std::setprecision(15) << bomb.y << ") радиус: "
                              << std::setprecision(15) << bomb.radius << "\n";
                } else {
                    std::cout << "Ошибка в данных бомбы под номером " << i + 1
                              << ". Пожалуйста, введите данные снова.\n";
                    i--;
                }
            }
        } else {
            throw std::invalid_argument("Неправильные данные");
        }
    }






void print_result(std::vector<b::Bomb>& bombs, std::vector<int>& max_indexes, double max_area) {
    std::cout << "\nВведенные вами данные:\n";
    for (size_t i = 0; i < bombs.size(); ++i) {
        std::cout << "Бомба " << i + 1 << " на (" <<std::setprecision(15)<<bombs[i].x<<", "<< std::setprecision(15)<<bombs[i].y
                  << ") с радиусом " <<std::setprecision(15)<< bombs[i].radius << "\n";
    }
    std::cout << "\n";

    std::cout << "Запуск поиска наибольшей цепной реакции...\n";
    Animation();
    b::find_indexes_of_max_chain_reaction(bombs, max_indexes, max_area);

    std::cout << "Индекс максимальной цепной реакции: ";
    for (int index : max_indexes) {
        std::cout << index + 1 << " ";
    }
    std::cout << "\n";

    std::cout << "Площадь (взорванная) " <<std::setprecision(15)<<max_area<< "\n";
}
