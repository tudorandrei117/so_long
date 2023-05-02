/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburlacu <tburlacu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:35:29 by tburlacu          #+#    #+#             */
/*   Updated: 2022/10/31 10:37:22 by tburlacu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90)
		|| (c >= '0' && c <= '9'))
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
	printf("%d", ft_isalnum(c));
	printf("%d", ft_isalnum(b));
	printf("%d", ft_isalnum(a));
}  */