# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfox <jfox.42angouleme@gmail.com>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/11 14:15:59 by j.fox             #+#    #+#              #
#    Updated: 2026/02/26 18:04:39 by jfox             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJECT_DIR ?= ./object_files
SRC_DIR = ./src
INC_DIR = ./header

SRC = main.c errors.c map.c free.c

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
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(TOOLS)
	@echo "\033[32m---------The so_long executable and object files have been made---------\033[0m"

# -------- Utility library ---------
$(TOOLS):
	@$(MAKE) -C libft

clean:
	@rm -rf $(OBJECT_DIR)
	@echo "\033[33m------The so_long and libft Object_Files were removed successfully------\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[33m--------------The executable has been removed successfully--------------\033[0m"
	@$(MAKE) fclean -C libft
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
