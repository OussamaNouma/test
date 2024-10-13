/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouma <onouma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 19:07:58 by onouma            #+#    #+#             */
/*   Updated: 2024/10/13 19:32:07 by onouma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	stack;
	int		*tab;
	int		nb_nbrs;

	ft_bzero(&stack, sizeof(t_stack));
	if (ac == 1)
		return (1);
	else if (ac == 2 && ft_strlen(av[1]) == 0)
		return (ft_putendl_err("Error"), 2);
	nb_nbrs = ac - 1;
	tab = parsing(ac - 1, &av[1], &(nb_nbrs));
	if (!tab)
		return (ft_putendl_err("Error"), 3);
	if (init_stack(&stack, tab, nb_nbrs) == 1)
		return (destroy_stack(&stack), ft_putendl_err("Error"), 4);
	if (sort(&stack) == 1)
		return (destroy_stack(&stack), ft_putendl_err("Error"), 5);
	destroy_stack(&stack);
	return (0);
}
