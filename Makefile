NAME = philo
BONUS = philo_bonus
CFLAGS = -Wall -Wextra -Werror -pthread -I includes
SRCS = philos/philo.c \
	libft/ft_atol.c libft/ft_errors.c philos/initialize.c philos/launch.c \
	philos/destroy.c philos/routine.c philos/utils/current_time.c philos/actions.c \
	philos/utils/is_dead.c philos/utils/state.c philos/utils/waiting.c \

B_SRCS = philos_bonus/philo_bonus.c \
	libft/ft_atol.c libft/ft_errors.c \


OBJS = $(SRCS:.c=.o)

B_OBJS = $(B_SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
		cc $(CFLAGS) $(OBJS) -o $(NAME)

bonus : $(BONUS)

$(BONUS) : $(B_OBJS)
		cc $(CFLAGS) $(B_OBJS) -o $(BONUS)

clean :
		rm -fr $(OBJS) $(B_OBJS)

fclean : clean
		rm -fr $(NAME) $(BONUS)

re : fclean all