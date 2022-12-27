/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aba-nabi <aba-nabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 01:50:13 by aba-nabi          #+#    #+#             */
/*   Updated: 2022/07/01 15:35:44 by aba-nabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_map(char **map, int flag)
{
	int	i;

	i = 0;
	if (flag)
	{
		free(map);
		return ;
	}
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	ft_modatoi(const char *str, t_stack prog, char **map, int flag)
{
	int		n;
	size_t	sum;

	sum = 0;
	n = 1;
	while ((*str == ' ' || (*str >= 9 && *str <= 13)) && *str)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			n = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if ((long long)(sum * n) > INT_MAX || (long long)(sum * n) < INT_MIN)
			ft_error(&prog, map, flag);
		sum = sum * 10 + *str++ - '0';
	}
	return (sum * n);
}

void	ft_error(t_stack *prog, char **map, int flag)
{
	printf("Error\n");
	if (map != NULL)
		ft_free_map(map, flag);
	if (prog)
	{
		free((*prog).a);
		(*prog).a = NULL;
	}
	if (prog)
	{
		free((*prog).b);
		(*prog).b = NULL;
	}
	exit(1);
}

void	ft_end(t_stack *prog)
{
	if (prog)
	{
		free((*prog).a);
		(*prog).a = NULL;
	}
	if (prog)
	{
		free((*prog).b);
		(*prog).b = NULL;
	}
	exit(0);
}
