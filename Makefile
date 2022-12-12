NAME = philo
CFLAGS = -Wall -Wextra -Werror -pthread -I .
SRCS = philosophers.c \
	libft/ft_atol.c libft/ft_errors.c srcs/initialize.c srcs/launch.c \
	srcs/destroy.c srcs/routine.c srcs/utils/current_time.c srcs/actions.c \
	srcs/utils/is_dead.c srcs/utils/state.c srcs/utils/waiting.c \

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
		cc $(CFLAGS) $(OBJS) -o $(NAME)

clean :
		rm -fr $(OBJS)

fclean : clean
		rm -fr $(NAME)

re : fclean all