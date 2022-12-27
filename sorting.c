/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aba-nabi <aba-nabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 00:50:04 by aba-nabi          #+#    #+#             */
/*   Updated: 2022/07/09 00:56:33 by aba-nabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	innerb(t_stack prog, int *start, int *end)
{
	prog = optimize(prog);
	while (prog.a_count && !is_a_sorted(prog)
		&& prog.a[0].pos < *end && prog.a[0].pos)
		prog = pb(prog);
	while (!prog.sorted && prog.a_count
		&& prog.a[prog.a_count - 1].pos < *end)
	{
		prog = rra(prog);
		prog = pb(prog);
	}
	while (prog.a_count && !is_a_sorted(prog)
		&& locate_smallest(prog).pos < *end
		&& locate_smallest(prog).pos >= *start)
	{
		if (prog.a[0].pos < *end)
			prog = pb(prog);
		else
		{
			prog = ra(prog);
			prog.total_rotations++;
		}
	}
	return (prog);
}

t_stack	to_b(t_stack prog, int start, int end)
{
	prog.total_rotations = 0;
	if (!is_a_sorted(prog) && prog.sorted && end - start <= 3)
		prog = swap_three(prog);
	if (!is_a_sorted(prog))
	{
		prog = innerb(prog, &start, &end);
		if (prog.a_count && prog.total_rotations
			&& !is_a_sorted(prog) && prog.sorted > 0)
			prog = restore(prog, -1);
	}
	return (prog);
}

t_stack	innerfunc(t_stack prog, int *sem, int myth)
{
	int	rrb_steps;

	rrb_steps = 0;
	while (prog.b_count && locate_largest(prog).pos > sem[2])
	{
		if (prog.b[0].pos < prog.b[1].pos)
			prog = optimize(prog);
		while (prog.b_count && prog.b[0].pos <= sem[2])
			to_a_support(prog, sem[1], &rrb_steps);
		prog = pa(prog);
	}
	while (sem[0] > 0 && rrb_steps--)
		prog = rrb(prog);
	if (!is_a_sorted(prog))
	{
		if (sem[1] - sem[2] == 1)
			prog = optimize(prog);
		else if (myth)
			prog = dat_ting(prog, sem[2], &sem[1], myth);
		else
			prog = dat_ting(prog, sem[0], &sem[2], myth);
	}
	return (prog);
}

t_stack	to_a(t_stack prog, int start, int end, int myth)
{
	int	midpoint;
	int	stats[3];

	midpoint = (end + start) / 2;
	while (end && start != end)
	{
		stats[0] = start;
		stats[1] = end;
		stats[2] = midpoint;
		prog = innerfunc(prog, stats, myth);
		end = midpoint;
		midpoint = (end + start) / 2 ;
	}
	return (prog);
}

t_stack	pivot(t_stack prog, int start, int midpoint, int myth)
{
	if (myth == 1 && prog.prev_steps < prog.steps)
		return (prog);
	if (prog.a_count <= 3)
		prog = swap_three(prog);
	if (!is_a_sorted(prog))
		prog = to_b(prog, start, midpoint);
	if (!is_a_sorted(prog))
		prog = pivot(prog, midpoint, midpoint + \
		(prog.a_count - prog.sorted - prog.start) / 2, myth);
	if (myth && midpoint - start >= 25)
		prog = to_a(prog, start, midpoint, myth);
	else
		prog = to_a(prog, start - 1, midpoint - 1, myth);
	if (prog.a_count == prog.total - 1)
		prog = pa(prog);
	return (prog);
}
