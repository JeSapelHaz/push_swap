/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ba.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 21:09:12 by hbutt             #+#    #+#             */
/*   Updated: 2024/06/14 16:20:05 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	nbr_rarb_bis(t_stack *stack_a, t_stack *stack_b, int nbr)
{
	int	i;
	int	j;
	int	operation;

	i = find_index(stack_b, nbr);
	j = find_place_a(stack_a, nbr);
	operation = 0;
	while (i > 0 && j > 0)
	{
		i--;
		j--;
		operation++;
	}
	while (i > 0)
	{
		i--;
		operation++;
	}
	while (j > 0)
	{
		j--;
		operation++;
	}
	return (operation);
}

int	nbr_rrarrb_bis(t_stack *stack_a, t_stack *stack_b, int nbr)
{
	int	i;
	int	j;
	int	operation;

	i = find_index(stack_b, nbr);
	j = find_place_a(stack_a, nbr);
	operation = 0;
	while (i < stacksize(stack_b) && j < stacksize(stack_a))
	{
		i++;
		j++;
		operation++;
	}
	while (i < stacksize(stack_b))
	{
		i++;
		operation++;
	}
	while (j < stacksize(stack_a))
	{
		j++;
		operation++;
	}
	return (operation);
}

int	nbr_rarrb_bis(t_stack *stack_a, t_stack *stack_b, int nbr)
{
	int	i;
	int	j;
	int	operation;

	i = find_index(stack_b, nbr);
	j = find_place_a(stack_a, nbr);
	operation = 0;
	while (i < stacksize(stack_b))
	{
		i++;
		operation++;
	}
	while (j > 0)
	{
		j--;
		operation++;
	}
	return (operation);
}

int	nbr_rrarb_bis(t_stack *stack_a, t_stack *stack_b, int nbr)
{
	int	i;
	int	j;
	int	operation;

	i = find_index(stack_b, nbr);
	j = find_place_a(stack_a, nbr);
	operation = 0;
	while (j < stacksize(stack_a))
	{
		j++;
		operation++;
	}
	while (i > 0)
	{
		i--;
		operation++;
	}
	return (operation);
}
