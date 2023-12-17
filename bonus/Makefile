# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/22 04:36:48 by ylamkhan          #+#    #+#              #
#    Updated: 2023/12/16 13:51:07 by ylamkhan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME = cub3d

SRC = cub3d_bonus.c check_args_bonus.c ft_draw_walls_bonus.c ft_map_parsing_bonus.c ft_movement_bonus.c \
		ft_player_bonus.c ft_put_error_bonus.c ft_read_file_bonus.c ft_rotation_bonus.c\
		ft_sprites_bonus.c ft_texture_bonus.c ft_update_bonus.c get_map_size_bonus.c libft_functions_bonus.c libft_functions_2_bonus.c \
		get_next_line_bonus.c get_next_line_utils_bonus.c parse_color_bonus.c parse_params_bonus.c min_map.c

CFLAGS = -Wall -Wextra -Werror -fsanitize=address
CC = gcc

OBJECT = $(SRC:.c=.o)

all: $(NAME)
	

$(NAME): $(OBJECT)
	$(CC) $(CFLAGS) $(OBJECT) -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -rf $(OBJECT)

fclean: clean
	rm -rf $(NAME)
	rm -rf screenshot.bmp
	
re: fclean all
