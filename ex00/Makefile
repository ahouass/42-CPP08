CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = easyfind
SRC = main.cpp
OBJ = $(SRC:.cpp=.o)
all: $(NAME)

$(NAME): $(OBJ) easyfind.hpp
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re