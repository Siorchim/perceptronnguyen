clean: perceptron
	rm -f *.o

perceptron: fichier.o correction.o gradient.o main.o 
	gcc -o perceptron fichier.o correction.o gradient.o main.o -Wall -ansi -pedantic -g -lm -lX11 -L/usr/include/X11/lib

fichier.o: fichier.c
	gcc -c fichier.c -Wall -ansi -pedantic -g -lm

correction.o: correction.c
	gcc -c correction.c -Wall -ansi -pedantic -g -lm

gradient.o: gradient.c
	gcc -c gradient.c -Wall -ansi -pedantic -g -lm

main.o: main.c
	gcc -c main.c -Wall -ansi -pedantic -g -lm -lX11 -L/usr/include/X11/lib


