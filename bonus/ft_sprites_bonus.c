/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprites_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 04:35:47 by ylamkhan          #+#    #+#             */
/*   Updated: 2023/11/22 10:59:54 by ylamkhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "cub3d_bonus.h"

void		ft_sort_sprites(t_data *data)
{
	double	distance[data->sprite_num];
	int		tmp;
	int		disttmp;
	int		i;

	i = -1;
	while (++i < data->sprite_num)
	{
		distance[i] = ((data->player.posx - data->sprite[i].x) * (data->player.posx
		- data->sprite[i].x) + (data->player.posy - data->sprite[i].y) *
		(data->player.posy - data->sprite[i].y));
		data->sprite_order[i] = i;
	}
	i = -1;
	while (++i < data->sprite_num - 1)
		if (distance[i] < distance[i + 1])
		{
			disttmp = distance[i];
			distance[i] = distance[i + 1];
			distance[i + 1] = disttmp;
			tmp = data->sprite_order[i];
			data->sprite_order[i] = data->sprite_order[i + 1];
			data->sprite_order[i + 1] = tmp;
			i = -1;
		}
}

t_sprite	*ft_get_sprites(t_data *data)
{
	int			x;
	int			y;
	int			i;
	t_sprite	*sprites;

	x = 0;
	i = 0;
	data->sprite_num = ft_count_sprites(data);
	sprites = malloc(sizeof(t_sprite) * data->sprite_num);
	data->sprite_order = malloc(sizeof(int) * data->sprite_num);
	while (x < data->map_width)
	{
		y = 0;
		while (y < data->map_height)
		{
			if (data->world_map[x][y] == '2')
			{
				sprites[i].x = x + 0.5;
				sprites[i++].y = y + 0.5;
			}
			y++;
		}
		x++;
	}
	return (sprites);
}

void		draw_sprite(t_data *data)
{
	data->draw_sp.texx = (int)(256 * (data->draw_sp.stripe -
		(-data->draw_sp.spritewidth / 2 + data->draw_sp.spritescreenx)) *
		data->tex_load.width_1 / data->draw_sp.spritewidth) / 256;
	if (data->draw_sp.transformy > 0 && data->draw_sp.stripe > 0 &&
		data->draw_sp.stripe < data->window.scr_w &&
		data->draw_sp.transformy < data->zbuffer[data->draw_sp.stripe])
	{
		data->draw_sp.y = data->draw_sp.drawstarty;
		while (data->draw_sp.y < data->draw_sp.drawendy)
		{
			data->draw_sp.d = (data->draw_sp.y) * 256 - data->window.scr_h
				* 128 + data->draw_sp.spriteheight * 128;
			data->draw_sp.texy =
				((data->draw_sp.d * data->tex_load.height_1) /
				data->draw_sp.spriteheight) / 256;
			data->draw_sp.color =
				data->tex_load.sp_text_data[(data->tex_load.width_1 *
				data->draw_sp.texy) + data->draw_sp.texx];
			if (data->draw_sp.color != 0)
				data->img.data[(data->draw_sp.y * data->window.scr_w) +
					data->draw_sp.stripe] = data->draw_sp.color;
			data->draw_sp.y++;
		}
	}
}

void		cal_sprite_size(t_data *data)
{
	data->draw_sp.spritescreenx = (int)(data->window.scr_w / 2) *
		(1 + data->draw_sp.transformx / data->draw_sp.transformy);
	data->draw_sp.spriteheight = abs((int)(data->window.scr_h /
		(data->draw_sp.transformy)));
	data->draw_sp.drawstarty = -data->draw_sp.spriteheight / 2 +
		data->window.scr_h / 2;
	if (data->draw_sp.drawstarty < 0)
		data->draw_sp.drawstarty = 0;
	data->draw_sp.drawendy = data->draw_sp.spriteheight / 2 +
		data->window.scr_h / 2;
	if (data->draw_sp.drawendy >= data->window.scr_h)
		data->draw_sp.drawendy = data->window.scr_h - 1;
	data->draw_sp.spritewidth = abs((int)(data->window.scr_h /
		(data->draw_sp.transformy)));
	data->draw_sp.drawstartx = -data->draw_sp.spritewidth /
		2 + data->draw_sp.spritescreenx;
	if (data->draw_sp.drawstartx < 0)
		data->draw_sp.drawstartx = 0;
	data->draw_sp.drawendx = data->draw_sp.spritewidth /
		2 + data->draw_sp.spritescreenx;
	if (data->draw_sp.drawendx >= data->window.scr_w)
		data->draw_sp.drawendx = data->window.scr_w - 1;
	data->draw_sp.stripe = data->draw_sp.drawstartx;
}

void		ft_sprites(t_data *data)
{
	int		i;

	i = 0;
	ft_sort_sprites(data);
	while (i < data->sprite_num)
	{
		data->draw_sp.spritex = data->sprite[data->sprite_order[i]].x -
			data->player.posx;
		data->draw_sp.spritey = data->sprite[data->sprite_order[i]].y -
			data->player.posy;
		data->draw_sp.invdet = 1.0 / (data->player.planex * data->player.diry -
			data->player.dirx * data->player.planey);
		data->draw_sp.transformx = data->draw_sp.invdet * (data->player.diry *
			data->draw_sp.spritex - data->player.dirx * data->draw_sp.spritey);
		data->draw_sp.transformy = data->draw_sp.invdet * (-data->player.planey *
			data->draw_sp.spritex + data->player.planex * data->draw_sp.spritey);
		cal_sprite_size(data);
		while (data->draw_sp.stripe < data->draw_sp.drawendx)
		{
			draw_sprite(data);
			data->draw_sp.stripe++;
		}
		i++;
	}
}
