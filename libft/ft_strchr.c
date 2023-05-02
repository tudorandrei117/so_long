/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburlacu <tburlacu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 13:59:06 by tburlacu          #+#    #+#             */
/*   Updated: 2022/10/31 10:33:53 by tburlacu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	ch;

	ch = c;
	while (*s != '\0' && *s != ch)
	{
		s++;
	}
	if (*s == ch)
	{
		return ((char *)s);
	}
	return (0);
}

/* #include "stdio.h"
int main(void)
{
	char str[] = "Isto sera um teste para encontar o y, isto ta depois do y";
	char ch = 'y';
	char *ret;
	ret = ft_strchr(str, ch);
	printf("a str depois do %c is.. %s", ch, ret);
} */