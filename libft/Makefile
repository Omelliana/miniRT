# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bodysseu <bodysseu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/30 14:26:37 by bodysseu          #+#    #+#              #
#    Updated: 2020/08/21 13:46:45 by bodysseu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a

HEAD_DIR = includes
INCLUDE = -I $(HEAD_DIR)
HEADER = $(addprefix $(HEAD_DIR)/, libft.h get_next_line.h)

# main libft files
MAIN_FILES = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
		ft_memchr.c ft_memcmp.c \
		ft_strlen.c ft_sstrlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c \
		ft_strnstr.c ft_strstr.c ft_strncmp.c ft_strcmp.c \
		ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_is_set.c \
		ft_toupper.c ft_tolower.c ft_isspace.c \
		ft_calloc.c ft_strdup.c ft_strndup.c \
		ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_split_set.c ft_strmapi.c \
		ft_atoi.c ft_atof.c ft_itoa.c \
		ft_uitoa.c ft_uitoa_base.c ft_luitoa_base.c ft_lluitoa_base.c \
		ft_litoa.c ft_llitoa.c ft_luitoa.c ft_lluitoa.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
		ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

# get next line
GNL_FILES = get_next_line.c get_next_line_utils.c

#folders
SRCS_FOLDER = srcs
MAIN_FOLDER = base_files
GNL_FOLDER = gnl

SRCS_MAIN = $(addprefix $(MAIN_FOLDER)/, $(MAIN_FILES))
SRCS_GNL = $(addprefix $(GNL_FOLDER)/, $(GNL_FILES))

SRCS = $(addprefix $(SRCS_FOLDER)/, $(SRCS_MAIN) $(SRCS_GNL))
OBJECTS = $(SRCS:.c=.o)

.PHONY: all bonus clean fclean re

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	@ar rcs $(NAME) $(OBJECTS)
	
clean:
		@rm -rf $(OBJECTS)

fclean: clean
		@rm -rf $(NAME)

re:		fclean all