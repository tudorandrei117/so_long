/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburlacu <tburlacu@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 20:18:00 by tburlacu          #+#    #+#             */
/*   Updated: 2023/05/14 22:16:25 by tburlacu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_darray(t_engine *engine, char *file, int **m, int size)
{
	int				i;

	i = 0;
	while (i < size)
		free(m[i++]);
	free(m);
	engine->game->map = 0;
	free(file);
	engine_destroy(engine, "map_parsing(): malloc()", errno);
}

static void	get_dir(t_engine *engine, char *file, int k, int *obj)
{
	if (file[k] == 'P')
	{
		engine->game->player.x = k % (engine->game->width + 1);
		engine->game->player.y = k / (engine->game->width + 1);
		file[k] = '0';
	}
	else if (file[k] == 'E')
	{
		engine->game->exit.x = k % (engine->game->width + 1);
		engine->game->exit.y = k / (engine->game->width + 1);
		file[k] = '0';
	}
	else if (file[k] == 'C')
	{
		engine->game->coll[*obj].x = k % (engine->game->width + 1);
		engine->game->coll[*obj].y = k / (engine->game->width + 1);
		file[k] = '0';
		(*obj)++;
	}
}

void	map_parser(t_engine *engine, char *file)
{
	int				i;
	int				j;
	int				k;
	int				obj;

	obj = 0;
	k = 0;
	j = -1;
	while (++j < engine->game->height)
	{
		engine->game->map[j] = (int *)malloc(sizeof(int) * engine->game->width);
		if (engine->game->map[j] == 0)
			free_darray(engine, file, engine->game->map, j);
		i = 0;
		while (i < engine->game->width)
		{
			get_dir(engine, file, k, &obj);
			engine->game->map[j][i++] = file[k++] - 48;
		}
		k++;
	}
}

void	read_map(t_engine *engine, char *file)
{
	map_width(engine, file);
	map_height(engine, file);
	checker_map(engine, file);
	engine->game->coll
		= (t_dir *)malloc(sizeof(t_dir) * engine->game->count_coll);
	if (engine->game->coll == 0)
	{
		free(file);
		engine_destroy(engine, "map_parsing(): malloc()", errno);
	}
	engine->game->map = (int **)malloc(sizeof(int *) * engine->game->height);
	if (engine->game->map == 0)
	{
		free(file);
		engine_destroy(engine, "map_parsing(): malloc()", errno);
	}
	map_parser(engine, file);
}
