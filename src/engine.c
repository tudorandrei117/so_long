/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburlacu <tburlacu@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 20:24:32 by tburlacu          #+#    #+#             */
/*   Updated: 2023/05/02 00:50:32 by tburlacu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	load_img(t_engine *engine, t_img **img, char *path)
{
	int				width;
	int				height;

	*img = mlx_xpm_file_to_image(engine->mlx, path, &width, &height);
	if (*img == 0)
		engine_destroy(0, "can't load texture", 0);
	(*img)->width = width;
	(*img)->height = height;
}

static void	texture_start(t_engine *engine)
{
	load_img(engine, &engine->player, "./textures/player.xpm");
	load_img(engine, &engine->exit, "./textures/exit.xpm");
	load_img(engine, &engine->coll, "./textures/gem.xpm");
	load_img(engine, &engine->wall, "./textures/wall.xpm");
	load_img(engine, &engine->ground, "./textures/ground.xpm");
}

static void	render_start(t_engine *engine)
{
	engine->mlx = mlx_init();
	if (engine->mlx == 0)
		engine_destroy(engine, "mlx_init(): can't load mlx", 0);
	engine->mlx_win = mlx_new_window(engine->mlx, engine->game->width * 40,
			engine->game->height * 40, "so_long");
	if (engine->mlx_win == 0)
		engine_destroy(engine, "mlx_new_window(): can't create a window", 0);
	engine->mlx_img = mlx_new_image(engine->mlx, engine->game->width * 40,
			engine->game->height * 40);
	if (engine->mlx_img == 0)
		engine_destroy(engine, "mlx_new_image(): can't create an image", 0);
}

t_engine	*engine_start(char *filename)
{
	t_engine			*engine;

	engine = (t_engine *)malloc(sizeof(t_engine));
	if (engine == 0)
		engine_destroy(0, "engine_init(): malloc()", errno);
	engine->game = 0;
	engine->mlx = 0;
	engine->mlx_win = 0;
	engine->mlx_img = 0;
	engine->player = 0;
	engine->exit = 0;
	engine->coll = 0;
	engine->wall = 0;
	engine->ground = 0;
	start_game(engine, filename);
	render_start(engine);
	texture_start(engine);
	return (engine);
}

void	engine_destroy(t_engine *engine, char *errmsg, int errnum)
{
	if (engine != 0)
	{
		if (engine->ground != 0)
			mlx_destroy_image(engine->mlx, engine->ground);
		if (engine->wall != 0)
			mlx_destroy_image(engine->mlx, engine->wall);
		if (engine->coll != 0)
			mlx_destroy_image(engine->mlx, engine->coll);
		if (engine->exit != 0)
			mlx_destroy_image(engine->mlx, engine->exit);
		if (engine->player != 0)
			mlx_destroy_image(engine->mlx, engine->player);
		if (engine->mlx_img != 0)
			mlx_destroy_image(engine->mlx, engine->mlx_img);
		if (engine->mlx_win != 0)
			mlx_destroy_window(engine->mlx, engine->mlx_win);
		if (engine->mlx != 0)
			mlx_destroy_display(engine->mlx);
		if (engine->game != 0)
			game_destroy(engine->game);
		free(engine);
	}
	end(errmsg, errnum);
}