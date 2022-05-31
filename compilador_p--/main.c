#include <stdio.h>
#include <stdlib.h>
#include "cabecalho.h"


int main()
{
    FILE* entrada;
    FILE* saida;

    entrada = fopen("meu_programa.txt", "r");
    saida = fopen("saida.txt", "w");








    fclose(entrada);
    fclose(saida);
    printf("Hello world!\n");
    oi();
    return 0;
}
