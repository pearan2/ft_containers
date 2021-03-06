# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: honlee <honlee@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/08 21:20:00 by honlee            #+#    #+#              #
#    Updated: 2021/05/02 16:17:13 by honlee           ###   ########.fr        #
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
					${CC} ${CF} -o ${NAME} -D TEST_NS=std
					./a.out > std_out.txt
					${CC} ${CF} -o ${NAME} -D TEST_NS=ft
					./a.out > ft_out.txt
					diff ft_out.txt std_out.txt > diff.txt
					@echo "===================== diff.txt ====================="
					@cat diff.txt
					@echo "=================== diff.txt end ==================="
					@echo "=================== leaks test start ===================="
					@${CC} ${CF} -o ${NAME} -D TEST_NS=ft -D LEAK_TEST=1 
					@./a.out > /dev/null
					@cat leaks_out
					@echo "=================== leaks test end ======================"
					rm -rf a.out
					rm -rf a.out.dSYM


fclean		:		
					rm -f ${NAME}
					rm -rf a.out.dSYM
					rm -rf ft_out.txt
					rm -rf std_out.txt
					rm -rf diff.txt
					rm -rf leaks_out

re			:		fclean all

all         :      	${NAME}

.PHONY		:		fclean re all test ${NAME}