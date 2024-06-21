/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:58:16 by hbutt             #+#    #+#             */
/*   Updated: 2024/06/18 14:43:27 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* affiche toute la liste */
void	print_stack(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp != NULL)
	{
		ft_printf("    %d", tmp->value);
		ft_printf("\n");
		tmp = tmp->next;
	}
}

/* affiche les 2 listes */
void	print_all_stacks(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	tmp_a = *stack_a;
	tmp_b = *stack_b;
	ft_printf(" stack a   stack b \n");
	ft_printf(" -------   -------\n");
	while (tmp_a != NULL && tmp_b != NULL)
	{
		ft_printf("|  <%d>  | |  <%d>  |\n", tmp_a->value, tmp_b->value);
		tmp_a = tmp_a->next;
		tmp_b = tmp_b->next;
	}
	while (tmp_a != NULL)
	{
		ft_printf("|  <%d>  | |       |\n", tmp_a->value);
		tmp_a = tmp_a->next;
	}
	while (tmp_b != NULL)
	{
		ft_printf("|       | |  <%d>  |\n", tmp_b->value);
		tmp_b = tmp_b->next;
	}
	ft_printf(" -------   -------\n");
}
