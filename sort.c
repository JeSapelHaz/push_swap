/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 13:57:58 by hbutt             #+#    #+#             */
/*   Updated: 2024/06/18 14:50:20 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* vérifie si la stack est déjà trié */
int	already_sorted(t_stack **stack_a)
{
	t_stack	*stack;

	stack = *stack_a;
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	sort_three(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	first = *stack;
	second = first->next;
	third = second->next;
	if (first->value > second->value && first->value > third->value)
		ra(stack);
	else if (second->value > first->value && second->value > third->value)
		rra(stack);
	if ((*stack)->value > (*stack)->next->value)
		sa(stack);
}

static void	sort_four(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*node;
	int		min;

	node = *stack_a;
	min = get_min(stack_a);
	while (node->value != min && node->next)
	{
		node = node->next;
		ra(stack_a);
	}
	pb(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
}

static void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*node;
	int		min;

	node = *stack_a;
	min = get_min(stack_a);
	while (node->value != min && node->next)
	{
		node = node->next;
		ra(stack_a);
	}
	pb(stack_a, stack_b);
	min = get_min(stack_a);
	node = *stack_a;
	while (node->value != min)
	{
		node = node->next;
		ra(stack_a);
	}
	pb(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

/* Va trier la stack si la taille ne depasse pas 5 */
void	sort_small(t_stack **stack_a, t_stack **stack_b)
{
	if (stacksize(*stack_a) == 2)
	{
		if ((*stack_a)->value > (*stack_a)->next->value)
			sa(stack_a);
	}
	else if (stacksize(*stack_a) == 3)
		sort_three(stack_a);
	else if (stacksize(*stack_a) == 4)
		sort_four(stack_a, stack_b);
	else if (stacksize(*stack_a) == 5)
		sort_five(stack_a, stack_b);
}
