/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aba-nabi <aba-nabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 01:36:49 by aba-nabi          #+#    #+#             */
/*   Updated: 2022/07/01 15:32:44 by aba-nabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_stack(t_stack *prog)
{
	(*prog).a = (t_element *)malloc(sizeof(t_element) * (*prog).total);
	(*prog).b = (t_element *)malloc(sizeof(t_element) * (*prog).total);
	(*prog).a_count = 0;
	(*prog).b_count = 0;
	(*prog).start = 0;
	(*prog).steps = 0;
	(*prog).sorted = 0;
	(*prog).last[0] = 0;
	(*prog).total_rotations = 0;
}

t_stack	helper(t_stack prog, char **values, int flag, long value)
{
	int		i;

	i = 0;
	while (values[i])
	{
		value = ft_modatoi(values[i], prog, values, flag);
		prog.a[i].value = value;
		prog.a_count++;
		i++;
	}
	prog.total = prog.a_count;
	i = 0;
	while (i < prog.a_count)
	{
		prog.a[i] = locate_element(i, prog);
		if (prog.a[i].pos == -1)
			ft_error(&prog, values, flag);
		i++;
	}
	return (prog);
}

t_stack	fill_stack(t_stack prog, char **values)
{	
	long	value;
	int		flag;

	flag = prog.total;
	value = 0;
	if (prog.total == 0)
		prog.total = count_args(values, 0) + 1;
	init_stack(&prog);
	prog = helper(prog, values, flag, value);
	ft_free_map(values, flag);
	return (prog);
}

int	is_sorted(t_stack prog)
{
	int	i;
	int	prev;

	i = 1;
	if (prog.a_count != prog.total || prog.b_count != 0)
		return (0);
	prev = prog.a[0].value;
	while (i < prog.total)
	{
		if (prog.a[i].value < prev)
			return (0);
		prev = prog.a[i].value;
		i++;
	}
	return (1);
}

int	is_a_sorted(t_stack prog)
{
	int	i;
	int	prev;

	i = 1;
	prev = prog.a[0].value;
	while (i < prog.a_count)
	{
		if (prog.a[i].value < prev)
			return (0);
		prev = prog.a[i].value;
		i++;
	}
	return (1);
}
