/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_r.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouma <onouma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 12:48:18 by onouma            #+#    #+#             */
/*   Updated: 2024/10/12 13:12:55 by onouma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
 * Rotates the elements in the 'stack' array in reverse order.
 * The last element becomes the first element,
	and all other elements are shifted down one position.
 *
 * @param stack The array to be rotated.
 * @param size The size of the 'stack' array.
 */

static void	rotate_reverse(int *stack, int size)
{
	int	tmp;
	int	i;

	i = size - 1;
	tmp = stack[size - 1];
	while (i > 0)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	stack[0] = tmp;
}

void	rra(t_stack *stack, bool print)
{
	if (stack->info_a.size >= 1)
	{
		rotate_reverse(stack->a, stack->info_a.size);
		if (print)
			ft_putendl("rra");
	}
}

void	rrb(t_stack *stack, bool print)
{
	if (stack->info_b.size >= 1)
	{
		rotate_reverse(stack->b, stack->info_b.size);
		if (print)
			ft_putendl("rrb");
	}
}

void	rrr(t_stack *stack, bool print)
{
	if (stack->info_a.size >= 1 && stack->info_b.size >= 1)
	{
		rotate_reverse(stack->a, stack->info_a.size);
		rotate_reverse(stack->b, stack->info_b.size);
		if (print)
			ft_putendl("rrr");
	}
}
