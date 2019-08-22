/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   chunk.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/22 14:31:01 by igvan-de       #+#    #+#                */
/*   Updated: 2019/08/22 16:29:06 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	size_chunk(int i, t_chunksize *chunksize)
{
	ft_printf("%d\n", i);
	if (i < 10)
		chunksize->size = i;
	else if (i >= 10 && i <= 100)
		chunksize->size = i / 5;
	else if (i > 100)
		chunksize->size = i / 11;
}