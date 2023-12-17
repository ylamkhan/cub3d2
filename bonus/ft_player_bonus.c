/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 04:35:16 by ylamkhan          #+#    #+#             */
/*   Updated: 2023/11/22 10:59:26 by ylamkhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "cub3d_bonus.h"

void	set_camera_ew(char spot, t_data *data)
{
	if (spot == 'W')
	{
		data->player.dirx = 0;
		data->player.diry = -1;
		data->player.planex = -0.66;
		data->player.planey = 0;
	}
	else if (spot == 'E')
	{
		data->player.dirx = 0;
		data->player.diry = 1;
		data->player.planex = 0.66;
		data->player.planey = 0;
	}
}

void	set_camera_ns(char dir, t_data *data)
{
	if (dir == 'N')
	{
		data->player.dirx = -1;
		data->player.diry = 0;
		data->player.planex = 0;
		data->player.planey = 0.66;
	}
	else if (dir == 'S')
	{
		data->player.dirx = 1;
		data->player.diry = 0;
		data->player.planex = 0;
		data->player.planey = -0.66;
	}
}

void	get_player_details(char spot, int x, int y, t_data *data)
{
	if (data->status.player_done == 1)
		ft_put_error("Multiple spawnpoints!", data);
	if (spot != 'N' && spot != 'S' && spot != 'W' && spot != 'E')
		ft_put_error("Invalid map character!", data);
	data->player.posx = x + 0.5;
	data->player.posy = y + 0.5;
	if (spot == 'N' || spot == 'S')
		set_camera_ns(spot, data);
	else
		set_camera_ew(spot, data);
}

int		check_for_player(int x, int y, t_data *data)
{
	char	spot;

	spot = data->world_map[x][y];
	if (spot != '0' && spot != '1' && spot != '2' && spot != 'x')
	{
		get_player_details(spot, x, y, data);
		return (1);
	}
	return (0);
}

void	player_position(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	data->status.player_done = 0;
	while (i <= data->map_width)
	{
		j = 0;
		while (j <= data->map_height)
		{
			if (check_for_player(i, j, data))
				data->status.player_done = 1;
			j++;
		}
		i++;
	}
	if (data->status.player_done == 0)
		ft_put_error("No player spawnpoint!", data);
}
