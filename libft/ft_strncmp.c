/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aba-nabi <aba-nabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 17:56:35 by aba-nabi          #+#    #+#             */
/*   Updated: 2021/12/28 20:17:48 by aba-nabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	o;
	int	t;

	while (n--)
	{
		if (*s1 == 0 && *s2 == 0)
		{
			return (0);
		}
		if (*(unsigned char *)s1++ != *(unsigned char *)s2++)
		{
			o = *(unsigned char *)--s1;
			t = *(unsigned char *)--s2;
			return (o - t);
		}
	}
	return (0);
}
