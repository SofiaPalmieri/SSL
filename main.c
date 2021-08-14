#include "scanner.h"

int main(void){
    token unToken;
    unToken = getToken();
    switch(unToken){
    case cad:
    printf("Cadena: %s", cad);
    break;
    case sep:
    printf("Separador: %s", sep);
    break;
    case fdt:
    printf("Fin de Texto: %s, fdt");
    break;
    default:
    break;
}
return 0;
}