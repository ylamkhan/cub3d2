/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 04:35:09 by ylamkhan          #+#    #+#             */
/*   Updated: 2023/11/22 10:59:22 by ylamkhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d_bonus.h"

int		check_movement(int x, int y, t_data *data)
{
	if (data->world_map[x][y] != '1' && data->world_map[x][y] != '2')
		return (1);
	return (0);
}

void	ft_move_left_right(t_data *data)
{
	if (data->keys.d == 1)
	{
		if (check_movement((int)data->player.posx, (int)(data->player.posy -
			data->player.dirx * data->player.movespeed), data))
			data->player.posy -= data->player.dirx * data->player.movespeed * 0.5;
		if (check_movement((int)(data->player.posx + data->player.diry *
			data->player.movespeed), (int)data->player.posy, data))
			data->player.posx += data->player.diry * data->player.movespeed * 0.5;
	}
	if (data->keys.a == 1)
	{
		if (check_movement((int)data->player.posx, (int)(data->player.posy +
			data->player.dirx * data->player.movespeed), data))
			data->player.posy += data->player.dirx * data->player.movespeed * 0.5;
		if (check_movement((int)(data->player.posx - data->player.diry *
			data->player.movespeed), (int)data->player.posy, data))
			data->player.posx -= data->player.diry * data->player.movespeed * 0.5;
	}
}

void	ft_movement(t_data *data)
{
	if (data->keys.w == 1)
	{
		if (check_movement((int)(data->player.posx + data->player.dirx *
			data->player.movespeed), (int)data->player.posy, data))
			data->player.posx += data->player.dirx * data->player.movespeed * 0.5;
		if (check_movement((int)data->player.posx, (int)(data->player.posy +
			data->player.diry * data->player.movespeed), data))
			data->player.posy += data->player.diry * data->player.movespeed * 0.5;
	}
	if (data->keys.s == 1)
	{
		if (check_movement((int)(data->player.posx - data->player.dirx *
			data->player.movespeed), (int)data->player.posy, data))
			data->player.posx -= data->player.dirx * data->player.movespeed * 0.5;
		if (check_movement((int)data->player.posx, (int)(data->player.posy -
			data->player.diry * data->player.movespeed), data))
			data->player.posy -= data->player.diry * data->player.movespeed * 0.5;
	}
	if (data->keys.d == 1 || data->keys.a == 1)
		ft_move_left_right(data);
	if (data->keys.right == 1 || data->keys.left == 1)
		ft_rotation(data);
}

int		ft_key_pressed(int key, t_data *data)
{
	if (key == 13)
		data->keys.w = 1;
	if (key == 1)
		data->keys.s = 1;
	if (key == 0)
		data->keys.a = 1;
	if (key == 2)
		data->keys.d = 1;
	if (key == 123)
		data->keys.left = 1;
	if (key == 124)
		data->keys.right = 1;
	return (0);
}

int		ft_key_released(int key, t_data *data)
{
	if (key == 13)
		data->keys.w = 0;
	if (key == 1)
		data->keys.s = 0;
	if (key == 0)
		data->keys.a = 0;
	if (key == 2)
		data->keys.d = 0;
	if (key == 123)
		data->keys.left = 0;
	if (key == 124)
		data->keys.right = 0;
	if (key == 53)
		ft_close_game(data, 0);
	return (0);
}
