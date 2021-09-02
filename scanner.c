#include "scanner.h"

Token getToken(char *);

Token getToken(char *buffer)
{
    int dim = 0;
    char caracter = getchar();

    while (caracter != EOF)
    {
        if (caracter == ',')
        {
            buffer[dim] = caracter;
            dim++;
            buffer[dim] = '\0';
            return sep;
        }

        if (isspace(caracter))
        {
            caracter = getchar();
        }

        if ((!isspace(caracter)) && (caracter != ',') && (caracter != EOF))
        {
            while ((!isspace(caracter)) && (caracter != ',') && (caracter != EOF))
            {
                buffer[dim] = caracter;
                dim++;
                caracter = getchar();
            }
            ungetc(caracter, stdin);
            buffer[dim++] = '\0';
            return cad;
        }
    }
    buffer[dim] = '\0';
    return fdt;
}
