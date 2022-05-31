#include <stdio.h>
#include <stdlib.h>
#include "cabecalho.h"


int main()
{
    FILE* entrada;
    FILE* saida;
    char c, t[16]; // o maior token(simb_menor_igual) tem tamanho 16

    entrada = fopen("meu_programa.txt", "r");
    saida = fopen("saida.txt", "w");
    while(1)
    {
        c = fgetc(entrada);
        t = devolve_token(c, entrada);
    }







    fclose(entrada);
    fclose(saida);
    printf("Hello world!\n");
    oi();
    return 0;
}
