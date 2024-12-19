#include <iostream>
#include "bomb.h"
int main() {
    double count;
    double r;
    char ch;
    std::cout<<"Введите количество бомб ";
    std::cin>>count;
    std::cout<<"Введите радиус";
    std::cin>>r;
    std::cout<<"Выберите метод,доступно:\n бомба на рандом \n вы введете координаты бомб\n";
    std::cout<<"1 для cамостоятельного ввода или любое другое число для рандома\n";
    bool variant;
    std::cin>>variant;
    bool count_checker=checkers::count_checker(count);
    bool r_checker=checkers::r_checker(r);

    if(variant) {
        std::vector<b::Bomb> bombs;


        for (int i = 0; i < count; ++i) {
            double x, y;
            std::cout << "введите координаты бомбы " << (i + 1) << " (x y): ";
            std::cin >> x >>y;

            bombs.emplace_back(x, y, r);
        }
       double max= b::findbest(bombs,r);
        std::cout<<max;

    }
else {
        if (count_checker == true && r_checker == true) {
            b::printBombs(b::generateBombs(5, 5, count));
            b::findbest(b::generateBombs(5, 5, count), r);
        }
    }
    return 0;
}