#include <iostream>
#include <utility>
#include <vector>

#include "input.h"

/*! \class Level
	\brief Represents a level of the game.

*/
class Level
{
	private:
		/*! \struct level_info
			\brief Structure to store a level's info.

		*/
		struct level_info
		{
			std::pair< int, int > dimensions;
			char** matrix;
			std::pair< int, int > spawn_point;
		};
		std::vector<level_info> levels; //!< Vector containing all inputed levels.

	public:
		//=== Constructors/Destructors
		/// Default constructor.
		Level();

		/// Default destructor.
		~Level();

		//=== Methods
		/// Stores all level information in a structure then alocated in a vector.
		/*
		void get_level()
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
		}
		*/
}; //Level class