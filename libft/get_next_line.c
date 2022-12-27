/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aba-nabi <aba-nabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 15:01:03 by aba-nabi          #+#    #+#             */
/*   Updated: 2022/05/13 20:39:33 by aba-nabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*update_storage(char *storage)
{
	char	*newstorage;
	int		i;
	int		j;

	i = 0;
	while (storage[i] && storage[i] != '\n')
		i++;
	if (!storage[i])
	{
		free(storage);
		return (NULL);
	}
	newstorage = (char *)malloc(sizeof(char) * (ft_strlen(storage) - i + 1));
	if (!newstorage)
		return (NULL);
	i++;
	j = 0;
	while (storage[i])
		newstorage[j++] = storage[i++];
	newstorage[j] = 0;
	free(storage);
	return (newstorage);
}

static char	*store(int fd, char	*storage)
{
	char	*holder;
	int		count;

	holder = (char *)malloc(sizeof(char) * (64 + 1));
	if (!holder)
		return (NULL);
	count = -1;
	while (count && !ft_strchr(storage, '\n'))
	{
		count = read(fd, holder, 64);
		if (count == -1)
		{
			free(holder);
			return (NULL);
		}
		holder[count] = 0;
		storage = ft_strmerge(storage, holder);
	}
	free(holder);
	return (storage);
}

static char	*get_line(char	*storage)
{
	char	*line;
	int		i;

	i = 0;
	if (!storage[0])
		return (NULL);
	while (storage[i] && storage[i] != '\n')
		i++;
	line = (char *)malloc(i + storage[i] / '\n' + 1);
	if (line)
	{
		line[i + storage[i] / '\n'] = 0;
		while (i-- >= 0)
			line[i + 1] = storage[i + 1];
		return (line);
	}
	free(line);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*line;

	if (fd < 0)
		return (0);
	storage = store(fd, storage);
	if (!storage)
		return (NULL);
	line = get_line(storage);
	storage = update_storage(storage);
	return (line);
}
