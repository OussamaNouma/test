/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouma <onouma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 19:22:35 by onouma            #+#    #+#             */
/*   Updated: 2024/10/13 19:25:25 by onouma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_int(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static int	found_pos(int *sorted_tab, int val, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (sorted_tab[i] == val)
			return (i + 1);
		i++;
	}
	return (-1);
}

void	bubble_sort(int *tab, int size, int sorted_tab[MAX_VALUE])
{
	int	i;
	int	j;

	i = -1;
	while (++i < size)
		sorted_tab[i] = tab[i];
	i = 0;
	while (i < size - 1)
	{
		j = size - 1;
		while (j > 1)
		{
			if (sorted_tab[j] < sorted_tab[j - 1])
				swap_int(&sorted_tab[j], &sorted_tab[j - 1]);
			j--;
		}
		i++;
	}
}

int	init_stack(t_stack *stack, int *tab, int nb_nbrs)
{
	int	i;
	int	sorted_tab[MAX_VALUE];

	stack->a = ft_calloc(nb_nbrs, sizeof(t_stack));
	if (!stack->a)
		return (free(tab), 1);
	stack->b = ft_calloc(nb_nbrs, sizeof(t_stack));
	if (!stack->b)
		return (free(tab), 1);
	if (nb_nbrs > MAX_VALUE)
		return (free(tab), 1);
	ft_bzero(sorted_tab, MAX_VALUE);
	bubble_sort(tab, nb_nbrs, sorted_tab);
	i = -1;
	while (++i < nb_nbrs)
		stack->a[i] = found_pos(sorted_tab, tab[i], nb_nbrs);
	stack->info = (t_info){.size = nb_nbrs, .min = 1, .max = nb_nbrs,
		.med = sorted_tab[nb_nbrs / 2]};
	stack->info_a = (t_info){.size = nb_nbrs, .min = 1, .max = nb_nbrs,
		.med = sorted_tab[nb_nbrs / 2]};
	stack->info_b = (t_info){.size = 0, .min = 0, .max = 0, .med = 0};
	return (free(tab), 0);
}

void	destroy_stack(t_stack *stack)
{
	if (stack->a)
		ft_free_ptr((void **)&stack->a);
	if (stack->b)
		ft_free_ptr((void **)&stack->b);
	ft_bzero(stack, sizeof(t_stack));
}
