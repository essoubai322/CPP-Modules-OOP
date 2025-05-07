NAME = Zombie

FLAGS = -std=c++98 -Wall -Werror -Wextra

SRC = main.cpp \
		Zombie.cpp \
		newZombie.cpp \
		randomChump.cpp

all: $(NAME)

$(NAME): $(SRC)
	 c++ $(FLAGS) $(SRC) -o $(NAME)

fclean:
	rm -f $(NAME)

re: fclean all
.phony: all clean fclean re