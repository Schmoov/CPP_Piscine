CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98

NAME := megaphone

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CXX) $(CXXFLAGS) $@.cpp -o $@

clean:

fclean: clean
	rm -f $(NAME)

re: fclean all

:PHONY all clean fclean re
