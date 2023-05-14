/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburlacu <tburlacu@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 20:12:40 by tburlacu          #+#    #+#             */
/*   Updated: 2023/05/14 22:16:54 by tburlacu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_height(t_engine *engine, char *file)
{
	int				i;
	int				j;

	engine->game->height = 1;
	i = engine->game->width + 1;
	while (file[i] != 0)
	{
		j = 0;
		while (file[i + j] != 0 && file[i + j] != '\n')
			j++;
		if (engine->game->width != j)
		{
			free(file);
			engine_destroy(engine, "map format is invalid", 0);
		}
		i += engine->game->width + 1;
		engine->game->height++;
	}
}

static void	parse_fd(t_engine *engine, char **file, char buf[], int fd)
{
	char			*tmp;

	tmp = ft_strjoin(*file, buf);
	free(*file);
	*file = tmp;
	if (*file == 0)
	{
		close(fd);
		engine_destroy(engine, "map_init(): ft_strjoin()", errno);
	}
}

static void	read_fd(t_engine *engine, char **file, char buf[], int fd)
{
	int				ret;

	ret = 1;
	while (ret != 0)
	{
		ret = read(fd, buf, 1024);
		if (ret == -1)
		{
			free(*file);
			close(fd);
			engine_destroy(engine, "map_init(): read()", errno);
		}
		else
		{
			buf[ret] = 0;
			parse_fd(engine, file, buf, fd);
		}
	}
}

static char	*fd_starter(t_engine *engine, int fd)
{
	char			*file;

	file = ft_calloc(1, 1);
	if (file == 0)
	{
		close(fd);
		engine_destroy(engine, "map_init(): ft_calloc()", errno);
	}
	return (file);
}

void	start_map(t_engine *engine, char *filename)
{
	int				fd;
	char			*file;
	char			buf[1024 + 1];

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		engine_destroy(engine, filename, errno);
	file = fd_starter(engine, fd);
	read_fd(engine, &file, buf, fd);
	close(fd);
	read_map(engine, file);
	free(file);
}
