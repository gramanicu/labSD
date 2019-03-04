# Copyright 2018 Grama Nicolae

# face coding-style automat, la standardul google, cu o mica modificare
# (4 spatii in loc de 2 la alineate)
beauty: 
	clang-format -i -style=file *.cpp *.h

.PHONY:beauty

FLAGS = -Wall -Wextra -Wno-unused-parameter -std=c++11 -g

complex: Complex.cpp clean
	g++ -o complex Complex.cpp $(FLAGS)

cardgame: Cardgame.cpp clean
	g++ -o cardgame Cardgame.cpp $(FLAGS)

runCard: cardgame
	./cardgame < cardgame.in > cardgame.out

clean:
	rm -f complex

.PHONY:clean