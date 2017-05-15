make all: calculadora

calculadora: main.o Interpret.o nodo.o pilha.o nodoChar.o pilhaChar.o
	gcc main.o Interpret.o nodo.o pilha.o nodoChar.o pilhaChar.o -o calculadora 

main.o: Sources/main.c
	gcc -c -std=c99 Sources/main.c

Interpret.o: Sources/Interpret.c
	gcc -c -std=c99 Sources/Interpret.c

nodo.o: Sources/nodo.c
	gcc -c -std=c99 Sources/nodo.c

pilha.o: Sources/pilha.c
	gcc -c -std=c99 Sources/pilha.c
	
nodoChar.o: Sources/nodoChar.c
    gcc -c -std=c99 Sources/nodoChar.c

pilhaChar.o: Sources/pilhaChar.c
    gcc -c -std=c99 Sources/pilhaChar.c	
	
clean:
	rm calculadora
	rm *.o
	rm Sources/*.o