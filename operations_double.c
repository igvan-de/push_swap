/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations_double.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/11 13:02:17 by igvan-de       #+#    #+#                */
/*   Updated: 2019/09/11 14:01:29 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ss(t_stack **stack_a, t_stack **stack_b)
{
	sa_sb(stack_a);
	sa_sb(stack_b);
	ft_printf("ss\n");
}

void		rr(t_stack **stack_a, t_stack **stack_b)
{
	ra_rb(stack_a);
	ra_rb(stack_b);
	ft_printf("rr\n");
}

void		rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra_rrb(stack_a);
	rra_rrb(stack_b);
	ft_printf("rrr\n");
}