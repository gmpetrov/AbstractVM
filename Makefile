# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/03 16:31:34 by gpetrov           #+#    #+#              #
#    Updated: 2015/02/03 17:20:01 by gpetrov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= avm

SRC_DIR = srcs

OBJ_DIR = $(SRC_DIR)/.obj

SRC_FILES = $(shell find $(SRC_DIR) -type f -print | grep "\.cpp")

OBJS	= $(SRC_FILES:srcs/%.cpp=$(OBJ_DIR)/%.o)

FLAGS	= -Wall -Wextra -Werror

CC 		= g++

all: $(NAME)

$(NAME): MKDIR_OBJ_DIR $(OBJS)
	@$(CC) $(FLAGS) $(OBJS) -o $(NAME)
	@echo "\n=> Compiling AbstractVM [\033[32mDONE\033[m]"

MKDIR_OBJ_DIR:
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@$(CC) -o $@ -c $< $(CFLAGS)
	@echo -n .

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all
.PHONY: all clean fclean re