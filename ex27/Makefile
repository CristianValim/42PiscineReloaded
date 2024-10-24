NAME = ft_display_file
CC = cc -Wall -Wextra -Werror
SRC = ft_display_file.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $@ $^

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
