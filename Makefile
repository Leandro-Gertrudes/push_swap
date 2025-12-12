# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/15 12:22:48 by lgertrud          #+#    #+#              #
#    Updated: 2025/05/21 18:05:05 by lgertrud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Executables
NAME = push_swap
BONUS_NAME = checker

# Compiler and flags
CC = cc
CFLAGS = -Wall -Werror -Wextra

# Directories
SRC_DIR = src
BONUS_DIR = bonus
INCLUDES_DIR = includes
LIBFT_DIR = libft

# Includes
INCLUDES = -I$(INCLUDES_DIR) -I$(LIBFT_DIR)

# Library
LIBFT = $(LIBFT_DIR)/libft.a

# Source files
SRC = $(SRC_DIR)/algorithm.c $(SRC_DIR)/commands_1.c $(SRC_DIR)/commands_2.c $(SRC_DIR)/easy_combinations.c \
	$(SRC_DIR)/fake_algorithm_1.c $(SRC_DIR)/fake_algorithm_2.c $(SRC_DIR)/ft_split_av.c $(SRC_DIR)/gertrud_sort.c \
	$(SRC_DIR)/main.c $(SRC_DIR)/target_utils.c $(SRC_DIR)/target.c $(SRC_DIR)/utils.c

BONUS_SRC = $(BONUS_DIR)/bonus.c $(BONUS_DIR)/commands_1.c $(SRC_DIR)/commands_2.c $(SRC_DIR)/ft_split_av.c $(BONUS_DIR)/tester.c \
	$(BONUS_DIR)/utils_tester.c

# Object files
OBJS = $(SRC:.c=.o)
BONUS_OBJS = $(BONUS_SRC:.c=.o)

# Colors
YELLOW = \e[93m
GREEN = \033[1;32m
RED = \033[1;31m
BLUE = \033[1;34m
RESET = \033[0m

# Banner
INTRO = @echo "$(BLUE)✨ Push Swap by: $(YELLOW)lgertrud 💻$(RESET)"

# Rules
all: $(LIBFT) $(NAME)

$(LIBFT):
	@echo "$(YELLOW)[LOADING...]$(RESET)"
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	$(INTRO)
	@echo "$(GREEN)[OK]$(RESET) Executable \"$(NAME)\" created 🚀"
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBFT) -o $(NAME)

bonus: $(LIBFT) $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	$(INTRO)
	@echo "$(GREEN)[OK]$(RESET) BONUS BONUS BONUS!!! 🔥"
	@$(CC) $(CFLAGS) $(INCLUDES) $(BONUS_OBJS) $(LIBFT) -o $(BONUS_NAME)

%.o: %.c
	@echo "$(YELLOW)[.o]$(RESET) Compiling $<"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@echo "$(RED)[CLEAN]$(RESET) Removing object files..."
	@rm -f $(OBJS) $(BONUS_OBJS)
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) clean

fclean:
	@echo "$(RED)[FCLEAN]$(RESET) Removing all generated files..."
	@rm -f $(NAME) $(BONUS_NAME)
	@rm -f $(OBJS) $(BONUS_OBJS)
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) fclean

re: fclean all