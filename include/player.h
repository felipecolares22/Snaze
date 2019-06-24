#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <utility>
#include <deque>
#include <random>
#include <cstdlib>
#include <ctime>

#include "snake.h"
#include "level.h"

/*! \class Player
	\brief Represents a level of the game.

*/
class Player
{
	protected:
		Level level;
		Snake snake;
		std::deque< std::pair< int, int > > foodWay; //!<  

	public:
		std::pair< int, int > food_pos; //!< Stores the food pellet's position on the level;
		std::pair< int, int > player_loc; //!< Stores the snake's head position
		
		Player()
		{
			player_loc.first = snake.head->x;
			player_loc.second = snake.head->y;

			food_pos.first = 0;
			food_pos.second = 0;
		}

		~Player()
		{/*Empty*/}

		//=== Methods
		/// Return true if has a valid way to food and false othewise
		bool find_solution( std::pair< int, int > food_loc, std::pair< int, int > player_loc, Level & level, int l_num );

		//Direction next_move();
		
		///
		std::pair<int, int> gen_food( Level & level );
}; // Player class

#endif