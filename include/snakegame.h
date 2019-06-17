#ifndef SNAKEGAME_H
#define SNAKEGAME_H

/*! \class Snakegame
	\brief The main entity that instatiates all other objects and manages the game execution.

*/
class Snakegame
{
	private:
		Snake snake;
		Level level;
		Player player;

	public:
		//=== Methods
		///
		initialize_game();

		update();

		process_events();

		renders();

		game_over();

	private:
		/*! \class Snake
			\brief Represents the snake and its attributes.
		
		*/
		class Snake
		{

		}

		class Level
		{

		}

		class Player
		{

		}
}