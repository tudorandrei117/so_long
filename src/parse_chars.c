/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburlacu <tburlacu@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 20:26:48 by tburlacu          #+#    #+#             */
/*   Updated: 2023/05/01 21:05:05 by tburlacu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move(t_engine *engine, int x, int y)
{
	if (engine->game->player.x != x || engine->game->player.y != y)
	{
		engine->game->player_move++;
		ft_putnbr_fd(engine->game->player_move, 1);
		ft_putendl_fd("", 1);
	}
}

static void	coin(t_engine *engine)
{
	int				k;

	k = 0;
	while (k < engine->game->count_coll)
	{
		if (engine->game->coll[k].x == engine->game->player.x
			&& engine->game->coll[k].y == engine->game->player.y)
		{
			engine->game->coll[k].x = -1;
			engine->game->coll[k].y = -1;
			engine->game->player_coll++;
		}
		k++;
	}
}

void	fps(t_engine *engine)
{
	int				x;
	int				y;

	x = engine->game->player.x;
	y = engine->game->player.y;
	if (engine->game->player_up != 0)
		move_up(engine, x, y);
	else if (engine->game->player_down != 0)
		move_down(engine, x, y);
	else if (engine->game->player_left != 0)
		move_left(engine, x, y);
	else if (engine->game->player_right != 0)
		move_right(engine, x, y);
	move(engine, x, y);
	coin(engine);
	parser(engine);
	if (engine->game->exit.x == engine->game->player.x
		&& engine->game->exit.y == engine->game->player.y)
		if (engine->game->count_coll == engine->game->player_coll)
			engine_destroy(engine, 0, 0);
}
