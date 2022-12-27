/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aba-nabi <aba-nabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 01:02:28 by aba-nabi          #+#    #+#             */
/*   Updated: 2021/12/28 20:52:42 by aba-nabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*s1;

	i = 0;
	if (!s)
		return (NULL);
	while (i++ < start && *s)
		s++;
	if (!*s)
		s1 = malloc(1);
	else if (ft_strlen(s) < len)
		s1 = malloc(ft_strlen(s) + 1);
	else
		s1 = malloc(len + 1);
	if (!s1)
		return (NULL);
	i = 0 ;
	while (i < len && *s)
	{
		s1[i] = *s++;
		i++;
	}
	s1[i] = 0;
	return (s1);
}
