/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_stackadd.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/06 17:29:46 by igvan-de       #+#    #+#                */
/*   Updated: 2019/08/06 17:38:27 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stackadd(t_stack **node, t_stack *new)
{
	if (!node || !new)
		return ;
	new->next = *node;
	*node = new;
}
