/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aba-nabi <aba-nabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 01:49:41 by aba-nabi          #+#    #+#             */
/*   Updated: 2022/04/21 06:29:17 by aba-nabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	sa(t_stack prog)
{
	t_element	temp;

	if (prog.a_count < 2)
		return (prog);
	temp = prog.a[0];
	prog.a[0] = prog.a[1];
	prog.a[1] = temp;
	prog.steps += 1;
	if (!prog.silence)
		write(1, "sa\n", 3);
	return (prog);
}

t_stack	sb(t_stack prog)
{
	t_element	temp;

	if (prog.b_count < 2)
		return (prog);
	temp = prog.b[0];
	prog.b[0] = prog.b[1];
	prog.b[1] = temp;
	prog.steps += 1;
	if (!prog.silence)
		write(1, "sb\n", 3);
	return (prog);
}

t_stack	ss(t_stack prog)
{
	t_element	temp;

	if (prog.b_count >= 2)
	{
		temp = prog.b[0];
		prog.b[0] = prog.b[1];
		prog.b[1] = temp;
	}
	if (prog.a_count >= 2)
	{
		temp = prog.a[0];
		prog.a[0] = prog.a[1];
		prog.a[1] = temp;
	}
	prog.steps += 1;
	if (!prog.silence)
		write(1, "ss\n", 3);
	return (prog);
}
