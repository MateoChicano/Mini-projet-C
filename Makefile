# Nom de l'exécutable
EXEC = main

# Dossiers
SRC_DIR = src
INC_DIR = include
OBJ_DIR = build

# Liste des fichiers sources
SRC = $(wildcard $(SRC_DIR)/*.c)

# Fichiers objets correspondants
OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

# Compilateur et options
# CC = gcc
# CFLAGS = -Wall -Wextra -std=c11


# Règle principale
all: $(EXEC)

# Exécutable
$(EXEC): $(OBJ)
	gcc -I$(INC_DIR) -o $@ $^

# Compilation des .c en .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	gcc -I$(INC_DIR) -c $< -o $@

# Nettoyage
clean:
	rm -rf $(OBJ_DIR)