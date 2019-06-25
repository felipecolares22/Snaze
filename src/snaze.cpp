#include <iostream>
#include <string>

#include "snakegame.h"
#include "prints.h"

int main( int argc, char* argv[] )
{
	if( argc == 1 )
	{
		throw std::runtime_error( "Invalid Number of Arguments\n" );
	}
	
	Snakegame manager;

	manager.initialize_game( argc, argv );

	//printmenu(1000, 5, 1000);
	//printstatus(5, 300, 2, 10, 3);
	return 0;
}