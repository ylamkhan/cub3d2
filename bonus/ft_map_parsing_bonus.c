/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_parsing_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 04:35:02 by ylamkhan          #+#    #+#             */
/*   Updated: 2023/12/17 17:59:10 by ylamkhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d_bonus.h"

void	map_allocation(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	data->world_map = malloc(sizeof(int *) * (data->map_width + 1));
	while (i <= data->map_width)
	{
		j = 0;
		data->world_map[i] = malloc(sizeof(int) * (data->map_height + 1));
		while (j <= data->map_height)
		{
			data->world_map[i][j] = 'x';
			j++;
		}
		i++;
	}
}

void	create_map(char **lines, t_data *data)
{
	int		i;
	int		j;
	int		x;
	int		y;
	int		last_y;

	x = 0;
	i = -1;
	last_y = 0;
	while (lines[++i])
	{
		y = 0;
		j = 0;
		while (lines[i][j])
		{
			while (lines[i][j] == ' ' || lines[i][j] == '\t' || lines[i][j] == '\n')
				j++;
			if (lines[i][j])
				data->world_map[x][y++] = lines[i][j++];	
				
		}
		if (last_y < y)
			last_y = y;
		x++;
	}
	data->map_height = last_y;
}

void	check_spot(t_data *data, int x, int y)
{
	int		**map;

	data->status.player_done = 0;
	map = data->world_map;
	if (x == 0 || y == 0 || x == data->map_width)
		ft_put_error("Map not properly closed off!", data);
	if (map[x][y - 1] == 'x')
		ft_put_error("Map not properly closed off!", data);
	if (map[x][y + 1] == 'x')
		ft_put_error("Map not properly closed off!", data);
	if (map[x + 1][y] == 'x')
		ft_put_error("Map not properly closed off!", data);
	if (map[x - 1][y] == 'x')
		ft_put_error("Map not properly closed off!", data);
}

void	ft_map_checker(t_data *data)
{
	int x;
	int y;

	x = 0;
	while (x < data->map_width)
	{
		y = 0;
		while (y < data->map_height)
		{
			if (data->world_map[x][y] != '1'
					&& data->world_map[x][y] != 'x')
				check_spot(data, x, y);
			y++;
		}
		x++;
	}
}

int		ft_count_sprites(t_data *data)
{
	int		x;
	int		y;
	int		ret;

	x = 0;
	y = 0;
	ret = 0;
	while (x < data->map_width)
	{
		y = 0;
		while (y < data->map_height)
		{
			if (data->world_map[x][y] == '2')
				ret++;
			y++;
		}
		x++;
	}
	return (ret);
}
