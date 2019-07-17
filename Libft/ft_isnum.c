/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isnum.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/17 16:34:08 by igvan-de       #+#    #+#                */
/*   Updated: 2019/07/17 16:48:16 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_isnum(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}
