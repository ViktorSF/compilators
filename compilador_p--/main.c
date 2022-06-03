#include <stdio.h>
#include <stdlib.h>
#include "cabecalho.h"
#include <windows.h>

int main()
{

    FILE* entrada;
    FILE* saida;
    char c, t[16]; // o maior token(simb_menor_igual) tem tamanho 16

    entrada = fopen("entrada.txt", "r");
    saida = fopen("saida.txt", "w");
    do
    {
        c = fgetc(entrada);
        strcpy( t, devolve_token(c, entrada) );
        fputs(t, saida);
    }while(c != EOF);






    fclose(entrada);
    fclose(saida);
    oi();
    return 0;
}
