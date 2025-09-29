NAME = Base

FLAGS = -std=c++98 -Wall -Wextra -Werror 

SRC = main.cpp Base.cpp

all: $(NAME)

$(NAME) : $(SRC)
	c++ $(FLAGS) $(SRC) -o $(NAME)

fclean: 
	rm -rf $(NAME)

re: fclean all