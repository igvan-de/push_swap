/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sorted.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/14 17:45:07 by igvan-de       #+#    #+#                */
/*   Updated: 2019/10/14 17:45:47 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_sorted(t_stack **stack_a)
{
	t_stack	*tmp;

	tmp = *stack_a;
	if (tmp->next == NULL)
		return (0);
	while (tmp->next != NULL)
	{
		if (tmp->number > tmp->next->number)
			return (-1);
		tmp = tmp->next;
	}
	return (0);
}

void	is_sorted(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) < ft_atoi(argv[i + 1]))
		{
			i++;
			if (argv[i + 1] == '\0')
				exit(0);
		}
		else
			break ;
	}
}
