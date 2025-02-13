CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98

NAME := hello_kitty

SRC := PhoneBook.cpp Contact.cpp main.cpp
OBJ := $(patsubst %.cpp, %.o, $(SRC))

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $^ -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

:PHONY all clean fclean re
