#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef enum {
    cad,
    sep,
    esp,
    fdt,
} token;

token getToken(void);

void imprimirCadena(token);