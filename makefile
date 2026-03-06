# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfox <jfox.42angouleme@gmail.com>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/11 14:15:59 by j.fox             #+#    #+#              #
#    Updated: 2026/03/06 10:28:01 by jfox             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MLX_DIR = macrolibx
MLX_REPO = https://github.com/seekrs/MacroLibX.git
MLX_LIB = $(MLX_DIR)/libmlx.so

OBJECT_DIR ?= ./object_files
SRC_DIR = ./src
INC_DIR = ./header

SRC = main.c map.c map_utils.c map_fill.c game.c render.c \
movement.c events.c errors.c free.c

NAME = so_long
OBJ = $(SRC:%.c=$(OBJECT_DIR)/%.o)

CC = cc
CFLAGS += -Wall -Wextra -Werror -g -I$(INC_DIR) -MMD -MP

TOOLS = libft.a

all: $(NAME) ping_make

# ---------- Build objects ---------
$(OBJECT_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJECT_DIR)
	@$(CC) -o $@ -c $< $(CFLAGS)

# --------- Build so_long ----------
$(NAME): $(TOOLS) $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(TOOLS) $(MLX_LIB) -lSDL2 -I $(MLX_DIR)/includes
	@echo "\033[32m---------The so_long executable and object files have been made---------\033[0m"

# -------- BUild MacrolibX ---------
$(MLX_DIR):
	@git clone $(MLX_REPO) $(MLX_DIR)

$(MLX_LIB): $(MLX_DIR)
	@$(MAKE) -j -C macrolibx

# -------- Utility libraries --------
$(TOOLS): $(MLX_LIB)
	@$(MAKE) -C libft
	@echo "\033[32m-------------The macrolibx was cloned and made successfully-------------\033[0m"

clean:
	@rm -rf $(OBJECT_DIR)
	@echo "\033[33m------The so_long and libft Object_Files were removed successfully------\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[33m--------------The executable has been removed successfully--------------\033[0m"
	@$(MAKE) fclean -C libft
	@$(MAKE) fclean -C macrolibx
	@rm -rf $(MLX_DIR)
	@echo "\033[33m--------------The macrolibx has been removed successfully---------------\033[0m"
	@echo "\033[33m"
	@echo "=============================CLEAN COMPLETE============================="
	@echo "\033[0m"

re: ping_re fclean all

ping_make:
	@echo "\033[32m"
	@echo "=============================MAKE COMPLETE=============================="
	@echo "\033[0m"

ping_re:
	@echo "\033[31m"
	@echo "=======================REBUILDING THE EXECUTABLE========================"
	@echo "\033[0m"

.PHONY: all clean fclean re tools ping_make ping_re

-include $(OBJ:.o=.d)
