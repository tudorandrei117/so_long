/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburlacu <tburlacu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:36:40 by tburlacu          #+#    #+#             */
/*   Updated: 2022/11/03 16:07:47 by tburlacu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	j = 0;
	i = 0;
	if (!str)
		return (NULL);
	while (s1[i] != '\0')
	{
	str[j] = s1[i];
			i++;
			j++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		str[j] = s2[i];
			i++;
			j++;
	}
	str[j] = '\0';
	return (str);
}
