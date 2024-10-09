NAME = miniRT

CFLAG = -WALL -WEXTRA -WERROR

SRC = $(wildcard */*.c)

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	cc $(CFLAG) $(SRC) -o $(NAME)

clean :
	rm -rf $(OBJ) $(NAME)

re : clean all
