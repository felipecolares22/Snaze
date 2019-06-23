#ifndef SNAKEGAME_H
#define SNAKEGAME_H

//#include "snake.h"
#include "level.h"
// #include "player.h"

/*! \class Snakegame
	\brief The main entity that instatiates all other objects and manages the game execution.

*/
class Snakegame
{
	private:
	//	Snake snake;
		Level level;
		// Player player;

	public:
		//=== Constructors / Destructor
		/// Default destructor
		Snakegame()
		{/*Empty*/}

		/// Default destructor
		~Snakegame()
		{/*Empty*/}

		//=== Methods
		void initialize_game(int argc, char* argv[]);

		/*update();*/

		/*process_events();*/

		/*renders();*/

		/*game_over();*/


};

#endif