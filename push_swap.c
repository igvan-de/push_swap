#include "push_swap.h"

void	algorithm(t_stack **stack_a)
{
	t_stack	*tmp;
	t_stack *tmp2;
	int	c1;
	int	c2;

	tmp = *stack_a;
	tmp2 = *stack_a;
	c1 = 1;
	c2 = 1;
	while (tmp->next != NULL)
	{
		if (tmp->number >= 0 && tmp->number <= 19)
			break ;
		tmp = tmp->next;
		c1++;
	}
	reverse(&tmp2);
	while (tmp2->next != NULL)
	{
		if (tmp2->number >= 0 && tmp2->number <= 19)
			break ;
		tmp2 = tmp2->next;
		c2++;
	}
	if (c1 > c2)
	{
		while (c1 > 0)
		{
			ft_printf("\ntestprint\n");
			ra_rb(stack_a);
			c1--;
		}
	}
	else
	{
		while (c2 > 0)
		{
			rra_rrb(stack_a);
			c2--;
		}
	}
}

