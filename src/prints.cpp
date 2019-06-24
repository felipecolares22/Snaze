#include "prints.h"

//=== Print functions
/// Prints the status of the actual run.
void printstatus( int lives, size_t score, int food_eaten, int food_to_eat, int current_level )
{
	struct winsize size;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);
	// TODO: put '♥' instead of '?'
	std::cout << std::setw(size.ws_col) << std::setfill('-') << "" << std::endl << std::endl
			  << std::setw( (size.ws_col-70)/2) << std::setfill(' ') << "" << "Lives: " << std::setw(lives) << std::setfill('?') << "" << " | Score: " << score << " | Food eaten: " << food_eaten << " out of " << food_to_eat << " | Current Level: " << current_level << std::endl
			  << std::setw(size.ws_col) << std::setfill('-') << "" << std::endl;
}

/// Prints the game main menu.
void printmenu( int loaded_levels, int starting_lives, size_t score, int food_to_eat )
{
	system("clear");
	struct winsize size;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);

	std::cout<< std::setw( (size.ws_col-43)/2 ) << std::setfill(' ') << "" << "---> Welcome to the classic Snake Game <---" << std::endl
			 << std::setw( (size.ws_col-25)/2 ) << std::setfill(' ') << "" << "copyright DIMap/UFRN 2017" << std::endl
			 << std::setw( size.ws_col) << std::setfill('-') << "" << std::endl
			 << std::setw( (size.ws_col-54)/2 ) << std::setfill(' ') << "" << "Levels Loaded: " << loaded_levels << " | Snake lives: " << starting_lives << " | Apples to eat: " << food_to_eat << std::endl
			 << std::setw( (size.ws_col-46)/2 ) << std::setfill(' ') << "" << "Clear all levels to win the game. Good Luck!!!" << std::endl
			 << std::setw( (size.ws_col-40)/2 ) << std::setfill(' ') << "" << ">>> Press <ENTER> to start the game! <<<" << std::endl;
	printstatus(starting_lives, score, 0, food_to_eat, 1);
	getchar();
	system("clear");
}

/// Prints the game itself (maze+snake).
void printgame();

/// Prints the end game screens (crashing into a wall, losing all lives)
void printendgame( int score )
{
	system("clear");
	struct winsize size;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);

	for( int i = 0 ; i < size.ws_row/2 ; i++ )
	{
		std::cout<<std::endl;
	}
	std::cout<< std::setw( (size.ws_col-16) / 2 ) << std::setfill(' ') << "" << ">>> END GAME <<<\n";
	std::cout<< std::setw( (size.ws_col-11) / 2 ) << std::setfill(' ') << "" << "Score: " << score << std::endl;
	getchar();
	system("clear");
}

