/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_r_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aba-nabi <aba-nabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 01:50:03 by aba-nabi          #+#    #+#             */
/*   Updated: 2022/07/09 00:58:34 by aba-nabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	pa(t_stack prog)
{
	t_element	temp;

	if (prog.b_count < 1)
		return (prog);
	temp = prog.b[0];
	prog.b = step_up(prog.b, prog.b_count);
	prog.b_count--;
	prog.a_count++;
	prog.a = step_down(prog.a, prog.a_count);
	prog.a[0] = temp;
	prog.steps += 1;
	if (!prog.silence)
		write(1, "pa\n", 3);
	return (prog);
}

t_stack	pb(t_stack prog)
{
	t_element	temp;

	if (prog.a_count < 1)
		return (prog);
	temp = prog.a[0];
	prog.a = step_up(prog.a, prog.a_count);
	prog.a_count--;
	prog.b_count++;
	prog.b = step_down(prog.b, prog.b_count);
	prog.b[0] = temp;
	prog.steps++;
	if (!prog.silence)
		write(1, "pb\n", 3);
	return (prog);
}

t_stack	ra(t_stack prog)
{
	t_element	top;

	if (prog.a_count < 2)
		return (prog);
	top = prog.a[0];
	prog.a = step_up(prog.a, prog.a_count);
	prog.a[prog.a_count - 1] = top;
	prog.steps += 1;
	if (!prog.silence)
		write(1, "ra\n", 3);
	return (prog);
}

t_element	*step_down(t_element *arr, int size)
{
	int	i;

	i = size - 1;
	while (i > 0)
	{
		arr[i] = arr[i - 1];
		i--;
	}
	return (arr);
}

t_element	*step_up(t_element *arr, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		arr[i] = arr[i + 1];
		i++;
	}
	return (arr);
}
