/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburlacu <tburlacu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:10:11 by tburlacu          #+#    #+#             */
/*   Updated: 2022/11/08 11:59:38 by tburlacu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	void	*destination;

	destination = malloc(nmemb * size);
	i = nmemb * size;
	if (destination == NULL)
	{
		return (destination);
	}
	ft_memset(destination, 0, i);
	return (destination);
}
