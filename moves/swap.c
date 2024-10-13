/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouma <onouma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 13:20:07 by onouma            #+#    #+#             */
/*   Updated: 2024/10/12 13:52:20 by onouma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	sa(t_stack *stack, bool print)
{
	if (stack->info_a.size > 1)
	{
		swap(&stack->a[0], &stack->a[1]);
		if (print)
			ft_putendl("sa");
	}
}

void	sb(t_stack *stack, bool print)
{
	if (stack->info_b.size > 1)
	{
		swap(&stack->b[0], &stack->b[1]);
		if (print)
			ft_putendl("sb");
	}
}

void	ss(t_stack *stack, bool print)
{
	if (stack->info_a.size > 1 && stack->info_b.size > 1)
	{
		sa(stack, 0);
		sb(stack, 0);
		if (print)
			ft_putendl("ss");
	}
}
