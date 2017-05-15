#ifndef NODOCHAR_H
#define NODOCHAR_H

typedef struct nodochar NodoChar;


NodoChar* New_NodoChar(char value);
char NodoChar_Get_Value(NodoChar* nodo);
NodoChar* NodoChar_Get_Prox(NodoChar* nodo);
void NodoChar_Add_Prox(NodoChar* nodo, NodoChar* prox);

#endif // NODO_H
