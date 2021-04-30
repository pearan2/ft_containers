# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: honlee <honlee@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/08 21:20:00 by honlee            #+#    #+#              #
#    Updated: 2021/04/30 15:00:58 by honlee           ###   ########.fr        #
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

dbg			:		fclean
					${CC} ${DCF} -o ${NAME}
					lldb a.out

test		:		fclean
					${CC} ${DCF} -o ${NAME} -D TEST_NS=ft
					./a.out > ft_out.txt
					${CC} ${DCF} -o ${NAME} -D TEST_NS=std
					./a.out > std_out.txt
					diff ft_out.txt std_out.txt > diff.txt
					@echo "===================== diff.txt ====================="
					@cat diff.txt
					@echo "=================== diff.txt end ==================="
					rm -rf a.out
					rm -rf a.out.dSYM

fclean		:		
					rm -f ${NAME}
					rm -rf a.out.dSYM
					rm -rf ft_out.txt
					rm -rf std_out.txt
					rm -rf diff.txt

re			:		fclean all

all         :      	${NAME}

.PHONY		:		fclean re all test ${NAME}