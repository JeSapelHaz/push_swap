/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 13:46:05 by hbutt             #+#    #+#             */
/*   Updated: 2024/05/27 13:47:11 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Fonction main */
int	main(int ac, char **av)
{
	t_stack	**stack_a;
	t_stack	**stack_b;

	stack_a = (t_stack **)malloc(sizeof(t_stack));
	stack_b = (t_stack **)malloc(sizeof(t_stack));
	if (!stack_a || !stack_b)
		return (0);
	*stack_a = NULL;
	*stack_b = NULL;
	init_stack(stack_a, ac, av);
	print_all_stacks(stack_a, stack_b);
	if (already_sorted(stack_a))
	{
		free_stack(stack_a);
		free_stack(stack_b);
		return (0);
	}
	if (stacksize(*stack_a) < 6)
		sort_small(stack_a, stack_b);
	else
		sort_big(stack_a, stack_b);
	print_all_stacks(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}

// pb(stack_a, stack_b);
// pb(stack_a, stack_b);
// do_rrarb(stack_a, stack_b, (*stack_a)->value);
// pb(stack_a, stack_b);
// pb(stack_a, stack_b);
// pb(stack_a, stack_b);
// sort_three(stack_a);
// ft_printf("%d", get_max(stack_b));
// ft_printf(" best place for 5 in b : <%d>\n", find_place_b(*stack_b, 5));
// ft_printf(" best place for 10 in a : <%d>\n", find_place_a(*stack_a, 10));
// do_rarb_bis(stack_a, stack_b, 5);
// do_rarb_bis(stack_a, stack_b, 14);
// do_rarb_bis(stack_a, stack_b, 10);
// do_rarb_bis(stack_a, stack_b, 16);
// print_all_stacks(stack_a, stack_b);
// printf("%d", if_rrarb(*stack_a, *stack_b, (*stack_a)->next->value));
// print_all_stacks(stack_a, stack_b);
// printf("%d\n", nbr_rarb_bis(*stack_a, *stack_b, 10));
// printf("%d\n", nbr_rrarrb_bis(*stack_a, *stack_b, 10));
// printf("%d\n", nbr_rarrb_bis(*stack_a, *stack_b, 10));
// printf("%d\n", nbr_rrarb_bis(*stack_a, *stack_b, 10));
// printf("17 : %d\n", find_index(*stack_b, 17));
// printf("14 : %d\n", find_index(*stack_b, 14));
// printf("12 : %d\n", find_index(*stack_b, 12));
// printf("10 : %d\n", find_index(*stack_b, 10));
// printf("2 : %d\n", find_index(*stack_b, 2));
// printf("1 : %d\n", find_index(*stack_b, 1));
// printf("19 : %d\n", find_index(*stack_b, 19));
// printf("18 : %d\n", find_index(*stack_b, 18));
// printf("place de 5 : %d\n", find_place_a(*stack_a, 5));
// printf("place de 10 : %d\n", find_place_a(*stack_a, 10));
// printf("place de 7 : %d\n", find_place_a(*stack_a, 7));
// printf("%d", nbr_rrarb_bis(*stack_a, *stack_b, 17));
// printf("%d", nbr_rarrb_bis(*stack_a, *stack_b, 17));
// printf("%d", nbr_rrarrb_bis(*stack_a, *stack_b, 17));
// sort_stack_a(stack_a, stack_b);
// else
// sort(stack_a, stack_b, stacksize(*stack_a));