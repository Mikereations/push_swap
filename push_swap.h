/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aba-nabi <aba-nabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 01:49:55 by aba-nabi          #+#    #+#             */
/*   Updated: 2022/07/09 00:54:16 by aba-nabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <string.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"
# include "./printf/libftprintf.h"

typedef struct s_element{
	int	idx;
	int	value;
	int	pos;
}	t_element;

typedef struct s_flag{
	int	v;
	int	c;
}	t_flag;

typedef struct s_stack{
	t_element	*a;
	t_element	*b;
	char		last[5];
	int			total;
	int			steps;
	int			prev_steps;
	int			total_rotations;
	int			silence;
	int			a_count;
	int			start;
	int			sorted;
	int			b_count;
	t_flag		flags;
}	t_stack;

int			is_numeric(char c);
t_stack		fill_stack(t_stack prog, char **values);
void		display(t_stack prog);
t_stack		sa(t_stack prog);
t_stack		sb(t_stack prog);
t_stack		ss(t_stack prog);
t_stack		pa(t_stack prog);
t_stack		pb(t_stack prog);
t_element	*step_down(t_element *arr, int size);
t_element	*step_up(t_element *arr, int size);
t_element	locate_element(int idx, t_stack prog);
int			locate_closest(t_stack prog, int end);
t_element	locate_smallest(t_stack prog);
t_element	locate_largest(t_stack prog);
int			ft_modatoi(const char *str, t_stack prog, char **map, int flag);
void		ft_error(t_stack *prog, char **map, int flag);
t_stack		rb(t_stack prog, int *rotation_count);
void		bring_to_top(t_stack *prog, int pos);
t_stack		ra(t_stack prog);
void		ft_end(t_stack *prog);
t_stack		optimize(t_stack prog);
t_stack		swap_three_b(t_stack prog);
t_stack		swap_five_sex(t_stack prog);
t_stack		restore(t_stack prog, int min);
t_stack		dat_ting(t_stack prog, int start, int *midpoint, int myth);
t_stack		rra(t_stack prog);
t_stack		rrb(t_stack prog);
int			is_a_sorted(t_stack prog);
void		ft_free_map(char **map, int flag);
t_stack		rr(t_stack prog);
t_stack		rrr(t_stack prog);
t_stack		to_b(t_stack prog, int start, int end);
t_stack		pivot(t_stack prog, int start, int midpoint, int myth);
t_stack		tovip(t_stack prog, int start, int end);
int			sorting(t_stack prog, int myth);
t_stack		to_a(t_stack prog, int start, int end, int myth);
t_stack		swap_three(t_stack prog);
t_stack		soreting(t_stack prog, int myth);
t_stack		sorted_count(t_stack prog);
int			is_sorted(t_stack prog);
t_stack		to_a_support(t_stack prog, int midpoint, int *rrb_steps);
t_stack		sort(t_stack prog);
t_stack		doubles(t_stack prog, int *steps);
int			count_args(char **argv, int start);
char		**ft_splitter(char const *s, char c);
t_stack		doubleopp(t_stack prog, int *steps);
t_stack		pivot(t_stack prog, int start, int midpoint, int myth);

#endif
