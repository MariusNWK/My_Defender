##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC	=	$(wildcard *.c)

OBJ	=	$(SRC:.c=.o)

NAME	=	my_defender

CFLAGS	=	-I./ -l csfml-audio -l csfml-graphics -l csfml-system -l csfml-window

all:	$(NAME)

$(NAME):	$(OBJ)
	$(MAKE) -C ./lib/my/
	$(CC) -g -o $(NAME) $(OBJ) lib/my/libmy.a $(CFLAGS)

clean:
	$(MAKE) -C ./lib/my/ clean
	$(RM) *.o

fclean: clean
	$(MAKE) -C ./lib/my/ fclean
	$(RM) $(NAME)

re:	fclean all

.Phony: all clean fclean re
