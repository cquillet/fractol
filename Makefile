# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/09 16:13:19 by cquillet          #+#    #+#              #
#    Updated: 2018/02/06 16:08:39 by cquillet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

DIRSRC = .
DIROBJ = .

VERSION_GET = $(shell sw_vers | grep "ProductVersion:" | grep -o "[0-9]\+\.[0-9]\+")
SIERRA = 10.12
EL_CAPITAN = 10.11

ifeq ($(VERSION_GET), $(SIERRA))
DIRMLX = minilibx_macos_sierra
else
DIRMLX = minilibx_macos
endif

DIRLIBFT = libft

DIRHEADER = ./$(DIRLIBFT)/includes ./$(DIRMLX)

DIRLIB = ./$(DIRLIBFT) ./$(DIRMLX)

CC = gcc

CFLAGS = $(DIRHEADER:%=-I%) -Wall -Wextra -Werror

LDFLAGS = $(DIRLIB:%=-L%) -framework OpenGL -framework AppKit
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

$(NAME): $(OBJ)
	make -C $(DIRLIBFT)
	make -C $(DIRMLX)
#	$(CC) $(CFLAGS) -c $?
	$(CC) $(LDFLAGS) $^ -o $@ $(LDLIBS)
#	$(CC) $(CFLAGS) -c $? -o $@

lib:
	make -C $(DIRLIBFT)
	make -C $(DIRMLX)

%.o: %.c
	$(CC) $(CFLAGS) -c $? -o $@

clean:
	make -C $(DIRLIBFT) clean
	make -C $(DIRMLX) clean
	$(RM) $(OBJ)

fclean:
	make -C $(DIRLIBFT) fclean
	make -C $(DIRMLX) clean
	$(RM) $(OBJ)
	$(RM) $(NAME)

re: fclean all
