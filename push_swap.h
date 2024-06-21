/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 13:48:54 by hbutt             #+#    #+#             */
/*   Updated: 2024/06/18 16:19:23 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "printf/ft_printf.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/* Structure */
typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}					t_stack;

/* Inititialize */
void				init_stack(t_stack **stack_a, int ac, char **av);
long				ft_atol(char *str);

/* Check args */
void				check_args(char **av, int k);
char				**ft_split(char const *str, char c);

/* Swap */
void				sa(t_stack **stack_a);
void				sb(t_stack **stack_b);
void				ss(t_stack **stack_a, t_stack **stack_b);

/* Push */

void				pa(t_stack **stack_a, t_stack **stack_b);
void				pb(t_stack **stack_a, t_stack **stack_b);

/* Rotate */
void				ra(t_stack **stack_a);
void				rb(t_stack **stack_b);
void				rr(t_stack **stack_a, t_stack **stack_b);

/* Reverse rotate */
void				rra(t_stack **stack_a);
void				rrb(t_stack **stack_b);
void				rrr(t_stack **stack_a, t_stack **stack_b);

/* Sort */
int					already_sorted(t_stack **stack_a);
void				sort_three(t_stack **stack);
void				sort_small(t_stack **stack_a, t_stack **stack_b);

/* Sort B */
void				sort_big(t_stack **stack_a, t_stack **stack_b);
void				sort_stack_b(t_stack **stack_a, t_stack **stack_b);
void				sort_stack_a(t_stack **stack_a, t_stack **stack_b);

/* Utils list */
t_stack				*stacknew(int value);
void				stackadd_back(t_stack **stack, t_stack *new);
void				stackadd_front(t_stack **stack, t_stack *new);
t_stack				*stacklast(t_stack *stack);
int					stacksize(t_stack *stack);

/* Utils Bis for sort */
int					get_min(t_stack **stack);
int					get_max(t_stack **stack);
int					find_place_b(t_stack *stack_b, int nbr);
int					find_place_a(t_stack *stack_a, int nbr);
int					find_index(t_stack *stack, int nbr);

/* Print */
void				print_stack(t_stack *stack);
void				print_all_stacks(t_stack **stack_a, t_stack **stack_b);

/* Utils */
void				ft_error(char *message);
void				*ft_free_all(char **str);
void				free_stack(t_stack **stack);

/* A to B */
int					nbr_rarb(t_stack *stack_a, t_stack *stack_b, int nbr);
int					nbr_rrarrb(t_stack *stack_a, t_stack *stack_b, int nbr);
int					nbr_rarrb(t_stack *stack_a, t_stack *stack_b, int nbr);
int					nbr_rrarb(t_stack *stack_a, t_stack *stack_b, int nbr);

/* Do A to B */
void				do_rarb(t_stack **stack_a, t_stack **stack_b, int nbr);
void				do_rrarrb(t_stack **stack_a, t_stack **stack_b, int nbr);
void				do_rarrb(t_stack **stack_a, t_stack **stack_b, int nbr);
void				do_rrarb(t_stack **stack_a, t_stack **stack_b, int nbr);

/* B to A */
int					nbr_rarb_bis(t_stack *stack_a, t_stack *stack_b, int nbr);
int					nbr_rrarrb_bis(t_stack *stack_a, t_stack *stack_b, int nbr);
int					nbr_rarrb_bis(t_stack *stack_a, t_stack *stack_b, int nbr);
int					nbr_rrarb_bis(t_stack *stack_a, t_stack *stack_b, int nbr);

/* Do B to A */
void				do_rarb_bis(t_stack **stack_a, t_stack **stack_b, int nbr);
void				do_rrarrb_bis(t_stack **stack_a, t_stack **stack_b,
						int nbr);
void				do_rarrb_bis(t_stack **stack_a, t_stack **stack_b, int nbr);
void				do_rrarb_bis(t_stack **stack_a, t_stack **stack_b, int nbr);

#endif