#include "cabecalho.h"

void oi() // debugger que conhe�o
{
    printf("oi\n");
}

 char* devolve_token(char c, FILE* entrada, char* cadeia)
{
    int s = 0; // estado inicial

    switch(s)
    {
        case 0 :
            if(c == '\t' || c == '\n' || c == 39 ){ s = 0; } // 39 na tabela ascii � a aspas simples '
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
            if(c == EOF) { retroceder(entrada); return (":, simb_dp"); }
            else{ return ("falha"); }
            break;
        case 4 :
            if(c == '=') { s = 5; }
            else if(c == '>') { s = 6; }
            break;
        case 5 :
            return("<=, simb_menor_igual");
            break;
        case 6 :
            return("<>, sim_dif");
            break;
        case 7 :
            retroceder(entrada);
            return("<, simb_menor");
            break;
        case 8 :
            return("=, simb_igual")
            break;
        case 9 :
            return(">=, simb_maior_igual")
            break;
        case 10 :
            retroceder(entrada);
            return(">, simb_maior");
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
            retroceder(entrada);
            return("cadeia, id");
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
            retroceder(entrada);
            return("cadeia, numero_inteiro");
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
            for(int i = 0; i <= 9; i++)
            {
                if(c == '0'+ i)
                {
                    s = 12;
                    flag = 1;
                    break;
                }
            }
            if(flag == 0) { s = 19;
            } else{ s = 18; }
            break;
        case 19 :
            retroceder(entrada);
            return("cadeia, numero_real");
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
