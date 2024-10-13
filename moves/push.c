/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouma <onouma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 11:43:01 by onouma            #+#    #+#             */
/*   Updated: 2024/10/12 12:56:33 by onouma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
 * Pushes the top element from 'to_push' array to 'to_receive' array.
 * Adjusts sizes and shifts elements in both arrays accordingly.
 *
 * @param to_push Array to push from
 * @param to_receive Array to push to
 * @param size_tp Pointer to size of 'to_push'
 * @param size_tr Pointer to size of 'to_receive'
 */
static void	push(int *to_push, int *to_receive, int *size_tp, int *size_tr)
{
	const int	size = *size_tp + *size_tr;
	int			tmp_top;
	int			i;

	tmp_top = to_push[0];
	to_push[0] = 0;
	i = -1;
	while (++i < *size_tp)
		if (i + 1 < size)
			to_push[i] = to_push[i + 1];
	*size_tp -= 1;
	*size_tr += 1;
	i = *size_tr + 1;
	while (--i > 0)
		if (i < size && i - 1 >= 0)
			to_receive[i] = to_receive[i - 1];
	to_receive[0] = tmp_top;
}

void	pa(t_stack *stack, bool print)
{
	if (stack->info_b.size > 0)
	{
		push(stack->b, stack->a, &stack->info_b.size, &stack->info_a.size);
		if (print)
			ft_putendl("pa");
	}
}

void	pb(t_stack *stack, bool print)
{
	if (stack->info_a.size > 0)
	{
		push(stack->a, stack->b, &stack->info_a.size, &stack->info_b.size);
		if (print)
			ft_putendl("pb");
	}
}
