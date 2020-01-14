# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dhaouhao <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/24 02:13:23 by dhaouhao          #+#    #+#              #
#    Updated: 2020/01/14 20:12:46 by dhaouhao         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= ft_atoi.c ft_putstr.c ft_fill_struct.c ft_set_prec.c \
ft_write_c.c ft_write_n_return_size.c ft_set_width.c ft_write_diux.c \
ft_ulltoa_base.c ft_strdup.c ft_write_p.c ft_substr.c ft_parse_str.c \
ft_write_s.c ft_is_type.c ft_printf.c ft_strlen.c ft_isdigit.c ft_putchar.c

HEADER		=	ft_printf.h

OBJS		=	${SRCS:.c=.o}

NAME		=	libftprintf.a

.c.o:
			gcc -Wall -Wextra -Werror -c -I./${HEADER} $< -o ${<:.c=.o}
			@echo "\033[92mstatus ${<:.c=.o} is [OK]\033[0m"

${NAME}:	${OBJS} ${HEADER}
			ar rc $@ $^
			ranlib ${NAME}
			@echo "\033[92mstatus ${NAME} is [OK]\033[0m"

all:		${NAME}
			@echo "\033[92mstatus $@ is [OK]\033[0m"

clean:
			rm -f ${OBJS}
			@echo "\033[92mstatus $@ is [OK]\033[0m"

fclean:		clean
			rm -f ${NAME}
			@echo "\033[92mstatus $@ [OK]\033[0m"

re:			fclean all
			@echo "\033[92mstatus $@ [OK]\033[0m"

.PHONY:		fclean clean re all
