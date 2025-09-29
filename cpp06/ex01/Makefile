NAME = Serializer

FLAGS = -std=c++98 -Wall -Wextra -Werror 

SRC = main.cpp Serializer.cpp

all: $(NAME)

$(NAME) : $(SRC)
	c++ $(FLAGS) $(SRC) -o $(NAME)

fclean: 
	rm -rf $(NAME)

re: fclean all