# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: epeters- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/08 17:38:21 by epeters-          #+#    #+#              #
#    Updated: 2022/12/09 10:59:38 by epeters-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = client
NAME_SRV = server

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra -I./include

DIR_SRCS	= src
DIR_LIBFT	= libft

SRCS =	client.c
SRCS_SRV = server.c

OBJS = $(addprefix $(DIR_SRCS)/,$(SRCS:.c=.o))
OBJS_SRV = $(addprefix $(DIR_SRCS)/,$(SRCS_SRV:.c=.o))

LIBFT = libft/libft.a

all: $(NAME) $(NAME_SRV)

$(NAME): $(OBJS)
	@echo Compiling $(NAME)...
	@echo Compiling libft...
	make -C $(DIR_LIBFT)
	$(CC) $(CLFAGS) -o $(NAME) $(OBJS) $(LIBFT)
	@echo $(NAME) ready!

$(NAME_SRV): $(OBJS_SRV)
	@echo Compiling $(NAME_SRV)...
	@echo Compiling libft...
	make -C $(DIR_LIBFT)
	$(CC) $(CLFAGS) -o $(NAME_SRV) $(OBJS_SRV) $(LIBFT)
	@echo $(NAME_SRV) ready!

clean:
	make clean -C $(DIR_LIBFT)
	rm -f $(OBJS) $(OBJS_SRV)

fclean: clean
	make fclean -C $(DIR_LIBFT)
	rm -f $(NAME) $(NAME_SRV)

re: fclean all

.PHONY: all clean fclean re
