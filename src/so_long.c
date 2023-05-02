/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburlacu <tburlacu@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 20:30:22 by tburlacu          #+#    #+#             */
/*   Updated: 2023/05/01 21:07:00 by tburlacu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

int	is_ber_extension(char *file)
{
	int				len;

	len = ft_strlen(file);
	if (file == 0)
		return (0);
	if (len < 5)
		return (0);
	if (ft_strcmp(file + len - 4, ".ber") != 0)
		return (0);
	return (1);
}

int	main(int ac, char *av[])
{
	t_engine			*engine;

	if (ac != 2)
		end("invalid number of arguments", 0);
	if (is_ber_extension(av[1]) == 0)
		end("invalid argument (<name>.ber)", 0);
	engine = engine_start(av[1]);
	parser(engine);
	mlx_hook(engine->mlx_win, 2, 1L << 0, key_controls, engine);
	mlx_hook(engine->mlx_win, 3, 1L << 1, key_hold, engine);
	mlx_hook(engine->mlx_win, 17, 1L << 17, destroy_hook, engine);
	mlx_loop(engine->mlx);
	return (0);
}
