/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   median.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/04 13:44:23 by igvan-de       #+#    #+#                */
/*   Updated: 2019/09/05 16:13:09 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		median(t_stack *stack, t_chunk *chunk, int i)
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
	chunk->chunk1 = median / 2;
	chunk->chunk2 = median;
	chunk->chunk3 = median + chunk->chunk1;
	chunk->chunk4 = highest;
	ft_printf("%d\n", chunk->chunk1);
	ft_printf("%d\n", chunk->chunk2);
	ft_printf("%d\n", chunk->chunk3);
	ft_printf("%d\n", chunk->chunk4);
}
