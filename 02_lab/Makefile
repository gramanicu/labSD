# Copyright 2018 Grama Nicolae

# face coding-style automat, la standardul google, cu o mica modificare
# (4 spatii in loc de 2 la alineate)
beauty: 
	clang-format -i -style=file *.cpp *.h

.PHONY:beauty

FLAGS = -Wall -Wextra

complex: Complex.cpp clean

	g++ -o complex Complex.cpp $(FLAGS)

problema2: 
	g++ -o problema2 problema2.cpp $(FLAGS)

clean:
	rm -f complex

.PHONY:clean