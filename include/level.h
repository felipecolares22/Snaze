#ifndef LEVEL_H
#define LEVEL_H

#include <iostream>
#include <utility>
#include <vector>
#include <stdexcept> //throw

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
		void get_level();

		/// Verify and save the input file
		void get_input();
		
}; //Level class

#endif