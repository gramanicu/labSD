# Copyright 2019 Grama Nicolae

.PHONY: clean gitignore beauty

CC = g++
CFLAGS = -Wall -Wextra -pedantic -O3 -Wno-unused-result -g
EXE = grafuri
SRC = $(wildcard *.cpp)
OBJ = $(SRC:.c=.o)

# compilarea programului
build: $(OBJ)
	$(CC) -o $(EXE) $^ $(CFLAGS)
	rm -f *.o
	make gitignore

run: build	
	./$(EXE)

clean: 
	rm -f *.o

gitignore:
	find . -executable -type f -not -path "*/.git/*" | cut -c 3- >.gitignore

beauty: 
	clang-format -i -style=file */*.cpp */*.h

.PHONY:beauty