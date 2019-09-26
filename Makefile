all:
	gcc -Wall -Werror -fsanitize=address -std=c11 test.c -o test