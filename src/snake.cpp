#include "snake.h"


/// Snake default constructor implemetation
Snake::Snake(int spawn_x, int spawn_y)
{
	head = new bodypart;
	head->x = spawn_x;
	head->y = spawn_y;
	head->prev = nullptr;
	head->next = nullptr;
}

/// Snake destructor implementation
Snake::~Snake()
{
	while(head->next != nullptr)
	{
		head = head->next;
		delete head->prev;
	}
	delete head;
}

/// grow_snake implementation
// TODO: store the correct values to new bodypart x and y.
/*void Snake::grow_snake()
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
}*/