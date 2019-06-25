#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <utility>
#include <set>
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
	public:
		std::deque< std::pair< int, int > > foodWay; //!<  

	public:
		std::pair< int, int > player_loc; //!< Stores the snake's head position

		Player()
		{/*Empty*/}

		~Player()
		{/*Empty*/}

		//=== Methods
		/// Return true if has a valid way to food and false othewise
		bool find_solution( std::pair< int, int > food_loc, std::pair< int, int > player_loc, Level* &level, int l_num );

		void set_loc(Snake* & snake)
		{
			player_loc.first = snake->head->x;
			player_loc.second = snake->head->y;
		}

		//Direction next_move();
}; // Player class

#endif