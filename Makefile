NAME = libft.a
AR = ar
CFLAGS = -Wall -Werror -Wextra
SRC = $(shell find . -name "*.c")
OBJ = $(SRC:.c=.o)
$(NAME): $(OBJ)
	$(AR) rcs $(NAME) $(OBJ)
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re:
	fclean $(NAME)
all: $(NAME)
