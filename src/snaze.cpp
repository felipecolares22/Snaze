#include <iostream>
#include <string>

#include "snakegame.h"
#include "prints.h"

int main(int argc, char* argv[])
{
	Snakegame manager;
	manager.initialize_game( argc, argv );

	std::cout << "hello world\n";
	//printmenu(1000, 5, 1000);
	//printstatus(5, 300, 2, 10, 3);
	return 0;
}