/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aba-nabi <aba-nabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 21:46:49 by aba-nabi          #+#    #+#             */
/*   Updated: 2021/12/23 23:49:47 by aba-nabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (needle[i])
	{
		while (haystack[j] && len--)
		{
			if (haystack[j++] == needle[i++])
			{
				if (!needle[i])
					return (&(((char *)haystack)[j - i]));
			}
			else
			{
				j = j - i + 1;
				len += i - 1;
				i = 0;
			}
		}
		return (NULL);
	}
	return ((char *)haystack);
}
