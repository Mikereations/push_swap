/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aba-nabi <aba-nabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 01:28:42 by aba-nabi          #+#    #+#             */
/*   Updated: 2021/12/28 20:59:04 by aba-nabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	cutleft(char *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s1[i])
	{
		j = 0;
		while (j < ft_strlen(set))
		{
			if (set[j] == s1[i])
				break ;
			else
				j++;
		}
		if (j == ft_strlen(set))
			break ;
		else
			i++;
	}
	return (i);
}

static size_t	cutright(char *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(s1) - 1;
	while (&s1[i] != &s1[0])
	{
		j = 0;
		while (j < ft_strlen(set))
		{
			if (set[j] == s1[i])
				break ;
			else
				j++;
		}
		if (j == ft_strlen(set))
			break ;
		else
			i--;
	}
	return (i + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;

	if (!s1 || !set)
		return (NULL);
	i = cutleft((char *)s1, set);
	j = cutright((char *)s1, set);
	return (ft_substr(s1, i, j - i));
}
