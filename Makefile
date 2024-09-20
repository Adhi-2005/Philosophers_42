# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adshafee <adshafee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/19 11:48:14 by adshafee          #+#    #+#              #
#    Updated: 2024/09/19 11:48:16 by adshafee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	gcc
CFLAGS	= -Wall -Wextra -Werror -pthread -I. -g
SRCS		=	philo.c utils_1.c utils_2.c utils_3.c arg_check.c
OBJS		= $(SRCS:.c=.o)
RM			= rm -f
NAME		= philo

all:			$(NAME)

$(NAME):	$(OBJS)
					$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
					$(RM) $(OBJS)

fclean:		clean
					$(RM) $(NAME)

re:				fclean $(NAME)
