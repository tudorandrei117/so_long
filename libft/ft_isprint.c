/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburlacu <tburlacu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:44:44 by tburlacu          #+#    #+#             */
/*   Updated: 2022/10/31 10:35:26 by tburlacu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
/*  #include "stdio.h"
int main (void)
{
	char c = '!';
	char a = '2';
	char b = 'B';
    char d = '\n';
	printf("%d", ft_isprint(c));
	printf("%d", ft_isprint(b));
	printf("%d", ft_isprint(a));
    printf("%d", ft_isprint(d));
}   */