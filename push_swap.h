/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouma <onouma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 20:03:36 by onouma            #+#    #+#             */
/*   Updated: 2024/10/13 19:36:07 by onouma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

# define MAX_VALUE 500
# define MAX 100000

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 255
# endif
// conversion
int			ft_atoi(const char *str);
int			ft_atol(const char *str);
// parsing
int			*parsing(int nb_args, char **strs, int *nb_nbrs);
// split
char		**ft_split(char const *str, char c);
// free
void		ft_free_ptr(void **ptr);
void		ft_free_ptrs(void **ptr);
// memory
void		ft_bzero(void *s, size_t n);
void		ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_calloc(size_t n, size_t size);
// string
size_t		ft_strlen(char *str);
int			ft_strcmp(const char *s1, const char *s2);
// print
int			ft_putstr_fd(char *str, int fd);
int			ft_putendl_fd(char *str, int fd);
int			ft_putendl(char *str);
int			ft_putendl_err(char *str);

// struct
typedef struct s_info
{
	int		min;
	int		max;
	int		size;
	int		med;
}			t_info;

typedef struct s_stack
{
	int		*a;
	int		*b;
	t_info	info;
	t_info	info_a;
	t_info	info_b;

}			t_stack;

typedef struct s_moves
{
	int		ra;
	int		rra;
	int		rb;
	int		rrb;
}			t_moves;

// rotate
void		ra(t_stack *stack, bool print);
void		rb(t_stack *stack, bool print);
void		rr(t_stack *stack, bool print);

// rotate_reverse
void		rra(t_stack *stack, bool print);
void		rrb(t_stack *stack, bool print);
void		rrr(t_stack *stack, bool print);

// swap
void		sa(t_stack *stack, bool print);
void		sb(t_stack *stack, bool print);
void		ss(t_stack *stack, bool print);

// push
void		pa(t_stack *stack, bool print);
void		pb(t_stack *stack, bool print);

// sort
int			found_index(int value, int *tab, int size);
void		sort_algo_5_bis(t_stack *stack);
void		sort_mediane(t_stack *stack);
void		exec_move(t_stack *stack, t_moves move);
void		bubble_sort(int *tab, int size, int sorted_tab[MAX_VALUE]);
int			init_stack(t_stack *stack, int *tab, int nb_nbrs);
void		destroy_stack(t_stack *stack);
void		select_move(t_stack *stack);
int			sort(t_stack *stack);
// info
void		update_info(t_stack *stack, bool mode);
#endif