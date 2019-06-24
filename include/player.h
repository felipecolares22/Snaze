#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <utility>
#include <deque>

/*! \class Level
	\brief Represents a level of the game.

*/
class Player
{
	protected:
		std::deque< std::pair< int, int > > foodWay; //!<  

	public:
		/// Return true if has a valid way to food and false othewise
		bool find_way( void );
		
}; // Player class