#include "snake.h"


/// Snake default constructor implemetation
Snake::Snake()
{
	std::cout << "n sei\n";
	level = new Level;
	std::cout << "n sei\n";

	head = new bodypart;
	std::cout << "n sei\n";
	head->x = level->levels[0].spawn_point.first;
	std::cout << "n sei\n";
	head->y = level->levels[0].spawn_point.second;
	std::cout << "n sei\n";
	head->next = nullptr;
	std::cout << "n sei\n";
	head->prev = nullptr;
	std::cout << "n sei\n";

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