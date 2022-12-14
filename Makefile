NAME = philo
CFLAGS = -Wall -Wextra -Werror -pthread -I includes
SRC = philos/philo.c \
	philos/actions.c philos/destroy.c philos/ft_atol.c philos/ft_errors.c \
	philos/initialize.c philos/is_dead.c philos/is_over.c philos/launch.c \
	philos/ptime.c philos/routine.c philos/state.c philos/waiting.c \

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
		cc $(CFLAGS) $(OBJ) -o $(NAME)

clean :
		rm -fr $(OBJ)

fclean : clean
		rm -fr $(NAME)

re : fclean all