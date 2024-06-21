/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:58:37 by hbutt             #+#    #+#             */
/*   Updated: 2024/06/18 15:12:41 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	sort_stack_b_bis(t_stack **stack_a, t_stack **stack_b, t_stack *tmp,
		int i)
{
	if (nbr_rarb(*stack_a, *stack_b, tmp->value) == i)
	{
		do_rarb(stack_a, stack_b, tmp->value);
		return (1);
	}
	else if (nbr_rrarb(*stack_a, *stack_b, tmp->value) == i)
	{
		do_rrarb(stack_a, stack_b, tmp->value);
		return (1);
	}
	else if (nbr_rarrb(*stack_a, *stack_b, tmp->value) == i)
	{
		do_rarrb(stack_a, stack_b, tmp->value);
		return (1);
	}
	else if (nbr_rrarrb(*stack_a, *stack_b, tmp->value) == i)
	{
		do_rrarrb(stack_a, stack_b, tmp->value);
		return (1);
	}
	return (0);
}

void	sort_stack_b(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	while (stacksize(*stack_a) > 3 && !already_sorted(stack_a))
	{
		tmp = *stack_a;
		while (tmp)
		{
			if (sort_stack_b_bis(stack_a, stack_b, tmp, i) == 1)
			{
				i = -1;
				break ;
			}
			tmp = tmp->next;
		}
		i++;
	}
}

static int	sort_stack_a_bis(t_stack **stack_a, t_stack **stack_b, t_stack *tmp,
		int i)
{
	if (nbr_rarb_bis(*stack_a, *stack_b, tmp->value) == i)
	{
		do_rarb_bis(stack_a, stack_b, tmp->value);
		return (1);
	}
	else if (nbr_rrarb_bis(*stack_a, *stack_b, tmp->value) == i)
	{
		do_rrarb_bis(stack_a, stack_b, tmp->value);
		return (1);
	}
	else if (nbr_rarrb_bis(*stack_a, *stack_b, tmp->value) == i)
	{
		do_rarrb_bis(stack_a, stack_b, tmp->value);
		return (1);
	}
	else if (nbr_rrarrb_bis(*stack_a, *stack_b, tmp->value) == i)
	{
		do_rrarrb_bis(stack_a, stack_b, tmp->value);
		return (1);
	}
	return (0);
}

void	sort_stack_a(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	while (stacksize(*stack_b) != 0)
	{
		tmp = *stack_b;
		while (tmp)
		{
			if (sort_stack_a_bis(stack_a, stack_b, tmp, i) == 1)
			{
				i = -1;
				break ;
			}
			tmp = tmp->next;
		}
		i++;
	}
}

void	sort_big(t_stack **stack_a, t_stack **stack_b)
{
	int	i;

	if (stacksize(*stack_a) > 3)
		pb(stack_a, stack_b);
	if (stacksize(*stack_a) > 3)
		pb(stack_a, stack_b);
	if (stacksize(*stack_a) > 3)
		sort_stack_b(stack_a, stack_b);
	sort_three(stack_a);
	sort_stack_a(stack_a, stack_b);
	i = find_index(*stack_a, get_min(stack_a));
	if (i < stacksize(*stack_a) - i)
	{
		while ((*stack_a)->value != get_min(stack_a))
			ra(stack_a);
	}
	else
	{
		while ((*stack_a)->value != get_min(stack_a))
			rra(stack_a);
	}
}
