/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburlacu <tburlacu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:41:52 by tburlacu          #+#    #+#             */
/*   Updated: 2022/10/31 10:37:19 by tburlacu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
/* 
  #include "stdio.h"
int main (void)
{
	char c = 'a';
	char a = '2';
	char b = 'B';
	printf("%d", ft_isascii(c));
	printf("%d", ft_isascii(b));
	printf("%d", ft_isascii(a));
}   */