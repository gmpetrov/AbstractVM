# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/03 16:31:34 by gpetrov           #+#    #+#              #
#    Updated: 2015/03/18 16:21:12 by gpetrov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= avm
SRCS	= $(shell find srcs -type f -print | grep "\.cpp")
OBJS	= $(SRCS:srcs/%.cpp=srcs/.obj/%.o)
INC		= -I includes
FLAGS	= -Wall -Wextra -Werror -pedantic
CC		= g++ -g -std=c++11
OBJ_DIR = srcs/.obj

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) $(OBJS) -o $(NAME) $(INC) $(LIB)
	@echo "\n=> Compiling $(NAME) [\033[32mDONE\033[m]"

$(OBJ_DIR)/%.o: srcs/%.cpp
	@mkdir -p $(OBJ_DIR)
	@$(CC) -c $< -o $@ $(FLAGS) $(INC)
	@echo -n .

gdb:
	$(CC) -g $(FLAGS) $(OBJS) -o $(NAME) $(INC)
	gdb $(NAME)

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all gdb clean fclean re

# NAME 	= avm

# SRC_DIR = srcs

# OBJ_DIR = $(SRC_DIR)/.obj

# SRC_FILES = $(shell find $(SRC_DIR) -type f -print | grep "\.cpp")

# OBJS	= $(SRC_FILES:srcs/%.cpp=$(OBJ_DIR)/%.o)

# FLAGS	= -Wall -Wextra -Werror -pedantic

# CC 		= g++ -g -std=c++11

# INC 	= -I includes

# all: $(NAME)

# $(NAME): MKDIR_OBJ_DIR $(OBJS)
# 	@$(CC) $(FLAGS) $(OBJS) -o $(NAME)
# 	@echo "\n=> Compiling AbstractVM [\033[32mDONE\033[m]"

# MKDIR_OBJ_DIR:
# 	@mkdir -p $(OBJ_DIR)

# $(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
# 	@$(CC) -o $@ -c $< $(CFLAGS) $(INC)
# 	@echo -n .

# clean:
# 	@rm -rf $(OBJ_DIR)

# fclean: clean
# 	@rm -f $(NAME)

# re: fclean all
# .PHONY: all clean fclean re
