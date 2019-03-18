# Copyright 2019 Grama Nicolae

.PHONY: gitignore check purge clean memory update beauty pack run
.SILENT: purge update beauty pack clean memory gitignore

# Informatii program
CC = g++
CFLAGS = -Wall -Wextra -pedantic -O3
#FLAGS = -lm
EXE = lab4
SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)


# Compilarea programului
build: $(OBJ)
	$(info Compiling code...)
	@$(CC) -o $(EXE) $^ $(LFLAGS) $(CFLAGS) ||:
	$(info Compilation successfull)
	-@rm -f *.o ||:
	@$(MAKE) -s gitignore ||:

# Ruleaza programul
run: build
		./$(EXE)

# Sterge executabilul si fisierele obiect
clean:
	rm -f $(EXE) $(OBJ)
	echo "Deleted the binary and object files"

# Face coding-style automat, la standardul google, cu o mica modificare
# (4 spatii in loc de 2 la alineate)
beauty:
	clang-format -i -style=file *.cpp *.h

# Verifica memoria pentru leak-uri
MFLAGS = --leak-check=full --show-leak-kinds=all 
memory:build
	valgrind $(MFLAGS) ./$(EXE)

# Sterge toate fisierele care nu o sa apara in repository
purge:
	rm -f $(EXE) $(OBJ)
	echo "All files were removed"

# Adauga toate fisierele care nu trebuie sa fie include in repository
# la .gitignore
gitignore:
	@echo "$(EXE)" > .gitignore ||:
	@echo ".vscode*" >> .gitignore ||:	
	@find . -executable -type f -not -path "*/.git/*" | cut -c 3- >>.gitignore ||:
	echo "Updated .gitignore"
