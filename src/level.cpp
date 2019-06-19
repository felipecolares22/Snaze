#include "level.h"

/// get_input method implementation
std::string Level::get_input(int argc, char* argv[])
{
	// checking if input argument is valid
	if(argc > 2)
		throw std::invalid_argument("many arguments");
	else
	{
		std::string file_name;
		file_name = argv[1];
		return file_name;
	}
	//TODO: Read and save input file
}

/// get_level method implementation
void Level::get_level()
{
	std::string file_name;
	file_name = Level::get_input(argc, argv[]);

	std::fstream inFile;
	inFile.open(file_name, std::fstream::in);

	if(inFile.fail())
	{
		throw std::runtime_error("Error opening file");
		return;
	}

	int count{0};
	level_info aux;

	while( inFile >> aux.dimensions.first >> aux.dimensions.second )
	{	
		std::cout<< "Level number " << count << ": ";
		count++

		if( aux.dimensions.first > 0 and aux.dimensions.second > 0 )
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
					inFile.get(matrix[i][j]);

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
}