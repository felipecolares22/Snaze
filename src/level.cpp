#include "level.h"

/// get_input method implementation
void Level::get_input( int argc, char* argv[] )
{
	// checking if input argument is valid
	if(argc > 2)
		throw std::invalid_argument( "many arguments" );
	else
	{
		std::string file_name;
		file_name = argv[1];

		Level::get_level( file_name );
	}

	//TODO: Read and save input file
}

/// get_level method implementation
void Level::get_level( std::string file_name )
{

	std::ifstream inFile;
	inFile.open( file_name, std::fstream::in );

	if( inFile.fail() )
	{
		throw std::runtime_error( "Error opening file" );
		return;
	}

	int count{1};
	level_info aux;

	while( inFile >> aux.dimensions.first >> aux.dimensions.second )
	{	
		std::cout<< "Level number " << count << ": ";
		count++;

		if( aux.dimensions.first > 0 and aux.dimensions.second > 0
			and aux.dimensions.first <= 100 and aux.dimensions.second <= 100)
		{
			std::cout << "Accepted!\n";

			//creating the auxiliar matrix
			aux.matrix = new char*[aux.dimensions.first];
			for( int i=0 ; i < aux.dimensions.first ; i++ )
			{
				aux.matrix[i] = new char[aux.dimensions.second];
			}

			//alocating the level on the auxiliar matrix
			std::string inputLine;
			std::getline(inFile, inputLine); // trash
			for( int i = 0 ; i < aux.dimensions.first ; i++)
			{
				std::getline(inFile, inputLine);

				for( int j = 0 ; j < aux.dimensions.second ; j++)
				{
					aux.matrix[i][j] = inputLine[j];

					//storing spawn_point location
					if( aux.matrix[i][j] == '*' )
					{
						aux.spawn_point.first = i;
						aux.spawn_point.second = j;
					}
				}
			}

			levels.push_back( aux );
		}
		else
		{
			throw std::runtime_error( "invalid level size" );
			//delete aux;
		}
	}
}

/// print_level method implementation
void Level::print_level( int a )
{
	if(a == -1)
	{
		for( int i = 0 ; i < (int)levels.size() ; i++ )
		{
			std::cout<< std::endl << std::endl;
			for( int j = 0 ; j < levels[i].dimensions.first ; j++ )
			{
				for( int k = 0 ; k < levels[i].dimensions.second ; k++ )
				{
					std::cout<< levels[i].matrix[j][k];
				}
				std::cout<< std::endl;
			}
		}
	}
	else
	{
		std::cout<< std::endl << std::endl;
		for( int j = 0 ; j < levels[a].dimensions.first ; j++ )
		{
			for( int k = 0 ; k < levels[a].dimensions.second ; k++ )
			{
				std::cout<< levels[a].matrix[j][k];
			}
			std::cout<< std::endl;
		}
	}
}