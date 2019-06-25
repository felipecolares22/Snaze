#include "snake.h"


Snake::Snake( )
{
	head = new bodypart;
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
void Snake::grow_snake()
{
	while(head->next != nullptr)
	{
		head = head->next;
	}

	head->next = new bodypart;
	head->next->prev = head;
	head->next->next = nullptr;
	head->next->x = head->x;
	head->next->y = head->y;

	while(head->prev != nullptr)
	{
		head = head->prev;
	}

	size++;
}

void Snake::move_snake(std::deque< std::pair< int, int > > & foodWay, int step)
{
	while(head->next != nullptr)
	{
		head = head->next;
	}

	while(head->prev != nullptr)
	{
		head->x = head->prev->x;
		head->y = head->prev->y;

		head = head->prev;
	}

	head->x = foodWay[step].first;
	head->y = foodWay[step].second;
}

void Snake::set_spawn( std::pair<int, int> spawn )
{
	head->x = spawn.first;
	head->y = spawn.second;
}