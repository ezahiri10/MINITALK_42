# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ezahiri <ezahiri@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/21 11:19:13 by ezahiri           #+#    #+#              #
#    Updated: 2024/04/21 13:46:51 by ezahiri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

SRC1 =	client.c \
		utils.c  

SRC2 =	server.c \
		utils.c  

OBJ1 = $(SRC1:.c=.o)

OBJ2 = $(SRC2:.c=.o)

NAME2 = server

NAME1 = client

all : $(NAME1) $(NAME2)

%.o : %.c minitalk.h
	$(CC) $(CFLAGS) -c $<

$(NAME1) : $(OBJ1)
	$(CC) $(CFLAGS) $(OBJ1)  -o $(NAME1)


$(NAME2) : $(OBJ2)
	$(CC) $(CFLAGS) $(OBJ2) -o $(NAME2)

clean : 
	$(RM) $(OBJ1) $(OBJ2)

fclean : clean
	$(RM) $(NAME1) $(NAME2)

re : fclean  all