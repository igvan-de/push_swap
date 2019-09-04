/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   median.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/04 13:44:23 by igvan-de       #+#    #+#                */
/*   Updated: 2019/09/04 15:58:03 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		median(t_stack *stack, t_median *max_int, int i)
{
	t_stack		*tmp;
	int			count;
	int			median;
	int			highest;

	tmp = stack;
	count = tmp->number;
	median = 0;
	highest = 0;
	while (tmp->next != NULL)
	{
		if (tmp->number > highest)
			highest = tmp->number;
		tmp = tmp->next;
		count += tmp->number;
	}
	median = count / i;
	max_int->chunk1 = median / 2;
	max_int->chunk2 = median;
	max_int->chunk3 = median + max_int->chunk1;
	max_int->chunk4 = highest;
	ft_printf("%d\n", max_int->chunk1);
	ft_printf("%d\n", max_int->chunk2);
	ft_printf("%d\n", max_int->chunk3);
	ft_printf("%d\n", max_int->chunk4);
}
