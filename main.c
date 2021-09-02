#include "scanner.h"

int main(void)
{
    Token token;
    char buffer[300];

    token = getToken(buffer);

    while (token != fdt)
    {
        if (token == cad)
        {
            printf("Cadena: ");
        }
        else if (token == sep)
        {
            printf("Separador: ");
        }
        printf("%s\n", buffer);

        token = getToken(buffer);
    }

    printf("Fin de texto: \n");
}