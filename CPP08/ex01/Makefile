NAME = span

FLAGS = -std=c++98 -Wall -Wextra -Werror 

SRC = main.cpp Span.cpp

all: $(NAME)

$(NAME) : $(SRC)
	c++ $(FLAGS) $(SRC) -o $(NAME)

fclean: 
	rm -rf $(NAME)

re: fclean all