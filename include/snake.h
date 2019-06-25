#ifndef SNAKE_H
#define SNAKE_H

#include <iostream>
#include <utility>
#include <set>
#include <deque>

#include "level.h"
#include "prints.h"

/*! \class Snake
	\brief Represents the snake and its attributes.

*/
class Snake
{
	private:
		struct bodypart //!< Linked list representing the snake's body
		{
			int x;
			int y;
			bodypart* next;
			bodypart* prev;
		};

	public:
		size_t size=1;
		bodypart* head; //!< Pointer to the Snake's head.
		
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