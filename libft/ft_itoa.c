/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aba-nabi <aba-nabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 23:53:56 by aba-nabi          #+#    #+#             */
/*   Updated: 2021/12/28 23:20:54 by aba-nabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_putnbr(int nb, char *s, int ofm)
{
	char	c;
	int		idx;

	idx = ofm;
	while (nb > 9 || nb < -9)
	{
		if (nb < -9)
			c = -(nb % 10) + '0';
		else
			c = nb % 10 + '0';
		nb = nb / 10 ;
		s[idx] = c;
		idx--;
	}
	if (nb < 0)
	{
		nb *= -1;
		s[0] = '-';
	}
	s[idx--] = nb % 10 + '0';
	return (s);
}

char	*ft_itoa(int n)
{
	long int	negative;
	int			ofm;
	char		*s;

	negative = 10;
	ofm = 1;
	if (n < 0)
	{
		negative = -10;
		ofm++;
	}
	while (n / negative > 0)
	{
		ofm++;
		negative *= 10;
	}
	s = malloc(ofm + 1);
	if (!s)
		return (NULL);
	s[ofm] = 0;
	return (ft_putnbr(n, s, ofm - 1));
}
