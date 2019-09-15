/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/15 16:08:27 by igvan-de       #+#    #+#                */
/*   Updated: 2019/09/15 16:51:36 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print(t_stack *stack_a, t_stack *stack_b)
{
	t_stack *tmp;

	tmp = stack_a;
	ft_printf("a = ");
	while (tmp != NULL)
	{
		ft_printf("%d ", tmp->number);
		tmp = tmp->next;
	}
	ft_printf("\n");
	if (stack_b == NULL)
		return ;
	tmp = stack_b;
	ft_printf("b = ");
	while (tmp != NULL)
	{
		ft_printf("%d ", tmp->number);
		tmp = tmp->next;
	}
	ft_printf("\n");
}

//NEED TO COMBINE IT WITH CHECKER.C
int			checker_sort(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (argv[i + 1] != '\0')
		{
			if (ft_atoi(argv[i]) > ft_atoi(argv[i + 1]))
				return (1);
		}
		i++;
	}
	return (0);
}
