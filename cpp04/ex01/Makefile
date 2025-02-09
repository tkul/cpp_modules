NAME = animal
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp \
       Animal.cpp \
       Dog.cpp \
       Cat.cpp \
       Brain.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean res