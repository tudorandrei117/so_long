/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_maker.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburlacu <tburlacu@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 20:07:23 by tburlacu          #+#    #+#             */
/*   Updated: 2023/05/01 21:04:33 by tburlacu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	make_rectangle(t_engine *engine, t_img *img, int x, int y)
{
	unsigned int	color;
	int				i;
	int				j;

	j = 0;
	while (j < 40)
	{
		i = 0;
		while (i < 40)
		{
			color = mlx_get_pixel(img, i, j);
			if (color != mlx_rgb_to_int(0, 255, 255, 255))
				mlx_draw_pixel(engine->mlx_img, x + i, y + j, color);
			i++;
		}
		j++;
	}
}

static void	make_inside(t_engine *engine, int i, int j)
{
	int				k;

	if (engine->game->exit.x == i && engine->game->exit.y == j)
		make_rectangle(engine, engine->exit, i * 40, j * 40);
	k = -1;
	while (++k < engine->game->count_coll)
		if (engine->game->coll[k].x == i && engine->game->coll[k].y == j)
			make_rectangle(engine, engine->coll, i * 40, j * 40);
	if (engine->game->player.x == i && engine->game->player.y == j)
		make_rectangle(engine, engine->player, i * 40, j * 40);
}

static void	make_map(t_engine *engine)
{
	int				i;
	int				j;

	j = 0;
	while (j < engine->game->height)
	{
		i = 0;
		while (i < engine->game->width)
		{
			if (engine->game->map[j][i] == 1)
				make_rectangle(engine, engine->wall, i * 40, j * 40);
			else
				make_rectangle(engine, engine->ground, i * 40, j * 40);
			make_inside(engine, i, j);
			i++;
		}
		j++;
	}
}

void	parser(t_engine *eng)
{
	make_map(eng);
	mlx_put_image_to_window(eng->mlx, eng->mlx_win, eng->mlx_img, 0, 0);
}

void	game_destroy(t_data *data)
{
	int				i;

	if (data != 0)
	{
		if (data->coll != 0)
			free(data->coll);
		if (data->map != 0)
		{
			i = 0;
			while (i < data->height)
				free(data->map[i++]);
			free(data->map);
		}
		free(data);
	}
}
