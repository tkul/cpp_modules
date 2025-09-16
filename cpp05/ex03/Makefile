NAME = Intern
CC = c++
CXX = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
clean:
	rm -f $(OBJ)
	rm -rf *_shrubbery
fclean: clean
	rm -f $(NAME)
	rm -rf *_shrubbery
re: fclean all

.PHONY: all clean fclean re