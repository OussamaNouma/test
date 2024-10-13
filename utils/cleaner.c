/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouma <onouma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 20:39:44 by onouma            #+#    #+#             */
/*   Updated: 2024/10/08 18:15:29 by onouma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// free a single pointer
void	ft_free_ptr(void **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

// free all pointers in array of pointers
void	ft_free_ptrs(void **ptrs)
{
	size_t	i;

	i = 0;
	if (!ptrs)
		return ;
	while (ptrs[i])
	{
		free(ptrs[i]);
		ptrs[i] = NULL;
		i++;
	}
	free(ptrs);
	ptrs = NULL;
}
