/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aba-nabi <aba-nabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 15:48:24 by aba-nabi          #+#    #+#             */
/*   Updated: 2022/07/01 15:06:19 by aba-nabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		idx;

	idx = ft_strlen(dst);
	if ((int)dstsize < 0)
	{
		ft_strlcpy(&dst[idx], src, ft_strlen(src));
		dst[idx + ft_strlen(src)] = 0;
		return (ft_strlen(dst));
	}
	if (idx < dstsize)
	{
		if (ft_strlen(src) < dstsize - idx)
		{
			ft_strlcpy(&dst[idx], src, ft_strlen(src) + 1);
			dst[idx + ft_strlen(src)] = 0;
			return (idx + ft_strlen(src));
		}
		else
		{
			ft_strlcpy(&dst[idx], src, dstsize - idx + 1);
			dst[dstsize - 1] = 0;
			return (idx + ft_strlen(src));
		}
	}
	return (dstsize + ft_strlen(src));
}
