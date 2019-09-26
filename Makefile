all: test

test: test.c
	gcc -Wall -Werror -fsanitize=address -std=c11 test.c -o test

clean:
	rm -rf test
