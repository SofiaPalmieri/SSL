#include "scanner.h"

typedef enum
{
    e0_inicial,
    e1_cad,
    e2_sep,
    e3_esp,
    e4_fdt
} Estado;

token getToken(void);

token getToken(){
    static int estadoActual = e0_inicial;
    char caracter;
    while(caracter = getchar() != EOF){
        switch(estadoActual){
            case e0_inicial:
            if(isalpha(caracter) | ispunct(caracter) | isdigit(caracter)){
                estadoActual = e1_cad;
            }
            if(caracter == ','){
               estadoActual = e2_sep;
            }
            if(isspace(caracter)){
                estadoActual = e3_esp;
            }
            if(caracter == '\n'){
                estadoActual = e4_fdt;
                caracter = EOF;
                return fdt;
                break;
            }
            case e1_cad:
            if(isalpha(caracter) | ispunct(caracter) | isdigit(caracter)){
                estadoActual = e0_inicial;
                ungetc(caracter, stdin);
                return cad;
                break;
            }
            case e2_sep:
            if(caracter == ','){
                estadoActual = e0_inicial;
                ungetc(caracter, stdin);
                return sep;
                break;
            }
            case e3_esp:
            if(isspace(caracter)){
                estadoActual = e0_inicial;
                ungetc(caracter, stdin);
                return esp;
                break;
            }
            default:
            estadoActual = fdt;
            break;
        }
    }

}

