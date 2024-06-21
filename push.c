/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:05:29 by hbutt             #+#    #+#             */
/*   Updated: 2024/06/18 14:44:04 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Va push le premier de la stack src vers la stack dest */
static int	push(t_stack **stack_src, t_stack **stack_dest)
{
	t_stack	*tmp;

	if (*stack_src == NULL)
		return (-1);
	tmp = (*stack_src)->next;
	(*stack_src)->next = *stack_dest;
	*stack_dest = *stack_src;
	*stack_src = tmp;
	return (0);
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	int	a;

	a = push(stack_b, stack_a);
	if (a == -1)
	{
		return ;
	}
	ft_printf("pa\n");
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	int	a;

	a = push(stack_a, stack_b);
	if (a == -1)
	{
		return ;
	}
	ft_printf("pb\n");
}
