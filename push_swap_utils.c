/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aba-nabi <aba-nabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 02:09:14 by aba-nabi          #+#    #+#             */
/*   Updated: 2022/04/24 02:11:07 by aba-nabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	to_a_support(t_stack prog, int midpoint, int *rrb_steps)
{
	if (prog.b[prog.b_count - 1].pos > midpoint)
		prog = rrb(prog);
	else
		prog = rb(prog, rrb_steps);
	return (prog);
}
