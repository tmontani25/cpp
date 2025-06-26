NAME = brainz

SRC = Zombie.cpp \
    newZombie.cpp \
    randomChump.cpp \
    main.cpp

# Fichiers objets
OBJ = $(SRC:.cpp=.o)

# Flags de compilation
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)


clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re