/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 04:36:08 by ylamkhan          #+#    #+#             */
/*   Updated: 2023/12/17 17:17:53 by ylamkhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "cub3d.h"

int		get_map_x(char **lines, t_data *data)
{
	int		i;
	int		j;
	int		empty;

	i = 0;
	j = 0;
	empty = 0;
	while (lines[i])
	{
		j = 0;
		while (lines[i][j] == ' ' || lines[i][j] == '\t')
			j++;
		if (!lines[i][j])
			empty = 1;
		if (lines[i][j] && empty)
			ft_put_error("Extra input after end of map!", data);
		i++;
	}
	return (i);
}

int		get_map_y(char **lines)
{
	int		i;
	int		j;
	int		ret;

	i = 0;
	j = 0;
	ret = 0;
	while (lines[i])
	{
		j = 0;
		while (lines[i][j])
			j++;
		if (ret < j)
			ret = j;
		i++;
	}
	return (ret-1);
}
