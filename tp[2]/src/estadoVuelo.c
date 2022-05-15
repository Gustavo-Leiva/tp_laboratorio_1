/*
 * estadoVuelo.c
 *
 *  Created on: 14 may. 2022
 *      Author: Impuestos
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estadoVuelo.h"
#define ACTIVO 1



/** \brief funcion que se encarga de buscar el ID en el vector de estado vuelo y copiar su descripcion
 *
 * \param
 * \param
 * \return
 *
 */

int cargarDescripcionEstadoVuelo(eEstadoVuelo estadoVuelo[], int tam, int id, char desc[]){
int todoOk;

if(estadoVuelo != NULL && tam > 0 && desc != NULL)
{
    for (int i = 0; i < tam ; i++)
    {
        if(estadoVuelo[i].id == id){

            strcpy(desc, estadoVuelo[i].descripcion);
            todoOk = 1;
            break;
        }
    }

}


return todoOk;
}

int listarEstadoVuelo(eEstadoVuelo estadoVuelo[], int tam){

 int todoOk = 0;
    if(estadoVuelo != NULL && tam > 0 ){

        printf("   *** Listado de Vuelos ***\n");
        printf("  id      descripcion     ");
        printf("------------------------\n");

         for(int i= 0; i < tam; i++){

           printf("    %4d      %10s       ", estadoVuelo[i].id, estadoVuelo[i].descripcion);

         }
    }
    return todoOk;
}



