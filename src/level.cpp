#include "level.h"

/// get_level method implementation
/*void Level::get_level()
{
	int count{0};
	level_info aux;
	while( std::cin >> aux.dimensions.first >> aux.dimensions.second )
	{	
		std::cout<< "Level number " << count << ": ";
		count++

		if( aux.rows > 0 and aux.columns > 0 )
		{
			std::cout << "Accepted!\n";

			//creating the auxiliar matrix
			aux.matrix = new char*[aux.rows];
			for( int i=0 ; i < aux.rows ; i++ )
			{
				matrix[i] = new char[aux.columns];
			}

			//alocating the level on the auxiliar matrix
			for( int i = 0 ; i < aux.rows ; i++)
			{
				for( int j = 0 ; j < aux.columns ; j++)
				{
					std::cin>>matrix[i][j];

					//storing spawn_point location
					if(matrix[i][j] == '*')
					{
						aux.spawn_point.first = i;
						aux.spawn_point.second = j;
					}
				}
			}

			levels.push_back(aux);
		}
		else
		{
			print_errors("invalid level size", );
			delete aux;
		}
	}
}*/

/// get_input method implementation
void Level::get_input(int argc, char* argv[])
{
	// checking if input argument is valid
	if(argc > 2)
		throw std::invalid_argument("many arguments");

	//TODO: Read and save input file
}