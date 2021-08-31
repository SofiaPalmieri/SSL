#include "scanner.h"

void getToken(void);

void printToken(char *, int *);

void getToken()
{
    static int estadoActual = e0_inicial;
    char caracter;
    caracter = getchar();
    char cadena[300];
    cadena[0] = '\0';
    int dim = 0;
    while (caracter != EOF)
    {
        switch (estadoActual)
        {
        case e0_inicial:
            if ((caracter != ',') && (!isspace(caracter)) && (caracter != '\n'))
            {
                caracter = getchar();
                cadena[dim] = caracter;
                dim++;
                estadoActual = e1_cad;
            }

            if (caracter == ',')
            {
                caracter = getchar();
                cadena[dim - 1] = '\0';
                printToken(cadena, &dim);
                cadena[dim] = caracter;
                dim++;
                estadoActual = e2_sep;
                printf("Separador: ,\n");
            }
            if (isspace(caracter))
            {
                caracter = getchar();
                cadena[dim - 1] = '\0';
                printToken(cadena, &dim);
                cadena[dim] = caracter;
                dim++;
            }
            if (caracter == '\n')
            {
                printToken(cadena, &dim);
                estadoActual = e3_fdt;
            }
        case e1_cad:

            ungetc(caracter, stdin);
            caracter = getchar();
            estadoActual = e0_inicial;
            break;

        case e2_sep:

            ungetc(caracter, stdin);
            caracter = getchar();
            estadoActual = e0_inicial;
            break;

        case e3_fdt:
            ungetc(caracter, stdin);
            caracter = EOF;
            break;
        }
    }
    cadena[dim] = '\0';
    printf("Cadena: %s\n", cadena);
    printf("Fin de Texto: \n");
}

void printToken(char *cadena, int *dim)
{
    if (strcmp(cadena, "\0"))
    {
        printf("Cadena: %s\n", cadena);
    }
    *dim = 0;
    cadena[0] = '\0';
}