/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburlacu <tburlacu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:04:11 by tburlacu          #+#    #+#             */
/*   Updated: 2022/10/31 14:19:26 by tburlacu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stddef.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!src && !dest)
		return (0);
	if ((size_t)dest - (size_t)src < n)
	{
		i = n -1;
		while (i < n)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i--;
		}
	}
	else
	{
		while (i < n)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dest);
}
/* #include "stdio.h"
int main()
{
	char str1[] = "oldstring";
	char str2[] = "NEWSTRING";
	
	printf("Before memmove dest = %s, src = %s\n", str1, str2);
	ft_memmove(str1, str2, 9);
	printf("After memmove dest = %s, src = %s\n", str1, str2);
}  */