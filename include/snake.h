#include <iostream>

#include "prints.h"

/*! \class Snake
	\brief Represents the snake and its attributes.

*/
class snake
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
		snake(int spawn_x, int spawn_y)
		{
			head = new bodypart;
			head->x = spawn_x;
			head->y = spawn_y;
			head->prev = nullptr;
			head->next = nullptr;
		}

		/// Default destructor.
		~snake()
		{
			while(head->next != nullptr)
			{
				head = head->next;
				delete head->prev;
			}
			delete head;
		}

		//=== Methods
		/// Adds a new piece to the snake body.
		/* TO DO: store the correct values to new bodypart x and y.
		void grow_snake()
		{
			while(head->next != nullptr)
			{
				head = head->next;
			}

			head->next = new bodypart;
			head->next->prev = head;
			head->next->next = nullptr;
			head->next->x = ;
			head->next->y = ;

			while(head->prev != nullptr)
			{
				head = head->prev;
			}
		}
		*/
}; //Snake class