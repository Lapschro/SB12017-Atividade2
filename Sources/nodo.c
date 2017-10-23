#include "../Headers/nodo.h"
#include <stdint.h>
#include <stdlib.h>

typedef struct nodo{
    uint64_t valor;
    Typeof type;
    Nodo* prox;
}Nodo;

Nodo* New_Nodo(long long value, Typeof type){
    Nodo* aux = (Nodo*)malloc(sizeof(Nodo));
    aux->valor = value;
    aux->type = type;
    aux->prox = NULL;
    return aux;
}

long long Nodo_Get_Value(Nodo* nodo){
    return nodo->valor;
}

Typeof Nodo_Get_Type(Nodo* nodo){
    return nodo->type;
}

Nodo* Nodo_Get_Prox(Nodo* nodo){
    if(nodo == NULL)
        return NULL;
    return nodo->prox;
}

void Nodo_Add_Prox(Nodo* nodo, Nodo* prox){
    prox->prox = nodo;
}
