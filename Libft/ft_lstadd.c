/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/04 08:19:57 by igvan-de       #+#    #+#                */
/*   Updated: 2019/08/08 14:49:07 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	if (*alst == NULL || new == NULL)
		return ;
	new->next = *alst;
	*alst = new;
}
