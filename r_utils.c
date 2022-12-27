/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aba-nabi <aba-nabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 01:49:47 by aba-nabi          #+#    #+#             */
/*   Updated: 2022/04/21 06:31:08 by aba-nabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	rb(t_stack prog, int *rotation_count)
{
	t_element	top;

	if (prog.b_count < 2)
		return (prog);
	top = prog.b[0];
	prog.b = step_up(prog.b, prog.b_count);
	prog.b[prog.b_count - 1] = top;
	prog.steps += 1;
	if (!prog.silence)
		write(1, "rb\n", 3);
	(*rotation_count)++;
	return (prog);
}

t_stack	rr(t_stack prog)
{
	t_element	top;

	if (prog.b_count >= 2)
	{
		top = prog.b[0];
		prog.b = step_up(prog.b, prog.b_count);
		prog.b[prog.b_count - 1] = top;
		prog.steps += 1;
	}
	if (prog.a_count >= 2)
	{
		top = prog.a[0];
		prog.a = step_up(prog.a, prog.a_count);
		prog.a[prog.a_count - 1] = top;
		prog.steps += 1;
	}
	if (!prog.silence)
		write(1, "rr\n", 3);
	return (prog);
}

t_stack	rrb(t_stack prog)
{
	t_element	bottom;

	if (prog.b_count < 2)
		return (prog);
	bottom = prog.b[prog.b_count - 1];
	prog.b = step_down(prog.b, prog.b_count);
	prog.b[0] = bottom;
	prog.steps += 1;
	if (!prog.silence)
		write(1, "rrb\n", 4);
	return (prog);
}

t_stack	rra(t_stack prog)
{
	t_element	bottom;

	if (prog.a_count < 2)
		return (prog);
	bottom = prog.a[prog.a_count - 1];
	prog.a = step_down(prog.a, prog.a_count);
	prog.a[0] = bottom;
	prog.steps += 1;
	if (!prog.silence)
		write(1, "rra\n", 4);
	return (prog);
}

t_stack	rrr(t_stack prog)
{
	prog = rra(prog);
	prog = rrb(prog);
	prog.steps += 1;
	return (prog);
}
