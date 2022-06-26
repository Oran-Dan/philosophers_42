SRC = helpers.c \
list.c \
thrd.c \
philo.c

OBJ =	${SRC:.c=.o}

NAME =	philo

all:		${NAME}

${NAME}:	${OBJ}
				gcc -Wall -Werror -Wextra ${OBJ} -o $@

.c.o:	
		gcc -Wall -Werror -Wextra -c $< -o $@

clean:		
			rm -rf *.o

fclean:		
			rm -rf *.o ${NAME}

re:			fclean all

.PHONY: all clean fclean re