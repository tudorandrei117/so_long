/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburlacu <tburlacu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:34:56 by tburlacu          #+#    #+#             */
/*   Updated: 2022/11/08 14:23:25 by tburlacu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_lenret(long long n, char *str)
{
	if (n >= 10)
		str = ft_lenret(n / 10, str);
	*str++ = (n % 10) + '0';
	*str = 0;
	return (str);
}

char	*ft_itoa(int n)
{
	char	str[15];

	if (n < 0)
	{
		str[0] = '-';
		ft_lenret(((long long)n * -1), &str[1]);
	}
	else
		ft_lenret(n, str);
	return (ft_substr(str, 0, (ft_strlen(str))));
}

/*  int main()
{
	long int a;
	a = -3000000000000000;
	printf("%s", ft_itoa(a));
}  */