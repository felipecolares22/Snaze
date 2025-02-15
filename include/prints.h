#ifndef PRINTS_H
#define PRINTS_H

#include <iostream>
#include <string>
#include <iomanip>
#include <sys/ioctl.h>
#include <unistd.h>
#include <fstream>

/// Prints the status of the actual run.
void printstatus( int lives, size_t score, int food, int food_to_eat, int current_level );

/// Prints the game main menu.
void printmenu( int loaded_levels, int starting_lives, size_t score, int food_to_eat );

/// Prints the game itself (maze+snake).
void printgame( );

/// Prints the next level screen
void printnextlevel( );

/// Prints the end game screens (crashing into a wall, losing all lives)
void printendgame( int score );

#endif
