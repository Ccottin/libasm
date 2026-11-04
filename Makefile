# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccottin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/03 12:16:24 by ccottin           #+#    #+#              #
#    Updated: 2023/10/04 19:46:44 by ccottin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libasm.a

SRCS	= ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s ft_atoi_base.s
OBJS	= $(SRCS:.s=.o)
TESTS   = testing test1 test2 NewFile

# Assembleur
AS		= nasm
# format = elf64bits
ASFLAGS	= -f elf64
# includes debug informations, usefull to debug with GDB
TSFLAGS	= -g

CC		= cc
CPATH	= .
# -m64 = compiles in 64bits
CFLAGS	= -m64 -Wall -Wextra -g # -Werror
#MAIN	= testyo.c
MAIN	= main.c

all:	$(NAME)

#linke les .o generes par la regle %.o

$(NAME):	$(OBJS)
#           ar = archive manipulation ; r: add or replace files ; c: creates archive if doesnt exist ; s : updates symbols
			ar rcs $@ $(OBJS)

# defines a rule that will be used to compile every file, one after another
%.o:	%.s
		$(AS) $(ASFLAGS) $(TSFLAGS) $< -o $@ 


# this will generate every test, ready to be executed
# -L. search for a library into current repository
# -lasm specifies that we links to an assembly library
testing:	$(NAME) $(MAIN)
		$(CC) $(CFLAGS) -o $@ $(MAIN) -L$(CPATH) -lasm

clean:
		rm -rf $(OBJS)

fclean:	clean
		rm -rf $(NAME) $(TESTS)

re:		fclean
		make

.PHONY	:	all fclean clean re testing
