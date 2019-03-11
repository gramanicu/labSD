# Copyright 2018 Grama Nicolae
FLAGS = -Wall -Wextra -Wno-unused-parameter -std=c++11 -g1

build: ex1.cpp ex2.cpp ex3.cpp
	g++ -o ex1 ex1.cpp ex1.h $(FLAGS)
	g++ -o ex2 ex2.cpp $(FLAGS)
	g++ -o ex3 ex3.cpp $(FLAGS)

# face coding-style automat, la standardul google, cu o mica modificare
# (4 spatii in loc de 2 la alineate)
beauty: 
	clang-format -i -style=file *.cpp *.h

.PHONY:beauty


clean:
	rm -f ex1
	rm -f ex2
	rm -f ex3

.PHONY:clean