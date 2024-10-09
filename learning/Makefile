NAME = rayTracing

CFLAG = -Wall -Wextra -Werror -lm

LIBMLX = /.libmlx/linux

LIBMLX_FLAGS = -lmlx -lXext -lX11 -lm -lz

SRC = $(wildcard *.c)

OBJ = $(SRC:.c:.o)
%.o : %.c
	cc $(CFLAG) $(SRC) -L $(LIBMLX) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJ)
	cc $(CFLAG)  $(LIBMLX_FLAGS) $(SRC) -o $(NAME)

clean :
	rm -rf $(OBJ) $(NAME)

re : clean all

