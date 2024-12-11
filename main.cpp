#include <iostream>
#include "bomb.h"
int main() {
    double procent;

    std::cout<<"Введите процент заполненности поля ";
    std::cin>>procent;
    double percent_checker(procent);
    nag::printBombs( nag::generateBombs(10000,10000,procent*1000000));


    return 0;
}
