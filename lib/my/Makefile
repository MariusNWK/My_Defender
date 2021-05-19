##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC	=	$(wildcard *.c)

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

CFLAGS	=	-I../../include/

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	$(RM) *.o
	$(RM) *~

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.Phony: all clean fclean re
