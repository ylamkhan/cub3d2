/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 04:34:48 by ylamkhan          #+#    #+#             */
/*   Updated: 2023/12/17 17:34:10 by ylamkhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>
# include "mlx.h"
# include "get_next_line_bonus.h"



typedef struct		s_window
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				scr_w;
	int				scr_h;
	int				floor_color;
	int				ceiling_color;
}					t_window;

typedef struct		s_player
{
	double			posx;
	double			posy;
	double			dirx;
	double			diry;
	double			planex;
	double			planey;
	double			olddirx;
	double			oldplanex;
	double			movespeed;
	double			rotspeed;
}					t_player;

typedef struct		s_ray
{
	double			camerax;
	double			sidedistx;
	double			sidedisty;
	double			deltadistx;
	double			deltadisty;
	int				stepx;
	int				stepy;
	int				hit;
}					t_ray;

typedef struct		s_keys
{
	int				left;
	int				right;
	int				w;
	int				s;
	int				a;
	int				d;
}					t_keys;

typedef struct		s_img
{
	void			*img_ptr;
	int				*data;
	int				size_l;
	int				bpp;
	int				endian;
}					t_img;

typedef struct		s_texture
{
	double			wallx;
	int				texx;
	int				texy;
	double			step;
	double			texpos;
	int				y;
	int				color;
}					t_texture;

typedef struct		s_paths
{
	char			*spr_path;
	char			*north_path;
	char			*south_path;
	char			*west_path;
	char			*east_path;
}					t_paths;

typedef struct		s_tex_load
{
	int				*sp_text_data;
	void			*sp_text;
	int				sp_height;
	int				sp_width;

	int				*texture_data;
	int				height;
	int				width;

	int				*text_data_1;
	void			*text_1;
	int				height_1;
	int				width_1;

	int				*text_data_2;
	void			*text_2;
	int				height_2;
	int				width_2;

	int				*text_data_3;
	void			*text_3;
	int				height_3;
	int				width_3;

	int				*text_data_4;
	void			*text_4;
	int				height_4;
	int				width_4;

	int				*text_data_5;
	void			*text_5;
	int				height_5;
	int				width_5;

	int				*text_data_6;
	void			*text_6;
	int				height_6;
	int				width_6;
}					t_tex_load;

typedef struct		s_draw_sp
{
	double			spritex;
	double			spritey;
	double			invdet;
	double			transformx;
	double			transformy;
	int				spritescreenx;
	int				spriteheight;
	int				spritewidth;
	int				drawstartx;
	int				drawstarty;
	int				drawendx;
	int				drawendy;
	int				stripe;
	int				texx;
	int				texy;
	int				y;
	int				d;
	int				color;
}				t_draw_sp;


typedef struct		s_sprite
{
	double			x;
	double			y;
}					t_sprite;

typedef struct		s_status
{
	int				res_done;
	int				floor_done;
	int				ceiling_done;
	int				sprite_done;
	int				north_done;
	int				south_done;
	int				west_done;
	int				east_done;
	int				player_done;
}					t_status;

typedef struct		s_color
{
	int				color;
	int				commas;
}					t_color;


typedef struct		s_bitmapfile
{
	uint16_t		file_type;
	uint32_t		file_size;
	uint16_t		reserved_1;
	uint16_t		reserved_2;
	uint32_t		pixel_offset;
}					t_bitmapfile;


typedef struct		s_data
{
	t_window		window;
	t_player		player;
	t_ray			ray;
	t_keys			keys;
	t_img			img;
	t_texture		texture;
	t_paths			path;
	t_color			color;
	t_tex_load		tex_load;
	t_status		status;
	t_draw_sp		draw_sp;
	t_sprite		*sprite;
	int				mapx;
	int				mapy;
	int				side;
	double			perpwalldist;
	double			raydirx;
	double			raydiry;
	int				lineheight;
	int				drawstart;
	int				drawend;
	char			walldir;
	char			**lines;
	int				lines_count;
	int				map_height;
	int				map_width;
	int				**world_map;
	int				*sprite_order;
	int				sprite_num;
	double			*zbuffer;
}					t_data;

int					get_lines_count();
void				min_map(t_data **d);
int					ft_update(t_data *data);
void				ft_sprites(t_data *data);
void				verify_vars(t_data *data);
void				ft_movement(t_data *data);
void				ft_rotation(t_data *data);
void				draw_sprite(t_data *data);
int					name_checker(char *arg);
int					get_map_y(char **lines);
void				texture_posx(t_data *data);
void				ft_init_vars(t_data *data);
void				ray_step_dir(t_data *data);
void				ft_initialize(t_data *data);
void				load_textures(t_data *data);
void				ft_check_vars(t_data *data);
void				ft_draw_walls(t_data *data);
void				load_right_tex(t_data *data);
void				ft_map_checker(t_data *data);
void				map_allocation(t_data *data);
void				ft_rotate_left(t_data *data);
t_sprite			*ft_get_sprites(t_data *data);
void				cal_sprite_size(t_data *data);
void				player_position(t_data *data);
void				ft_sort_sprites(t_data *data);
int					check_file(char *file_path);
int					ft_count_sprites(t_data *data);
void				ft_texture(t_data *data, int x);
void				cal_wall_distance(t_data *data);
void				ft_move_left_right(t_data *data);
void				ft_read_map_2(t_data *data, int i);
void				ft_draw_ceiling_floor(t_data *data);
int					ft_close_game(t_data *data, int ret);
void				ft_start_game(t_data *data);
void				ft_read_map(t_data *data, char *file);
void				set_camera_ns(char dir, t_data *data);
void				parse_color(char *line, t_data *data);
int					parse_lines(char *line, t_data *data);
int					get_map_x(char **lines, t_data *data);
int					ft_key_pressed(int key, t_data *data);
void				check_spot(t_data *data, int x, int y);
void				create_map(char **lines, t_data *data);
void				get_tex_path(char *line, t_data *data);
void				set_camera_ew(char spot, t_data *data);
int					ft_key_released(int key, t_data *data);
void				ft_put_error(char *error, t_data *data);
void				get_resolution(char *line, t_data *data);
void				get_sprite_path(char *line, t_data *data);
int					check_movement(int x, int y, t_data *data);
int					color_parse(char *line, int i, t_data *data);
int					check_for_player(int x, int y, t_data *data);
void				get_color(char *line, t_data *data, char type);
char				**get_filelines(int count, int fd);
void				west_east_path(char *line, t_data *data, int i, int j);
void				north_south_path(char *line, t_data *data, int i, int j);
void				get_player_details(char spot, int x, int y, t_data *data);

#endif
