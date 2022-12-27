/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   locators.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aba-nabi <aba-nabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 00:49:42 by aba-nabi          #+#    #+#             */
/*   Updated: 2022/07/01 15:11:36 by aba-nabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_element	locate_element(int idx, t_stack prog)
{
	int			i;
	t_element	item;

	i = 0;
	item.idx = idx;
	item.pos = 0;
	item.value = prog.a[idx].value;
	while (i < prog.a_count)
	{
		if (prog.a[i].value == item.value && i != idx)
		{
			item.pos = -1;
			return (item);
		}
		if (prog.a[i].value < item.value)
			item.pos++;
		i++;
	}
	return (item);
}

int	locate_closest(t_stack prog, int end)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (prog.a[i].pos > end)
		i++;
	j = prog.a_count;
	while (prog.a[j].pos > end)
		j--;
	if (prog.a_count - j > i)
		return (i);
	return (j);
}

t_element	locate_largest(t_stack prog)
{
	int			i;
	t_element	item;

	i = 0;
	item.idx = 0;
	item.value = prog.b[0].value;
	while (i < prog.b_count)
	{
		if (prog.b[i].value > item.value)
		{
			item.value = prog.b[i].value;
			item.idx = i;
		}
		i++;
	}
	return (prog.b[item.idx]);
}

t_element	locate_smallest(t_stack prog)
{
	int			i;
	t_element	item;

	i = 1;
	item.idx = 0;
	item.value = prog.a[0].value;
	while (i < prog.a_count)
	{
		if (prog.a[i].value < item.value)
		{
			item.value = prog.a[i].value;
			item.idx = i;
		}
		i++;
	}
	return (prog.a[item.idx]);
}
