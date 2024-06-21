/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 17:50:47 by hbutt             #+#    #+#             */
/*   Updated: 2024/06/18 15:54:13 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Va reverse rotate la stack et donc tout descendre de 1*/
static void	reverse_rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;
	int		len_stack;

	len_stack = stacksize(*stack) - 1;
	first = *stack;
	last = stacklast(*stack);
	while (len_stack != 1)
	{
		first = first->next;
		len_stack--;
	}
	first->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rra(t_stack **stack_a)
{
	reverse_rotate(stack_a);
	ft_printf("rra\n");
}

void	rrb(t_stack **stack_b)
{
	reverse_rotate(stack_b);
	ft_printf("rrb\n");
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_printf("rrr\n");
}
