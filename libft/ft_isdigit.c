/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburlacu <tburlacu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:30:54 by tburlacu          #+#    #+#             */
/*   Updated: 2022/10/31 10:37:15 by tburlacu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
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
	char c = 'a';
	char a = '2';
	char b = 'B';
	printf("%d", ft_isdigit(c));
	printf("%d", ft_isdigit(b));
	printf("%d", ft_isdigit(a));
}  */