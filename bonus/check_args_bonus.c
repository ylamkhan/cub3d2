/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 04:34:22 by ylamkhan          #+#    #+#             */
/*   Updated: 2023/11/22 11:04:33 by ylamkhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d_bonus.h"

void	ft_init_vars(t_data *data)
{
	data->status.res_done = 0;
	data->status.north_done = 0;
	data->status.south_done = 0;
	data->status.west_done = 0;
	data->status.east_done = 0;
	data->status.sprite_done = 0;
	data->status.floor_done = 0;
	data->status.ceiling_done = 0;
	data->window.scr_w = 0;
	data->window.scr_h = 0;
	data->path.north_path = NULL;
	data->path.south_path = NULL;
	data->path.west_path = NULL;
	data->path.east_path = NULL;
	data->path.spr_path = NULL;
	data->window.floor_color = 0;
	data->window.ceiling_color = 0;
}

int		name_checker(char *arg)
{
	int		i;

	i = 0;
	while (arg[i])
		i++;
	if (arg[i - 1] == 'b' && arg[i - 2] == 'u' && arg[i - 3] == 'c'
		&& arg[i - 4] == '.')
		return (1);
	return (0);
}

