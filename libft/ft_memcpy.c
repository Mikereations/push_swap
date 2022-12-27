/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aba-nabi <aba-nabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 13:53:13 by aba-nabi          #+#    #+#             */
/*   Updated: 2021/12/28 19:57:30 by aba-nabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int		i;

	i = 0;
	if (!((unsigned char *)dst) && !((unsigned char *)src))
		return (dst);
	while (i++ < (int)n)
	{
		((unsigned char *)dst)[i - 1] = ((unsigned char *)src)[i - 1];
	}
	return (dst);
}
