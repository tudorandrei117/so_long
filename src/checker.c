/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburlacu <tburlacu@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 20:15:29 by tburlacu          #+#    #+#             */
/*   Updated: 2023/05/02 00:00:50 by tburlacu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	wall(t_engine *engine, int i)
{
	if (i < engine->game->width || i > (engine->game->width + 1)
		* (engine->game->height - 1) || i % (engine->game->width + 1) == 0 || i
		% (engine->game->width + 1) == engine->game->width - 1)
		return (1);
	return (0);
}

static void	checker_good(t_engine *engine, char *file, int i)
{
	if (file[i] == 'P')
		engine->game->count_player++;
	else if (file[i] == 'E')
		engine->game->count_exit++;
	else if (file[i] == 'C')
		engine->game->count_coll++;
	else if (file[i] == '1' || file[i] == '0')
		return ;
	else
	{
		free(file);
		engine_destroy(engine, "map content is invalid", 0);
	}
}

void	checker_map(t_engine *engine, char *file)
{
	int	i;

	i = -1;
	while (file[++i] != 0)
	{
		if (file[i] == '\n')
			continue ;
		if (wall(engine, i))
		{
			if (file[i] != '1')
			{
				free(file);
				engine_destroy(engine, "map isn't surrounded by walls", 0);
			}
		}
		else
			checker_good(engine, file, i);
	}
	if (engine->game->count_player != 1 || engine->game->count_exit != 1
		|| engine->game->count_coll < 1)
	{
		free(file);
		engine_destroy(engine, "map configuration is invalid", 0);
	}
}
