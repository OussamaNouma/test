/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouma <onouma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:27:09 by onouma            #+#    #+#             */
/*   Updated: 2024/09/30 14:21:51 by onouma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// check if a given char is valid
static int	is_char(char c)
{
	const char	valid_chars[] = "0123456789-+";
	int			i;

	i = 0;
	while (valid_chars[i])
	{
		if (c == valid_chars[i])
			return (1);
		i++;
	}
	return (0);
}

// here we return true if its a duplicate
static int	is_duplicate(int *arr, int nlen)
{
	int	i;
	int	j;

	i = 0;
	while (i < nlen)
	{
		j = i + 1;
		while (j < nlen)
		{
			if (arr[i] == arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

// here we check if evrything is indeed a number
static int	is_all_number(char **strs)
{
	int	i;
	int	j;

	i = 0;
	while (strs[i])
	{
		j = 0;
		while (strs[i][j])
		{
			if (!is_char(strs[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

// we create a tab and check for overflow after conversion
int	*tab_and_overfow(char **strs, int nbrs_len)
{
	long	tmp;
	int		*tab;
	int		i;

	tab = malloc(sizeof(int) * nbrs_len);
	if (!tab)
		return (0);
	i = 0;
	while (i < nbrs_len)
	{
		tab[i] = ft_atoi(strs[i]);
		tmp = ft_atol(strs[i]);
		if (tmp != (long)tab[i])
		{
			ft_free_ptr((void **)&tab);
			return (0);
		}
		i++;
	}
	return (tab);
}

// parses the input arguments and return an arr of int
int	*parsing(int nb_args, char **strs, int *nb_nbrs)
{
	int	*tab;

	if (nb_args == 1)
	{
		strs = ft_split(strs[0], ' ');
		if (!strs)
			return (NULL);
		*nb_nbrs = 0;
		while (strs[*nb_nbrs])
			(*nb_nbrs)++;
	}
	if (is_all_number(strs) == 0)
	{
		if (nb_args == 1)
			ft_free_ptrs((void **)strs);
		return (NULL);
	}
	tab = tab_and_overfow(strs, *nb_nbrs);
	if (nb_args == 1)
		ft_free_ptrs((void **)strs);
	if (!tab)
		return (NULL);
	if (is_duplicate(tab, *nb_nbrs) == 1)
		return (ft_free_ptr((void **)&tab), NULL);
	return (tab);
}
