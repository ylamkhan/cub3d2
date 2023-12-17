# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/22 04:36:48 by ylamkhan          #+#    #+#              #
#    Updated: 2023/11/24 09:57:21 by ylamkhan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME = cub3d

SRC = cub3d.c check_args.c ft_draw_walls.c ft_map_parsing.c ft_movement.c \
		ft_player.c ft_put_error.c ft_read_file.c ft_rotation.c \
	 	ft_texture.c ft_update.c get_map_size.c libft_functions.c libft_functions_2.c \
		get_next_line.c get_next_line_utils.c parse_color.c parse_params.c

CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3
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
