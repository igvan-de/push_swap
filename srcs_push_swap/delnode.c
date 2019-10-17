/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   delnode.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/08 13:58:49 by igvan-de       #+#    #+#                */
/*   Updated: 2019/10/17 18:00:50 by igvan-de      ########   odam.nl         */
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

void	memdel_stack(t_stack **stack)
{
	if (*stack == NULL)
		return ;
	memdel_stack(&(*stack)->next);
	ft_memdel((void*)stack);
}
