/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aba-nabi <aba-nabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 21:30:07 by aba-nabi          #+#    #+#             */
/*   Updated: 2021/12/28 20:02:11 by aba-nabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int	o;
	int	t;

	while (n--)
	{
		if (*(unsigned char *)s1++ != *(unsigned char *)s2++)
		{
			o = *(unsigned char *)--s1;
			t = *(unsigned char *)--s2;
			return (o - t);
		}
	}
	return (0);
}
