build:
	gcc -Wall -Wextra src/*.c -lSDL2 -o game
clean:
	rm game
run:
	./game
