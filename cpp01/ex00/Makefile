NAME = brainz

# Fichiers source
SRC = Zombie.cpp \
    newZombie.cpp \
    randomChump.cpp \
    main.cpp

# Fichiers objets
OBJ = $(SRC:.cpp=.o)

# Flags de compilation
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Règle par défaut
all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

# Nettoyer les fichiers objets
clean:
	rm -f $(OBJ)

# Nettoyer tout (objets + exécutable)
fclean: clean
	rm -f $(NAME)

# Recompiler à partir de zéro
re: fclean all

.PHONY: all clean fclean re