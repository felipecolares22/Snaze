#include "snakegame.h"

void Snakegame::initialize_game( int argc, char* argv[] )
{

	level->get_input( argc, argv );

	printmenu(level->levels.size(), 5, 0, 10);

	for( int i = 0; i< (int)level->levels.size() ; i++)
	{
		snake->set_spawn(level->levels[i].spawn_point);

		while(!game_over())
		{
			process_events();
		}
		current_level++;
	}
}

void Snakegame::process_events( )
{
	if(snake->head->x == food_pos.first and snake->head->y == food_pos.second)
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
			while(snake->head->x != food_pos.first and snake->head->y != food_pos.second)
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

	if(snake->size == 1)
	{
		if(step == 0)
		{
			level->levels[current_level].matrix[player->foodWay[step].first][player->foodWay[step].second] = 'G';
			level->levels[current_level].matrix[snake->head->x][snake->head->y] = ' ';
		}
	}
	else
	{
		if(step == 0)
		{
			level->levels[current_level].matrix[player->foodWay[step].first][player->foodWay[step].second] = 'G';
			level->levels[current_level].matrix[snake->head->x][snake->head->y] = 'o';
		}
		else
		{
			level->levels[current_level].matrix[player->foodWay[step].first][player->foodWay[step].second] = 'G';
			level->levels[current_level].matrix[snake->head->x][snake->head->y] = 'o';
			while(snake->head->next != nullptr)
			{
				snake->head = snake->head->next;
			}
			level->levels[current_level].matrix[snake->head->x][snake->head->y] = ' ';

			while(snake->head->prev != nullptr)
			{
				snake->head = snake->head->prev;
			}		
		}
	}
}

void Snakegame::render( )
{	
	system("clear");
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
	while( level->levels[current_level].matrix[food_pos.first][food_pos.second] != ' ' )
	{
		food_pos.first = random_numbers_x();
		food_pos.second = random_numbers_y();
	}
	level->levels[current_level].matrix[food_pos.first][food_pos.second] = 'f';
}

