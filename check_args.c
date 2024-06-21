/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:23:15 by hbutt             #+#    #+#             */
/*   Updated: 2024/06/21 17:33:15 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_num(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-' && !num[1])
		return (0);
	if (num[0] == '-')
		i++;
	while (num[i])
	{
		if (num[i] > '9' || num[i] < '0')
			return (0);
		i++;
	}
	return (1);
}

static int	is_dup(int tmp, char **av, int i)
{
	i++;
	while (av[i])
	{
		if (tmp == ft_atol(av[i]))
			return (1);
		i++;
	}
	return (0);
}

/* Verifie s'il n y a pas autre chose que des int, des doublons */
void	check_args(char **av, int k)
{
	int		i;
	long	tmp;

	i = 1;
	if (k == 2)
		i = 0;
	while (av[i])
	{
		tmp = ft_atol(av[i]);
		if (is_num(av[i]) == 0)
			ft_error("Error : on a dit que des nombres chef\n");
		if (is_dup(tmp, av, i) == 1)
			ft_error("Error : il y a des doublons chef\n");
		if (tmp > 2147483647 || tmp < -2147483648)
			ft_error("Error : calme toi avec tes nombres trop grand\n");
		i++;
	}
}
