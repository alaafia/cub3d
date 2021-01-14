# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alaafia <alaafia@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/13 15:25:37 by alaafia           #+#    #+#              #
#    Updated: 2021/01/14 18:52:14 by alaafia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

MLX =  -lmlx -framework OpenGL -framework AppKit

NAME = cub3D

NAMELIB = printflib.a

SRCS = srcs/ft_init.c \
		srcs/ft_key_pressed.c \
		srcs/ft_move.c \
		srcs/ft_player.c \
		srcs/ft_puterror.c \
		srcs/ft_readmap.c \
		srcs/ft_screenshot.c \
		srcs/ft_sprite.c \
		srcs/ft_texture.c \
		srcs/ft_update.c \
		srcs/ft_check.c \
		srcs/ft_draw.c \
		srcs/main.c

CC = gcc

CFLAGS = -Wall -Werror -Wextra

GETNEXT =	get_next_line/get_next_line.c \
			get_next_line/get_next_line_utils.c

OBJ = $(SRCS:.c=.o)
B_OBJ = $(B_SRCS:%.c=%.o) 
OBJGET	= $(GETNEXT:.c=.o)

$(NAME) : $(OBJ) $(OBJGET)
	@echo "\033[31m[Remove last version Of Cub3D...]"
	@rm -rf Cub3D
	@$(MAKE) -C ./ft_printf
	@mv ./ft_printf/printflib.a .
	@echo "\033[32m[Cub3D compilation...]"
	@$(CC) $(OBJ) $(OBJGET) -I ./includes -Wall -Wextra -Werror $(MLX) $(NAMELIB) -o $(NAME) -g
	@echo "\033[34m[Done !]"


all : $(NAME)

clean :
	@echo "\033[31m[Cleaning The Old Files...!]\033[34m"
	@rm -rf $(OBJ) $(B_OBJ)
	@$(MAKE) clean -C ./ft_printf

fclean : clean
	@echo "\033[31m[Cleaning printf Files...!]"
	@$(MAKE) fclean -C ./ft_printf
	@rm -rf printflib.a
	@echo "\033[31m[Cleaning Cub3D Files...!]"
	@rm -rf $(NAME) $(OBJ) $(OBJGET)
	@echo "\033[31m[Deleting Old Screenshot...!]"
	@rm -rf Screenshot.bmp

re : fclean all
