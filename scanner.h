#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

typedef enum
{
    cad,
    sep,
    esp,
    fdt,
} token;

token getToken(void);