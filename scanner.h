#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef enum {
    e0_inicial,
    e1_cad,
    e2_sep,
    e3_fdt
} Estado;

void getToken(void);
