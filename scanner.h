#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef enum {
    cad,
    sep,
    fdt
} Token;

Token getToken(char *buffer);
