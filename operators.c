/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operators.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/06 14:13:54 by igvan-de       #+#    #+#                */
/*   Updated: 2019/08/06 17:42:30 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> //REMOVE!!!!!!!!!!!!!!!!!!!!!

int		sa(char **argv)
{
	int a;
	int b;

	if (argv[1] == NULL)
		return (0);
	a = ft_atoi(argv[1]);
	b = ft_atoi(argv[2]);
	ft_swap(&a, &b);
	return (0);
}


// size = argc 

// stack a = malloc argc * size of int *

// int array[1000]

// print array[500]

// int stack_a[10];
// int stack_b[10];

// char *str "hallo"

// int size = stack_a[10];

// ft_putchar(str[3]);
// j = size / 2;
// stack_b[0] = stack_a[j];
// stack_b->node = a; 


// a   b
// 1	0
// 2	0
// 3	0
// 4	0
// 5	0

// t_stack_a stack(t_stack_a a)
// {
// 	t_stack_a fiets;

// 	fiets->a = argv[0];

// }

// while (stack_a->node->next != NULL)
// {
// 	if (stack_a->node->next == NULL)
// 		stack_b->node = stack_a->node;
// 	stack_a->node = stack_a->node->next;
// }


// stack_b[0] = stack_a[2];
// stack_a[2] = stack_a[3];
// stack_a[3] = stack_a[4];