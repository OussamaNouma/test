/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouma <onouma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 14:56:03 by onouma            #+#    #+#             */
/*   Updated: 2024/10/13 19:06:02 by onouma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	found_index(int value, int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (tab[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

void	sort_algo_5_bis(t_stack *stack)
{
	int	i;
	int	mode;

	i = 0;
	if (found_index(1, stack->a, stack->info_a.size) < stack->info_a.size / 2)
		mode = 0;
	else
		mode = 1;
	while (stack->info_a.size != 3)
	{
		if (stack->a[0] == i + 1)
		{
			pb(stack, 1);
			if (found_index(++i + 1, stack->a,
					stack->info_a.size) < stack->info_a.size / 2)
				mode = 0;
			else
				mode = 1;
		}
		else if (mode == 0)
			ra(stack, 1);
		else
			rra(stack, 1);
	}
}

void	sort_mediane(t_stack *stack)
{
	while (stack->info_a.size != 3)
	{
		if (stack->info_a.med <= stack->a[0])
		{
			pb(stack, 1);
			if (stack->info_a.med == stack->b[0])
				update_info(stack, 1);
			else
				ra(stack, 1);
		}
	}
}

static void	r_moves(t_stack *stack, t_moves *move)
{
	while (move->rra > 0 && move->rrb > 0)
	{
		rr(stack, 1);
		move->rra--;
		move->rrb--;
	}
	while (move->ra > 0 && move->rb > 0)
	{
		rr(stack, 1);
		move->ra--;
		move->rb--;
	}
}

void	exec_move(t_stack *stack, t_moves move)
{
	r_moves(stack, &move);
	while (move.ra > 0)
	{
		ra(stack, 1);
		move.ra--;
	}
	while (move.rb > 0)
	{
		rb(stack, 1);
		move.rb--;
	}
	while (move.rra > 0)
	{
		rra(stack, 1);
		move.rra--;
	}
	while (move.rrb > 0)
	{
		rrb(stack, 1);
		move.rrb--;
	}
	pa(stack, 1);
}
