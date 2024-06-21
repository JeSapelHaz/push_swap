/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 18:36:20 by hbutt             #+#    #+#             */
/*   Updated: 2024/06/02 16:59:53 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Renvoie message d'erreur */
void	ft_error(char *message)
{
	ft_printf("%s", message);
	exit(0);
}

/* va libérer la mémoire allouée à la chaine pointée par str
	+ va mettre le pointer str à NULL pour eéviter l'accès aà une
	zone de mémoire déjà libérée (segfault)	*/
void	*ft_free_all(char **str)
{
	free(*str);
	*str = NULL;
	return (0);
}

/* Libère la mémoire pour chaque noeud et ensuite pour la liste */
void	free_stack(t_stack **stack)
{
	t_stack	*node;
	t_stack	*tmp;

	node = *stack;
	while (node)
	{
		tmp = node;
		node = node->next;
		free(tmp);
	}
	free(stack);
}
