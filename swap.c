/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:00:28 by hbutt             #+#    #+#             */
/*   Updated: 2024/06/18 15:58:03 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Va swap les 2 premiers de la stack */
static int	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;
	int		tmp;

	if (stacksize(*stack) < 2)
		return (-1);
	first = *stack;
	second = first->next;
	tmp = first->value;
	first->value = second->value;
	second->value = tmp;
	return (0);
}

void	sa(t_stack **stack_a)
{
	int	a;

	a = swap(stack_a);
	if (a == -1)
	{
		return ;
	}
	ft_printf("sa\n");
}

void	sb(t_stack **stack_b)
{
	int	b;

	b = swap(stack_b);
	if (b == -1)
	{
		return ;
	}
	ft_printf("sb\n");
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	if (stacksize(*stack_a) < 2 || stacksize(*stack_b) < 2)
		return ;
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss\n");
}
