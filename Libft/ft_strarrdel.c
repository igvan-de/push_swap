/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strarrdel.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/09 14:48:47 by igvan-de       #+#    #+#                */
/*   Updated: 2019/09/23 14:00:57 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_strarrdel(char ***arr)
{
	int i;

	i = 0;
	if (arr == NULL || *arr == NULL)
		return ;
	while ((*arr)[i] != NULL)
	{
		ft_strdel(&((*arr)[i]));
		i++;
	}
	free(*arr);
	*arr = NULL;
}
