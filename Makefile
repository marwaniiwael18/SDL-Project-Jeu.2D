prog: main.o
	gcc main.c -I /usr/local/include/ -L /usr/local/lib/ -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -o main
main.o:main.c
	gcc -c main.c
