the_game.out:	main.o window.o
	tcc -o the_game main.o window.o -lglfw

main.o:		main.c window.h
	tcc -c main.c

window.o:	window.c window.h
	tcc -c window.c
