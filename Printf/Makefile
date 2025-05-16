# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksng <ksng@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/16 11:59:01 by ksng              #+#    #+#              #
#    Updated: 2025/05/16 17:19:17 by ksng             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SOURCES = \
		ft_flags.c ft_itoa.c ft_printf.c ft_puchar.c ft_puhexnbr.c\
		ft_puitoa.c ft_pupointer.c ft_pustring.c ft_puunitoa.c ft_strdup.c\
		ft_strjoin.c ft_utils.c ft_pupercent.c

OBJECTS = $(SOURCES:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

bonus: $(NAME)

$(NAME): $(OBJECTS)
		$(AR) -r $@ $?

%.o: %.c
		$(CC) -g -O0 -c $(CFLAGS) $?

clean: 
		rm -f $(OBJECTS) $(BOBJECTS)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
