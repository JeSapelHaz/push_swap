/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 16:34:51 by hbutt             #+#    #+#             */
/*   Updated: 2024/06/13 16:48:00 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Fonction reprise de la libft pour créer un nouvel élément (struct)
		d'une list */
t_stack	*stacknew(int value)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = value;
	new->next = NULL;
	return (new);
}

/* Fonction reprise de la libft pour rajouter un élément à la fin d'une liste */
void	stackadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*t;

	if (!stack || !new)
		return ;
	if (!(*stack))
	{
		*stack = new;
		return ;
	}
	t = *stack;
	while (t->next)
		t = t->next;
	t->next = new;
}

/* Fonction reprise de la libft pour rajouter un élément au début d'une liste */
void	stackadd_front(t_stack **stack, t_stack *new)
{
	if (!stack || !new)
		return ;
	new->next = *stack;
	*stack = new;
}

/* retourne le dernier élément de la liste */
t_stack	*stacklast(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next != NULL)
	{
		stack = stack->next;
	}
	return (stack);
}

/* retourne la taille de la liste */
int	stacksize(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack != NULL)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}
