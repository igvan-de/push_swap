/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   delnode.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/08 13:58:49 by igvan-de       #+#    #+#                */
/*   Updated: 2019/08/08 14:08:06 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_delnode(t_stack *stack)
{
	if (stack == NULL)
		return ;
	free(stack);
	stack = NULL;
}
