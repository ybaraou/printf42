FLAGS = -Wall -Wextra -Werror 
CC = cc
SOURCES = ft_printf.c ft_puthex.c ft_putint.c ft_putptr.c ft_putunsigned_int.c

NAME = libftprintf.a
OBJECTS = $(SOURCES:%.c=%.o)

$(NAME): $(OBJECTS)
	ar -rsc $(NAME) $(OBJECTS)

all: $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re
.SECONDARY: $(OBJECTS)