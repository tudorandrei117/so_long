/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburlacu <tburlacu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:32:51 by tburlacu          #+#    #+#             */
/*   Updated: 2022/11/03 16:07:32 by tburlacu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str1)
{
	char	*str2;

	str2 = (char *)malloc(ft_strlen(str1) + 1);
	if (!str2)
		return (0);
	ft_memcpy(str2, str1, ft_strlen(str1) + 1);
	return (str2);
}
