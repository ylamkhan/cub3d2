/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 07:27:28 by ylamkhan          #+#    #+#             */
/*   Updated: 2022/11/10 07:29:52 by ylamkhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

void	*ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(char *)(s + i) = '\0';
			i++;
	}
	return (s);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*str;

	if (count > 0 && size >= SIZE_MAX / count)
		return (NULL);
	str = (char *)malloc(count * size);
	if (!str)
		return (NULL);
	str = (char *)ft_bzero(str, count * size);
	return (str);
}

char	*ft_strchr(char *s, int c)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(s);
	while (i <= j)
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i1;
	int		i2;
	char	*str;

	if (!s1)
		return (NULL);
	if (!s2)
		return (NULL);
	i1 = ft_strlen(s1);
	i2 = ft_strlen(s2);
	str = (char *)malloc((i1 + i2 + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i1 = -1;
	while (s1 && s1[++i1])
		str[i1] = s1[i1];
	i2 = -1;
	while (s2 && s2[++i2])
		str[i1 + i2] = s2[i2];
	str[i1 + i2] = '\0';
	free(s1);
	return (str);
}
