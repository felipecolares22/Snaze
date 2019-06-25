#ifndef SNAKEGAME_H
#define SNAKEGAME_H

#include "snake.h"
#include "level.h"
#include "prints.h"
#include "player.h"

/*! \class Snakegame
	\brief The main entity that instatiates all other objects and manages the game execution.

*/
class Snakegame
{
	private:
		Snake * snake;
		Level * level;
		Player * player;
		size_t score = 0; //!< Stores the game score
		int current_level = 0; //!< Stores the number of the current running level.
		int lives = 5;
		int food_eaten = 0;
		int food_to_eat = 10;
		std::pair< int, int > food_pos; //!< Stores the food pellet's position on the level;

		int random_numbers_x()
		{
			std::random_device dev;
			std::mt19937 rng( dev() );
			std::uniform_int_distribution<std::mt19937::result_type> dist6( 1, level->levels[current_level].dimensions.first );
			return dist6(rng);
		}

		int random_numbers_y()
		{
			std::random_device dev;
			std::mt19937 rng( dev() );
			std::uniform_int_distribution<std::mt19937::result_type> dist6( 1, level->levels[current_level].dimensions.second );
			return dist6(rng);
		}

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
			snake = new Snake;
		}

		/// Default destructor
		~Snakegame( )
		{/*Empty*/}

		//=== Methods
		/// Initializes the game
		void initialize_game( int argc, char* argv[] );

		/*update();*/

		void process_events( );

		/// redraws the level with the snake
		void redraw(int step);

		/// Prints Status + Maze + Snake
		void render( );

		/// Checks if game is over, if it is, it prints the endgame screen and returns true, else returns false
		bool game_over();

		void gen_food( );


};// Snakegame class

#endif