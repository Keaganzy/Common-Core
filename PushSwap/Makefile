# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksng <ksng@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/04 19:28:24 by ksng              #+#    #+#              #
#    Updated: 2025/07/29 21:28:43 by ksng             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -I. -I./libft

# Project name and header
NAME = push_swap
BONUS = checker
HEADER = push_swap.h

# Source files (all .c files in current directory except libft)
SRCS = push_swap.c

BONUS_SRC = checker.c 

SHARED_SRC = push_swap_arr_utils.c error_check.c \
push_swap_stk_utils.c sort_array.c push.c rot.c swap.c op_check.c \
cost_cal.c do_low_op_a.c fill_stk_b.c low_op_utils.c \
stk_utils.c \

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRC:.c=.o)
SHARED_OBJS = $(SHARED_SRC:.c=.o)
ALL_OBJS = $(OBJS) $(BONUS_OBJS) $(SHARED_OBJS)

# Libft configuration
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

# Main target
all: $(NAME)

# Build main executable
$(NAME): $(OBJS) $(SHARED_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(SHARED_OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

bonus: $(BONUS)

$(BONUS): $(BONUS_OBJS) $(SHARED_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(SHARED_OBJS) -L$(LIBFT_DIR) -lft -o $(BONUS)

# Compile object files
%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

# Build libft
$(LIBFT):
	@echo "Building libft..."
	@$(MAKE) -C $(LIBFT_DIR)

# Clean object files
clean:
	@echo "Cleaning object files..."
	@rm -f $(ALL_OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean

# Full clean (objects + executable)
fclean: clean
	@echo "Cleaning executable..."
	@rm -f $(NAME) $(BONUS)
	@$(MAKE) -C $(LIBFT_DIR) fclean

# Rebuild everything
re: fclean all

# Force rebuild of libft
libft_re:
	@$(MAKE) -C $(LIBFT_DIR) re

# Declare phony targets
.PHONY: all bonus clean fclean re libft_re 