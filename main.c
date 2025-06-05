#include "my_lib.h"

int main(void)
{
    char articulo[90];
    articulos_t articulos[CANT_ARTICULOS] = {0};

    if (bienvenida ()){
        printf ("Error de ejecucion");
        return 1;
    } /*Mensaje de bienvenida*/

    if (cargadefichas (articulo,articulos)){
        printf ("Error de ejecucion");
        return 2;
    } /*CARGA de las fichas*/

    if (impfichas (articulo,articulos)){
        printf ("Error de ejecucion");
        return 3;
    } /* Impresion de fichas cargadas*/

    if (ordenamiento (articulo,articulos)){
        printf ("Error de ejecucion");
        return 4;
    }; /* Ordenamiento */

    return 0;
}

