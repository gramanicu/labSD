# Copyright 2018 Grama Nicolae

# face coding-style automat, la standardul google, cu o mica modificare
# (4 spatii in loc de 2 la alineate)
beauty: 
	clang-format -i -style=file */*.c */*.h

.PHONY:beauty