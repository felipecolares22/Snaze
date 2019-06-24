#ifndef LEVEL_H
#define LEVEL_H

#include <iostream> //std::cout & std::cin
#include <utility> //std::pair
#include <vector> //std::vector
#include <stdexcept> //throw
#include <fstream> //ifstream


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

	public:
		std::vector<level_info> levels; //!< Vector containing all inputed levels.

		//=== Constructors/Destructors
		/// Default constructor.
		Level()
		{/*Empty*/}

		/// Default destructor.
		~Level()
		{/*Empty*/}

		//=== Methods
		/// Verify and save the input file
		void get_input( int argc, char* argv[] );

		/// Stores all level information in a structure then alocated in a vector.
		void get_level( std::string file_name );

		/// Prints the levels vector
		void print_level( int a = -1 );

		/// Returns the size of the vector
		int num_levels( );


		
}; //Level class

#endif