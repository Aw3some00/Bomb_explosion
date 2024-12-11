#include <iostream>
#include "bomb.h"
int main() {
    double count;
    double r;
    std::cout<<"Введите количество бомб ";
    std::cin>>count;
    std::cout<<"Введите радиус";
    std::cin>>r;

    bool count_checker=checkers::count_checker(count);
    bool r_checker=checkers::r_checker(r);
    if(count_checker==true && r_checker==true) {
        b::printBombs( b::generateBombs(5,5,count));
    }

    return 0;
}
