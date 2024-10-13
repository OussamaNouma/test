/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouma <onouma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 14:53:33 by onouma            #+#    #+#             */
/*   Updated: 2024/10/13 19:36:52 by onouma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	is_sorted(t_stack *stack)
{
	int	i;

	if (stack->info_b.size != 0)
		return (0);
	i = 0;
	while (i < stack->info_a.size)
	{
		if (stack->a[i] != i + 1)
			return (0);
		i++;
	}
	return (1);
}

static void	sort_size_3(t_stack *stack)
{
	if (stack->a[0] == stack->info_a.min)
	{
		if (stack->a[1] == stack->info_a.max)
		{
			sa(stack, 0);
			ra(stack, 0);
		}
	}
	else if (stack->a[0] == stack->info_a.max)
	{
		if (stack->a[1] == stack->info_a.min)
			ra(stack, 0);
		else
		{
			sa(stack, 0);
			rra(stack, 0);
		}
	}
	else
	{
		if (stack->a[1] == stack->info_a.min)
			sa(stack, 0);
		else
			rra(stack, 0);
	}
}

static void	sort_size_5(t_stack *stack)
{
	sort_algo_5_bis(stack);
	update_info(stack, 1);
	sort_size_3(stack);
	while (stack->info_b.size != 0)
		pa(stack, 1);
}

static void	sort_n(t_stack *stack)
{
	int	mode;

	update_info(stack, 1);
	sort_mediane(stack);
	update_info(stack, 1);
	sort_size_3(stack);
	while (stack->info_b.size != 0)
	{
		update_info(stack, 0);
		select_move(stack);
	}
	update_info(stack, 1);
	if (found_index(stack->info.min, stack->a,
			stack->info_a.size) < stack->info_a.med)
		mode = 0;
	else
		mode = 1;
	while (stack->a[0] != stack->info_a.min)
	{
		if (mode == 0)
			ra(stack, 1);
		else
			rra(stack, 1);
	}
}

int	sort(t_stack *stack)
{
	if (is_sorted(stack) == 1)
		return (0);
	if (stack->info.size == 2)
		sa(stack, 1);
	else if (stack->info.size <= 3)
		sort_size_3(stack);
	else if (stack->info.size <= 5)
		sort_size_5(stack);
	else
		sort_n(stack);
	if (is_sorted(stack) == 1)
		return (0);
	return (1);
}
