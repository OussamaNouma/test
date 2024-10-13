/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_bis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouma <onouma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 14:55:31 by onouma            #+#    #+#             */
/*   Updated: 2024/10/13 19:33:01 by onouma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	calculate_r(int a, int b)
{
	if (a == b)
		return (a);
	if (a > b)
		return ((a - b) + b);
	if (a < b)
		return ((b - a) + a);
	return (a + b);
}

static t_moves	smallest_combo(int combo[4], t_moves move, t_moves best)
{
	int	min;
	int	type;
	int	i;

	min = combo[0];
	i = 0;
	while (i < 4)
	{
		if (combo[i] < min)
			min = combo[i];
		i++;
	}
	type = found_index(min, (int *)combo, 4);
	if (type == 0)
		move = (t_moves){.ra = move.ra, .rb = move.rb, .rra = 0, .rrb = 0};
	else if (type == 1)
		move = (t_moves){.ra = 0, .rb = 0, .rra = move.rra, .rrb = move.rrb};
	else if (type == 2)
		move = (t_moves){.ra = move.ra, .rb = 0, .rra = 0, .rrb = move.rrb};
	else if (type == 3)
		move = (t_moves){.ra = 0, .rb = move.rb, .rra = move.rra, .rrb = 0};
	if (min < best.ra + best.rb + best.rra + best.rrb)
		return (move);
	return (best);
}

static t_moves	best_move(t_stack *stack, t_moves *move)
{
	int		combo[4];
	t_moves	best;
	int		i;

	best = (t_moves){MAX, MAX, MAX, MAX};
	i = 0;
	while (i < stack->info_b.size)
	{
		combo[0] = calculate_r(move[i].ra, move[i].rb);
		combo[1] = calculate_r(move[i].rra, move[i].rrb);
		combo[2] = move[i].ra + move[i].rrb;
		combo[3] = move[i].rra + move[i].rb;
		best = smallest_combo(combo, move[i], best);
		if (best.ra + best.rb + best.rra + best.rrb == 0)
			break ;
		i++;
	}
	return (best);
}

static int	found_nb_ra(t_stack *stack, int value)
{
	int	i;

	i = 1;
	while (i < stack->info_a.size)
	{
		if (value > stack->a[i - 1] && value < stack->a[i])
			return (i);
		i++;
	}
	if (value < stack->a[0] && value > stack->a[stack->info_a.size - 1])
		return (i);
	return (found_index(stack->info_a.min, stack->a, stack->info_a.size));
}

void	select_move(t_stack *stack)
{
	t_moves	*move;
	t_moves	to_do;
	int		i;

	move = (t_moves *)ft_calloc(stack->info_b.size, sizeof(t_moves));
	if (!move)
		return (ft_putendl("Error"), destroy_stack(stack), exit(6));
	i = 0;
	while (i < stack->info_b.size)
	{
		move[i] = (t_moves){.ra = found_nb_ra(stack, stack->b[i]), .rb = i,
			.rra = stack->info_a.size - found_nb_ra(stack, stack->b[i]),
			.rrb = stack->info_b.size - i};
		i++;
	}
	to_do = best_move(stack, move);
	exec_move(stack, to_do);
	free(move);
}
