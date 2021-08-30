#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef enum {
    cad,
    sep,
    fdt,
} token;

void getToken(void);
