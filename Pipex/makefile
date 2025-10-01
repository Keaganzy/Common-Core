# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksng <ksng@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/01 12:15:51 by ksng              #+#    #+#              #
#    Updated: 2025/10/01 12:35:36 by ksng             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#SETUP
NAME = pipex
BONUS = blah

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

#FILES AND PATH
SRCS_DIR = srcs/
SRCS_SRCS = main.c pipex.c pipex_utils.c free.c
SOURCES = $(addprefix $(SRCS_DIR), $(SRCS_SRCS))
LIB = srcs/libft/ft_strlcat.c srcs/libft/ft_strlen.c srcs/libft/ft_split.c srcs/libft/ft_strjoin.c srcs/libft/ft_strncmp.c srcs/libft/ft_strrchr.c srcs/libft/ft_strdup.c srcs/libft/ft_strtrim.c srcs/libft/ft_substr.c srcs/libft/ft_strlcpy.c

#COMMANDS
all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SOURCES) $(LIB) -o $(NAME)

bonus:
	$(CC) $(CFLAGS) $(SOURCES) $(LIB) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean:	clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
