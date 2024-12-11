#include <iostream>
#include "bomb.h"
int main() {
    double count;

    std::cout<<"Введите количество бомб ";
    std::cin>>count;
    double percent_checker(count);
    b::printBombs( b::generateBombs(10000,10000,count));
    


    return 0;
}
