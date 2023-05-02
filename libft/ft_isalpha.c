/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburlacu <tburlacu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 11:42:45 by tburlacu          #+#    #+#             */
/*   Updated: 2022/10/31 10:37:20 by tburlacu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
/*  #include "stdio.h"
  #include "ctype.h"
int main (void)
{
	char c = 'a';
	char a = '2';
	char b = 'B';
	printf("%d\n", ft_isalpha(c));
	printf("%d\n", ft_isalpha(b));
	printf("%d\n", ft_isalpha(a));
	printf("%d\n", isalpha(c));
	printf("%d\n", isalpha(a));
}  */