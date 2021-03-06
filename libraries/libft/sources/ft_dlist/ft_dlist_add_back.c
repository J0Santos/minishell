/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_add_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 13:03:28 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/07/26 16:04:16 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** This function adds an element to a double linked list.
** The ft_dlist_add_back() function adds the element 'new' at the end of the
** list.
**
** @param	t_dlist **dlist	- address of a pointer to the first link of dlist.
** @param	t_dlist *new	- address of a pointer to the element to be added to
**							the list.
*/
void	ft_dlist_add_back(t_dlist **dlist, t_dlist *new)
{
	t_dlist	*last;

	if (!dlist)
		*dlist = new;
	else
	{
		last = ft_dlist_last(*dlist);
		new->previous = last;
		last->next = new;
	}
}
