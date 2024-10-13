/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouma <onouma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 13:13:27 by onouma            #+#    #+#             */
/*   Updated: 2024/10/12 13:50:02 by onouma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate(int *stack, int size)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = stack[0];
	while (i < size - 1)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[size - 1] = tmp;
}

void	ra(t_stack *stack, bool print)
{
	if (stack->info_a.size >= 1)
	{
		rotate(stack->a, stack->info_a.size);
		if (print)
			ft_putendl("ra");
	}
}

void	rb(t_stack *stack, bool print)
{
	if (stack->info_b.size >= 1)
	{
		rotate(stack->b, stack->info_b.size);
		if (print)
			ft_putendl("rb");
	}
}

void	rr(t_stack *stack, bool print)
{
	if (stack->info_a.size >= 1 && stack->info_b.size >= 1)
	{
		ra(stack, 0);
		rb(stack, 0);
		if (print)
			ft_putendl("rr");
	}
}
