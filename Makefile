##
## EPITECH PROJECT, 2023
## makefile
## File description:
## task01
##

SRC =   *.c

OBJ =	$(SRC:.c=.o)

NAME = libmy.a

FLAGS = -g3

all:    $(NAME)

$(NAME):
	make -C lib/my
	make clean -C lib/my
	gcc -o mysh $(SRC) -L./lib/my -lmy $(FLAGS)

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
