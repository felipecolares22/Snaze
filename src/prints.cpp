#include "prints.h"

//=== Print functions
/// Prints the game main menu.
void printmenu( int loaded_levels, int starting_lives, int food_to_eat )
{
	struct winsize size;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);
	std::cout<< std::setw((size.ws_row-43)/2) << std::setfill(' ') << "---> Welcome to the classic Snake Game <---" << std::endl
			 << std::setw((size.ws_row-25)/2) << std::setfill(' ') << "copyright DIMap/UFRN 2017" << std::endl
			 << std::setw(size.ws_row) << std::setfill('-') << std::endl
			 << std::setw(size.ws_row) << std::setfill(' ') << "Levels Loaded: " << loaded_levels << " | Snake lives: " << starting_lives << " | Apples to eat: " << food_to_eat << std::endl
			 << std::setw((size.ws_row-46)/2) << std::setfill(' ') << "Clear all levels to win the game. Good Luck!!!" << std::endl
			 << std::setw((size.ws_row-40)/2) << std::setfill(' ') << ">>> Press <ENTER> to start the game! <<<" << std::endl;
}

/// Prints the status of the actual run.
void printstatus( int lives, size_t score, int food_eaten, int food_to_eat, int current_level )
{
	std::cout << std::setw(size.ws_row) << std::setfill('-') << std::endl << std::endl
			  << "Lives: " << std::setw(5-lives) << std::setfill('♥') << " | Score: " << score << " | Food eaten: " << food_eaten << " out of " << food_to_eat << std::endl
			  << std::setw(size.ws_row) << std::setfill('-') << std::endl;
}

/// Prints the game itself (maze+snake).
void printgame();

/// Prints error messages
void print_errors( std::string error )
{
	if( error == "many arguments" )
		std::cout << "Too many arguments, rerun the program with a valid number of arguments\n";
	
	else if( error == "invalid level size" )
		std::cout << " ERROR: Invalid level size\n";
}

/// Prints the end game screens (crashing into a wall, losing all lives)
void printendgame( int lives );

