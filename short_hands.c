/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_hands.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aba-nabi <aba-nabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 01:49:26 by aba-nabi          #+#    #+#             */
/*   Updated: 2022/07/09 00:58:12 by aba-nabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	sorted_count(t_stack prog)
{
	int	i;
	int	pos;

	i = prog.a_count;
	pos = prog.total - 1;
	prog.sorted = 0;
	while (i)
	{
		if (prog.a[i - 1].pos == pos)
		{
			pos--;
			prog.sorted++;
			i--;
		}
		else
			break ;
	}
	return (prog);
}

void	copy_arr(t_element *src, t_element *dst, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		dst[i].value = src[i].value;
		i++;
	}
}

t_stack	sort(t_stack prog)
{
	int			myth1;
	int			i;
	t_element	*a;
	t_element	*b;

	prog.silence = 1;
	a = (t_element *)malloc(sizeof(t_element) * prog.total);
	b = (t_element *)malloc(sizeof(t_element) * prog.total);
	copy_arr(prog.a, a, prog.a_count);
	prog.prev_steps = sorting(prog, 0);
	copy_arr(a, prog.a, prog.a_count);
	i = 0;
	while (i++ < prog.a_count)
		prog.a[i - 1] = locate_element(i - 1, prog);
	myth1 = sorting(prog, 1);
	copy_arr(a, prog.a, prog.a_count);
	i = 0;
	while (i++ < prog.a_count)
		prog.a[i - 1] = locate_element(i - 1, prog);
	prog.silence = 0;
	prog = soreting(prog, myth1 < prog.prev_steps);
	free(a);
	free(b);
	return (prog);
}

t_stack	soreting(t_stack prog, int myth)
{
	int	midpoint;
	int	start;

	while (!is_sorted(prog))
	{
		start = 0;
		if (start == prog.total)
			return (prog);
		midpoint = prog.a_count / 2;
		prog = pivot(prog, start, start + midpoint, myth);
		if (prog.a[0].pos > prog.a[1].pos)
			prog = sa(prog);
		prog = sorted_count(prog);
	}
	return (prog);
}

int	sorting(t_stack prog, int myth)
{
	int	midpoint;
	int	start;

	while (!is_sorted(prog))
	{
		start = 0;
		if (start == prog.total)
			return (prog.steps);
		midpoint = prog.a_count / 2;
		prog = pivot(prog, start, start + midpoint, myth);
		if (prog.a[0].pos > prog.a[1].pos)
			prog = sa(prog);
		prog = sorted_count(prog);
		if (myth == 1 && prog.prev_steps < prog.steps)
			return (prog.steps);
	}
	return (prog.steps);
}
