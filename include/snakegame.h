#ifndef SNAKEGAME_H
#define SNAKEGAME_H

//#include "snake.h"
#include "level.h"
#include "prints.h"
#include "player.h"

/*! \class Snakegame
	\brief The main entity that instatiates all other objects and manages the game execution.

*/
class Snakegame
{
	private:
	//	Snake snake;
		Level * level;
		Player * player;
		size_t score = 0; //!< Stores the game score
		int current_level = 0; //!< Stores the number of the current running level.
		int lives = 10;
		int food_eaten = 0;
		int food_to_eat = 10;

	public:
		//=== Constructors / Destructor
		/// Default destructor
		explicit Snakegame( )
		{
			std::cout << "opaa\n";
			level = new Level;
			std::cout << "opaa\n";
			player = new Player;
			std::cout << "opaa\n";
		}

		/// Default destructor
		~Snakegame( )
		{/*Empty*/}

		//=== Methods
		/// Initializes the game
		void initialize_game( int argc, char* argv[] );

		/*update();*/

		void process_events( );

		/// Prints Status + Maze + Snake
		void render( );

		/// Checks if game is over, if it is, it prints the endgame screen and returns true, else returns false
		bool game_over();


};// Snakegame class

#endif