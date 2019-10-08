/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   extra_print.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/08 14:38:42 by igvan-de       #+#    #+#                */
/*   Updated: 2019/10/08 14:43:16 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	timed_print(t_options *option)
{
	if (option->flags & FLAG_T)
	{
		sleep(1);
		system("clear");
	}
}

void	result_print(t_stack *stack_a, t_stack *stack_b, t_options *option)
{
	if (option->flags & FLAG_R)
		print(stack_a, stack_b);
}
