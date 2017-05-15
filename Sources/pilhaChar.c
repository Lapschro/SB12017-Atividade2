#include "../Headers/pilhaChar.h"
#include <stdlib.h>

typedef struct pilhachar {
    NodoChar* ultimo;
    int size;
} PilhaChar;

PilhaChar* New_PilhaChar(){
    PilhaChar* aux = (PilhaChar*)malloc(sizeof(PilhaChar));
    aux->ultimo = NULL;
    aux->size = 0;
    return aux;
}

NodoChar* PilhaChar_Pop(PilhaChar* pilha){
    if(pilha == NULL)
        return NULL;
    if(pilha->size > 0){
        NodoChar* aux = pilha->ultimo;
        pilha->ultimo = NodoChar_Get_Prox(aux);
        pilha->size--;
        return aux;
    }
    return NULL;
}

void PilhaChar_Push(PilhaChar* pilha, NodoChar* nodo){
    NodoChar_Add_Prox(pilha->ultimo, nodo);
    pilha->ultimo = nodo;
    pilha->size++;
}

int PilhaChar_Get_Size(PilhaChar* pilha){
    if(pilha == NULL)
        return -1;
    return pilha->size;
}

char PilhaChar_Peek(PilhaChar* pilha){
    return NodoChar_Get_Value(pilha->ultimo);
}
