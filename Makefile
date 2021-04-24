# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: honlee <honlee@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/08 21:20:00 by honlee            #+#    #+#              #
#    Updated: 2021/04/24 11:21:39 by honlee           ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

SRCS		=		\
					list_main.cpp\

NAME		=		a.out

CC			=		clang++

CF			=		-Wall -Wextra -Werror -std=c++98 ${SRCS}
DCF			=		-g ${SRCS}

${NAME}     :       
					${CC} ${CF} -o ${NAME}

test		:		fclean
					${CC} ${DCF} -o ${NAME}
					lldb a.out

fclean		:		
					rm -f ${NAME}
					rm -rf a.out.dSYM

re			:		fclean all

all         :      	${NAME}

.PHONY		:		fclean re all test ${NAME}