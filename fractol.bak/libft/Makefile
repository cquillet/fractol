NAME = libft.a

DIRSRC = .
DIROBJ = .

DIRHEADER = ./include ./includes

DIRLIB = .

CC = gcc

CFLAGS = $(DIRHEADER:%=-I%) -Wall -Wextra -Werror

SRC = ./calc/complex.c ./calc/complex_ops.c ./calc/cplx_elem.c \
./calc/float_2f.c ./calc/ft_abs.c ./calc/ft_power.c ./calc/int_2d.c \
./calc/int_3d.c ./calc/matrix_func.c ./calc/matrix_ops.c ./calc/poly_math.c \
./calc/poly_ops.c ./calc/poly_real.c ./calc/poly_test.c \
./calc/polynomial.c ./calc/quat_ops.c ./calc/quat_vector.c \
./calc/quaternion.c ./calc/scale.c ./calc/tab_bin.c ./calc/vector.c \
./calc/vector_ops.c ./conv/ft_atoi.c ./conv/ft_atoi_base.c ./conv/ft_itoa.c \
./conv/ft_itoa_base.c ./gnl/get_next_line.c ./graph/box.c ./graph/box_redim.c \
./graph/boxf.c ./graph/boxf_cplx.c ./graph/boxf_redim.c ./graph/draw_box.c \
./graph/draw_line.c ./graph/landsea.c ./graph/mlx_image.c ./graph/pixel.c \
./graph/rgb.c ./graph/rgbf.c ./graph/wavelength.c ./graph/window.c \
./is/barely_equals.c ./is/ft_isalnum.c ./is/ft_isalpha.c ./is/ft_isascii.c \
./is/ft_isdigit.c ./is/ft_ishex.c ./is/ft_isnumber.c ./is/ft_isprint.c \
./lst/ft_lstadd.c ./lst/ft_lstdel.c ./lst/ft_lstdelone.c ./lst/ft_lstiter.c \
./lst/ft_lstlen.c ./lst/ft_lstmap.c ./lst/ft_lstnew.c ./mem/ft_bzero.c \
./mem/ft_memalloc.c ./mem/ft_memccpy.c ./mem/ft_memchr.c ./mem/ft_memcmp.c \
./mem/ft_memcpy.c ./mem/ft_memdel.c ./mem/ft_memdel2dim.c ./mem/ft_memlen.c \
./mem/ft_memmove.c ./mem/ft_memset.c ./put/ft_putcenter.c ./put/ft_putchar.c \
./put/ft_putchar_fd.c ./put/ft_putendl.c ./put/ft_putendl_fd.c \
./put/ft_putnbr.c ./put/ft_putnbr_base.c ./put/ft_putnbr_base_fd.c \
./put/ft_putnbr_fd.c ./put/ft_putstr.c ./put/ft_putstr_fd.c \
./str/ft_lenchar.c ./str/ft_replace.c ./str/ft_strcat.c ./str/ft_strcenter.c \
./str/ft_strchr.c ./str/ft_strclr.c ./str/ft_strcmp.c ./str/ft_strcpy.c \
./str/ft_strdel.c ./str/ft_strdup.c ./str/ft_strequ.c ./str/ft_striter.c \
./str/ft_striteri.c ./str/ft_strjoin.c ./str/ft_strlcat.c ./str/ft_strlen.c \
./str/ft_strmap.c ./str/ft_strmapi.c ./str/ft_strmset.c ./str/ft_strncat.c \
./str/ft_strncmp.c ./str/ft_strncpy.c ./str/ft_strnequ.c ./str/ft_strnew.c \
./str/ft_strnstr.c ./str/ft_strpad.c ./str/ft_strrchr.c ./str/ft_strset.c \
./str/ft_strsplit.c ./str/ft_strstr.c ./str/ft_strsub.c ./str/ft_strtrim.c \
./str/ft_tolower.c ./str/ft_toupper.c

OBJ = $(SRC:%.c=%.o)

RM = rm -f

.PHONY: all clean fclean

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $? -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
