#ifndef SNAKE_H
#define SNAKE_H

#include <iostream>

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
		bodypart* head; //!< Pointer to the Snake's head.

	public:
		//=== Constructors/Destructors
		/// Default constructor.
		Snake(int spawn_x, int spawn_y);

		/// Default destructor.
		~Snake();

		//=== Methods
		/// Adds a new piece to the snake body.
		void grow_snake();
		
}; //Snake class

#endif