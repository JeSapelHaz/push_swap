/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_ab.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:32:35 by hbutt             #+#    #+#             */
/*   Updated: 2024/06/18 14:51:14 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Va faire rotate les 2 stacks */
void	do_rarb(t_stack **stack_a, t_stack **stack_b, int nbr)
{
	int	i;

	i = find_place_b(*stack_b, nbr);
	while ((*stack_a)->value != nbr && i > 0)
	{
		rr(stack_a, stack_b);
		i--;
	}
	while ((*stack_a)->value != nbr)
	{
		ra(stack_a);
	}
	while (i > 0)
	{
		rb(stack_b);
		i--;
	}
	pb(stack_a, stack_b);
}

/* Va reverse rotate les 2 stacks */
void	do_rrarrb(t_stack **stack_a, t_stack **stack_b, int nbr)
{
	int	i;

	i = find_place_b(*stack_b, nbr);
	while ((*stack_a)->value != nbr && i < stacksize(*stack_b))
	{
		rrr(stack_a, stack_b);
		i++;
	}
	while ((*stack_a)->value != nbr)
	{
		rra(stack_a);
	}
	while (i < stacksize(*stack_b))
	{
		rrb(stack_b);
		i++;
	}
	pb(stack_a, stack_b);
}

/* Va rotate la stack a et reverse rotate la stack b */
void	do_rarrb(t_stack **stack_a, t_stack **stack_b, int nbr)
{
	int	i;

	i = find_place_b(*stack_b, nbr);
	while ((*stack_a)->value != nbr)
	{
		ra(stack_a);
	}
	while (i < stacksize(*stack_b))
	{
		rrb(stack_b);
		i++;
	}
	pb(stack_a, stack_b);
}

/* Va rotate la stack b et reverse rotate la stack a */
void	do_rrarb(t_stack **stack_a, t_stack **stack_b, int nbr)
{
	int	i;

	i = find_place_b(*stack_b, nbr);
	while ((*stack_a)->value != nbr)
	{
		rra(stack_a);
	}
	while (i > 0)
	{
		rb(stack_b);
		i--;
	}
	pb(stack_a, stack_b);
}
