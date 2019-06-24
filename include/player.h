#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <utility>
#include <deque>

#include "snake.h"
#include "level.h"

/*! \class Player
	\brief Represents a level of the game.

*/
class Player
{
	protected:
		Level level;
//		Snake snake;
		std::pair< int, int > food_pos; //!< Stores the food pellet's position on the level;
		std::deque< std::pair< int, int > > foodWay; //!<  

	public:
		Player()
		{/*Empty*/}

		~Player()
		{/*Empty*/}

		//=== Methods
		/// Return true if has a valid way to food and false othewise
		bool find_solution( void );

		//Direction next_move();
		
		///
		std::pair<int, int> gen_food(Level & level);
}; // Player class

#endif