/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_stacknew.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/06 17:05:44 by igvan-de       #+#    #+#                */
/*   Updated: 2019/08/06 17:33:10 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *ft_newnode(int number)
{
	t_stack		*new_node;

	new_node = (t_stack*)ft_memalloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->number = number;
	new_node->next = NULL;
	return (new_node);
}
