#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "scanner.h"

typedef enum
{
    e0_inicial,
    e1_cad,
    e2_sep,
    e3_fdt
} Estado;

token getToken(void);

token getToken(void){
    static estadoActual = e0_inicial;
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
            if(caracter == "\n"){
                estadoActual = e3_fdt;
                caracter = EOF;
                return fdt;
                break;
            }
        }
    }

}

