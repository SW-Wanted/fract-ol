# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecarneir <ecarneir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/07 19:49:29 by ecarneir          #+#    #+#              #
#    Updated: 2025/12/07 19:49:37 by ecarneir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = cc
CFLAGS = -Wall -Wextra -Werror

MLX_PATH = minilibx-linux/
MLX_NAME = libmlx.a
MLX_LIB = $(MLX_PATH)$(MLX_NAME)

LFLAGS = -L$(MLX_PATH) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz

SRCS = main.c init.c render.c utils.c events.c
OBJS = $(SRCS:.c=.o)

all: $(MLX_LIB) $(NAME)

$(MLX_LIB):
	@make -C $(MLX_PATH)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -C $(MLX_PATH)
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re