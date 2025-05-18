CC = gcc
CFLAGS = -Wall -Wextra -Werror -g


SRCS = philo.c helper.c init_data.c parssing.c

OBJECTS = $(SRCS:.c=.o)

NAME = philo


all : $(NAME)


$(NAME) : $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

%.o: %.c philo.h
	$(CC) $(CFLAGS) -o $@ -c $<


clean :
	rm -rf $(OBJECTS)

fclean : clean
	rm -rf $(NAME)


re :fclean all

.PHONY : all clean fclean re

