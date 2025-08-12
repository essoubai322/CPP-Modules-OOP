NAME = Form

FLAGS = -std=c++98 -Wall -Wextra -Werror 

SRC = main.cpp Bureaucrat.cpp Form.cpp

all: $(NAME)

$(NAME) : $(SRC)
	c++ $(FLAGS) $(SRC) -o $(NAME)

fclean: 
	rm -rf $(NAME)

re: fclean all