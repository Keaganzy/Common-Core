# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksng <ksng@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/30 16:05:52 by ksng              #+#    #+#              #
#    Updated: 2025/08/05 21:39:18 by ksng             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Executable Names
NAME        = so_long
BONUS  = so_long_bonus

# Compiler & Flags
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g

# Directory Paths
MANDATORY_DIR   = Mandatory
BONUS_DIR       = Bonus
LIBFT_DIR       = libft
MLX_DIR         = minilibx
OBJ_DIR         = obj

# Include Paths
INCLUDES        = -I$(MANDATORY_DIR) -I$(BONUS_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR)

# Source Files
MANDATORY_SRCS  = \
				$(MANDATORY_DIR)/so_long.c \
				$(MANDATORY_DIR)/populate_arr.c \
				$(MANDATORY_DIR)/path_check.c \
				$(MANDATORY_DIR)/map_print.c \
				$(MANDATORY_DIR)/map_check.c \
				$(MANDATORY_DIR)/image.c \
				$(MANDATORY_DIR)/handle_key.c \
				$(MANDATORY_DIR)/free_call.c \
				$(MANDATORY_DIR)/walk.c \
				$(MANDATORY_DIR)/close.c \
				$(MANDATORY_DIR)/error_msg.c \

BONUS_SRCS      = \
				$(BONUS_DIR)/so_long_bonus.c \
				$(BONUS_DIR)/populate_arr_bonus.c \
				$(BONUS_DIR)/path_check_bonus.c \
				$(BONUS_DIR)/map_print_bonus.c \
				$(BONUS_DIR)/map_check_bonus.c \
				$(BONUS_DIR)/image_bonus.c \
				$(BONUS_DIR)/handle_key_bonus.c \
				$(BONUS_DIR)/free_call_bonus.c \
				$(BONUS_DIR)/walk_bonus.c \
				$(BONUS_DIR)/close_bonus.c \
				$(BONUS_DIR)/error_msg_bonus.c \
				$(BONUS_DIR)/monster_walk.c \
				$(BONUS_DIR)/monster.c \
				$(BONUS_DIR)/find_monster.c \


# Object Files
MANDATORY_OBJS  = $(patsubst %.c,$(OBJ_DIR)/%.o,$(notdir $(MANDATORY_SRCS)))
BONUS_OBJS      = $(patsubst %.c,$(OBJ_DIR)/%.o,$(notdir $(BONUS_SRCS)))

# Libraries
LIBFT           = $(LIBFT_DIR)/libft.a
MLX_LIB         = $(MLX_DIR)/libmlx.a

# OS-specific MLX flags
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Linux)
    MLXFLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
endif
ifeq ($(UNAME_S), Darwin)
    MLXFLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
endif

# Main Targets
all: $(NAME)

$(NAME): $(MANDATORY_OBJS) $(LIBFT) $(MLX_LIB)
	@$(CC) $(CFLAGS) $(MANDATORY_OBJS) $(MLXFLAGS) -o $@ -Llibft -lft
	@echo "Compiled: $(NAME)"

bonus: $(BONUS)

$(BONUS): $(BONUS_OBJS) $(LIBFT) $(MLX_LIB)
	@$(CC) $(CFLAGS) $(BONUS_OBJS) -lft -Llibft -L$(MLX_DIR) $(MLXFLAGS) -o $@
	@echo "Compiled: $(BONUS)"

# Object Compilation Rules
$(OBJ_DIR)/%.o: $(MANDATORY_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/%.o: $(BONUS_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Build libraries
$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(MLX_LIB):
	@$(MAKE) -C $(MLX_DIR)

# Clean Rules
clean:
	@$(MAKE) clean -C $(LIBFT_DIR)
	@$(MAKE) clean -C $(MLX_DIR)
	@rm -rf $(OBJ_DIR)
	@echo "🧹 Cleaned object files."

fclean: clean
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@rm -f $(NAME) $(BONUS)
	@echo "🧹 Removed executables."

re: fclean all

.PHONY: all bonus clean fclean re
