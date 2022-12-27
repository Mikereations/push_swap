/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aba-nabi <aba-nabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 18:15:47 by aba-nabi          #+#    #+#             */
/*   Updated: 2021/12/28 21:26:48 by aba-nabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	c = (unsigned char)c;
	while (n--)
	{
		if (*(unsigned char *)s == c)
			return ((void *)s);
		else if ((unsigned char *)s && *(unsigned char *)++s == c && n)
			return ((void *)s);
		if (!*(unsigned char *)s)
			return (NULL);
	}
	return (NULL);
}
