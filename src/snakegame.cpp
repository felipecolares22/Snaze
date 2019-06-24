#include "snakegame.h"

void Snakegame::initialize_game( int argc, char* argv[] )
{
	level.get_input( argc, argv );
	printmenu(level.num_levels(), 5, 0, 10);
	level.print_level( current_level );
	while(!game_over())
	{
		render(level);
	}
}

void Snakegame::process_events( Level & level, Player & player )
{
	if( player.find_solution( player.food_pos, player.player_loc, level, current_level ) )
	{
		render(level);
	}
}

void Snakegame::render( Level & level )
{	
	system("clear");
	printstatus(lives, score, food_eaten, 10, current_level );
	level.print_level(current_level);
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

