/*
 * tipoPasajero.c
 *
 *  Created on: 14 may. 2022
 *      Author: Impuestos
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipoPasajero.h"


int cargarDescripcionTipoPasajero(eTipoPasajero tipoPasajero[], int tam, int id, char desc[]){
int todoOk;

if(tipoPasajero != NULL && tam > 0 && desc != NULL)
{
    for (int i = 0; i < tam ; i++)
    {
        if(tipoPasajero[i].id == id){

            strcpy(desc, tipoPasajero[i].descripcion);
            todoOk = 1;
            break;
        }
    }

}

return todoOk;
}






//
//int validarTipoPasajero(eTipoPasajero vec[], int tam, int id){
// int esValido = 0;
// int indice;
//
// if (buscarTipoPasajero(vec, tam, id, &indice) ){
//    if(indice != -1){
//        esValido = 1;
//    }
// }
// return esValido;
//}
