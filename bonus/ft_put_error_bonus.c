/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_error_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 04:35:21 by ylamkhan          #+#    #+#             */
/*   Updated: 2023/11/22 10:59:31 by ylamkhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "cub3d_bonus.h"

int		check_file(char *file_path)
{
	int		fd;

	fd = open(file_path, O_RDONLY);
	close(fd);
	return (fd);
}

void	verify_vars(t_data *data)
{
	if (check_file(data->path.north_path) == -1)
		ft_put_error("North texture file does not exist!", data);
	if (check_file(data->path.south_path) == -1)
		ft_put_error("South texture file does not exist!", data);
	if (check_file(data->path.west_path) == -1)
		ft_put_error("West texture file does not exist!", data);
	if (check_file(data->path.east_path) == -1)
		ft_put_error("East texture file does not exist!", data);
	if (check_file(data->path.spr_path) == -1)
		ft_put_error("Sprite texture file does not exist!", data);
	if (data->window.scr_h > 1440)
		data->window.scr_h = 1440;
	if (data->window.scr_w > 2560)
		data->window.scr_w = 2560;
	if (data->window.scr_h < 0)
		ft_put_error("Invalid resolution input!", data);
	if (data->window.scr_w < 0)
		ft_put_error("Invalid resolution input!", data);
}

int		ft_close_game(t_data *data, int ret)
{
	int		i;

	i = 0;
	if (data->lines != NULL)
	{
		while (i <= data->lines_count)
			free(data->lines[i++]);
		free(data->lines);
	}
	if (data->status.north_done)
		free(data->path.north_path);
	if (data->status.south_done)
		free(data->path.south_path);
	if (data->status.west_done)
		free(data->path.west_path);
	if (data->status.east_done)
		free(data->path.east_path);
	if (data->status.sprite_done)
		free(data->path.spr_path);
	if (ret == 0)
		exit(EXIT_SUCCESS);
	exit(EXIT_FAILURE);
}

void	ft_put_error(char *error, t_data *data)
{
	ft_putstr("Error:\n\033[0;31m\t");
	ft_putstr(error);
	ft_putstr("\n");
	ft_close_game(data, 1);
}

void	ft_check_vars(t_data *data)
{
	if (!data->status.res_done)
		ft_put_error("Missing resolution identifier!", data);
	else if (!data->status.north_done)
		ft_put_error("Missing north texture identifier!", data);
	else if (!data->status.south_done)
		ft_put_error("Missing south texture identifier!", data);
	else if (!data->status.west_done)
		ft_put_error("Missing west texture identifier!", data);
	else if (!data->status.east_done)
		ft_put_error("Missing east texture identifier!", data);
	else if (!data->status.sprite_done)
		ft_put_error("Missing sprite texture identifier!", data);
	else if (!data->status.floor_done)
		ft_put_error("Missing floor color identifier!", data);
	else if (!data->status.ceiling_done)
		ft_put_error("Missing ceiling color identifier!", data);
}
