#include "../Headers/Interpret.h"
#include "../Headers/nodoChar.h"
#include "../Headers/pilhaChar.h"
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    uint64_t field:48;
}uint48_t;

int Is_Op(char c);
void Add_Operation(char c);
/*
//-----------------OPERAÇÕES--------------------
long long adicionar(long long a, long long b){
    uint48_t ax, bx;
    ax.field =a;
    bx.field = b;
    return ax.field+bx.field;
}

long long subtrair(long long a, long long b){
    uint48_t ax, bx;
    ax.field =a;
    bx.field = b;
    return ax.field-bx.field;
}

long long dividir(long long a, long long b){
    return a/b;
}

long long multiplicar(long long a, long long b){
    uint48_t ax, bx;
    ax.field =a;
    bx.field = b;
    return ax.field*bx.field;
}
*/
long long adicionar(long long a, long long b){
    return a+b;
}

long long subtrair(long long a, long long b){
    return a-b;
}

long long dividir(long long a, long long b){
    return a/b;
}

long long multiplicar(long long a, long long b){
    return a*b;
}



long long numero(Nodo* a){
    return Nodo_Get_Value(a);
}

int checkUnary(char* base, int offset){
	
	//printf("Checking if unary\n");
	if(offset == 1){
		return 1;
	}
	if(Is_Op(base[offset - 1]) || base[offset - 1] == '(' || base[offset - 1] == ')'){
		return 1;
	}
	return 0;
}


int classifica_Op(char letra, char letra_atual){
    int prioLetra = 0, prioLetra_atual = 0;

  if(letra == '*' || letra == '/')
    prioLetra = 5;
  else if(letra == '+' || letra == '-')
    prioLetra = 0;
  else if(letra == '(')
    prioLetra = 3;


  if(letra_atual == '*' || letra_atual == '/')
    prioLetra_atual = 5;
  else if(letra_atual == '+' || letra_atual == '-')
    prioLetra_atual = 0;
  else if(letra_atual == '(')
    prioLetra_atual = 0;

    return (prioLetra - prioLetra_atual);
}

//-----------------------------------------------


//Ponteiro para cada tipo de operacao
long long (*list_of_operations[4]) (long long, long long) = {adicionar, subtrair, multiplicar, dividir};

static Pilha* pilha;

//Interpreta a expressao passada, transformando-a em notacao Polonesa Reversa e faz a avaliacao da pilha
long long Interpret(char* expressao){
    pilha = New_Pilha();

    PilhaChar* pilhaOp = New_PilhaChar();
    int check = 0;
    char c;
    char newExpressao[300];

    newExpressao[0] = '(';
    strcpy(newExpressao+1, expressao);
    newExpressao[strlen(newExpressao)+1] = 0;
    newExpressao[strlen(newExpressao)] = ')';
    strcpy(expressao, newExpressao);

    printf("%s\n", expressao);

    for(int i = 0; i < strlen(expressao);){
        c = expressao[i];
        //printf("%c\n", c);
        check = 0;
        if(Is_Op(c)){
			if(c == '-'){
				if(checkUnary(expressao, i)){
					Pilha_Push(pilha, New_Nodo(-atoll(expressao + ++i), VAL));
					check = 1;
				}
			}else{
				while(PilhaChar_Get_Size(pilhaOp) > 0 && Is_Op(PilhaChar_Peek(pilhaOp))){
					if(classifica_Op(c, PilhaChar_Peek(pilhaOp)) <= 0){
						NodoChar* aux = PilhaChar_Pop(pilhaOp);
						Add_Operation(NodoChar_Get_Value(aux));
						free(aux);
						continue;
					}
					break;
				}
				PilhaChar_Push(pilhaOp, New_NodoChar(c));
			}
        }else if (c == '('){
            PilhaChar_Push(pilhaOp, New_NodoChar(c));
        }else if(c == ')'){
            while(PilhaChar_Get_Size(pilhaOp) > 0 && PilhaChar_Peek(pilhaOp) != '('){
                NodoChar* aux = PilhaChar_Pop(pilhaOp);
                Add_Operation(NodoChar_Get_Value(aux));
                free(aux);
            }
            free(PilhaChar_Pop(pilhaOp));
        }else{
            Pilha_Push(pilha, New_Nodo(atoll(expressao + i), VAL));
            check = 1;
        }
        if(check){
            while(expressao[i] <= '9' && expressao[i] >= '0')
                i++;
        }else
            i++;
    }

/*****************************************/
	/*printf("Dump:\n");
    Pilha_Dump(pilha);
	printf("\n");*/
    long long value = Evaluate(Pilha_Pop(pilha));
    free(pilha);
    return  value;
}
//Faz a avaliacao do nodo e retorna o valor da avaliacao
long long Evaluate(Nodo* a){
    //Se o nodo for do tipo operacao é avaliado o lado direito e esquerdo
    //e entao é retornado o resultado da operacao
    if(Nodo_Get_Type(a)){
        Nodo* aux = Pilha_Pop(pilha);
        //Avalia o lado direito
        long long right = Evaluate(aux);
        free(aux);
        //Avalia o lado esquerdo
        aux = Pilha_Pop(pilha);
        long long left = Evaluate(aux);
        free(aux);
        //Executa a operação
        long long res = list_of_operations[Nodo_Get_Type(a) - 1](left, right);
        //free(a);
        //Checa se o numero a retornar deve ser negativo
        //res |= ((res>>47)&1)?0xffff000000000000:0x0;
        return res;
    }else{
        //Se o tipo for Valor então retorna o valor.
        return Nodo_Get_Value(a);
    }
}

int Is_Op(char c){
    return c == '+'||c == '-'||c == '*'||c == '/';
}

void Add_Operation(char c){
switch(c){
    case '+':
        Pilha_Push(pilha, New_Nodo(0, SUM));
        break;
    case '-':
        Pilha_Push(pilha, New_Nodo(0, SUB));
        break;
    case '*':
        Pilha_Push(pilha, New_Nodo(0, MUL));
        break;
    case '/':
        Pilha_Push(pilha, New_Nodo(0, DIV));
        break;
    }
}
