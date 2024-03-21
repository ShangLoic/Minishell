##
## EPITECH PROJECT, 2023
## makefile
## File description:
## task01
##

SRC =   *.c

OBJ =	$(SRC:.c=.o)

NAME = libmy.a

all:    $(NAME)

$(NAME):
	gcc -c $(SRC)
	ar rc $(NAME) $(OBJ)
	rm -f $ *.o

clean:
	rm -f $ *.o

fclean:
	rm -f *~
	rm -f *#
	rm -f *.a
	rm -f lib/my/*.a
	rm -f $(NAME)

re:
	fclean all
