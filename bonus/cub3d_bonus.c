/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 04:34:35 by ylamkhan          #+#    #+#             */
/*   Updated: 2023/11/22 11:18:36 by ylamkhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "cub3d_bonus.h"

void	load_textures(t_data *data)
{
	data->tex_load.text_1 = mlx_xpm_file_to_image(data->window.mlx_ptr,
		data->path.south_path, &data->tex_load.width_1, &data->tex_load.height_1);
	data->tex_load.text_data_1 = (int *)mlx_get_data_addr(data->tex_load.text_1,
		&data->img.bpp, &data->img.size_l, &data->img.endian);
	data->tex_load.text_2 = mlx_xpm_file_to_image(data->window.mlx_ptr,
		data->path.north_path, &data->tex_load.width_2, &data->tex_load.height_2);
	data->tex_load.text_data_2 = (int *)mlx_get_data_addr(data->tex_load.text_2,
		&data->img.bpp, &data->img.size_l, &data->img.endian);
	data->tex_load.text_3 = mlx_xpm_file_to_image(data->window.mlx_ptr,
		data->path.west_path, &data->tex_load.width_3, &data->tex_load.height_3);
	data->tex_load.text_data_3 = (int *)mlx_get_data_addr(data->tex_load.text_3,
		&data->img.bpp, &data->img.size_l, &data->img.endian);
	data->tex_load.text_4 = mlx_xpm_file_to_image(data->window.mlx_ptr,
		data->path.east_path, &data->tex_load.width_4, &data->tex_load.height_4);
	data->tex_load.text_data_4 = (int *)mlx_get_data_addr(data->tex_load.text_4,
		&data->img.bpp, &data->img.size_l, &data->img.endian);
	data->tex_load.text_5 = mlx_xpm_file_to_image(data->window.mlx_ptr, "textures/light_tiles.XPM",
		&data->tex_load.width_5, &data->tex_load.height_5);
	data->tex_load.text_data_5 = (int *)mlx_get_data_addr(data->tex_load.text_5,
		&data->img.bpp, &data->img.size_l, &data->img.endian);
	data->tex_load.text_6 = mlx_xpm_file_to_image(data->window.mlx_ptr, "textures/dark_tiles.XPM",
		&data->tex_load.width_6, &data->tex_load.height_6);
	data->tex_load.text_data_6 = (int *)mlx_get_data_addr(data->tex_load.text_6,
		&data->img.bpp, &data->img.size_l, &data->img.endian);
	data->tex_load.sp_text = mlx_xpm_file_to_image(data->window.mlx_ptr,
		data->path.spr_path, &data->tex_load.sp_width, &data->tex_load.sp_height);
	data->tex_load.sp_text_data = (int *)mlx_get_data_addr(data->tex_load.sp_text,
		&data->img.bpp, &data->img.size_l, &data->img.endian);
}

void	ft_initialize(t_data *data)
{
	data->player.movespeed = 0.1;
	data->player.rotspeed = 0.04;
	data->window.mlx_ptr = mlx_init();
	data->window.win_ptr = mlx_new_window(data->window.mlx_ptr, data->window.scr_w,
	data->window.scr_h, "cub3d");
	load_textures(data);
}

void	ft_start_game(t_data *data)
{
	ft_initialize(data);
	mlx_hook(data->window.win_ptr, 2, (1L << 0), ft_key_pressed, data);
	mlx_hook(data->window.win_ptr, 3, (1L << 1), ft_key_released, data);
	mlx_hook(data->window.win_ptr, 17, (1L << 5), ft_close_game, data);
	mlx_loop_hook(data->window.mlx_ptr, ft_update, data);
	mlx_loop(data->window.mlx_ptr);
}

int		main(int argc, char **argv)
{
	t_data	data;

	data.lines = NULL;
	ft_init_vars(&data);
	if (argc == 2 && name_checker(argv[1]))
	{
		ft_read_map(&data, argv[1]);
		ft_start_game(&data);
	}
	else
		ft_put_error("Invalid arguments!", &data);
	return (0);
}
