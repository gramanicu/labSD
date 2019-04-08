# Copyright 2018 Grama Nicolae

main:
	@echo "Not a valid command. To ingore all executables from git, use the following commands"
	@echo "	excludeA - will append the files to exclude to .gitignore" 
	@echo "	excludeO - will overwrite .gitignore with the files to exclude"
	@echo "The modified .gitignore file is the one in the root folder (ludum)"

excludeA: 
	find . -executable -type f -not -path "*/.git/*" | cut -c 3- >>.gitignore
	.vscode >> .gitignore
excludeO:
	find . -executable -type f -not -path "*/.git/*" | cut -c 3- >.gitignore
	.vscode >> .gitignore

.PHONY: excludeA excludeO

# face coding-style automat, la standardul google, cu o mica modificare
# (4 spatii in loc de 2 la alineate)
beauty: 
	clang-format -i -style=file */*.cpp */*.h

.PHONY:beauty