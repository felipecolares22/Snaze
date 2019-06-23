#include "snakegame.h"

void Snakegame::initialize_game( int argc, char* argv[] )
{
	level.get_input( argc, argv );
	level.print_level();
}

