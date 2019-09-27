all: third

third: test.c
	gcc -Wall -Werror -fsanitize=address test.c -o test

clean:
	rm -rf test