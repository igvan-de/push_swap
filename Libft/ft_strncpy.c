/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/18 08:38:26 by igvan-de       #+#    #+#                */
/*   Updated: 2019/05/09 17:55:59 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char *temp;

	temp = dst;
	while (len && *src)
	{
		*temp = *src;
		src++;
		temp++;
		len--;
	}
	while (len)
	{
		*temp = 0;
		temp++;
		len--;
	}
	return (dst);
}
