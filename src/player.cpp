#include "player.h"

bool Player::find_solution( std::pair< int, int > food_loc, std::pair< int, int > player_loc, Level* & level, int l_num )
{	
	std::cout << "entrou\n";
	// cleaning deque
	this->foodWay.clear();

	// backtracking
	std::set< std::pair< int, int > > visited;

	this->foodWay.push_back( std::make_pair(player_loc.first, player_loc.second) );
	std::pair< int, int > current (player_loc.first, player_loc.second);
	visited.insert( current );

	while( this->foodWay.back() != food_loc and this->foodWay.empty() == false )
	{
		std::pair< int, int > aux;
		bool findOutlet = false;
		{
			if( level->levels[l_num].matrix[current.first + 1][current.second] == ' ' and visited.count( std::make_pair(current.first + 1, current.second) ) == 0)
			{
				findOutlet = true;
				aux = std::make_pair(current.first + 1, current.second);
			}
			else if( level->levels[l_num].matrix[current.first - 1][current.second] == ' ' and visited.count( std::make_pair(current.first - 1, current.second) ) == 0)
			{
				findOutlet = true;
				aux = std::make_pair(current.first - 1, current.second);
			}
			else if( level->levels[l_num].matrix[current.first][current.second + 1] == ' ' and visited.count( std::make_pair(current.first, current.second + 1) ) == 0)
			{
				findOutlet = true;
				aux = std::make_pair(current.first, current.second + 1);
			}
			else if( level->levels[l_num].matrix[current.first][current.second - 1] == ' ' and visited.count( std::make_pair(current.first, current.second - 1) ) == 0)
			{
				findOutlet = true;
				aux = std::make_pair(current.first, current.second - 1);
			}
			// ----------------------------------
			if( level->levels[l_num].matrix[current.first + 1][current.second] == 'f')
			{
				aux = std::make_pair(current.first + 1, current.second);
				this->foodWay.push_back(aux);
				break;
			}
			else if( level->levels[l_num].matrix[current.first - 1][current.second] == 'f')
			{
				aux = std::make_pair(current.first - 1, current.second);
				this->foodWay.push_back(aux);
				break;
			}
			else if( level->levels[l_num].matrix[current.first][current.second + 1] == 'f')
			{
				aux = std::make_pair(current.first, current.second + 1);
				this->foodWay.push_back(aux);
				break;
			}
			else if( level->levels[l_num].matrix[current.first][current.second - 1] == 'f')
			{
				aux = std::make_pair(current.first, current.second - 1);
				this->foodWay.push_back(aux);
				break;
			}
		}
		if(findOutlet)
		{
			this->foodWay.push_back(aux);
			visited.insert(aux);
		}
		else
		{
			this->foodWay.pop_back();
		}
		if( this->foodWay.empty() )
			return false;
		current = this->foodWay.back();
	}
	
	return true;
}
