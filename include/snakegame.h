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
		Level level;
		Player player;
		size_t score = 0; //!< Stores the game score

	public:
		//=== Constructors / Destructor
		/// Default destructor
		Snakegame()
		{/*Empty*/}

		/// Default destructor
		~Snakegame()
		{/*Empty*/}

		//=== Methods
		/// Initializes the game
		void initialize_game(int argc, char* argv[]);

		/*update();*/

		/*process_events();*/

		/*renders();*/

		void game_over();


};// Snakegame class

#endif