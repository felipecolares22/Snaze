#ifndef SNAKE_H
#define SNAKE_H

#include <iostream>
#include <utility>
#include <set>
#include <deque>
#include <vector>

#include "level.h"
#include "prints.h"

/*! \class Snake
	\brief Represents the snake and its attributes.

*/
class Snake
{
	public:
		// std::deque<std::pair<int, int>> body;
		std::pair<int, int> head;

	
		size_t size=1;
		
		//=== Constructors/Destructors
		/// Default constructor.
		Snake( );

		/// Default destructor.
		~Snake( );

		//=== Methods
		/// Adds a new piece to the snake body.
		void grow_snake( );
		
		/// Sets the head spawn point
		void set_spawn(	std::pair< int, int > spawn );

		/// Moves the Snake
		void move_snake( std::deque< std::pair< int, int > > & foodWay, int step );
}; //Snake class

#endif