#include "nodoChar.h"

#ifndef PILHACHAR_H
#define PILHACHAR_H
typedef struct pilhachar PilhaChar;

PilhaChar* New_PilhaChar();
NodoChar* PilhaChar_Pop(PilhaChar* pilha);
void PilhaChar_Push(PilhaChar* pilha, NodoChar* nodo);
int PilhaChar_Get_Size(PilhaChar* piha);
char PilhaChar_Peek(PilhaChar* pilha);

#endif // PILHA_H
