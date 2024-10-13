/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouma <onouma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:52:09 by onouma            #+#    #+#             */
/*   Updated: 2024/10/08 18:15:56 by onouma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// write str in fd
int	ft_putstr_fd(char *str, int fd)
{
	return (write(fd, str, ft_strlen(str)));
}

/**
 * write str followed by a newline
 * and return the nb of char written or -1 if error
 */
int	ft_putendl_fd(char *str, int fd)
{
	int	ret;

	ret = ft_putstr_fd(str, fd);
	if (ret == -1)
		return (-1);
	ret = ft_putstr_fd("\n", fd);
	if (ret == -1)
		return (-1);
	return (ret);
}

// outpout str to the standard outpout
int	ft_putendl(char *str)
{
	return (ft_putendl_fd(str, 1));
}

// outpout str to the error outpout
int	ft_putendl_err(char *str)
{
	return (ft_putendl_fd(str, 2));
}
