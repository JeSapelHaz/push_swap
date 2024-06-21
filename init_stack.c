/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:08:30 by hbutt             #+#    #+#             */
/*   Updated: 2024/06/21 17:36:20 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(char *str)
{
	char	sign;
	long	result;

	result = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == 45)
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - 48);
		str++;
	}
	return (result * sign);
}

/* Va initialiser la stack a si les arguments sont mis entre guillemets */
static void	commas_args(t_stack **stack, char *av)
{
	int		i;
	int		j;
	char	**tmp;

	i = 0;
	j = 0;
	tmp = ft_split(av, 32);
	while (tmp[j])
		j++;
	if (j < 2)
	{
		ft_error("Error : Rajoute des nombres chef, pourquoi t'es timide comme ca\n");
	}
	check_args(tmp, 2);
	while (i < j)
	{
		stackadd_back(stack, stacknew(ft_atol(tmp[i])));
		i++;
	}
}

/* Va initialiser la stack a */
void	init_stack(t_stack **stack, int ac, char **av)
{
	int		i;
	t_stack	*new;

	i = 1;
	if (ac < 2)
	{
		ft_error("Error : Rajoute des nombres chef, pourquoi t'es timide comme ca\n");
	}
	if (ac == 2)
	{
		commas_args(stack, av[1]);
	}
	else
	{
		check_args(av, 1);
		while (i < ac)
		{
			new = stacknew(ft_atol(av[i]));
			stackadd_back(stack, new);
			i++;
		}
	}
}
