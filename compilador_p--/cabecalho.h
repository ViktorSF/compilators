#ifndef CABECALHO_H_INCLUDED
#define CABECALHO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

void oi(); // debugger por força bruta
void retroceder(FILE* entrada);
char* devolve_token(char c, FILE* entrada, int* s);
void casen(int n);

#endif // CABECALHO_H_INCLUDED
