#include "snakegame.h"

void Snakegame::initialize_game( int argc, char* argv[] )
{
	std::cout << "entrou\n";

	level->get_input( argc, argv );
	std::cout << "entrou\n";

	printmenu(level->num_levels(), 5, 0, 10);
	std::cout << "entrou\n";

	level->print_level( current_level );
	std::cout << "entrou\n";

	while(!game_over())
	{
		render();
	}
}

void Snakegame::process_events( )
{
	if( player->find_solution( player->food_pos, player->player_loc, *level, current_level ) )
	{
		render();
	}
}

void Snakegame::render( )
{	
	system("clear");
	printstatus(lives, score, food_eaten, 10, current_level );
	level->print_level(current_level);
}

bool Snakegame::game_over( )
{
	if(lives == 0)
	{
		printendgame( score );
		return true;
	}
	else
	{
		return false;
	}
}

