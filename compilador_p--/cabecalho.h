#ifndef CABECALHO_H_INCLUDED
#define CABECALHO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

void oi(); // tipo de debugger, pode-se distribuir pelo codigo para verificar onde esta dando erro
void retroceder(FILE* entrada);
char* devolve_token(char c, FILE* entrada);

#endif // CABECALHO_H_INCLUDED
