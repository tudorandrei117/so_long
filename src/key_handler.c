/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburlacu <tburlacu@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 20:09:36 by tburlacu          #+#    #+#             */
/*   Updated: 2023/05/14 22:16:42 by tburlacu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_width(t_engine *engine, char *file)
{
	engine->game->width = 0;
	while (file[engine->game->width] && file[engine->game->width] != '\n')
		engine->game->width++;
	if (engine->game->width == 0 || file[engine->game->width] == 0)
	{
		free(file);
		engine_destroy(engine, "map file is invalid", 0);
	}
}

int	key_controls(int keycode, t_engine *engine)
{
	if (keycode == 65307)
		engine_destroy(engine, 0, 0);
	if (keycode == 119)
		engine->game->player_up = 1;
	if (keycode == 115)
		engine->game->player_down = 1;
	if (keycode == 97)
		engine->game->player_left = 1;
	if (keycode == 100)
		engine->game->player_right = 1;
	fps(engine);
	return (0);
}

int	key_hold(int keycode, t_engine *engine)
{
	if (keycode == 119)
		engine->game->player_up = 0;
	if (keycode == 115)
		engine->game->player_down = 0;
	if (keycode == 97)
		engine->game->player_left = 0;
	if (keycode == 100)
		engine->game->player_right = 0;
	fps(engine);
	return (0);
}

int	destroy_hook(int keycode, t_engine *engine)
{
	(void)keycode;
	(void)engine;
	engine_destroy(0, 0, 0);
	return (0);
}
