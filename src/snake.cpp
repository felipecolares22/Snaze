#include "snake.h"


/// Snake default constructor implemetation
Snake::Snake()
{
	head = new bodypart;
	head->x = level.levels[0].spawn_point.first;
	head->y = level.levels[0].spawn_point.second;
	head->next = nullptr;
	head->prev = nullptr;

}

/// Snake destructor implementation
Snake::~Snake( )
{
	while( head->next != nullptr )
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