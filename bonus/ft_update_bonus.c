/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 523/11/22 04:36:02 by ylamkhan          #+#    #+#             */
/*   Updated: 2023/12/16 13:57:10 by ylamkhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "cub3d_bonus.h"
void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char *dst = mlx_get_data_addr(data->img.img_ptr, &data->img.bpp, &data->img.size_l, &data->img.endian);
    *(unsigned int *)(dst + (y * data->img.size_l + x * (data->img.bpp / 8))) = color;
}
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
	int i=0;
	while (i<data->map_width)
	{
		int j=0;
		while (j<data->map_height)
		{
			if(data->world_map[i][j]==49 || data->world_map[i][j]==50)
			{
				int i1=i*20;
				while (i1 < (i + 1)*20  && i1<20*data->map_width)
				{
					int j1 =j*10;
					while (j1<((j+1)*10)&&j1<10*data->map_height)
					{
							my_mlx_pixel_put(data, i1, j1,0xFF00FF);
						j1++;
					}
					i1++;
				}
			}
		 	else
		 	{
				int i1=i*20;
				while (i1<(i+1)*20 && i1<20*data->map_width)
				 {
				 	int j1 =j*10;
				 	while (j1<(j+1)*10 && j1<10*data->map_height)
				 	{
	 					my_mlx_pixel_put(data, i1, j1,0x0000FF);	
				 		j1++;
				 	}
				 	i1++;
				 }
		 	}			
	 		j++;
		}
		i++;
	}
	// int sx=data->player.posx*(20*data->map_width-1)/data->window.scr_w - 3;
	// int sy = data->player.posy*(10*data->map_height-1)/data->window.scr_h - 3;
	// printf("***%d, %d\n",(int)data->player.posx,(int)data->player.posy);
	int b=0;
	while (b<5)
	{
		int d=0;
		while (d<5)
		{
			my_mlx_pixel_put(data,(int)(data->player.posx*20+b) ,(int)(data->player.posy*10+d) ,0xFFFFFF);
			d++;
		}
		b++;
	}
	
	free(data->zbuffer);
	mlx_put_image_to_window(data->window.mlx_ptr, data->window.win_ptr,
		data->img.img_ptr, 0, 0);
	mlx_destroy_image(data->window.mlx_ptr, data->img.img_ptr);
	return (0);
}
