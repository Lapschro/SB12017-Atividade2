make all: grafos

grafos: main.o Aluno.o Alunos_Manager.o Lists.o Vector.o Vector_Node.o
	gcc main.o Aluno.o Alunos_Manager.o Lists.o Vector.o Vector_Node.o -o grafos -lm
	rm *.o
	rm Sources/*.o
	./grafos

main.o: Sources/main.c
	gcc -c -std=c99 Sources/main.c

Aluno.o: Sources/Aluno.c
	gcc -c -std=c99 Sources/Aluno.c

Alunos_Manager.o: Sources/Alunos_Manager.c
	gcc -c -std=c99 Sources/Alunos_Manager.c

Lists.o: Sources/Lists.c
	gcc -c -std=c99 Sources/Lists.c

Vector.o: Sources/Vector.c
	gcc -c -std=c99 Sources/Vector.c

Vector_Node.o: Sources/Vector_Node.o
	gcc -c -std=c99 Sources/Vector_Node.c

clean:
	rm grafos & rm *.o
