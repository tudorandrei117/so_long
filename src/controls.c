/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburlacu <tburlacu@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 20:05:48 by tburlacu          #+#    #+#             */
/*   Updated: 2023/05/01 20:26:18 by tburlacu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_engine *engine, int x, int y)
{
	if (engine->game->map[y - 1][x] == 0)
		engine->game->player.y -= 1;
}

void	move_down(t_engine *engine, int x, int y)
{
	if (engine->game->map[y + 1][x] == 0)
		engine->game->player.y += 1;
}

void	move_left(t_engine *engine, int x, int y)
{
	if (engine->game->map[y][x - 1] == 0)
		engine->game->player.x -= 1;
}

void	move_right(t_engine *engine, int x, int y)
{
	if (engine->game->map[y][x + 1] == 0)
		engine->game->player.x += 1;
}

void	end(char *errmsg, int errnum)
{
	if (errmsg != 0 || errnum != 0)
		ft_putendl_fd("Error", 2);
	if (errmsg != 0)
		ft_putstr_fd(errmsg, 2);
	if (errmsg != 0 && errnum != 0)
		ft_putstr_fd(": ", 2);
	if (errnum != 0)
		ft_putstr_fd(strerror(errnum), 2);
	if (errmsg != 0 || errnum != 0)
	{
		ft_putendl_fd("", 2);
		exit(1);
	}
	exit(0);
}
