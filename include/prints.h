#ifndef PRINTS_H
#define PRINTS_H

#include <iostream>
#include <string>

void printmenu(int loaded_levels, int starting_lives, int food_to_eat);

void printstatus(int lives, size_t score, int food, int food_to_eat);

void printgame();

void printendgame(std::string cause);

#endif
