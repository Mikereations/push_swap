/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aba-nabi <aba-nabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 17:47:02 by aba-nabi          #+#    #+#             */
/*   Updated: 2021/12/27 13:48:15 by aba-nabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*l;

	l = NULL;
	c = c % 128;
	while (1)
	{
		if (*s == c)
			l = (char *)s;
		if (!*(char *)s)
			return (l);
		s++;
		if (*s == c)
			l = (char *)s;
	}
	return (l);
}
