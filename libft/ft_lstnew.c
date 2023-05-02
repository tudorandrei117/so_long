/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburlacu <tburlacu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:28:22 by tburlacu          #+#    #+#             */
/*   Updated: 2022/11/08 16:34:46 by tburlacu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*newlst;

newlst = (t_list *)malloc(sizeof(t_list));
	if (newlst == NULL)
		return (NULL);
newlst->content = content;
newlst->next = NULL;
	return (newlst);
}
