/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburlacu <tburlacu@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 11:48:51 by tburlacu          #+#    #+#             */
/*   Updated: 2023/05/01 23:55:45 by tburlacu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <mlx.h>
# include <mlx_int.h>
# include "libft.h"

typedef struct s_dir
{
	int			x;
	int			y;
}				t_dir;

typedef struct s_data
{
	int			**map;
	int			height;
	int			width;
	t_dir		player;
	int			player_up;
	int			player_down;
	int			player_left;
	int			player_right;
	int			player_move;
	int			player_coll;
	t_dir		exit;
	t_dir		*coll;
	int			count_coll;
	int			count_exit;
	int			count_player;
}				t_data;

typedef struct s_engine
{
	void		*mlx;
	void		*mlx_win;
	t_img		*mlx_img;
	t_data		*game;
	t_img		*player;
	t_img		*exit;
	t_img		*coll;
	t_img		*wall;
	t_img		*ground;
}				t_engine;

void			end(char *errmsg, int errnum);

void			parser(t_engine *root);

int				key_controls(int keycode, t_engine *root);
int				key_hold(int keycode, t_engine *root);
int				destroy_hook(int keycode, t_engine *root);

void			game_destroy(t_data *game);

void			start_game(t_engine *root, char *filename);

void			map_height(t_engine *root, char *file);

void			start_map(t_engine *root, char *filename);

void			checker_map(t_engine *root, char *file);

void			map_parser(t_engine *root, char *file);

void			read_map(t_engine *root, char *file);

void			map_width(t_engine *root, char *file);

unsigned int	mlx_get_pixel(t_img *img, int x, int y);
void			mlx_draw_pixel(t_img *mlx_img, int x, int y, int color);
unsigned int	mlx_rgb_to_int(int o, int r, int g, int b);

void			move_up(t_engine *root, int x, int y);
void			move_down(t_engine *root, int x, int y);
void			move_left(t_engine *root, int x, int y);
void			move_right(t_engine *root, int x, int y);

void			engine_destroy(t_engine *root, char *errmsg, int errnum);

t_engine		*engine_start(char *filename);

void			fps(t_engine *root);

#endif