/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 20:58:39 by hbutt             #+#    #+#             */
/*   Updated: 2024/06/18 14:48:18 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Va calculer le nombre d'opérations il faudrait pour mettre nbr de la stack A
	vers la stack B en utilisant que des rotate */
int	nbr_rarb(t_stack *stack_a, t_stack *stack_b, int nbr)
{
	int	i;
	int	j;
	int	operation;

	i = find_index(stack_a, nbr);
	j = find_place_b(stack_b, nbr);
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

/* Va calculer le nombre d'opérations il faudrait pour mettre nbr de la stack A
	vers la stack B en utilisant que des reverse rotate */
int	nbr_rrarrb(t_stack *stack_a, t_stack *stack_b, int nbr)
{
	int	i;
	int	j;
	int	operation;

	i = find_index(stack_a, nbr);
	j = find_place_b(stack_b, nbr);
	operation = 0;
	while (i < stacksize(stack_a) && j < stacksize(stack_b))
	{
		i++;
		j++;
		operation++;
	}
	while (i < stacksize(stack_a))
	{
		i++;
		operation++;
	}
	while (j < stacksize(stack_b))
	{
		j++;
		operation++;
	}
	return (operation);
}

/* Va calculer le nombre d'opérations il faudrait pour mettre nbr de la stack A
	vers la stack B en utilisant que des rotate pour la stack A et des rr 
	pour la stack B */
int	nbr_rarrb(t_stack *stack_a, t_stack *stack_b, int nbr)
{
	int	i;
	int	j;
	int	operation;

	i = find_index(stack_a, nbr);
	j = find_place_b(stack_b, nbr);
	operation = 0;
	while (i > 0)
	{
		i--;
		operation++;
	}
	while (j < stacksize(stack_b))
	{
		j++;
		operation++;
	}
	return (operation);
}

/* Va calculer le nombre d'opérations il faudrait pour mettre nbr de la stack A
	vers la stack B en utilisant que des reverse rotate pour la stack A et des r 
	pour la stack B */
int	nbr_rrarb(t_stack *stack_a, t_stack *stack_b, int nbr)
{
	int	i;
	int	j;
	int	operation;

	i = find_index(stack_a, nbr);
	j = find_place_b(stack_b, nbr);
	operation = 0;
	while (i < stacksize(stack_a))
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
