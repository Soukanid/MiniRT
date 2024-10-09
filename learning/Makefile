NAME = rayTracing

CFLAG = -Wall -Wextra -Werror -lm

LIBMLX = ~/libmlx/linux

LIBMLX_FLAGS = -lmlx -lXext -lX11 -lm -lz

SRC = $(wildcard *.c)

OBJ = $(SRC:.c=.o)

.c.o:
	cc 	-I $(LIBMLX) 	$(CFLAG) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJ)
	cc $(OBJ) $(CFLAG) $(LIBMLX_FLAGS) -L $(LIBMLX) -o $(NAME)

clean :
	rm -rf $(OBJ) $(NAME)

re : clean all

