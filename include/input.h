#include <iostream> //std::cin, std::cout
#include <fstream> //std::fstream
#include <string> //std::string

#include "prints.h"

/*! \class Input
	\brief class to receive input

*/
class Input
{
	private:
		std::string filename; //!< Stores the input file's name
	
	public:
		//=== Constructors/Destructor
		/// Default constructor
		Input(int argc, char *argv[])
		{
			if(argc > 2) print_errors("many arguments");
			else
			{
				filename = argv[1];
			}
		}

		/// Default destructor
		~Input();
}