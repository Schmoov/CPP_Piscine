CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98

NAME := sedIsBetterThanMe

SRC := main.cpp

all: $(NAME)
test: sed_tester

$(NAME): .obj/main.o .obj/bootsed.o
	$(CXX) $(CXXFLAGS) $^ -o $@

sed_tester: .obj/test.o .obj/bootsed.o
	$(CXX) $(CXXFLAGS) $^ -o $@

.obj/%.o : %.cpp
	@ mkdir -p .obj
	$(CXX) $(CXXFLAGS) -c $^ -o $@

clean:
	rm -rf .obj

fclean: clean
	rm -f $(NAME)
	rm -f sed_tester

re: fclean all

.PHONY: all clean fclean re test
