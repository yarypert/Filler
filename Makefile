NAME = yarypert.filler

SRCS = main.c

OBJ = main.o

INCLUDES = -I ./

LIB = Libft/libft.a

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME) :
	@clear
	@echo "\033[1;49;92m===Filler : Compilating Champion...\033[0m"
	@make -C Libft
	@clear
	@echo "\033[1;49;92m===Filler : Compilating Champion...\033[0m"
	@echo "\033[1;49;92m[======                        ]\033[0m"
	@clear
	@echo "\033[1;49;92m===Filler : Compilating Champion...\033[0m"
	@echo "\033[1;49;92m[============                  ]\033[0m"
	@gcc $(SRCS) $(LIB) -o $(NAME)
	@clear
	@echo "\033[1;49;92m===Filler : Compilating Champion...\033[0m"
	@echo "\033[1;49;92m[==================            ]\033[0m"
	@clear
	@echo "\033[1;49;92m===Filler : Compilating Champion...\033[0m"
	@echo "\033[1;49;92m[========================      ]\033[0m"
	@clear
	@echo "\033[1;49;92m===Filler : Compilating Champion...\033[0m"
	@echo "\033[1;49;92m[==============================]\033[0m"
	@echo "\033[1;49;92m===Filler : Done\033[0m"

clean:
	@make clean -C Libft
	@echo "\033[38;5;1m===Filler : Deleting .o Files...\033[0m"
	@rm -rf TMP

fclean: clean
	@make fclean -C Libft
	@echo "\033[38;5;1m===Filler : Deleting Filler executable...\033[0m"
	@rm -rf $(NAME)
	@echo "\033[38;5;1m===Filler : Deleted.\033[0m"

re: fclean all

.SUFFIXES:

.PHONY: all clean fclean re
