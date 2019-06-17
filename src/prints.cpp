#include "prints.h"

/// Prints the game main menu.
void printmenu(int loaded_levels, int starting_lives, int food_to_eat)
{
	struct winsize size;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);
	std::cout<< std::setw((size.ws_row-43)/2) << std::setfill(' ') << "---> Welcome to the classic Snake Game <---" << std::endl
			 << std::setw((size.ws_row-25)/2) << std::setfill(' ') << "copyright DIMap/UFRN 2017" << std::endl
			 << std::setw(size.ws_row) << std::setfill('-') << std::endl
			 << std::setw(size.ws_row) << std::setfill(' ') << "Levels Loaded: " << loaded_levels << " | Snake lives: " << starting_lives << " | Apples to eat: " << food_to_eat << std::endl
			 << std::setw((size.ws_row-)/2) << std::setfill(' ') << "Clear all levels to win the game. Good Luck!!!" << std::endl;
}

/// Prints the status of the actual run.
void printstatus(int lives, size_t score, int food, int food_to_eat, int current_level);

/// Prints the game itself (maze+snake).
void printgame();

/// Prints the end game screens (crashing into a wall, losing all lives)
void printendgame(int lives);

