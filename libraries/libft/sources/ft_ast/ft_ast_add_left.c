/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ast_add_left.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 14:02:42 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/01/19 00:08:43 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_ast_add_left(t_ast **root, t_ast *new)
{
	if (!(*root))
	{
		*root = new;
		return ;
	}
	(*root)->left = new;
}
