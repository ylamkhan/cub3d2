/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_functions_2_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 04:36:33 by ylamkhan          #+#    #+#             */
/*   Updated: 2023/12/17 17:29:57 by ylamkhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "cub3d_bonus.h"

void			ft_putstr(char *s)
{
	if (s == NULL)
		return ;
	while (*s)
	{
		ft_putchar(*s);
		s++;
	}
}

// size_t			ft_strlen(const char *s)
// {
// 	size_t i;

// 	i = 0;
// 	if (s == NULL)
// 		return (0);
// 	while (*s != '\0')
// 	{
// 		i++;
// 		s++;
// 	}
// 	return (i);
// }

int				ft_atoi(const char *str)
{
	long	a;
	int		b;
	int		c;

	a = 0;
	b = 0;
	c = 1;
	while (((*str <= 13) && (*str >= 9)) || (*str == 32))
		str++;
	while ((*str == '+') || (*str == '-'))
	{
		if (*str == '-')
			c = -1;
		b++;
		str++;
	}
	if (b > 1)
		return (0);
	while ((*str <= '9') && (*str >= '0'))
	{
		a = (*str - 48) + a * 10;
		str++;
	}
	return (a * c);
}

size_t			ft_smallest(char *s, unsigned int start, size_t len)
{
	if (len > ft_strlen(s + start))
		return (ft_strlen(s + start) + 1);
	return (len + 1);
}

char			*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*x;
	size_t	i;

	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
		len = 0;
	i = 0;
	x = (char *)malloc(sizeof(char) * ft_smallest(s, start, len));
	if (x == 0)
		return (NULL);
	while (i < (ft_smallest(s, start, len) - 1))
	{
		x[i] = s[i + start];
		i++;
	}
	x[i] = '\0';
	return (x);
}
