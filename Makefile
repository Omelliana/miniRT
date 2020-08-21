# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bodysseu <bodysseu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/08 20:40:47 by bodysseu          #+#    #+#              #
#    Updated: 2020/08/21 13:58:40 by bodysseu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT

CC = clang
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -L$(MLXDIR) -lmlx -framework OpenGL -framework AppKit
HEAD_DIR = includes
HEADER = $(addprefix $(HEAD_DIR)/, minirt.h pixels.h enviroment.h objects.h)

LIBFT_DIR = libft
LIBFT_FLAG = -L $(LIBFT_DIR) -lft

MLXDIR = miniLibX
INCLUDE_HEADER = -I $(HEAD_DIR)
INCLUDE_MLX_HEADER = -I $(MLXDIR)

SRCS_FOLDER = 	srcs
PARS_FOLDER =	parsing
EVENETS_FOLDER =	events
RENEDRING_FOLDER =	rendering
OBJECT_FOLDER = objects
RAY_FOLDER = ray
VECRTOR_FOLDER = vector
COLOR_FOLDER = color
SAVE_FOLDER = save_image

EVENT_FILES = exit.c free_obj.c key_press.c camera.c
PARS_FILES = open_file.c parse.c parse_env.c parse_figures.c parse_vector.c

RENDERING_FILES = open_window.c
OBJECT_FILES =	sphere.c plane.c square.c discriminant.c \
				get_normal.c triangle.c cylinder.c
RAY_FILES =		matrix.c ray.c ray_trace.c intersect.c inter.c
VECTOR_FILES =	vector.c stuff.c vector_2.c
COLOR_FILES = 	color_rgb.c color_frgb.c render.c shades.c light.c

SAVE_FILES = buffer.c save.c write_to_bmp.c
SRCS_FILES = main.c

EVENTS = $(addprefix $(EVENETS_FOLDER)/, $(EVENT_FILES))
PARSING = $(addprefix $(PARS_FOLDER)/, $(PARS_FILES))

OBJECTS = $(addprefix $(OBJECT_FOLDER)/, $(OBJECT_FILES))
RAY = $(addprefix $(RAY_FOLDER)/, $(RAY_FILES))
VECTOR = $(addprefix $(VECRTOR_FOLDER)/, $(VECTOR_FILES))
COLORS = $(addprefix $(COLOR_FOLDER)/, $(COLOR_FILES))
RENDER = $(addprefix $(RENEDRING_FOLDER)/, $(RENDERING_FILES) $(OBJECTS) $(RAY) $(VECTOR) $(COLORS))
SAVE_IMG = $(addprefix $(SAVE_FOLDER)/, $(SAVE_FILES))
SRCS = 	$(addprefix $(SRCS_FOLDER)/, $(SRCS_FILES) $(EVENTS) $(PARSING) $(RENDER) $(SAVE_IMG))
SRCS_OBJ = $(SRCS:.c=.o)

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) $(INCLUDE_HEADER) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(SRCS_OBJ)
	@make -s -C $(MLXDIR) --no-print-directory
	@make -s -C $(LIBFT_DIR) --no-print-directory
	@$(CC) $(CFLAGS) $(MLXFLAGS) $(LIBFT_FLAG) $(INCLUDE_HEADER) $(SRCS) -o $(NAME)
	@echo "\033[1;34m[$(NAME)] CREATED\033[0m"

clean:
		@make clean -s -C $(MLXDIR) --no-print-directory
		@make clean -s -C $(LIBFT_DIR) --no-print-directory
		@rm -f $(SRCS_OBJ)
		@echo "\033[1;32m[Objects files cleared]\033[0m"

fclean: clean
		@rm -f $(NAME)
		@make fclean -C $(LIBFT_DIR)
		@echo "\033[1;33m[$(NAME)] REMOVED\033[0m"

re:		fclean all

.PHONY: all clean fclean re