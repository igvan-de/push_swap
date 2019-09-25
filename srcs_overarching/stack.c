/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/07 17:26:15 by igvan-de       #+#    #+#                */
/*   Updated: 2019/09/25 15:44:31 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_stackaddback(t_stack **stack, t_stack *new)
{
	t_stack		*tmp;

	tmp = *stack;
	if (*stack == NULL)
	{
		*stack = new;
		return ;
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}

void		ft_stackaddfront(t_stack **stack, t_stack *new)
{
	new->next = *stack;
	*stack = new;
}

t_stack		*ft_newnode(int number)
{
	t_stack		*new_node;

	new_node = (t_stack*)ft_memalloc(sizeof(t_stack));
	if (new_node == NULL)
		return (NULL);
	new_node->number = number;
	new_node->next = NULL;
	return (new_node);
}

t_stack		*ft_emptynode(void)
{
	t_stack		*new_node;

	new_node = (t_stack*)ft_memalloc(sizeof(t_stack));
	if (new_node == NULL)
		return (NULL);
	new_node->next = NULL;
	return (new_node);
}

void		reverse(t_stack **stack)
{
	t_stack	*previous;
	t_stack	*current;
	t_stack	*next;

	current = *stack;
	previous = NULL;
	while (current != NULL)
	{
		next = current->next;
		current->next = previous;
		previous = current;
		current = next;
	}
	*stack = previous;
}
