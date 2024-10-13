/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouma <onouma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 18:29:58 by onouma            #+#    #+#             */
/*   Updated: 2024/10/13 19:06:40 by onouma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	min(int *arr, int size)
{
	int	minimum;
	int	i;

	minimum = arr[0];
	i = 0;
	while (i < size)
	{
		if (arr[i] < minimum)
			minimum = arr[i];
		i++;
	}
	return (minimum);
}

static int	max(int *arr, int size)
{
	int	maximum;
	int	i;

	maximum = arr[0];
	i = 0;
	while (i < size)
	{
		if (arr[i] > maximum)
			maximum = arr[i];
		i++;
	}
	return (maximum);
}

static int	update_info_bis(t_info *info, int *tab, int size, bool mode)
{
	int	sorted_tab[MAX_VALUE];

	info->size = size;
	info->min = min(tab, size);
	info->max = max(tab, size);
	if (mode == 1)
	{
		ft_bzero(sorted_tab, MAX_VALUE);
		bubble_sort(tab, size, sorted_tab);
		info->med = sorted_tab[size / 2];
	}
	else
		info->med = -1;
	return (0);
}

void	update_info(t_stack *stack, bool mode)
{
	if (update_info_bis(&stack->info_a, stack->a, stack->info_a.size, mode))
		return (destroy_stack(stack), ft_putendl_err("Error"), exit(7));
	if (update_info_bis(&stack->info_b, stack->b, stack->info_b.size, mode))
		return (destroy_stack(stack), ft_putendl_err("Error"), exit(7));
}
