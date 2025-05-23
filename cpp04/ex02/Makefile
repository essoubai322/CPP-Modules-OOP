NAME = Animals

FLAGS = -std=c++98 -Wall -Werror -Wextra

SRC = main.cpp Animal.cpp Cat.cpp Dog.cpp Brain.cpp

all: $(NAME)

$(NAME): $(SRC)
	 c++ $(FLAGS) $(SRC) -o $(NAME)

fclean:
	rm -f $(NAME)

re: fclean all
.phony: all clean fclean re