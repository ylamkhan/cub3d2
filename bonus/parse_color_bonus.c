/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 04:36:54 by ylamkhan          #+#    #+#             */
/*   Updated: 2023/12/17 17:39:53 by ylamkhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "cub3d_bonus.h"

void	parse_color(char *line, t_data *data)
{
	if (*line == 'C')
		get_color(&(*++line), data, 'C');
	else
		get_color(&(*++line), data, 'F');
}

int		color_parse(char *line, int i, t_data *data)
{
	int		count;

	count = 0;
	data->color.color = 0;
	data->color.commas = 0;
	while (count < 3)
	{
		while (line[i] == ' ' || line[i] == '\t')
			i++;
		if (!ft_isdigit(line[i]) || ft_atoi(line + i) > 255)
			ft_put_error("Invalid color input!", data);
		data->color.color = data->color.color * 256 + ft_atoi(line + i);
		i += ft_intsize(ft_atoi(line + i));
		count++;
		if (count == 3)
			break ;
		while (line[i] == ' ' || line[i] == '\t' )
			i++;
		if (line[i] == ',')
		{
			data->color.commas++;
			i++;
		}
	}
	return (i);
}

void	get_color(char *line, t_data *data, char type)
{
	int		i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t' || line[i] == '\n')
		i++;
	i = color_parse(line, i, data);
	while (line[i] == ' ' || line[i] == '\t' || line[i] == '\n')
		i++;
	if (data->color.commas != 2 || line[i])
		ft_put_error("Invalid color input!", data);
	if (type == 'C')
	{
		if (data->status.ceiling_done)
			ft_put_error("Ceiling color already defined!", data);
		data->window.ceiling_color = data->color.color;
		data->status.ceiling_done = 1;
	}
	else
	{
		if (data->status.floor_done)
			ft_put_error("Floor color already defined!", data);
		data->window.floor_color = data->color.color;
		data->status.floor_done = 1;
	}
}
