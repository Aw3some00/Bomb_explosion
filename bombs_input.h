#ifndef BOMB_INPUT_H
#define BOMB_INPUT_H
#include <iostream>
#include <vector>
#include "bomb.h"


bool is_duplicate(const std::vector<b::Bomb>& bombs, const b::Bomb& new_bomb);
void Animation() ;
void collect_info(std::vector<b::Bomb>& bombs);
void print_result(std::vector<b::Bomb>& bombs, std::vector<int>& max_indexes, double max_area);


#endif //BOMB_INPUT_H