# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: epeters- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/08 17:38:21 by epeters-          #+#    #+#              #
#    Updated: 2022/12/15 17:05:41 by epeters-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = client
NAME_SRV = server
NAME_BNS = client
NAME_BNS_S	= server

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra -I./include

DIR_SRCS	= src
DIR_LIBFT	= libft

SRCS		= client.c
SRCS_SRV	= server.c
SRCS_BNS_C	= client_bonus.c
SRCS_BNS_S	= server_bonus.c


OBJS		= $(addprefix $(DIR_SRCS)/,$(SRCS:.c=.o))
OBJS_SRV	= $(addprefix $(DIR_SRCS)/,$(SRCS_SRV:.c=.o))
OBJS_BNS_C	= $(addprefix $(DIR_SRCS)/,$(SRCS_BNS_C:.c=.o))
OBJS_BNS_S	= $(addprefix $(DIR_SRCS)/,$(SRCS_BNS_S:.c=.o))

LIBFT = libft/libft.a

CACHE	= cache

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

bonus: $(CACHE)	

$(CACHE): $(OBJS_BNS_C) $(OBJS_BNS_S)
	make -C $(DIR_LIBFT)
	$(CC) $(CLFAGS) -o $(NAME) $(OBJS_BNS_C) $(LIBFT)
	$(CC) $(CLFAGS) -o $(NAME_SRV) $(OBJS_BNS_S) $(LIBFT)
	touch $(CACHE)
	@echo Bonus ready!

clean:
	make clean -C $(DIR_LIBFT)
	rm -f $(OBJS) $(OBJS_SRV) $(OBJS_BNS_C) $(OBJS_BNS_S)

fclean: clean
	make fclean -C $(DIR_LIBFT)
	rm -f $(NAME) $(NAME_SRV) $(CACHE)

re: fclean all

.PHONY: all clean fclean re bonus
