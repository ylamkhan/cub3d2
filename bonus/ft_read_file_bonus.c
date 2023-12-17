/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 04:35:29 by ylamkhan          #+#    #+#             */
/*   Updated: 2023/12/17 17:35:44 by ylamkhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d_bonus.h"

int check_line2(char *str)
{
	int i=0;
	while(str[i] == '\n' || str[i] == '\t' || str[i] == ' ')
		i++;
	if((int)ft_strlen(str)==i)
		return(0);
	else
		return(1);
}

char	**get_filelines(int count, int fd)
{
	char	*string;
	char	**lines;
	int		j;
	int		k;

	k = 0;
	lines = malloc((count+1)*sizeof(char *));
	while (1)
	{
		string=get_next_line(fd);
		if(string==NULL)
			break;
		if(check_line2(string))
		{
			lines[k] = malloc(ft_strlen(string)+1);
			j=0;
			while(string[j])
			{
				lines[k][j]=string[j];
				j++;
			}
			lines[k][j]='\0';
			k++;
		}
		free(string);
	}
	lines[k] = NULL;
	if(string)
		free(string);
	return (lines);
}


int		get_lines_count(char *file)
{
	int		fd;
	char	*line;
	int		count;

	count = 0;
	fd = open(file, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
			if(line==NULL)
				break;
		if(check_line2(line))
			count++;
		free(line);
	}
	if (line)
		free(line);
	close(fd);
	return (count);
}

int		parse_lines(char *line, t_data *data)
{
	while (*line == ' ' || *line == '\t' || *line == '\n')
		line++;
	if (*line == '\0')
		return (0);
	if (*line == 'R' && *(line + 1) == ' ')
		get_resolution(line, data);
	else if (*line == 'S' && *(line + 1) == ' ')
		get_sprite_path(line, data);
	else if ((*line == 'C' && *(line + 1) == ' ') ||
		(*line == 'F' && *(line + 1) == ' '))
		parse_color(line, data);
	else if ((*line == 'N' && *(line + 1) == 'O' && *(line + 2) == ' ') ||
	(*line == 'S' && *(line + 1) == 'O' && *(line + 2) == ' ') ||
	(*line == 'W' && *(line + 1) == 'E' && *(line + 2) == ' ') ||
	(*line == 'E' && *(line + 1) == 'A' && *(line + 2) == ' '))
		get_tex_path(line, data);
	else if (*line == '0' || *line == '1' || *line == '2')
		return (1);
	else
		ft_put_error("Invalid Identifier!", data);
	return (0);
}

void	ft_read_map_2(t_data *data, int i)
{
	verify_vars(data);
	data->map_width = get_map_x(&data->lines[i - 1], data);
	data->map_height = get_map_y(&data->lines[i - 1]);
	map_allocation(data);
	create_map(&data->lines[i - 1], data);
	player_position(data);
	ft_map_checker(data);
	data->sprite = ft_get_sprites(data);
}

void	ft_read_map(t_data *data, char *file)
{
	int		i;
	int		ret;
	int		fd;
	char	**temp;

	if ((fd = open(file, O_RDONLY)) < 0)
		ft_put_error("Map file does not exist!", data);
	i = 0;
	ret = 0;
	temp = NULL;
	data->lines = 0;
	data->lines_count = get_lines_count(file);
	ft_init_vars(data);
	data->lines = get_filelines(data->lines_count, fd);
	close(fd);
	while (data->lines[i] && !ret)
	{
		ret = parse_lines(data->lines[i], data);
		i++;
	}
	if (!ret)
		ft_put_error("No map included in file!", data);
	ft_check_vars(data);
	ft_read_map_2(data, i);
}
