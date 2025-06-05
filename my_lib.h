#ifndef _MY_LIB_H
#define _MY_LIB_H

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define CANT_ARTICULOS 60

#define SUCURSAL_1 0
#define SUCURSAL_2 1
#define SUCURSAL_3 2
#define TOTAL 4

typedef struct {
    char descripcion[90];
    int cantidad_sucursal[3]; // sucursal 1 2 3    
    int total;
}articulos_t;

int bienvenida (void);

int cargadefichas (char *articulo, articulos_t *articulos);

int impfichas (char *articulo, articulos_t *articulos);

int ordenamiento (char *articulo, articulos_t *articulos);

#endif