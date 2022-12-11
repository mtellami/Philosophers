NAME = philo
CFLAGS = -Wall -Wextra -Werror -pthread -I .
SRCS = philosophers.c \
	ft_printf/ft_printf.c ft_printf/ft_putchar_fd.c ft_printf/ft_putstr_fd.c \
	ft_printf/ft_putnbr_fd.c libft/ft_atol.c libft/ft_errors.c \
	srcs/initialize.c srcs/launch.c srcs/destroy.c srcs/routine.c \
	srcs/current_time.c srcs/eat.c srcs/is_dead.c srcs/state.c srcs/waiting.c \

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
		cc $(CFLAGS) $(OBJS) -o $(NAME)

clean :
		rm -fr $(OBJS)

fclean : clean
		rm -fr $(NAME)

re : fclean all