CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98

NAME := ptdr

SRC := Account.cpp tests.cpp

all: $(NAME)

$(NAME):
	$(CXX) $(CXXFLAGS) $(SRC) -o $@

clean:

fclean:
	rm -f $(NAME)

re: fclean all

:PHONY all clean fclean re
