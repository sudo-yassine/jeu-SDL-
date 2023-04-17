prog:main.o enigme.o temps.o enigme.h temps.h
	gcc main.o enigme.o temps.o -lSDL -lSDL_image -lSDL_ttf -o prog -g 
temps.o:temps.c
	gcc -c temps.c -g
enigme.o:enigme.c
	gcc -c enigme.c -g
main.o:main.c
	gcc -c main.c -g
