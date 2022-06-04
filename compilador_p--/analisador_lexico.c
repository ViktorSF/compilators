#include <stdio.h>
#include <stdlib.h>
#include "cabecalho.h"


void oi() // debugger que conheço
{
    printf("oi\n");
}
void casen(int n)
{
    printf("case %d\n", n);
}


 char* devolve_token(char c, FILE* entrada, int* s)
{
    printf("estado = %d\n", *s);
    switch(*s)
    {
        case 0 :
            casen(0);
            if(c == '\t' || c == '\n' || c == 39 )                      { *s = 0;  } // 39 na tabela ascii é a aspas simples '
            else if(c == ':')                                           { *s = 1;  }                     // como colocar aspas simples dentro de aspas simples ''' em c?
            else if(c == '<')                                           { *s = 4;  }
            else if(c == '=')                                           { *s = 8;  }
            else if(c == '>')                                           { *s = 11; }
            else if( (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ) { *s = 12; }
            else if(c == '+' || c == '-')                               { *s = 14; }
            else if(c >= '0' && c <= '9')                               { *s = 15; }
            else if(c == '{')                                           { *s = 20; }
            break;
        case 1 :
            casen(1);
            if(c == '=') { *s = 2; }
            else{ *s = 3; }
            break;
        case 2 :
            casen(2);
            if(c == EOF) { *s = 0; return ("simb_atrib"); }
            else{ return ("falha"); }
            break;
        case 3 :
            casen(3);
            if(c == EOF) { *s = 0; retroceder(entrada); return (":, simb_dp"); }
            else{ return ("falha"); }
            break;
        case 4 :
            casen(4);
            if(c == '=') { *s = 5; }
            else if(c == '>') { *s = 6; }
            break;
        case 5 :
            casen(5);
            *s = 0;
            return("<=, simb_menor_igual");
            break;
        case 6 :
            casen(6);
            *s = 0;
            return("<>, sim_dif");
            break;
        case 7 :
            casen(7);
            *s = 0;
            retroceder(entrada);
            return("<, simb_menor");
            break;
        case 8 :
            casen(8);
            *s = 0;
            return("=, simb_igual");
            break;
        case 9 :
            casen(9);
            *s = 0;
            return(">=, simb_maior_igual");
            break;
        case 10 :
            casen(10);
            *s = 0;
            retroceder(entrada);
            return(">, simb_maior");
            break;
        case 11 :
            casen(11);
            if(c == '=') { *s = 9; }
            else{ *s = 0; return ("falha"); }
            break;
        case 12 :
            casen(12);
            if( (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            {
                *s = 12;
            }else{ *s = 13; }
            break;
        case 13 :
            casen(13);
            *s = 0;
            retroceder(entrada);
            return("cadeia, id");
            break;
        case 14 :
            casen(14);
            if( c >= '0' && c <= '9')
            {
                *s = 15;
            } else{ *s = 0; return("falha"); }
            break;
        case 15 :
            casen(15);
            if(c == '.') {*s =  17; }
            else if ( ((c >= '0') && (c <= '9')) ) { s = 15; }
            else { *s = 16;}
            break;
        case 16 :
            casen(16);
            *s = 0;
            retroceder(entrada);
            return("cadeia, numero_inteiro");
            break;
        case 17 :
            casen(17);
            if(c >= '0' && c <= '9')
            {
                *s = 18;
            }else { *s = 0; return("falha"); }
            break;
        case 18 :
            casen(18);
            if(c >= '0' && c <= '9')
            {
                *s = 18;
            } else{ *s = 19; }
            break;
        case 19 :
            casen(19);
            *s = 0;
            retroceder(entrada);
            return("cadeia, numero_real");
            break;
        case 20 :
            casen(20);
            if(c == '}') { *s = 21; }
            else { *s = 20; }
            break;
        case 21 :
            casen(21);
            *s = 0;
            return("cadeia, comentario");
            break;
    }
    return ("");

}




void retroceder(FILE* entrada)
{
    //fseek(entrada, -1 , SEEK_CUR);
}
