/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aba-nabi <aba-nabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 15:11:45 by aba-nabi          #+#    #+#             */
/*   Updated: 2021/12/23 19:29:26 by aba-nabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	if (dstsize > 0)
	{
		if (ft_strlen(src) < dstsize)
		{
			ft_bzero(dst, ft_strlen(src) + 1);
			ft_memcpy(dst, src, ft_strlen(src));
		}
		else
		{
			ft_bzero(dst, dstsize);
			ft_memcpy(dst, src, dstsize - 1);
		}
	}
	return (ft_strlen(src));
}
