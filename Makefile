# Nom de l'exécutable
EXEC = main

# Liste des fichiers sources
SRC = main.c chiffrement.c dechiffrement.c misc.c verification.c

# Fichiers objets correspondants
OBJ = $(SRC:.c=.o)

# Compilateur et options
CC = gcc
CFLAGS = -Wall -Wextra -std=c11

# Règle par défaut
all: $(EXEC)

# Règle de l'exécutable
$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Règle de compilation des fichiers .c en .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Nettoyage des fichiers objets et de l'exécutable
clean:
	rm -f *.o $(EXEC)