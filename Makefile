# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: epeters- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/09 17:56:05 by epeters-          #+#    #+#              #
#    Updated: 2022/11/27 18:54:55 by epeters-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= client
NAMESRV	= server

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra -I./include

DIR_SRCS	= src
DIR_LIBFT	= libft

SRCS	= client.c
SRCSSRV	= server.c

OBJS	= $(addprefix $(DIR_SRCS)/,$(SRCS:.c=.o))
OBJSSRV	= $(addprefix $(DIR_SRCS)/,$(SRCSSRV:.c=.o))

LIBFT = libft/libft.a

all: $(NAME) $(NAMESRV)

$(NAME): $(OBJS)
	@echo Compiling $(NAME)...
	@echo Compiling libft...
	make -C $(DIR_LIBFT)
	$(CC) $(CLFAGS) -o $(NAME) $(OBJS) $(LIBFT)
	@echo $(NAME) ready!

$(NAMESRV): $(OBJSSRV)
	@echo Compiling $(NAMESRV)...
	@echo Compiling libft...
	make -C $(DIR_LIBFT)
	$(CC) $(CLFAGS) -o $(NAMESRV) $(OBJSSRV) $(LIBFT)
	@echo $(NAMESRV) ready!

clean:
	make clean -C $(DIR_LIBFT)
	rm -f $(OBJS) $(OBJSSRV)

fclean: clean
	make fclean -C $(DIR_LIBFT)
	rm -f $(NAME) $(NAMESRV)

re: fclean all

.PHONY: all clean fclean re
