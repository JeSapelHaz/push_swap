/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack_bis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:25:22 by hbutt             #+#    #+#             */
/*   Updated: 2024/06/18 16:18:46 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* renvoie le minimum de la stack */
int	get_min(t_stack **stack)
{
	t_stack	*node;
	int		min;

	node = *stack;
	min = node->value;
	while (node->next != NULL)
	{
		node = node->next;
		if (min > node->value)
		{
			min = node->value;
		}
	}
	return (min);
}

/* renvoie le max de la stack */
int	get_max(t_stack **stack)
{
	t_stack	*node;
	int		max;

	node = *stack;
	max = node->value;
	while (node->next != NULL)
	{
		node = node->next;
		if (max < node->value)
		{
			max = node->value;
		}
	}
	return (max);
}

/* retourne l'index du nbr en paramètre */
int	find_index(t_stack *stack, int nbr)
{
	int	i;

	i = 0;
	while (stack->value != nbr)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

/* cherche l'index du parametre nbr dans la stack
	si nbr plus grand que le dernier de la stack et plus petit que le premier
		: return 0
	si nbr plus petit que le plus petit de la stack ou plus grand que le plus
		grand de la stack
		: return index du plus grand car il prendra sa place
	sinon on retourne la valeur de i qui monte de 1 à chaque fois
		que la valeur pointée par la stack est plus petite que nbr
		ou que la valeur suivante pointée par stack est plus grande que nbr */
int	find_place_b(t_stack *stack_b, int nbr)
{
	int		i;
	t_stack	*tmp;

	i = 1;
	if (nbr < stacklast(stack_b)->value && nbr > stack_b->value)
		return (0);
	else if (nbr < get_min(&stack_b) || nbr > get_max(&stack_b))
		return (find_index(stack_b, get_max(&stack_b)));
	else
	{
		tmp = stack_b->next;
		while (stack_b->value < nbr || tmp->value > nbr)
		{
			stack_b = stack_b->next;
			tmp = stack_b->next;
			i++;
		}
	}
	return (i);
}

/* renvoie la place de nbr dans la stack a */
int	find_place_a(t_stack *stack_a, int nbr)
{
	int		i;
	t_stack	*tmp;

	i = 1;
	if (nbr > stacklast(stack_a)->value && nbr < stack_a->value)
		return (0);
	else if (nbr > get_max(&stack_a) || nbr < get_min(&stack_a))
		return (find_index(stack_a, get_min(&stack_a)));
	else
	{
		tmp = stack_a->next;
		while (stack_a->value > nbr || tmp->value < nbr)
		{
			stack_a = stack_a->next;
			tmp = stack_a->next;
			i++;
		}
	}
	return (i);
}
