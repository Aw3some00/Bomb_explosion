#include <iostream>
#include "bomb.h"
int main() {
    double count;
    double r;
    std::cout<<"Введите количество бомб ";
    std::cin>>count;
    std::cout<<"Введите радиус ";
    std::cin>>r;
    std::cout<<"\n";

    bool count_checker=checkers::count_checker(count);
    bool r_checker=checkers::r_checker(r);
    if(count_checker==true && r_checker==true) {
       auto field= b::generateBombs(2,2,count);
        b::printBombs(field);
       std::cout<<b::findbest(field,r);


    }

    return 0;
}
