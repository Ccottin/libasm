# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccottin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/03 12:16:24 by ccottin           #+#    #+#              #
#    Updated: 2023/09/28 19:29:21 by ccottin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libasm.a

SRCS	= ft_strlen.s ft_strcpy.s
OBJS	= $(SRCS:.s=.o)

AS		= nasm
ASFLAGS	= -f elf64

CC		= gcc
CFLAGS	= -m64 -Wall -Wextra -Werror -g
MAIN	= main.c

all:	$(NAME)

#linke les .o generes par la regle %.o
$(NAME):	$(OBJS)
			ar rcs $@ $(OBJS)
			@ranlib $(NAME)

#definit la regle de compilation a effectuer pour chaque fichier,
#les uns apres les autres
%.o:	%.s
		$(AS) $(ASFLAGS) $< -o $@ 

#pour avoir dirctement tous les tests prets a etre executes :
# -L. cherche une librairie dans le repertroire courant
# -lasm permet de specifier qu on lie une librairie asm
test:	$(NAME)
		$(CC) $(CFLAGS) -o $@ $(MAIN) -L. -lasm

clean:
		rm -rf $(OBJS)

fclean:	clean
		rm -rf $(NAME) test

re:		fclean
		make

.PHONY	:	all fclean clean re test
