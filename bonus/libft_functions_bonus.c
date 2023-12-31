/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_functions_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 04:36:40 by ylamkhan          #+#    #+#             */
/*   Updated: 2023/11/22 11:00:33 by ylamkhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "cub3d_bonus.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_isdigit(int c)
{
	if ((c > 47 && c < 58))
		return (1);
	else
		return (0);
}

void	ft_putnbr(long n)
{
	long i;
	long bn;

	bn = n;
	i = 1;
	if (n == 0)
		ft_putchar('0');
	else
	{
		if (n < 0)
		{
			bn = -bn;
			ft_putchar('-');
		}
		while ((bn / (i * 10)) != 0)
			i = (i * 10);
		while (i != 0)
		{
			ft_putchar((bn / i) + 48);
			bn = (bn % i);
			i = (i / 10);
		}
	}
}

void	*ft_memcpy(void *dst, void *src, size_t n)
{
	size_t			i;
	unsigned char	*x;
	unsigned char	*y;

	x = src;
	y = dst;
	i = 0;
	if (src == dst)
		return (dst);
	if ((dst == NULL) && (src == NULL))
		return (NULL);
	while (i < n)
	{
		y[i] = x[i];
		i++;
	}
	return (y);
}

int		ft_intsize(long nb)
{
	int		l;

	l = 0;
	if (nb == 0)
		l++;
	if (nb < 0)
	{
		nb = -nb;
		l++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		l++;
	}
	return (l);
}
