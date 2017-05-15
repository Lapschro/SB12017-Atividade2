#ifndef NODO_H
#define NODO_H

typedef struct nodo Nodo;

typedef enum {VAL = 0, SUM, SUB, MUL, DIV} Typeof;

Nodo* New_Nodo(long long value, Typeof type);
long long Nodo_Get_Value(Nodo* nodo);
Typeof Nodo_Get_Type(Nodo* nodo);
Nodo* Nodo_Get_Prox(Nodo* nodo);
void Nodo_Add_Prox(Nodo* nodo, Nodo* prox);

#endif // NODO_H
