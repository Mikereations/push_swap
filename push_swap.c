/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aba-nabi <aba-nabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 01:18:13 by aba-nabi          #+#    #+#             */
/*   Updated: 2022/07/09 00:41:01 by aba-nabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_args(char **argv, int start)
{
	int		i;
	int		j;
	char	c;

	i = start;
	while (argv[i])
	{
		j = 0;
		c = argv[i][j];
		while (c)
		{
			if (!is_numeric(c) && !(c == '-' && j == 0) && start)
				ft_error(NULL, NULL, 0);
			else if (!is_numeric(c) && !(c == '-' && j == 0))
				ft_error(NULL, argv, 0);
			if (c == '-' && j == 0 && argv[i][j + 1] == 0 && start)
				ft_error(NULL, NULL, 0);
			else if (c == '-' && j == 0 && argv[i][j + 1] == 0)
				ft_error(NULL, argv, 0);
			j++;
			c = argv[i][j];
		}
		i++;
	}
	return (i - 1);
}

int	main(int argc, char **argv)
{
	char	**params;
	t_stack	prog;
	int		i;

	i = 1;
	prog.total = 0;
	if (argc < 2)
		return (0);
	if (argc == 2)
		params = ft_splitter(argv[1], ' ');
	else
	{
		prog.total = count_args(argv, 1);
		params = (char **)malloc(sizeof(char *) * (prog.total + 1));
		params[prog.total] = 0;
		while (argv[i])
		{
			params[i - 1] = argv[i];
			i++;
		}
	}
	prog = fill_stack(prog, params);
	prog = sort(prog);
	ft_end(&prog);
	return (0);
}
