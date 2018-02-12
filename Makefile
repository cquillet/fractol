# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/09 16:13:19 by cquillet          #+#    #+#              #
#    Updated: 2018/02/10 20:42:55 by cquillet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

DIRSRC = .
DIROBJ = .

CC = gcc

DIRLIBS = ../libs

DIRHEADER = . $(DIRLIBS)/includes
CFLAGS = $(DIRHEADER:%=-I%) -Wall -Wextra -Werror

LDFLAGS = $(DIRLIBS:%=-L%) -framework OpenGL -framework AppKit
LIBNAME = libft.a libmlx.a libm.a libftprintf.a
LDLIBS = $(LIBNAME:lib%.a=-l%)

SRC = fractol.c fract_init.c fract_display.c fract_others.c \
	  fract_mouse_move.c fract_mouse_press.c fract_mouse_release.c \
	  fract_key_event.c \
	  mandelbrot.c julia.c burning_ship.c newton.c main.c

OBJ = $(SRC:%.c=%.o)

RM = rm -f

.PHONY: all clean debug fclean re lib

all: $(NAME)

$(NAME): lib $(OBJ)
	$(CC) $(LDFLAGS) $(OBJ) -o $@ $(LDLIBS)

lib:
	make -C $(DIRLIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $? -o $@

clean:
	make -C $(DIRLIBS) clean
	$(RM) $(OBJ)

fclean:
	make -C $(DIRLIBS) fclean
	$(RM) $(OBJ)
	$(RM) $(NAME)

re: fclean all

