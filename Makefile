target: main

main: main.o arvore.o busca.o lista.o tempo.o 
	gcc main.o arvore.o busca.o lista.o tempo.o -o main

main.o: main.c busca.h lista.h arvore.h tempo.h
	gcc -c main.c
arvore.o: arvore.c arvore.h
	gcc -c arvore.c
busca.o: busca.c busca.h arvore.h lista.h
	gcc -c busca.c
lista.o: lista.c lista.h
	gcc -c lista.c
tempo.o: tempo.c tempo.h
	gcc -c tempo.c

clean:
	rm -f *.o main
	