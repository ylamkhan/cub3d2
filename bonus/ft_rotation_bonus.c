/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotation_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 04:35:35 by ylamkhan          #+#    #+#             */
/*   Updated: 2023/11/22 10:59:41 by ylamkhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "cub3d_bonus.h"

void	ft_rotate_left(t_data *data)
{
	data->player.olddirx = data->player.dirx;
	data->player.dirx = (data->player.dirx * cos(data->player.rotspeed)) -
		(data->player.diry * sin(data->player.rotspeed));
	data->player.diry = (data->player.olddirx * sin(data->player.rotspeed)) +
		(data->player.diry * cos(data->player.rotspeed));
	data->player.oldplanex = data->player.planex;
	data->player.planex = (data->player.planex * cos(data->player.rotspeed)) -
		(data->player.planey * sin(data->player.rotspeed));
	data->player.planey = (data->player.oldplanex * sin(data->player.rotspeed))
	+ (data->player.planey * cos(data->player.rotspeed));
}

void	ft_rotation(t_data *data)
{
	if (data->keys.right == 1)
	{
		data->player.olddirx = data->player.dirx;
		data->player.dirx = (data->player.dirx * cos(-data->player.rotspeed)) -
			(data->player.diry * sin(-data->player.rotspeed));
		data->player.diry = (data->player.olddirx * sin(-data->player.rotspeed)) +
			(data->player.diry * cos(-data->player.rotspeed));
		data->player.oldplanex = data->player.planex;
		data->player.planex = (data->player.planex * cos(-data->player.rotspeed)) -
			(data->player.planey * sin(-data->player.rotspeed));
		data->player.planey = (data->player.oldplanex *
			sin(-data->player.rotspeed)) + (data->player.planey *
			cos(-data->player.rotspeed));
	}
	if (data->keys.left == 1)
		ft_rotate_left(data);
}
