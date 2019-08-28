/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   chunk.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/22 14:31:01 by igvan-de       #+#    #+#                */
/*   Updated: 2019/08/28 13:16:45 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	size_chunk(int i, t_chunksize *chunk)
{
	if (i < 100)
	{
		if (i % 5 == 0)
			chunk->size = i / 5;
		else
			chunk->size = i / 5 + 1;
	}
	if (i > 100)
	{
		if (i % 11 == 0)
			chunk->size = i / 11;
		else
			chunk->size = i / 11 + 1;
	}
}
