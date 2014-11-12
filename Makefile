# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fteuber <fteuber@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/19 13:44:31 by fteuber           #+#    #+#              #
#    Updated: 2014/10/12 16:38:53 by fteuber          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME =	ft_minishell1

SRCS =	ft_access.c		ft_bin.c		ft_cd.c				ft_env.c\
		ft_error.c		ft_print.c		ft_read.c			ft_unsetenv.c\
		get_next_line.c	main.c			ft_memalloc.c		ft_memcpy.c\
		ft_memdel.c		ft_putstr.c			ft_putendl.c\
		ft_putstr_fd.c	ft_realloc.c	ft_strchr.c			ft_strdup.c\
		ft_strequ.c		ft_strjoin.c	ft_strlen.c			ft_strncat.c\
		ft_strncmp.c	ft_strnequ.c	ft_strnew.c			ft_strpos.c\
		ft_strsplit.c	ft_strsub.c		ft_strtrim.c		ft_putendl_fd.c\
		ft_putchar_fd.c	ft_putchar.c	ft_bzero.c			ft_strcat.c\
		ft_isblank.c\

HDR = 	ft_sh.h		get_next_line.h

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	gcc -Wall -Wextra -Werror $(OBJ) -o $(NAME)

%.o: ./srcs/qq%.c
	@gcc -c -Wall -Wextra -Werror $(SRCS)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all c clean fclean re
