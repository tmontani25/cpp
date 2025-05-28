NAME = zombieHorde

# Source files
SRC = main.cpp \
    Zombie.cpp \
    zombieHorde.cpp

# Object files
OBJ = $(SRC:.cpp=.o)

# Compiler and flags
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Default target
all: $(NAME)

# Linking
$(NAME): $(OBJ)
		$(CXX)	$(CXXFLAGS) $(OBJ) -o $(NAME)

# Cleaning targets
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

# Rebuild
re: fclean all

.PHONY: all clean fclean re

