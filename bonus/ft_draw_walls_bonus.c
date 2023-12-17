/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_walls_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 04:34:54 by ylamkhan          #+#    #+#             */
/*   Updated: 2023/12/16 16:33:11 by ylamkhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d_bonus.h"

void	ft_draw_ceiling_floor(t_data *data)
{
	int		y;

	y = 0;
	while (y < data->window.scr_h)
	{
		float rayDirX0 = data->player.dirx - data->player.planex;
		float rayDirY0 = data->player.diry - data->player.planey;
		float rayDirX1 = data->player.dirx + data->player.planex;
		float rayDirY1 = data->player.diry + data->player.planey;
		int p = y - data->window.scr_h / 2;
		float posZ = 0.5 * data->window.scr_h;
		float rowDistance = posZ / p;
		float floorStepX = rowDistance * (rayDirX1 - rayDirX0) / data->window.scr_w;
		float floorStepY = rowDistance * (rayDirY1 - rayDirY0) / data->window.scr_w;
		float floorX = data->player.posx + rowDistance * rayDirX0;
		float floorY = data->player.posy + rowDistance * rayDirY0;
		int	x = 0;
		while (x < data->window.scr_w)
		{
			int cellX = (int)floorX;
			int cellY = (int)floorY;
			int tx = (int)(data->tex_load.width_1 * (floorX - cellX)) & (data->tex_load.width_1 - 1);
			int ty = (int)(data->tex_load.height_1 * (floorY - cellY)) & (data->tex_load.height_1 - 1);
			floorX += floorStepX;
			floorY += floorStepY;
			int	color = data->tex_load.text_data_6[(data->tex_load.width_1 * ty) + tx];
			data->img.data[(y * data->window.scr_w) + x] = color;
			color = data->tex_load.text_data_5[(data->tex_load.width_1 * ty) + tx];
			data->img.data[(data->window.scr_h - y - 1) * data->window.scr_w + x] = color;
			x++;
		}
		y++;
	}
}

void	ray_step_dir(t_data *data)
{
	if (data->raydirx < 0)
	{
		data->ray.stepx = -1;
		data->ray.sidedistx = (data->player.posx - data->mapx) *
			data->ray.deltadistx;
	}
	else
	{
		data->ray.stepx = 1;
		data->ray.sidedistx = (data->mapx + 1.0 - data->player.posx) *
			data->ray.deltadistx;
	}
	if (data->raydiry < 0)
	{
		data->ray.stepy = -1;
		data->ray.sidedisty = (data->player.posy - data->mapy) *
			data->ray.deltadisty;
	}
	else
	{
		data->ray.stepy = 1;
		data->ray.sidedisty = (data->mapy + 1.0 - data->player.posy) *
			data->ray.deltadisty;
	}
}

void	cal_wall_distance(t_data *data)
{
	data->ray.hit = 0;
	while (data->ray.hit == 0)
	{
		if (data->ray.sidedistx < data->ray.sidedisty)
		{
			data->ray.sidedistx += data->ray.deltadistx;
			data->mapx += data->ray.stepx;
			data->side = 0;
		}
		else
		{
			data->ray.sidedisty += data->ray.deltadisty;
			data->mapy += data->ray.stepy;
			data->side = 1;
		}
		if (data->world_map[data->mapx][data->mapy] == '1')
			data->ray.hit = 1;
	}
	if (data->side == 0)
		data->perpwalldist = (data->mapx - data->player.posx +
			(1 - data->ray.stepx) / 2) / data->raydirx;
	else
		data->perpwalldist = (data->mapy - data->player.posy +
			(1 - data->ray.stepy) / 2) / data->raydiry;
}

void	ft_draw_walls(t_data *data)
{
	int			x;

	x = -1;
	while (++x < data->window.scr_w)
	{
		data->ray.camerax = 2 * x / (double)data->window.scr_w - 1;
		data->raydirx = data->player.dirx + data->player.planex * data->ray.camerax;
		data->raydiry = data->player.diry + data->player.planey * data->ray.camerax;
		data->mapx = (int)data->player.posx;
		data->mapy = (int)data->player.posy;
		data->ray.deltadistx = fabs(1 / data->raydirx);
		data->ray.deltadisty = fabs(1 / data->raydiry);
		ray_step_dir(data);
		cal_wall_distance(data);
		data->lineheight = (int)(data->window.scr_h / data->perpwalldist);
		data->drawstart = -data->lineheight / 2 + data->window.scr_h / 2;
		if (data->drawstart < 0)
			data->drawstart = 0;
		data->drawend = data->lineheight / 2 + data->window.scr_h / 2;
		if (data->drawend >= data->window.scr_h)
			data->drawend = data->window.scr_h - 1;
		ft_texture(data, x);
		data->zbuffer[x] = data->perpwalldist;
	}
	
	ft_sprites(data);
}
