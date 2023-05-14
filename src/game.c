/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburlacu <tburlacu@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 20:12:04 by tburlacu          #+#    #+#             */
/*   Updated: 2023/05/14 22:17:16 by tburlacu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	start_game(t_engine *engine, char *filename)
{
	engine->game = (t_data *)malloc(sizeof(t_data));
	if (engine->game == 0)
		engine_destroy(engine, "game_init(): malloc()", errno);
	engine->game->map = 0;
	engine->game->coll = 0;
	engine->game->count_coll = 0;
	engine->game->count_exit = 0;
	engine->game->count_player = 0;
	engine->game->player_move = 0;
	engine->game->player_coll = 0;
	engine->game->player_up = 0;
	engine->game->player_down = 0;
	engine->game->player_left = 0;
	engine->game->player_right = 0;
	start_map(engine, filename);
}
