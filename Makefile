# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaubin <aaubin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/26 22:57:40 by aaubin            #+#    #+#              #
#    Updated: 2013/12/27 05:31:40 by aaubin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=clang
LKFLAGS=-Wall -Wextra -pedantic -I./libft/includes -Werror -L./libft -lft
CFLAGS=-Wall -Wextra -pedantic -I./libft/includes
LDFLAGS=-g
NAME=ft_minishell1
SRC=ft_cd.c\
	ft_envutils.c\
	ft_shbin.c\
	ft_shenv.c\
	ft_shprint.c\
	ft_shread.c\
	ft_shaccess.c\
	ft_sherror.c\
	get_next_line.c\
	main.c
NOM=$(basename $(SRC))
OBJ=$(addsuffix .o, $(NOM))

all: makelib normal

normal: $(NAME)

makelib:
	@git submodule update --init -q
	@make -f Makefile -C libft

cleanlib:
	@git submodule update --init -q
	@make -f Makefile -C libft clean

fcleanlib:
	@git submodule update --init -q
	@make -f Makefile -C libft fclean

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(INC_PATH) $^ $(LKFLAGS)

%.o: %.c
	$(CC) $(LFLAGS) -g -o $@ -c $< $(CFLAGS)

clean: cleanlib
	@rm -rf $(OBJ)

fclean: clean fcleanlib mrproper

re: fclean fcleanlib all

.PHONY: clean mrproper

mrproper: clean
	@rm -rf $(NAME)
