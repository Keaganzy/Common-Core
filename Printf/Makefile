# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksng <ksng@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/16 11:59:01 by ksng              #+#    #+#              #
#    Updated: 2025/05/21 10:01:20 by ksng             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SOURCES = ft_printf.c ft_puchar.c ft_puhexnbr.c\
		ft_puitoa.c ft_pupointer.c ft_pustring.c ft_puunitoa.c\

BSOURCES = \
		ft_flags_bonus.c ft_printf_bonus.c ft_puchar_bonus.c ft_puhexnbr_bonus.c\
		ft_puitoa_bonus.c ft_pupointer_bonus.c ft_pustring_bonus.c ft_puunitoa_bonus.c\
		ft_utils_bonus.c ft_pupercent_bonus.c ft_utils_i_bonus.c ft_utils_libft_1_bonus.c\
		ft_utils_libft_2_bonus.c ft_utils_space_bonus.c ft_utils_hex_bonus.c ft_utils_i_d_bonus.c\
		ft_utils_p_bonus.c

OBJECTS = $(SOURCES:.c=.o)
BOBJECTS = $(BSOURCES:.c=.o)

HDR = ft_printf.h

BHDR = ft_printf_bonus.h

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS)
		$(AR) -r $@ $(OBJECTS)

$(OBJECTS): %.o: %.c $(HDR)
		$(CC) $(CFLAGS) -c $< -o $@

bonus:  $(OBJECTS) $(BOBJECTS)
		$(AR) -r $(NAME) $(BOBJECTS)

$(BOBJECTS): %.o: %.c $(BHDR)
		$(CC) $(CFLAGS) -c $< -o $@

clean: 
		rm -f $(OBJECTS) $(BOBJECTS)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
