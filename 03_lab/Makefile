# Copyright 2018 Grama Nicolae

build: ex1.cpp ex2.cpp ex3.cpp
	g++ -o ex1 ex1.cpp -Wall -Wextra
	g++ -o ex2 ex2.cpp -Wall -Wextra
	g++ -o ex3 ex3.cpp -Wall -Wextra

# face coding-style automat, la standardul google, cu o mica modificare
# (4 spatii in loc de 2 la alineate)
beauty: 
	clang-format -i -style=file *.cpp *.h

.PHONY:beauty

FLAGS = -Wall -Wextra -Wno-unused-parameter -std=c++11 -g

clean:
	rm -f complex

.PHONY:clean