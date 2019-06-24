#include "snakegame.h"

void Snakegame::initialize_game( int argc, char* argv[] )
{
	level.get_input( argc, argv );
	printmenu(level.num_levels(), 5, 0, 10);
	level.print_level();
	game_over(30000);
}

void Snakegame::game_over( )
{
	printendgame( score );
}

