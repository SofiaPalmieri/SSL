#include "scanner.h"

typedef enum {
    e0_inicial,
    e1_cad,
    e2_sep,
    e3_fdt
} Estado;

void getToken(void);

void getToken()
{
    static int estadoActual = e0_inicial;
    char caracter;
    caracter = getchar();
    while (caracter != EOF)
    {
        switch (estadoActual)
        {
        case e0_inicial:
            if ((caracter != ',') && (caracter != ' ') && (caracter != '\n'))
            {
                printf("Cadena: ");
                estadoActual = e1_cad;
            }
            if ((caracter != ',') && (caracter != isspace(caracter)) && (caracter != '\n'))
            {
                caracter = getchar();
            }

            if (caracter == ',')
            {
                printf("Separador: ,\n");
                caracter = getchar();
                estadoActual = e2_sep;
            }
            if (isspace(caracter))
            {
                caracter = getchar();
            }
            if (caracter == '\n')
            {
                printf("Fin de Texto: ");
                estadoActual = e3_fdt;
                caracter = EOF;
                break;
            }
        case e1_cad:
            if ((caracter != ',') && (caracter != isspace(caracter)) && (caracter != '\n'))
            {
                ungetc(caracter, stdin);
                printf("%c", caracter);
                caracter = getchar();
                printf("\n");
                estadoActual = e0_inicial;
                break;
            }
        case e2_sep:
            if (caracter == ',')
            {
                ungetc(caracter, stdin);
                printf("%c", caracter);
                caracter = getchar();
                printf("\n");
                estadoActual = e0_inicial;
                break;
            }
        }
    }
}
