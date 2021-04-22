# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: honlee <honlee@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/08 21:20:00 by honlee            #+#    #+#              #
#    Updated: 2021/04/22 13:38:40 by honlee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=		\
					list_main.cpp\

NAME		=		a.out

CC			=		clang++

CF			=		-Wall -Wextra -Werror -std=c++98 ${SRCS}
DCF			=		-g ${SRCS}

${NAME}     :       
					${CC} ${DCF} -o ${NAME}

test		:		fclean
					${CC} ${DCF} -o ${NAME}
					lldb a.out

fclean		:		
					rm -f ${NAME}
					rm -rf a.out.dSYM

re			:		fclean all

all         :      	${NAME}

.PHONY		:		fclean re all test ${NAME}