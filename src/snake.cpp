#include "snake.h"


Snake::Snake( )
{
}

/// Snake destructor implementation
Snake::~Snake( )
{
}

/// grow_snake implementation
// TODO: store the correct values to new bodypart x and y.
void Snake::grow_snake()
{
	// std::pair<int, int> aux = body.back();

	size++;
}

void Snake::move_snake(std::deque< std::pair< int, int > > & foodWay, int step)
{
	head = foodWay.front();
	foodWay.pop_front();
}

void Snake::set_spawn( std::pair<int, int> spawn )
{
	head = spawn;
}