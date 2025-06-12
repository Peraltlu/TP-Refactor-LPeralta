#include "my_lib.h"

void bienvenida (void){

    printf("\n\n\t\t************Bienvenido al final de Info 1************\n");
}

int cargadefichas (articulos_t *articulos){

    int i, articulo_index, sucursal, opc;
    char articulo[90] = {0};

    do
    {
        printf("\nIngrese la descripcion del articulo: ");
        scanf("%s",articulo);
    
        i=0;

        while (articulos[i].descripcion[0] && strcmp(articulo, articulos[i].descripcion)) i++;
        articulo_index = i;
        strcpy(articulos[i].descripcion, articulo);

        printf("\n%s, Indice: %d\n", articulos[articulo_index].descripcion, articulo_index);

        printf("\nPara que sucursal va a realizar la carga (1,2,3)?: ");
        scanf("%d", &sucursal);

        printf("\nIngrese la cantidad del articulo para la sucursal %d: ", sucursal);
        scanf("%d", &articulos[articulo_index].cantidad_sucursal[sucursal-1]);
        for(i=0;i<3;i++) articulos[articulo_index].total += articulos[articulo_index].cantidad_sucursal[i];        

        printf("\nDesea ingresar otro articulo?(1-Si, 2-No): ");
        scanf("%d",&opc);
    } while (opc==1);

    return 0;

}

int impfichas (articulos_t *articulos){

    int i=0;
    printf("\nArticulo\tSucursal 1\tSucursal 2\tSucursal 3\tTotal\n");
    while(i< CANT_ARTICULOS && articulos[i].descripcion[0]){
        printf("%s\t%9d\t%9d\t%9d\t%9d\n", articulos[i].descripcion, articulos[i].cantidad_sucursal[SUCURSAL_1], articulos[i].cantidad_sucursal[SUCURSAL_2], articulos[i].cantidad_sucursal[SUCURSAL_3],articulos[i].total);
        i++;
    }

    return 0;
}

int ordenamiento (articulos_t *articulos){

    char articulo[90] ={0};

    int  opc=0, i, articulo_index, sucursal;

     for ( opc = 1; opc < CANT_ARTICULOS; opc++)
    {
        for ( i = 0; i < CANT_ARTICULOS-1; i++)
        {
            if(articulos[i].total<articulos[i+1].total){
                strcpy (articulo,articulos[i].descripcion);
                strcpy(articulos[i].descripcion,articulos[i+1].descripcion);
                strcpy(articulos[i+1].descripcion, articulo);

                articulo_index = articulos[i].cantidad_sucursal[SUCURSAL_1];
                articulos[i].cantidad_sucursal[SUCURSAL_1] = articulos[i+1].cantidad_sucursal[SUCURSAL_1];
                articulos[i+1].cantidad_sucursal[SUCURSAL_1] = articulo_index;

                articulo_index = articulos[i].cantidad_sucursal[SUCURSAL_2];
                articulos[i].cantidad_sucursal[SUCURSAL_2] = articulos[i + 1].cantidad_sucursal[SUCURSAL_2];
                articulos[i + 1].cantidad_sucursal[SUCURSAL_2] = articulo_index;

                articulo_index = articulos[i].cantidad_sucursal[SUCURSAL_3];
                articulos[i].cantidad_sucursal[SUCURSAL_3] = articulos[i + 1].cantidad_sucursal[SUCURSAL_3];
                articulos[i + 1].cantidad_sucursal[SUCURSAL_3] = articulo_index;

                articulo_index = articulos[i].total;
                articulos[i].total = articulos[i + 1].total;
                articulos[i + 1].total = articulo_index;
            }
            
        }
        
    }

    return 0;

}

void separador (void){

    printf("\n\n\t\t\t###################################");
    printf("\n\t\t############## FICHAS ORDENADAS ################");
    printf("\n\t\t\t################################### \n\n");
}