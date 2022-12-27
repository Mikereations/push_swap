/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispay.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aba-nabi <aba-nabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 01:50:22 by aba-nabi          #+#    #+#             */
/*   Updated: 2022/04/24 02:07:31 by aba-nabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	display(t_stack prog)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	ft_printf("a\tb\n");
	while (i < prog.total)
	{
		if (i >= prog.a_count && j >= prog.b_count)
			break ;
		if (i < prog.a_count)
		{
			ft_printf("%d", prog.a[i].value);
		}
		if (j < prog.b_count)
		{
			ft_printf("\t%d", prog.b[j].value);
		}
		i++;
		j++;
		ft_printf("\n");
	}
}
