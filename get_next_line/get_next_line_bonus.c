/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 07:27:07 by ylamkhan          #+#    #+#             */
/*   Updated: 2022/11/10 22:55:33 by ylamkhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_update(char *resirve)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (resirve[i] && resirve[i] != '\n')
		i++;
	if (!resirve[i])
	{
		free(resirve);
		return (NULL);
	}
	new = malloc(ft_strlen(resirve) - i + 1);
	if (!new)
	{
		free(resirve);
		return (NULL);
	}
	i++;
	while (resirve[i])
		new[j++] = resirve[i++];
	new[j] = '\0';
	free(resirve);
	return (new);
}

static char	*ft_remplire(char *str)
{
	char	*line;
	int		j;

	j = 0;
	if (!str[j])
		return (NULL);
	while (str[j] && str[j] != '\n')
		j++;
	line = (char *)malloc((j + 2) * sizeof(char));
	if (!line)
		return (NULL);
	j = 0;
	while (str[j] && str[j] != '\n')
	{
		line[j] = str[j];
		j++;
	}
	if (str[j] == '\n')
		line[j++] = '\n';
	line[j] = '\0';
	return (line);
}

static char	*ft_contuniresirve(int fd, char *resirve)
{
	char	*buffer;
	int		i;

	if (!resirve)
		resirve = ft_calloc(1, 1);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	i = 1;
	while (!ft_strchr(resirve, '\n') && i != 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
		{
			free(buffer);
			free(resirve);
			return (NULL);
		}
		buffer[i] = '\0';
		resirve = ft_strjoin(resirve, buffer);
	}
	free(buffer);
	return (resirve);
}

char	*get_next_line(int fd)
{
	static char	*resirve[10240];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	resirve[fd] = ft_contuniresirve(fd, resirve[fd]);
	if (!resirve[fd])
		return (NULL);
	line = ft_remplire(resirve[fd]);
	resirve[fd] = ft_update(resirve[fd]);
	return (line);
}
