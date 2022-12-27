/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aba-nabi <aba-nabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 01:30:51 by aba-nabi          #+#    #+#             */
/*   Updated: 2022/07/09 01:11:56 by aba-nabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	swap_three(t_stack prog)
{
	if (prog.a_count == 2 && prog.a[0].pos > prog.a[1].pos)
	{
		prog = sa(prog);
		return (prog);
	}
	if (prog.a_count == 3)
	{
		if (prog.a[0].pos > prog.a[1].pos && prog.a[0].pos > prog.a[2].pos)
			prog = ra(prog);
		if (prog.a[0].pos > prog.a[1].pos)
			prog = sa(prog);
		if (prog.a[2].pos < prog.a[0].pos)
			prog = rra(prog);
	}
	if (prog.a[0].pos < prog.a[1].pos && prog.a[1].pos > prog.a[2].pos)
	{
		prog = pb(prog);
		prog = sa(prog);
		prog = pa(prog);
	}
	if (prog.a[0].pos > prog.a[1].pos && prog.a[0].pos < prog.a[2].pos)
		prog = optimize(prog);
	return (prog);
}

t_stack	swap_five_sex(t_stack prog)
{
	if (prog.a[2].pos > prog.a[3].pos && prog.a[2].pos < prog.a[4].pos)
	{
		prog = ra(prog);
		prog = ra(prog);
		prog = swap_three(prog);
		prog = rra(prog);
		prog = rra(prog);
	}
	if (prog.a[1].pos > prog.a[2].pos && prog.a[1].pos < prog.a[3].pos)
	{
		prog = ra(prog);
		prog = swap_three(prog);
		prog = rra(prog);
	}
	prog = swap_three(prog);
	return (prog);
}

t_stack	restore(t_stack prog, int min)
{
	while (prog.a[prog.a_count - 1].pos != prog.total - 1
		&& prog.a[prog.a_count - 1].pos > min)
		prog = rra(prog);
	return (prog);
}

t_stack	dat_ting(t_stack prog, int start, int *midpoint, int myth)
{
	if (*midpoint - start <= 3 && myth)
		prog = swap_three(prog);
	if (!is_a_sorted(prog))
	{
		prog = sorted_count(prog);
		*midpoint = (prog.total - prog.sorted);
		prog = pivot(prog, start + 1, (start + 1 + *midpoint) / 2, myth);
	}
	return (prog);
}

t_stack	optimize(t_stack prog)
{
	int	a;
	int	b;

	a = prog.a[0].pos == prog.a[1].pos + 1;
	b = prog.b[0].pos + 1 == prog.b[1].pos;
	if (a && b)
		prog = ss(prog);
	else if (a)
		prog = sa(prog);
	else if (b)
		prog = sb(prog);
	return (prog);
}
