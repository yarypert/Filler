# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phanna <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/27 03:28:40 by phanna            #+#    #+#              #
#    Updated: 2018/03/07 16:09:53 by atgerard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = atgerard.filler

# Colors - Echo

_END = $'\x1b[0m
_GREY = $'\x1b[30m
_RED = $'\x1b[31m
_GREEN = $'\x1b[32m
_YELLOW = $'\x1b[33m
_BLUE = $'\x1b[34m
_PURPLE = $'\x1b[35m
_CYAN = $'\x1b[36m
_WHITE = $'\x1b[37m

LOLXD_RGB = "\033[38;2;237;34;56m"
LOLXD_RGB = "\033[48;2;237;34;56m"

SRC_PATH = ./SRC/
OBJ_PATH = ./obj/
INC_PATH = ./includes/
LIB_PATH = ./libft/

SRC_NAME = main.c\
		   heatmap.c\
		   get_elements.c\
		   canplace.c\
		   put_pieces.c\

OBJ_NAME = $(SRC_NAME:.c=.o)
INC_NAME = filler.h
LIB_NAME = libft.a

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix $(INC_PATH),$(INC_NAME))
LIB = $(addprefix $(LIB_PATH),$(LIB_NAME))

CC = gcc

CFLAGS = -Wall -Werror -Wextra
CPPFLAGS = -Iinc
SANITIZE = -g -fsanitize=address

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIB_PATH)
	@gcc -o $(NAME) $(OBJ) $(LIB)
	@echo "\n${_GREEN}$(NAME) generate${_END} [${_GREEN}✔${_END}]"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(INC)
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<
	@echo "${_RED}█${_END}\c"

clean:
	@make clean -C $(LIB_PATH)
	@rm -rf $(OBJ_PATH) 
	@echo "${_RED}cleaning ${_END}${_BLUE}filler${_END} ${_RED}objects files${_END} [${_GREEN}✔${_END}]"

fclean: clean
	@make fclean -C $(LIB_PATH)
	@rm -f $(NAME)
	@echo "${_RED}delete $(NAME)${_END} [${_GREEN}✔${_END}]"

re: fclean all
