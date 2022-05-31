#include "cabecalho.h"

void oi() // debugger que conheço
{
    printf("oi\n");
}

 char* devolve_token(char c, FILE* entrada)
{
    int s = 0; // estado inicial
    switch(s)
    {
        case 0 :
            if(c == '\t' || c == '\n' || c == 39 ){ s = 0; } // 39 na tabela ascii é a aspas simples '
            else if(c == ':') { s = 1; }                     // como colocar aspas simples dentro de aspas simples ''' em c?
            else if(c == '<') { s = 4; }
            else if(c == '=') { s = 8; }
            else if(c == '>') { s = 11;}
            else if(c == '+' || c == '-') { s = 14; }
            else if(c == '{') { s = 20;}
            for(int i = 0; i<= 9; i++)
            {
                if(c == '0'+ i) { s = 15; break;}
            }
            break;
        case 1 :
            if(c == '=') { s = 2; }
            else{ s = 3; }
            break;
        case 2 :
            if(c == EOF) { return ("simb_atrib"); }
            else{ return ("falha"); }
            break;
        case 3 :
            if(c == EOF) { retroceder(entrada); return ("simb_dp"); }
            else{ return ("falha"); }
            break;
        case 4 :
            if(c == '=') { s = 5; }
            else if(c == '>') { s = 6; }
            break;
        case 5 :
            break;
        case 6 :
            break;
        case 7 :
            break;
        case 8 :
            break;
        case 9 :
            break;
        case 10 :
            break;
        case 11 :
            if(c == '=') { s = 9; }
            else{ return ("falha"); }
            break;
        case 12 :
            int flag = 0;
            for(int i = 0; i < 26; i++ ){
                if(c == ('A' + i) ||c == ('a' + i) )
                {
                    s = 12;
                    flag = 1;
                    break;
                }

            }
            for(int i = 0; i <= 9; i++)
            {
                if(c == '0'+ i)
                {
                    s = 12;
                    flag = 1;
                    break;
                }
            }
            if(flag == 0) { s = 13; }
            break;
        case 13 :
            break;
        case 14 :
            int flag = 0;
            for(int i = 0; i <= 9; i++)
            {
                if(c == '0' + i)
                {
                    s = 15;
                    flag = 1;
                    break;
                }
            }
            if(flag == 0 ) { return("falha"); }
            break;
        case 15 :
            if(c == '.') {s =  17; }
            else { s = 16;}
            break;
        case 16 :
            break;
        case 17 :
            int flag = 0;
            for(int i = 0; i <= 9; i++)
            {
                if(c == '0' + i)
                {
                    s = 15;
                    flag = 1;
                    break;
                }
            }
            if(flag == 0 ) { return("falha"); }
            break;
        case 18 :
            break;
        case 19 :
            break;
        case 20 :
            if(c == '}') {s = 21;}
            else { s = 20; }
            break;
        case 21 :
            break;
    }
}




void retroceder(FILE* entrada)
{
    fseek(entrada, -1 , SEEK_CUR);
}
