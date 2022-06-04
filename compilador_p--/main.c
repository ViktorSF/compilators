#include <stdio.h>
#include <stdlib.h>
#include "cabecalho.h"


int main()
{

    FILE* entrada;
    FILE* saida;
    char c, t[32]; // o maior token(simb_menor_igual) tem tamanho 16
    int *s;
    s = (int*) malloc(sizeof(int));
    entrada = fopen("entrada.txt", "r");
    saida = fopen("saida.txt", "w");
    *s = 0;
    do
    {
        c = fgetc(entrada);
        printf("%c", c);
        strcpy( t , devolve_token(c, entrada, s) );

        printf("%s\n",t);
        fputs(t, saida);
    }while(c != EOF);


    free(s);
    fclose(entrada);
    fclose(saida);
    return 0;
}
