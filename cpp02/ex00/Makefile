NAME = main

FLAGS = -std=c++98 -Wall -Werror -Wextra

SRC = main.cpp Fixed.cpp

OBJ = $(SRC:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	 c++ $(FLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
.phony: all clean fclean re