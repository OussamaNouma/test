/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouma <onouma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 12:30:32 by onouma            #+#    #+#             */
/*   Updated: 2024/10/08 18:15:47 by onouma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// free the mem allocated to the array and return null
static char	**error_handler(char **strs, size_t x)
{
	size_t	i;

	i = 0;
	while (i < x)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

// return the number of word with c as seperating char
static size_t	ft_count_word(char const *str, char c)
{
	size_t	nb_word;
	size_t	i;

	i = 0;
	nb_word = 0;
	if (!str)
		return (nb_word);
	while (str[i])
	{
		while (str[i] == c)
		{
			i++;
			if (!str[i])
				return (nb_word);
		}
		while (!(str[i] == c) && str[i])
			i++;
		nb_word++;
	}
	return (nb_word);
}

// return the lenght of the word
static size_t	ft_strlen_word(char const *str, char c)
{
	size_t	i;
	size_t	l;

	i = 0;
	l = 0;
	while (str[i] && !(str[i] == c))
	{
		l++;
		i++;
	}
	return (l);
}

// duplicate a string with a given length
static char	*ft_strdup_split(char const *str, size_t len)
{
	char	*dup;
	size_t	i;

	dup = (char *)malloc((len + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = 0;
	return (dup);
}

// split a string into arrays using a specified separator
char	**ft_split(char const *str, char c)
{
	char	**strs;
	size_t	i;
	size_t	x;

	i = 0;
	x = 0;
	if (!str)
		return (NULL);
	strs = (char **)malloc(sizeof(char *) * (ft_count_word(str, c) + 1));
	if (!strs)
		return (NULL);
	while (x < ft_count_word(str, c))
	{
		if (!(str[i] == c) && str[i])
		{
			strs[x] = ft_strdup_split(&str[i], ft_strlen_word(&str[i], c));
			if (!strs[x])
				return (error_handler(strs, x));
			i += ft_strlen_word(&str[i], c);
			x++;
		}
		i++;
	}
	strs[x] = 0;
	return (strs);
}
