#include "snakegame.h"

void Snakegame::initialize_game( int argc, char* argv[] )
{

	level->get_input( argc, argv );

	printmenu(level->levels.size(), 5, 0, 10);

	for( int i = 0; i< (int)level->levels.size() ; i++)
	{
		// colocar bobrinha na matriz;
		snake->set_spawn(level->levels[i].spawn_point);

		level->levels[i].matrix[snake->head.first][snake->head.second] = 'G';
		gen_food( );

		// while(!game_over())
		// {
			player->find_solution( food_pos, snake->head, level, current_level );
			int num = player->foodWay.size();

			// print
			for(int ii = 0; ii < num ; ii++)
			{
				printmenu(level->levels.size(), 5, 0, 10);
				for( int a = 0; a < level->levels[i].dimensions.first ; a++ )
				{
					for( int b = 0; b < level->levels[i].dimensions.first ; b++ )
					{
						std::cout << level->levels[i].matrix[a][b];
					}
					std::cout << std::endl;
				}


				// atualizar
				level->levels[i].matrix[snake->head.first][snake->head.second] = ' ';
				snake->move_snake( player->foodWay, i );
				level->levels[i].matrix[snake->head.first][snake->head.second] = 'G';
			}

		// }

		current_level++;
	}
}

void Snakegame::process_events( )
{
	if(snake->head.first == food_pos.first and snake->head.second == food_pos.second)
	{
		snake->grow_snake();
		render();
		gen_food( );
		std::cout<<"ggggggg\n";
	}
	else
	{
		if( player->find_solution( food_pos, player->player_loc, level, current_level ) )
		{
			while(snake->head.first != food_pos.first and snake->head.second != food_pos.second)
			{
				int step = 0;
				redraw(step);
				snake->move_snake(player->foodWay, step);
				player->player_loc.first = player->foodWay[step].first;
				player->player_loc.second = player->foodWay[step].second;
				step++;
				render();
			}
		}
	}
}

void Snakegame::redraw( int step )
{

	std::cout<<"pegaporra\n";
	level->levels[current_level].matrix[food_pos.first][food_pos.second] = 'f';

	level->print_level(0);

	if(snake->size == 1)
	{
		if(step == 0)
		{
			level->levels[current_level].matrix[player->foodWay[step].first][player->foodWay[step].second] = 'G';
			level->levels[current_level].matrix[snake->head.first][snake->head.second] = ' ';
		}
	}
	else
	{
		if(step == 0)
		{
			level->levels[current_level].matrix[player->foodWay[step].first][player->foodWay[step].second] = 'G';
			level->levels[current_level].matrix[snake->head.first][snake->head.second] = 'o';
		}
		else
		{
			level->levels[current_level].matrix[player->foodWay[step].first][player->foodWay[step].second] = 'G';
			level->levels[current_level].matrix[snake->head.first][snake->head.second] = 'o';	
		}
	}
}

void Snakegame::render( )
{	
	// system("clear");
	printstatus(lives, score, food_eaten, 10, current_level );
	level->print_level(current_level);
}

bool Snakegame::game_over( )
{
	if(lives == 0)
	{
		printendgame( score );
		return true;
	}
	else
	{
		return false;
	}
}

void Snakegame::gen_food( )
{
	food_pos.first = random_numbers_x();
	food_pos.second = random_numbers_y();
	while( level->levels[current_level].matrix[food_pos.first][food_pos.second] != ' ' )
	{
		food_pos.first = random_numbers_x();
		food_pos.second = random_numbers_y();
	}
	std::cout << "------v\n";
	level->levels[current_level].matrix[food_pos.first][food_pos.second] = 'f';
	std::cout << "------^\n";
}

