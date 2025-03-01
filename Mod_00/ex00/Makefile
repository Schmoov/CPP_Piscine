CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98

NAME := megaphone
SRC := megaphone.cpp

all: $(NAME)

$(NAME): $(SRC)
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:

fclean: clean
	rm -f $(NAME)

re: fclean all

:PHONY all clean fclean re
