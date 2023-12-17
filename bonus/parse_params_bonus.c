/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_params_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 04:37:01 by ylamkhan          #+#    #+#             */
/*   Updated: 2023/12/17 18:00:42 by ylamkhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	north_south_path(char *line, t_data *data, int i, int j)
{
	if (line[0] == 'N')
	{
		if (data->status.north_done)
			ft_put_error("North texture path already defined!", data);
		data->path.north_path = ft_substr(line, i, j - i);
		data->status.north_done = 1;
	}
	else if (line[0] == 'S')
	{
		if (data->status.south_done)
			ft_put_error("South texture path already defined!", data);
		data->path.south_path = ft_substr(line, i, j - i);
		data->status.south_done = 1;
	}
}

void	west_east_path(char *line, t_data *data, int i, int j)
{
	if (line[0] == 'W')
	{
		if (data->status.west_done)
			ft_put_error("West texture path already defined!", data);
		data->path.west_path = ft_substr(line, i, j - i);
		data->status.west_done = 1;
	}
	else if (line[0] == 'E')
	{
		if (data->status.east_done)
			ft_put_error("East texture path already defined!", data);
		data->path.east_path = ft_substr(line, i, j - i);
		data->status.east_done = 1;
	}
}

void	get_tex_path(char *line, t_data *data)
{
	int		i;
	int		j;

	i = 2;
	j = 0;
	while (line[i] == ' ' || line[i] == '\t' || line[i] == '\n')
		i++;
	j = i;
	while (line[j] != ' ' && line[j] != '\0' && line[j] != '\t' && line[j] != '\n')
		j++;
	north_south_path(line, data, i, j);
	west_east_path(line, data, i, j);
	while (line[j] == ' ' || line[j] == '\t' || line[j] == '\n')
		j++;
	if (line[j])
		ft_put_error("Extra input next to texture path!", data);
}

void	get_sprite_path(char *line, t_data *data)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	if (data->status.sprite_done)
		ft_put_error("Sprite path already defined!", data);
	while (line[i] == ' ' || line[i] == '\t' || line[i] == '\n')
		i++;
	j = i;
	while (line[j] != '\n' && line[j] != '\t' && line[j] != ' ' && line[j] != '\0')
		j++;
	data->path.spr_path = ft_substr(line, i, j - i);
	data->status.sprite_done = 1;
	while (line[j] == ' ' || line[j] == '\t' || line[j] == '\n')
		j++;
	if (line[j])
		ft_put_error("Extra input next to sprite path!", data);
}

void	get_resolution(char *line, t_data *data)
{
	int		i;

	i = 1;
	while (line[i] == ' ' || line[i] == '\t' || line[i] == '\n')
		i++;
	if (data->status.res_done)
		ft_put_error("Resolution identifier already defined!", data);
	if (!ft_isdigit(line[i]))
		ft_put_error("Invalid resolution input!", data);
	data->window.scr_w = ft_atoi(line + i);
	i += ft_intsize(data->window.scr_w);
	while (line[i] == ' ' || line[i] == '\t' || line[i] == '\n')
		i++;
	if (!ft_isdigit(line[i]))
		ft_put_error("Invalid resolution input!", data);
	data->window.scr_h = ft_atoi(line + i);
	i += ft_intsize(data->window.scr_h);
	while (line[i] == ' ' || line[i] == '\t' || line[i] == '\n')
		i++;
	if (line[i])
		ft_put_error("Invalid resolution input!", data);
	data->status.res_done = 1;
}
