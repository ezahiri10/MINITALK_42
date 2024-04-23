# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ezahiri <ezahiri@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/21 11:19:13 by ezahiri           #+#    #+#              #
#    Updated: 2024/04/23 12:37:00 by ezahiri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

SRC1 =	client.c \
		utils.c  

SRC2 =	server.c \
		utils.c


SRC1_BONUS =	BONUS/client_bonus.c \
				BONUS/utils_bonus.c  

SRC2_BONUS =	BONUS/server_bonus.c \
				BONUS/utils_bonus.c

OBJ1 = $(SRC1:.c=.o)

OBJ2 = $(SRC2:.c=.o)

OBJ1_BONUS = $(SRC1_BONUS:.c=.o)

OBJ2_BONUS = $(SRC2_BONUS:.c=.o)

NAME2 = server

NAME1 = client

NAME2_BONUS = server_bonus

NAME1_BONUS = client_bonus

all : $(NAME1) $(NAME2)

bonus : $(NAME1_BONUS) $(NAME2_BONUS)

BONUS/%.o : BONUS/%.c BONUS/minitalk_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

%.o : %.c minitalk.h
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME1) : $(OBJ1)
	$(CC) $(CFLAGS) $(OBJ1)  -o $(NAME1)


$(NAME2) : $(OBJ2)
	$(CC) $(CFLAGS) $(OBJ2) -o $(NAME2)

$(NAME1_BONUS) : $(OBJ1_BONUS)
	$(CC) $(CFLAGS) $(OBJ1_BONUS) -o $(NAME1_BONUS)


$(NAME2_BONUS) : $(OBJ2_BONUS)
	$(CC) $(CFLAGS) $(OBJ2_BONUS) -o $(NAME2_BONUS)

clean :
	$(RM) $(OBJ1_BONUS) $(OBJ2_BONUS) $(OBJ1) $(OBJ2)

fclean : clean
	$(RM) $(NAME1_BONUS) $(NAME2_BONUS) $(NAME1) $(NAME2)

re : fclean  all