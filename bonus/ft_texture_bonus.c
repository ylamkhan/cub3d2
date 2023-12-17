/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 04:35:54 by ylamkhan          #+#    #+#             */
/*   Updated: 2023/11/22 10:59:58 by ylamkhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "cub3d_bonus.h"

void	texture_posx(t_data *data)
{
	if (data->side == 0)
		data->texture.wallx = data->player.posy + (data->perpwalldist *
			data->raydiry);
	else
		data->texture.wallx = data->player.posx + (data->perpwalldist *
			data->raydirx);
	data->texture.wallx -= floor((data->texture.wallx));
	data->texture.texx = (int)(data->texture.wallx *
		(double)data->tex_load.width_1);
	if (data->side == 0)
	{
		if (data->raydirx > 0)
			data->walldir = 'N';
		else
			data->walldir = 'S';
		data->texture.texx = data->tex_load.width_1 - data->texture.texx - 1;
	}
	else
	{
		if (data->raydiry > 0)
			data->walldir = 'W';
		else
			data->walldir = 'E';
		data->texture.texx = data->tex_load.width_1 - data->texture.texx - 1;
	}
}

void	load_right_tex(t_data *data)
{
	if (data->walldir == 'N')
	{
		data->tex_load.texture_data = data->tex_load.text_data_1;
		data->tex_load.height = data->tex_load.height_1;
		data->tex_load.width = data->tex_load.width_1;
	}
	else if (data->walldir == 'S')
	{
		data->tex_load.texture_data = data->tex_load.text_data_2;
		data->tex_load.height = data->tex_load.height_2;
		data->tex_load.width = data->tex_load.width_2;
	}
	else if (data->walldir == 'E')
	{
		data->tex_load.texture_data = data->tex_load.text_data_3;
		data->tex_load.height = data->tex_load.height_3;
		data->tex_load.width = data->tex_load.width_3;
	}
	else if (data->walldir == 'W')
	{
		data->tex_load.texture_data = data->tex_load.text_data_4;
		data->tex_load.height = data->tex_load.height_4;
		data->tex_load.width = data->tex_load.width_4;
	}
}

void	ft_texture(t_data *data, int x)
{
	texture_posx(data);
	data->texture.step = (1.0 * data->tex_load.height_1) / data->lineheight;
	data->texture.texpos = (data->drawstart - (data->window.scr_h / 2) +
		(data->lineheight / 2)) * data->texture.step;
	data->texture.y = data->drawstart;
	load_right_tex(data);
	while (data->texture.y < data->drawend)
	{
		data->texture.texy = (int)data->texture.texpos &
			(data->tex_load.height_1 - 1);
		data->texture.texpos += data->texture.step;
		data->texture.color = data->tex_load.texture_data[(data->tex_load.height_1
			* data->texture.texy) + data->texture.texx];
		data->img.data[(data->texture.y * data->window.scr_w) + x] =
			data->texture.color;
		data->texture.y++;
	}
}
