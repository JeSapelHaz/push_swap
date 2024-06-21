/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_ba.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 12:46:56 by hbutt             #+#    #+#             */
/*   Updated: 2024/06/17 16:27:28 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_rarb_bis(t_stack **stack_a, t_stack **stack_b, int nbr)
{
	int	i;

	i = find_place_a(*stack_a, nbr);
	while ((*stack_b)->value != nbr && i > 0)
	{
		rr(stack_a, stack_b);
		i--;
	}
	while ((*stack_b)->value != nbr)
	{
		rb(stack_b);
	}
	while (i > 0)
	{
		ra(stack_a);
		i--;
	}
	pa(stack_a, stack_b);
}

void	do_rrarrb_bis(t_stack **stack_a, t_stack **stack_b, int nbr)
{
	int	i;

	i = find_place_a(*stack_a, nbr);
	while ((*stack_b)->value != nbr && i < stacksize(*stack_a))
	{
		rrr(stack_a, stack_b);
		i++;
	}
	while ((*stack_b)->value != nbr)
	{
		rrb(stack_b);
	}
	while (i < stacksize(*stack_a))
	{
		rra(stack_a);
		i++;
	}
	pa(stack_a, stack_b);
}

void	do_rrarb_bis(t_stack **stack_a, t_stack **stack_b, int nbr)
{
	int	i;

	i = find_place_a(*stack_a, nbr);
	while ((*stack_b)->value != nbr)
	{
		rb(stack_b);
	}
	while (i < stacksize(*stack_a))
	{
		rra(stack_a);
		i++;
	}
	pa(stack_a, stack_b);
}

void	do_rarrb_bis(t_stack **stack_a, t_stack **stack_b, int nbr)
{
	int	i;

	i = find_place_a(*stack_a, nbr);
	while ((*stack_b)->value != nbr)
	{
		rrb(stack_b);
	}
	while (i > 0)
	{
		ra(stack_a);
		i--;
	}
	pa(stack_a, stack_b);
}
