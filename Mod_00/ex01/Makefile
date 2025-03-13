CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98

NAME := hello_kitty

SRC := src/PhoneBook.cpp src/Contact.cpp src/main.cpp
OBJ := $(patsubst src/%.cpp, .obj/%.o, $(SRC))
INC := -Iinc

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(INC) $^ -o $@

.obj/%.o : src/%.cpp
	@ mkdir -p .obj
	$(CXX) $(CXXFLAGS) $(INC) -c $^ -o $@

clean:
	rm -rf .obj

fclean: clean
	rm -f $(NAME)

re: fclean all

:PHONY all clean fclean re
