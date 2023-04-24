prog:main.o background.o
	gcc main.o background.o -o prog -lSDL_image -lSDL_ttf -lSDL_mixer -lSDL
main.o:main.c
	gcc -c main.c 
background.o:background.c
	gcc -c background.c
