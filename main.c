#include "my_lib.h"

int main(void)
{
    articulos_t articulos[CANT_ARTICULOS] = {0};

    bienvenida (); /*Mensaje de bienvenida*/

    if (cargadefichas (articulos)){
        printf ("Error de ejecucion");
        return 1;
    } /*CARGA de las fichas*/

    if (impfichas (articulos)){
        printf ("Error de ejecucion");
        return 2;
    } /* Impresion de fichas cargadas*/

    if (ordenamiento (articulos)){
        printf ("Error de ejecucion");
        return 3;
    }; /* Ordenamiento */

    separador (); /*Separa impresión de ficha sin ordenar de la ordenada*/

      if (impfichas (articulos)){
        printf ("Error de ejecucion");
        return 4;
    } /* Impresion de fichas ordenadas por cantidad, de mayor a menor*/

    return 0;
}


