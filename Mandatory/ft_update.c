/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 04:36:02 by ylamkhan          #+#    #+#             */
/*   Updated: 2023/11/24 08:51:29 by ylamkhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "cub3d.h"

int		ft_update(t_data *data)
{
	data->img.img_ptr = mlx_new_image(data->window.mlx_ptr, data->window.scr_w,
		data->window.scr_h);
	data->img.data = (int *)mlx_get_data_addr(data->img.img_ptr,
		&data->img.bpp, &data->img.size_l, &data->img.endian);
	mlx_clear_window(data->window.mlx_ptr, data->window.win_ptr);
	ft_movement(data);
	data->zbuffer = malloc(sizeof(double) * data->window.scr_w);
	ft_draw_ceiling_floor(data);
	ft_draw_walls(data);
	free(data->zbuffer);
	mlx_put_image_to_window(data->window.mlx_ptr, data->window.win_ptr,
		data->img.img_ptr, 0, 0);
	mlx_destroy_image(data->window.mlx_ptr, data->img.img_ptr);
	return (0);
}
