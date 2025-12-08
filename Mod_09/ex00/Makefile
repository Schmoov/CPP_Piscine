CXX := c++ -g3
CXXFLAGS := -Wall -Wextra -Werror -std=c++98

NAME := btc

SRC := main.cpp BitcoinExchange.cpp db.cpp
OBJ := $(patsubst %.cpp, .obj/%.o, $(SRC))

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

.obj/%.o : %.cpp
	@ mkdir -p .obj
	$(CXX) $(CXXFLAGS) -c $^ -o $@

clean:
	rm -rf .obj

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
